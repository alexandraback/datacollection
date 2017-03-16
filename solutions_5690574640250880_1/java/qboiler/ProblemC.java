/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.brycealcock.codejam.y2014.qr;

import com.brycealcock.codejam.Case;
import com.brycealcock.codejam.CodeJamBase;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author bryce
 */
public class ProblemC extends CodeJamBase {

    @Override
    protected Case readAndProcessCase(int caseNumber, BufferedReader br) throws IOException, NumberFormatException {
        Scanner s = new Scanner(br.readLine());
        int rows = s.nextInt();
        int cols = s.nextInt();
        boolean transpose = false;
        if (rows > cols) {
            int tmp = rows;
            rows = cols;
            cols = tmp;
            transpose = true;
        }
        return new PCase(caseNumber, rows, cols, s.nextInt(), transpose);
    }

    class PCase extends Case {

        int rows;
        int columns;
        int mins;
        boolean transpose;
        char[][] resultArray;
        int ci;

        PCase(int caseNumber, int r, int c, int m, boolean t) {
            super(caseNumber);
            rows = r;
            ci=caseNumber;
            columns = c;
            mins = m;
            transpose = t;
            this.resultArray = new char[rows][columns];
        }
        String result = "";

        @Override
        protected String caseResult() {
            return result;
        }

        @Override
        protected Case processCase() {
            System.out.println("Starting Case Number: " + ci);
            // Handle no mins.
            boolean impossible = false;
            if (rows * columns - mins == 1) {
                // handle single spot...
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        resultArray[i][j] = '*';
                    }
                }
                resultArray[0][0] = 'c';
            } else if (mins == 0) {
                //  any grid will do.
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {
                        resultArray[i][j] = '.';
                    }
                }
                resultArray[0][0] = 'c';
            } else if (rows == 1) {
                // handle 1 row....
                for (int i = 0; i < columns; ++i) {
                    if (i < mins) {
                        resultArray[0][i] = '*';
                    } else {
                        resultArray[0][i] = '.';
                    }
                }
                resultArray[0][columns - 1] = 'c';
            } else if (rows == 2) {
                // handle 2 rows.
                if (mins % 2 == 1 || mins == columns * rows - 2) {
                    impossible = true;
                } else {
                    int minesPlaced = 0;
                    for (int i = 0; i < columns; ++i) {
                        for (int j = 0; j < rows; ++j) {
                            if (minesPlaced < mins) {
                                ++minesPlaced;
                                resultArray[j][i] = '*';
                            } else {
                                resultArray[j][i] = '.';
                            }
                        }
                    }
                    resultArray[rows - 1][columns - 1] = 'c';
                }
            } else if (rows >= 3) {
                //2 Looses
                //3 looses
                //4 wins
                //5 looses
                //6 wins
                //7 looses
                //8 wins
                //9 wins.
                int freeSpots = rows * columns - mins;
                if (freeSpots == 2
                        || freeSpots == 3
                        || freeSpots == 5
                        || freeSpots == 7) {
                    impossible = true;
                } else if(freeSpots ==4 ){
                    // This is a special case.
                    for (int i = 0; i < columns; ++i) {
                        for (int j = 0; j < rows; ++j) {
                            resultArray[j][i] = '*';
                        }
                    }
                    resultArray[0][0]='c';
                    resultArray[1][0]='.';
                    resultArray[0][1]='.';
                    resultArray[1][1]='.';
                    
                } else {
                    System.out.println("big table.");
                    for (int i = 0; i < columns; ++i) {
                        for (int j = 0; j < rows; ++j) {
                            resultArray[j][i] = '.';
                        }
                    }
                    resultArray[rows-1][columns-1] = 'c';
                    
                    //  lets just make a connected grid.
                    int columnReduction = mins / rows;// = columnReduction;
                    for (int i = 0; i < columnReduction; ++i) {
                        for (int j = 0; j < rows; ++j) {
                            resultArray[j][i] = '*';
                        }
                    }
                    System.out.println("Table After pass1." + process(resultArray, transpose));
                    int remainder = mins % rows;
                    if (columns - columnReduction == 1) {
                        //  move them down.
                        for (int i = 0; i < rows; ++i) {
                            resultArray[i][columnReduction-1] = '.';
                        }
                        remainder += rows;

                        // borrow 3 more if need.
                        if (remainder % 2 == 1) {
                            remainder += 3;
                            for (int i = 0; i < 3; ++i) {
                                //steal 3 from the previous row.
                                resultArray[rows - i - 1][columnReduction - 2] = '.';
                            }
                        }
                        // just place them.
                        int placed = 0;
                        for (int i = 0; i < rows; ++i) {
                            for (int j = columnReduction - 1; j < columns; ++j) {
                                if (placed < remainder) {
                                    resultArray[i][j] = '*';
                                    ++placed;
                                }
                            }
                        }

                        //  we have to carve out a square of some kind.
                    } else if (columns - columnReduction == 3) {
                        if (remainder >= 3) {
                            // Place 3 down.
                            for(int i=0;i<3;++i){
                                resultArray[0][columnReduction + i]='*';
                                remainder--;
                            }
                            
                            
                            for(int i=0;i<remainder;++i){
                                resultArray[i+1][columnReduction]='*';
                            }
                        }else{
                            for(int i=0;i<remainder;++i){
                                resultArray[i][columnReduction]='*';
                            }
                        }

                    } else {
                        System.out.println("2 columns remaining");
                        if (remainder % 2 == 1 && columnReduction>0 && rows>4) {
                            if(rows==5 && remainder!=1){
                                
                            }else{
                            remainder += 3;
                            for (int i = 0; i < 3; ++i) {
                                //steal 3 from the previous row.
                                resultArray[rows - i - 1][columnReduction - 1] = '.';
                            }
                            }
                        }
                        int placed = 0;
                        for (int i = 0; i < rows; ++i) {
                            for (int j =0; j < 2; ++j) {
                                if (placed < remainder) {
                                    resultArray[i][columnReduction+j] = '*';
                                    ++placed;
                                }
                            }
                        }
                    }
                }
            }

            if (impossible) {
                result += "\nImpossible";
            } else {
                result += process(resultArray, transpose);
            }
            return this;
        }

        private String process(char[][] result, boolean transpose) {
            String r = "";
            if (transpose) {
                for (int i = 0; i < columns; ++i) {
                    r += "\n";
                    for (int j = 0; j < rows; ++j) {
                        r += result[j][i];
                    }
                }

            } else {
                for (int i = 0; i < rows; ++i) {
                    r += "\n";
                    for (int j = 0; j < columns; ++j) {
                        r += result[i][j];
                    }
                }
            }
            return r;
        }

    }
}

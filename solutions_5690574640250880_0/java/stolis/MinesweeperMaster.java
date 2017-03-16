package qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class MinesweeperMaster {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("C-small-attempt3.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int R = in.nextInt();
            int C = in.nextInt();
            int M = in.nextInt();
            StringBuilder maze = new StringBuilder();
            if (R == 1) {
                maze.append('c');
                for (int c=1; c<C-M; c++) {
                    maze.append('.');
                }
                for (int c=0; c<M; c++) {
                    maze.append('*');
                }
                maze.append('\n');
            } else if (C == 1) {
                maze.append("c\n");
                for (int r=1; r<R-M; r++) {
                    maze.append(".\n");
                }
                for (int r=0; r<M; r++) {
                    maze.append("*\n");
                }
            } else {
                int D = R*C-M;
                if (D == 1) {
                    for (int r=0; r<R; r++) {
                        for (int c=0; c<C; c++) {
                            if (c == 0 && r == 0) {
                                maze.append('c');
                            } else {
                                maze.append('*');
                            }
                        }
                        maze.append('\n');
                    }
                } else if (D < 4 || D == 5 || D == 7 || (D%2 == 1 && (R == 2 || C == 2))) {
                    maze.append("Impossible\n");
                } else {
                    boolean[][] mines = new boolean[C][R];
                    int rest = M;
                    if (C > 2) {
                        int fullRows = Math.min(R-2, M/(C-2));
                        for (int i=0; i<fullRows; i++) {
                            for (int j=0; j<C-2; j++) {
                                mines[j][i] = true;
                            }
                        }
                        rest -= fullRows*(C-2);
                        if (fullRows == R-2) {
                            if (D%2 == 1) {
                                mines[C-3][R-3] = false;
                                rest++;
                            }
                        } else {
                            for (int j=0; j<rest; j++) {
                                mines[j][fullRows] = true;
                            }
                            rest = 0;
                        }
                    }
                    int column = 0;
                    while (rest > 0 && column+3<C) {
                        mines[column][R-2] = true;
                        mines[column][R-1] = true;
                        rest-=2;
                        column++;
                    }
                    int row = 0;
                    while (rest > 0 && row+3<R) {
                        mines[C-2][row] = true;
                        mines[C-1][row] = true;
                        rest-=2;
                        row++;
                    }
                    if (rest > 0) {
                        if (R > 2) {
                            mines[C-2][R-3] = true;
                            mines[C-1][R-3] = true;
                            rest-=2;
                        }
                    }
                    if (rest > 0) {
                        mines[C-3][R-1] = true;
                        mines[C-3][R-2] = true;
                        rest-=2;
                    }
                    for (int r=0; r<R; r++) {
                        for (int c=0; c<C; c++) {
                            if (mines[c][r]) {
                                maze.append('*');
                            } else if (c == C-1 && r == R-1) {
                                maze.append('c');
                            } else {
                                maze.append('.');
                            }
                        }
                        maze.append('\n');
                    }
                }
            }
            
            out.println("Case #"+(t+1)+":");
            out.print(maze);
        }

        out.close();
    }
    
}

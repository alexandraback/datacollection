package codejam2014;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Title: Problem C. Minesweeper Master
 * 
 * Link: https://code.google.com/codejam/contest/2974486/dashboard#s=p2
 */
public class MinesweeperMaster {
    public static void main(String... args) throws Exception {
        //resolve("2014-QR-mines-tiny");
        //resolve("2014-QR-mines-small0");
        //resolve("2014-QR-mines-small1");
        //resolve("2014-QR-mines-small2");
        //resolve("2014-QR-mines-small3");
        resolve("2014-QR-mines-large");
    }
    
    private static void resolve(String dataFile) throws Exception {
        // Initialize input and output.
        Scanner scanner = new Scanner(new File(dataFile + ".in"));
        PrintWriter printer = new PrintWriter(dataFile + ".out");
        
        // Read number of test cases.
        int T = scanner.nextInt();
        
        // Evaluate each test case.
        for(int t=0; t<T; t++) {
            // Read input.
            int R = scanner.nextInt();
            int C = scanner.nextInt();
            int M = scanner.nextInt();
            
            // Calculate result.
            System.out.println(R + " - " + C + " - " + M);
            char[][] result = resolveTestCase(R, C, M);
            
            // Print output.
            String message = "Case #" + (t+1) + ":\n";
            if(result == null) {
                message += "Impossible\n";
            } else {
                for(int i=0; i<R; i++) {
                    for(int j=0; j<C; j++) {
                        message += result[i][j];
                    }
                    message += "\n";
                }
            }
            System.out.print(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static char[][] resolveTestCase(int R, int C, int M) {        
        // Basic verification.
        int diff = R*C - M;
        if(diff <= 0) return null;
        
        // Case -1.
        if(M == 0) {
            char[][] result = new char[R][C];
            for(int i=0; i<R; i++)
                for(int j=0; j<C; j++)
                    result[i][j] = '.';
            result[0][0] = 'c';
            return result;
        }
        
        // Case 0.
        if(diff == 1) {
            char[][] result = new char[R][C];
            for(int i=0; i<R; i++)
                for(int j=0; j<C; j++)
                    result[i][j] = '*';
            result[0][0] = 'c';
            return result;
        }
          
        // Case 1.
        if(R == 1 || C == 1) {
            char[][] result = new char[R][C];
            for(int i=0; i<R; i++)
                for(int j=0; j<C; j++)
                    result[i][j] = (i+j < diff)? '.' : '*';
            result[0][0] = 'c';
            return result;
        }
        
        // Case 2.
        if(R == 2 || C == 2) {
            if(diff > 2 && diff%2 ==0) {                
                char[][] result = new char[R][C];
                int k = 0;
                if(R == 2) {
                    for(int j=0; j<C; j++)
                        for(int i=0; i<R; i++) {
                            result[i][j] = (k < diff)? '.' : '*';
                            k++;
                    }
                } else {
                    for(int i=0; i<R; i++)
                        for(int j=0; j<C; j++) {
                            result[i][j] = (k < diff)? '.' : '*';
                            k++;
                        }             
                }
                result[0][0] = 'c';
                return result;
            } else {
                return null;
            }
        }

        // Case 3: Remove exceptions.
        if(diff == 4 || diff == 6 || diff == 9) {
            char[][] result = new char[R][C];
            for(int i=0; i<R; i++)
                for(int j=0; j<C; j++)
                    result[i][j] = '*';
            result[0][0] = 'c';
            result[0][1] = '.';
            result[1][0] = '.';
            result[1][1] = '.';
            if(diff == 6 || diff == 9) {
                result[2][0] = '.';
                result[2][1] = '.';            
            }
            if(diff == 9) {
                result[0][2] = '.';
                result[1][2] = '.';
                result[2][2] = '.';
            }
            return result;
        }
        
        // Case 3: Filter impossible cases.
        if(diff < 8) {
            return null;
        }
        
        // Case 3.1: At least two rows are filled.
        if(diff > 2*C + 1) {
            char[][] result = new char[R][C];
            
            // Fill rows sequencially.
            int k = 0;
            for(int i=0; i<R; i++)
                for(int j=0; j<C; j++) {
                    result[i][j] = k < diff? '.' : '*';
                    k++;
                }
            
            // Verify if there is a lonely block.
            if(diff%C == 1) {
                int last_row = diff/C;
                result[last_row][1] = '.';
                result[last_row-1][C-1] = '*';
            }
            
            result[0][0] = 'c';
            return result;
        }
                                
        // Case 3.2: less than two rows filled.
        // Even: .....*  Odd: .....*
        //       .....*       .....*
        //       ******       ...***
        int k = 0;
        char[][] result = new char[R][C];
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                result[i][j] = '*';
        
        if(diff%2 == 1) {
            result[2][0] = '.';
            result[2][1] = '.';
            result[2][2] = '.';
            k += 3;
        }
        
        int j=0;
        while(k < diff) {
            result[0][j] = '.';
            result[1][j] = '.';
            j++;
            k += 2;
        }
        
        result[0][0] = 'c';
        return result;
    }
}
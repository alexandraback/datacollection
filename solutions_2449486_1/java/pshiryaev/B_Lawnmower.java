package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/**
 *
 * @author Pavel.Shiryaev
 */
public class B_Lawnmower {

    static byte[][] f1 = new byte[100][100]; // original field
    static byte[][] f2 = new byte[100][100];
    static int n = 0;
    static int m = 0;

    public static void main(String fileName) {

        InputStream fis;
        OutputStream fos;
        BufferedReader br;
        BufferedWriter bw;

        String output = "";

        try {
            fis = new FileInputStream(fileName);
            fos = new FileOutputStream(fileName.concat(".out"));

            br = new BufferedReader(new InputStreamReader(fis)); //, Charset.forName("UTF-8")));
            bw = new BufferedWriter(new OutputStreamWriter(fos)); //, Charset.forName("UTF-8")));

            String line = br.readLine();
            int nc = Integer.parseInt(line); // The first line of the input gives the number of test cases, T. T test cases follow. 

            // read cases
            for (int cc = 1; cc <= nc; cc++) {

                System.out.print("Case #" + cc + " out of " + nc + ": ");
                bw.write("Case #" + cc + ": ");

                // Each test case begins with a line containing two integers: N and M. 
                line = br.readLine();
                String[] nm = line.split(" ");

                n = Integer.parseInt(nm[0]);
                System.out.print("  N: " + Integer.toString(n));
                m = Integer.parseInt(nm[1]);
                System.out.println("  M: " + Integer.toString(m));

                // declare field var

                byte fmin = 100; // lowest spot

                // Next follow N lines, with the ith line containing M integers ai,j each, 
                // the number ai,j describing the desired height of the grass in the jth square of the ith row.

                for (int i = 0; i < n; i++) {
                    line = br.readLine();
                    String[] aj = line.split(" ");
                    for (int j = 0; j < m; j++) {
                        byte b = Byte.parseByte(aj[j]);
                        f1[i][j] = b; // fill matrix
                        f2[i][j] = b; // fill 2nd copy of the matrix
                        if (fmin > b) {
                            fmin = b;
                        } // set new minimum - lowest point on the field
                    }
                }

                //DebugPrintMatrix();

                // iterate from the lowest point to T = 100
                boolean result = false;
                boolean unSolvable = false;
                for (int t = 1; t <= 100; t++) {
                    //System.out.println("T = " + t);
                    // check if the field is flat -> success
                    byte check = f1[0][0]; // arbitrary field
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (f1[i][j] != check) {
                                check = -1;
                                break;
                            }
                        }
                    }
                    if (check != -1) {
                        result = true;
                        break;
                    }

                    // find current minimum T on a perimeter of the matrix
                    // 1. iterate through the columns                    
                    for (int j = 0; j < m; j++) {
                        boolean foundColumn = true;
                        if ((f1[0][j] == t) || (f1[n - 1][j] == t)) {   // found t on the first or the last line - now check if all of this column is filled with t
                            for (int i = 0; i < n; i++) {
                                if (f1[i][j] != t) {
                                    foundColumn = false;
                                    break;
                                }
                            }
                            if (foundColumn) // yes!
                            {
                                // add +1 to all cells in this column reversing the mowing process
                                for (int i = 0; i < n; i++) {
                                    f2[i][j] = (byte) (t + 1);
                                }  // t+1 ?
                            }

                        }
                    }

                    //DebugPrintMatrix2();
                    
                    // 2. iterate through the rows                    
                    for (int i = 0; i < n; i++) {
                        boolean foundRow = true;
                        if ((f1[i][0] == t) || (f1[i][m - 1] == t)) {   // found t on the first or the last column  - now check if all of this column is filled with t
                            for (int j = 0; j < m; j++) {
                                if (f1[i][j] != t) {
                                    foundRow = false;
                                    break;
                                }
                            }
                            if (foundRow) // yes!
                            {
                                // add +1 to all cells in this column reversing the mowing process
                                for (int j = 0; j < m; j++) {
                                    f2[i][j] = (byte) (t + 1);
                                }
                            }

                        }
                    }

                    //DebugPrintMatrix2();
                    
                    // copy f2 -> f1
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            f1[i][j] = f2[i][j];
                            if (f1[i][j] < t) 
                            {
                                unSolvable = true;
                                i = n;
                                break;
                            } // check if any fields have value < t -> means unsolvable
                        }
                    }


                    if (unSolvable) {
                        break; // for t                     
                    }

                    //DebugPrintMatrix();
                    
                } // end for t



                // display results
                output = (result) ? "YES" : "NO";

                System.out.println("Result: " + output);
                bw.write(output);
                bw.newLine();


                // line = br.readLine(); // Each test case is followed by an empty line.
            }


            br.close();
            fis.close();
            bw.close();
            fos.close();
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }
    }

    static void DebugPrintMatrix2() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(f2[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void DebugPrintMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(f1[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
    
}
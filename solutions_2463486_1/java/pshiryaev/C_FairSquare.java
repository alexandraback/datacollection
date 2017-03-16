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
class C_FairSquare {

    public void main(String fileName) {

        InputStream fis;
        OutputStream fos;
        BufferedReader br;
        BufferedWriter bw;

        try {
            fis = new FileInputStream(fileName);
            fos = new FileOutputStream(fileName.concat(".out"));

            br = new BufferedReader(new InputStreamReader(fis)); //, Charset.forName("UTF-8")));
            bw = new BufferedWriter(new OutputStreamWriter(fos)); //, Charset.forName("UTF-8")));

            String line = br.readLine();
            int nc = Integer.parseInt(line); // The first line of the input gives the number of test cases, T. T lines follow.

            // Each line contains two numbers, A and B - the endpoints of the interval Little John is looking at.
            long a = 0;
            long b = 0;
            // read cases
            for (int cc = 1; cc <= nc; cc++) {

                String output = "Case #" + cc + ": ";
                System.out.print(output);
                bw.write(output);

                line = br.readLine();
                String[] ab = line.split(" ");
                a = Long.parseLong(ab[0]);
                System.out.print("  A: " + Long.toString(a));
                b = Long.parseLong(ab[1]);
                System.out.print("  B: " + Long.toString(b));

                // find root squares of A & B
                long a1 = (long) Math.sqrt(a);
                System.out.print("  A': " + Long.toString(a1));
                long b1 = (long) Math.sqrt(b);
                System.out.println("  B': " + Long.toString(b1));

                int count = 0;


                {
                    for (long x = a1; x <= b1; x++) {


                        if (testFairSquare(x)) {
                            if ((x * x >= a)) {
                                count++;
                                //System.out.println("Palindrome: " + x*x);
                            }
                        }


                        if (x >= 1000) // 2-digit optimization    
                        {
                            byte f = getFirst2DigitsBackOrder(x);
                            long xx = ((x / 100) * 100) + f;
                            if (x < xx) {
                                x = xx - 1;
                            } // fast forward to the next number
                            else {
                                // e.g. 1001 -> 1111, 1221, 1331, 1441, 1551, ..., 1991, 2002 .. 9889, 9999, 10001                                
                                if (f == 99) // e.g. 9999 -> 10001
                                {
                                    x = xx + 1;
                                }
                                else if (f >= 90) // e.g. 1991 -> 2002 (backorder!)
                                { 
                                    x = xx + 10;
                                }
                                else { // e.g. 1001 -> 1111, 1991 -> 2002, 10001 -> 10101
                                    if (x < 10000) {
                                    x = xx + 109; } else
                                    {
                                        x = xx + 99; // 10001 -> 10101
                                    }
                                }
                            }
                        } else if (x >= 10) // 1-digit optimization
                        {
                            byte f = getFirstDigit(x);
                            long xx = ((x / 10) * 10) + f;
                            if (x < xx) {
                                x = xx - 1;
                            } // fast forward to the next number
                            else {

                                if (f != 9) {
                                    if (x < 100) {
                                        x = xx + 10;
                                    } else {
                                        x = xx + 9;
                                    }
                                } else {
                                    x = xx + 1;
                                }
                            }

                        }
                    }

                }


                // display results
                output = Integer.toString(count);

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

    private boolean testFairSquare(long x) {
        return (isPalindrome(x) && isPalindrome(x * x)) ? true : false;
    }

    
    private boolean isPalindrome(long x) {
        String t = Long.toString(x);
        if (t.length() == 1) {
            return true;
        }
        for (int i = 0; i < (t.length() / 2); i++) {
            if (t.charAt(i) != t.charAt(t.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private byte getFirstDigit(long x) {
        return (byte) (((byte) (Long.toString(x).charAt(0))) - 48); // '0'
    }

    private byte getFirst2DigitsBackOrder(long x) {
        byte t = (byte) (((byte) (Long.toString(x).charAt(1))) - 48); // '0'
        t = (byte) (t * 10);
        t += (byte) (((byte) (Long.toString(x).charAt(0))) - 48); // '0'
        return t;
    }

}

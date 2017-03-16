package com.company.codejam;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int cases = in.nextInt();
            for (int index = 1; index <= cases; index++) {

                int L = in.nextInt();
                int X = in.nextInt();
                String exp = in.next();
                String answer;
                if (!isEligible(exp, X)) {
                    answer = "NO";
                } else {
                    if (success(exp, X)) {
                        answer = "YES";
                    } else {
                        answer = "NO";
                    }
                }
                out.printf("Case #%d: %s\n", index, answer);
                out.flush();

            }


        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }//end method main

    public static boolean isEligible(String exp, int X) {
        if (X % 4 == 0) {
            return false;
        }
        boolean sign = false;    // false = + , true = -
        char c;
        char result = '1';
        for (int index = 0; index < exp.length(); index++) {
            c = exp.charAt(index);
            if (result == '1') {
                result = c;
            } else if (result == 'i') {
                if (c == 'i') {
                    sign = !sign;
                    result = '1';
                } else if (c == 'j') {
                    result = 'k';
                } else if (c == 'k') {
                    sign = !sign;
                    result = 'j';
                }
            } else if (result == 'j') {
                if (c == 'i') {
                    sign = !sign;
                    result = 'k';
                } else if (c == 'j') {
                    sign = !sign;
                    result = '1';
                } else if (c == 'k') {
                    result = 'i';
                }

            } else // if (result == 'k')
            {
                if (c == 'i') {
                    result = 'j';
                } else if (c == 'j') {
                    sign = !sign;
                    result = 'i';
                } else if (c == 'k') {
                    sign = !sign;
                    result = '1';
                }

            }
        }//end for
        if(X%4==2){
            if(result=='1'){
                return false;
            }else{
                return true;
            }
        }
        if (result != '1' && X % 4 == 3) {
            sign = !sign;
        }


        if (sign && result == '1') {
            return true;
        } else {
            return false;
        }

    }//end method isEligible

    public static boolean success(String exp, int X) {
        boolean possible = false;
        int firstMarker = 0;
        int expLength = exp.length();

        boolean sign = false;
        char result = '1';
        while (!possible && firstMarker <= (expLength * X - 3)) {
            char c = exp.charAt(firstMarker % expLength);
            /////////////////// Evaluate result * c /////////////////
            if (result == '1') {
                result = c;
            } else if (result == 'i') {
                if (c == 'i') {
                    sign = !sign;
                    result = '1';
                } else if (c == 'j') {
                    result = 'k';
                } else if (c == 'k') {
                    sign = !sign;
                    result = 'j';
                }
            } else if (result == 'j') {
                if (c == 'i') {
                    sign = !sign;
                    result = 'k';
                } else if (c == 'j') {
                    sign = !sign;
                    result = '1';
                } else if (c == 'k') {
                    result = 'i';
                }

            } else // if (result == 'k')
            {
                if (c == 'i') {
                    result = 'j';
                } else if (c == 'j') {
                    sign = !sign;
                    result = 'i';
                } else if (c == 'k') {
                    sign = !sign;
                    result = '1';
                }

            }
            ///////////////// End Evaluate result * c ///////////////////////////////
            if (result == 'i') {
                possible = true;
            }
            firstMarker++;
        }//end while
        if (!possible) {
            return false;
        }

        possible = false;
        sign = false;
        result = '1';
        while (!possible && firstMarker < expLength * X - 1) {
            char c = exp.charAt(firstMarker % expLength);
            /////////////////// Evaluate result * c //////////////
            if (result == '1') {
                result = c;
            } else if (result == 'i') {
                if (c == 'i') {
                    sign = !sign;
                    result = '1';
                } else if (c == 'j') {
                    result = 'k';
                } else if (c == 'k') {
                    sign = !sign;
                    result = 'j';
                }
            } else if (result == 'j') {
                if (c == 'i') {
                    sign = !sign;
                    result = 'k';
                } else if (c == 'j') {
                    sign = !sign;
                    result = '1';
                } else if (c == 'k') {
                    result = 'i';
                }

            } else // if (result == 'k')
            {
                if (c == 'i') {
                    result = 'j';
                } else if (c == 'j') {
                    sign = !sign;
                    result = 'i';
                } else if (c == 'k') {
                    sign = !sign;
                    result = '1';
                }

            }
            //////////////////// End Evaluation result * c ///////
            if (result == 'j') {
                possible = true;
            }
            firstMarker++;
        }//end while

        return possible;

    }//end method success
}//end class Main

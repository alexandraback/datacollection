package concursoprogramacion;

import java.math.BigInteger;
import java.util.*;

public class Ejercicio2 {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int cases = in.nextInt();
        in.nextLine();

        for (int k = 1; k <= cases; k++) {
            String line = in.nextLine();
            String[] input = line.split(" ");

            String[] ret = scoreBoard(input);

            for (int i = 0; i < input[0].length(); i++) {

                String[] inputs = new String[2];
                inputs[0] = input[0];
                inputs[1] = input[1];

                if (inputs[0].charAt(i) == '?' && inputs[1].charAt(i) != '?') {
                    if (((char) (inputs[1].charAt(i) - 1)) >= '0') {
                        inputs[0] = inputs[0].substring(0, i) + ((char) (inputs[1].charAt(i) - 1)) 
                                + inputs[0].substring(i+1, inputs[0].length());
                    }
                    String[] ret2 = scoreBoard(inputs);
                    ret = bestChoice(ret, ret2);

                    if (((char) (inputs[1].charAt(i) + 1)) <= '9') {
                        inputs[0] = inputs[0].substring(0, i) + ((char) (inputs[1].charAt(i) + 1)) 
                                + inputs[0].substring(i+1, inputs[0].length());
                    }
                    ret2 = scoreBoard(inputs);
                    ret = bestChoice(ret, ret2);
                    
                } else if (inputs[0].charAt(i) != '?' && inputs[1].charAt(i) == '?') {
                    if (((char) (inputs[0].charAt(i) - 1)) >= '0') {
                        inputs[1] = inputs[1].substring(0, i) + ((char) (inputs[0].charAt(i) - 1)) 
                                + inputs[1].substring(i+1, inputs[1].length());
                    }
                    String[] ret2 = scoreBoard(inputs);
                    ret = bestChoice(ret, ret2);

                    if (((char) (inputs[0].charAt(i) + 1)) <= '9') {
                        inputs[1] = inputs[1].substring(0, i) + ((char) (inputs[0].charAt(i) + 1)) 
                                + inputs[1].substring(i+1, inputs[1].length());
                    }
                    ret2 = scoreBoard(inputs);
                    ret = bestChoice(ret, ret2);
                } else if (inputs[0].charAt(i) == '?' && inputs[1].charAt(i) == '?') {
                    inputs[0] = inputs[0].substring(0, i) + '0' + inputs[0].substring(i+1, inputs[0].length());
                    inputs[1] = inputs[1].substring(0, i) + '1' + inputs[1].substring(i+1, inputs[1].length());

                    String[] ret2 = scoreBoard(inputs);
                    ret = bestChoice(ret, ret2);

                    inputs[0] = inputs[0].substring(0, i) + '1' + inputs[0].substring(i+1, inputs[0].length());
                    inputs[1] = inputs[1].substring(0, i) + '0' + inputs[1].substring(i+1, inputs[1].length());

                    ret2 = scoreBoard(inputs);
                    ret = bestChoice(ret, ret2);
                }
            }

            System.out.println("Case #" + k + ": " + ret[0] + " " + ret[1]);
        }

    }
    
    public static String[] bestChoice(String[] a, String[] b) {
        BigInteger diffA = difference(a);
        BigInteger diffB = difference(b);
        
        if(diffA.compareTo(diffB) == -1) {
            return a;
        } else if(diffA.compareTo(diffB) == 0) {
            BigInteger codersA = new BigInteger(a[0]);
            BigInteger codersB = new BigInteger(b[0]);
            
            if(codersA.compareTo(codersB) == -1) {
                return a;
            } else if(codersA.compareTo(codersB) == 0) {
                BigInteger othersA = new BigInteger(a[1]);
                BigInteger othersB = new BigInteger(b[1]);
                
                if(othersA.compareTo(othersB) < 1) {
                    return a;
                }
            }
        }
        
        return b;
    }

    public static BigInteger difference(String[] score) {
        BigInteger a = new BigInteger(score[0]);
        BigInteger b = new BigInteger(score[1]);

        return (a.subtract(b)).abs();
    }

    public static String[] scoreBoard(String[] inputs) {
        String left = "";
        String right = "";
        int bigger = -1;
        for (int i = 0; i < inputs[0].length(); i++) {
            if (bigger == -1) {
                if (inputs[0].charAt(i) == '?' && inputs[1].charAt(i) == '?') {
                    left += '0';
                    right += '0';
                } else if (inputs[0].charAt(i) == '?') {
                    left += inputs[1].charAt(i);
                    right += inputs[1].charAt(i);
                } else if (inputs[1].charAt(i) == '?') {
                    left += inputs[0].charAt(i);
                    right += inputs[0].charAt(i);
                } else if (inputs[0].charAt(i) == inputs[1].charAt(i)) {
                    left += inputs[0].charAt(i);
                    right += inputs[0].charAt(i);
                } else if (inputs[0].charAt(i) > inputs[1].charAt(i)) {
                    left += inputs[0].charAt(i);
                    right += inputs[1].charAt(i);
                    bigger = 0;
                } else {
                    left += inputs[0].charAt(i);
                    right += inputs[1].charAt(i);
                    bigger = 1;
                }
            } else {
                if (inputs[0].charAt(i) == '?') {
                    if (bigger == 0) {
                        left += '0';
                    } else {
                        left += '9';
                    }
                } else {
                    left += inputs[0].charAt(i);
                }

                if (inputs[1].charAt(i) == '?') {
                    if (bigger == 1) {
                        right += '0';
                    } else {
                        right += '9';
                    }
                } else {
                    right += inputs[1].charAt(i);
                }

            }

        }

        String[] ret = new String[2];
        ret[0] = left;
        ret[1] = right;

        return ret;

    }

}

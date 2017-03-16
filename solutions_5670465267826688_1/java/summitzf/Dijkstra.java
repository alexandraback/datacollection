import java.util.*;
import java.io.*;

public class Dijkstra {
    private static byte multiply(byte a, byte b) throws Exception {
        // 'i' -> 2, 'j' -> 4, 'k' -> 8
        byte sign = 1;
        if (a < 0) {
            a = (byte)(-a);
            sign = (byte)(-sign);
        }
        if (b < 0) {
            b = (byte)(-b);
            sign = (byte)(-sign);
        }
        byte result;
        if (a == 1 || b == 1) {
            result = (byte)(a*b);
        } else if (a == b) {
            result = (byte)(-1);
        } else {
            byte mid = (byte)(a*b);
            if (mid == 8) {
                result = (byte)((a < b) ? mid: -mid);
            } else if (mid == 32) {
                result = (byte)((a < b) ? 2: -2);
            } else if (mid == 16) {
                result = (byte)((a > b) ? 4: -4);
            } else {
                throw new Exception("2 4 8 not working");
            }
        }
        return (byte)(sign*result);
    }
    
    public static void main(String[] args) throws Exception {
        if (args.length == 0)
            throw new IllegalArgumentException("Require input file name");
        Scanner sc = new Scanner(new FileReader(args[0]));
        String outFilename = args[0].replaceFirst("[.][^.]+$", "").concat(".out");
        PrintWriter pw = new PrintWriter(new FileWriter(outFilename));
        int caseCnt = Integer.parseInt(sc.nextLine());
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");
            String[] LX = sc.nextLine().split("\\s+");
            boolean isDijkstra = false;
            int L = Integer.parseInt(LX[0]); // max L is 10000, Integer should be ok
            long X = Long.parseLong(LX[1]); // to hold large data set X
            String baseStr = sc.nextLine();
            byte[] base = new byte[L];
            byte baseValue = 1;
            for (int i = 0; i < L; i++) {
                switch(baseStr.charAt(i)) {
                    case 'i':
                        base[i] = (byte)2;
                        break;
                    case 'j':
                        base[i] = (byte)4;
                        break;
                    case 'k':
                        base[i] = (byte)8;
                        break;
                    default:
                        throw new Exception("it is not ijk");
                }
                baseValue = multiply(baseValue, base[i]);
            }
            // 4 repeated substring always 1
            // so examine at most 3 substrings
            // first check if its multiplication is -1
            int repeat = (int)(X%4);
            byte testMinus1 = 1;
            while (repeat-- > 0) {
                testMinus1 = multiply(testMinus1, baseValue);
            }
            if (testMinus1 == -1) {
                // now the total multiplication is -1
                // examine if it is ijk
                repeat = (int)(X%4);
                // if X is larger than 4, must take at least 4 in scan
                repeat += (X > 4l) ? 4: 0;
                byte currentValue = 1;
                boolean foundI = false;
                boolean foundJ = false;
                outerlooper:
                while(repeat-- > 0) {
                    for (int i = 0; i < L; i++) {
                        currentValue = multiply(currentValue, base[i]);
                        if (!foundI && currentValue == 2 && !foundJ) {
                            foundI = true;
                            currentValue = 1;
                        }
                        if (foundI && currentValue == 4 && !foundJ) {
                            foundJ = true;
                            break outerlooper;
                        }
                    }
                }
                isDijkstra = foundI && foundJ;
            }
            if (isDijkstra) {
                pw.println("YES");
            } else {
                pw.println("NO");
            }
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}

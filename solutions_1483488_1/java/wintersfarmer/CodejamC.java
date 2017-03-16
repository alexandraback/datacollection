import java.io.*;
import java.util.*;

class CodejamC {
    public static int power[];
    public static void main (String [] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("E:/C-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("E:/outC.txt")));
        int nTest = Integer.parseInt(in.readLine());
        power = new int[10];
        power[0] = 1;
        for (int i = 1; i < power.length; i++) {
            power[i] = power[i-1] * 10;
        }
        for (int testIndex = 0; testIndex < nTest; testIndex++) {
            out.print("Case #" + (testIndex + 1) + ": ");
            /***** start **********/
            StringTokenizer st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long result = 0;
            for (int p = a; p <= b; p++) {
                int len = getLen(p);
                int q = p;
                for (int offset = 1; offset < len; offset++) {
                    int t = q * 10;
                    q = t % power[len] + t / power[len];
                    if (q == p) {
                        break;
                    }
                    if (q <= b && q > p) {
                        result++;
                    }
                }
            }
            out.print(result);
            /***** end   **********/
            out.println();
        }
        out.close();
    }
    public static int getLen(long l) {
        for (int i = 1; i < 10; i++) {
            if (l < power[i]) {
                return i;
            }
        }
        return -1;
    }
    public static int itoa(int a, char[] s) {
        int len = 0;
        while (a > 0) {
            s[len] = (char) (a % 10 + '0');
            a /= 10;
            len++;
        }
        return len;
    }
    /*
     * for (int i = lenCurrent - 1; i >= 0; i--) {
                        int shiftIndex = i + offset;
                        if (shiftIndex >= lenCurrent) {
                            shiftIndex -= lenCurrent;
                        }
                        if (lenMax <= lenCurrent && current[shiftIndex] > max[i]) {
                            continue;
                        }
                    }
                    for (int i = lenCurrent - 1; i >= 0; i--) {
                        int shiftIndex = i + offset;
                        if (shiftIndex >= lenCurrent) {
                            shiftIndex -= lenCurrent;
                        }
                        if (lenMax <= lenCurrent && current[shiftIndex] > max[i]) {
                            continue;
                        }
                        if (current[shiftIndex] > current[i]) {
                            ok = true;
                            break;
                        } else if (current[shiftIndex] < current[i]) {
                            break;
                        }
                    }
                    if (ok) {
                        result++;
                    }
                    
                    for (int i = lenCurrent - 1; i >= 0; i--) {
                        int shiftIndex = i + offset;
                        if (shiftIndex >= lenCurrent) {
                            shiftIndex -= lenCurrent;
                        }
                        if (lenMax <= lenCurrent && current[shiftIndex] > max[i]) {
                            continue;
                        }
                    }
                    for (int i = lenCurrent - 1; i >= 0; i--) {
                        int shiftIndex = i + offset;
                        if (shiftIndex >= lenCurrent) {
                            shiftIndex -= lenCurrent;
                        }
                        if (lenMax <= lenCurrent && current[shiftIndex] > max[i]) {
                            continue;
                        }
                        if (current[shiftIndex] > current[i]) {
                            ok = true;
                            break;
                        } else if (current[shiftIndex] < current[i]) {
                            break;
                        }
                    }
                    if (ok) {
                        result++;
                    }
                    */
}
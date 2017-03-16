package CodeJam;

import com.sun.javafx.binding.StringFormatter;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.*;

/**
 * User: balder
 * Date: 4/11/15
 * Time: 9:53 PM
 * With Intellij IDEA for JavaTest
 */
public class Q3 {

    private static char[] IJK = {'i', 'j', 'k'};

    private Map<Character, Integer> charMap;

    private Map<Integer, Map<Integer, Integer>> quaternion;

    public Q3() {
        charMap = new HashMap<>();
        charMap.put('i', 2);
        charMap.put('j', 3);
        charMap.put('k', 4);

        quaternion = new HashMap<>();
        Map<Integer, Integer> tmp;

        // 1
        tmp = new HashMap<>();
        tmp.put(1, 1);
        tmp.put(2, 2);
        tmp.put(3, 3);
        tmp.put(4, 4);
        quaternion.put(1, tmp);

        // i
        tmp = new HashMap<>();
        tmp.put(1, 2);
        tmp.put(2, -1);
        tmp.put(3, 4);
        tmp.put(4, -3);
        quaternion.put(2, tmp);

        // j
        tmp = new HashMap<>();
        tmp.put(1, 3);
        tmp.put(2, -4);
        tmp.put(3, -1);
        tmp.put(4, 2);
        quaternion.put(3, tmp);

        // k
        tmp = new HashMap<>();
        tmp.put(1, 4);
        tmp.put(2, 3);
        tmp.put(3, -2);
        tmp.put(4, -1);
        quaternion.put(4, tmp);
    }

    public boolean check(String str, int target) {
        int carry = 1;
        int digit = 1;
        for (char c: str.toCharArray()) {
            int next = charMap.get(c);
            carry = quaternion.get(carry).get(next);
            if (carry < 0) {
                carry = -carry;
                digit = -digit;
            }
        }
        return carry == target && digit == 1;
    }


    public void solve() throws IOException {
        FileInputStream inputStream = new FileInputStream("Q3.txt");
        Scanner scanner = new Scanner(inputStream);

        FileOutputStream outputStream = new FileOutputStream("Q3_out.txt");

        int round = scanner.nextInt();
        for (int iter = 1; iter < round+1; iter++) {
            long L = scanner.nextLong();
            long X = scanner.nextLong();
//            System.out.format("%d %d", L, X);
            String str = scanner.next();
//            boolean result = this.solveRec(2, L, X, str, 0, 0);
            int carry = 1;
            int digit = 1;
            // index of L*X
            long j = 0;
            // mark of ijk
            int k = 2;
            // index of str
            int s = 0;
            // last pos of match J
            long lastJ = -1;
            long lastI = -1;
            // result
            boolean match = false;
            String tmp = "";
            for (int i = 0; i < X; i++) {
                tmp += str;
            }
//            str = tmp;
//            System.out.println(str.length());
//            System.out.println(L*X);
            while (true) {

                if (j == L*X) {
                    if (k == 5) {
                        if (carry == 1 && digit == 1) {
                            match = true;
                            break;
                        } else {
                            k = 4;
                        }
                    }
                    if (k == 4) {
                        k = 2;
                        j = lastJ;
                        if (j == L*X) {
                            break;
                        }
                        s = (int) (j%L);
                        carry = 4;
                        digit = 1;
                    } else {
                        break;
                    }
                } else if (j > L*X) {
                    System.out.println("Wrong");
                    break;
                }

                int next = charMap.get(str.charAt(s));
                carry = quaternion.get(carry).get(next);
                if (carry < 0) {
                    carry = -carry;
                    digit = -digit;
                }
                j += 1;
                s = (int) (j%L);

                // matches current, find next
                if (carry == k && digit == 1) {
                    if (k == 3) {
                        lastJ = j;
//                        if(!this.check(tmp.substring(0, (int) lastI),2)) {
//                            System.out.println("Not J");
//                        }
                    }
                    if (k == 2) {
                        lastI = j;
//                        if(!this.check(tmp.substring(0, (int) lastI),2)) {
//                            System.out.println("Not I");
//                        }
                    }
                    if (k == 4) {
//                        if(!this.check(tmp.substring((int) lastJ, (int)j),4)) {
//                            System.out.println("Not K");
//                        }
                    }
                    k += 1;
                    carry = 1;
                    digit = 1;
                }
            }
            if (match && lastI != -1 && lastJ != -1) {
                System.out.format("%d %d\n", lastI, lastJ);

                System.out.println(this.check(tmp.substring(0, (int) lastI),2));
//                if (!this.check(tmp.substring(0, (int) lastI),2)) {
//                    System.out.println(tmp.substring(0, (int) lastI));
//                }
                System.out.println(this.check(tmp.substring((int) lastI, (int) lastJ),3));
                System.out.println(this.check(tmp.substring((int) lastJ),4));
            }


            String ret = match ? "YES" : "NO";
            System.out.format("Case #%d: " + ret + "\n\n", iter);
            outputStream.write(StringFormatter.format("Case #%d: " + ret + "\n", iter).getValue().getBytes());
        }
        outputStream.close();
    }

    public static void main(String[] args) throws IOException {
        Q3 q3 = new Q3();
        q3.solve();
    }
}


import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class GettingDigits {

    static Scanner scanner = new Scanner(System.in);
    static PrintWriter writer;
    
    public static void run() throws FileNotFoundException, UnsupportedEncodingException {
        int T = scanner.nextInt();
        writer = new PrintWriter("output");
        for (int i = 0; i < T; i++) {
            Solution solution = new Solution();
            String output = solution.solve();
            out(i + 1, output);
        }
        writer.close();
    }
    
    static void out(int testcase, String result) {
        String output = "Case #" + testcase + ": " + result;
        System.out.println(output);
        writer.println(output);
    }
    
    static class Solution {
        static int[] D = new int[26];
        static int[] C = new int[10];
        
        public String solve() {
            String S = scanner.next();
            
            for (int i = 0; i < S.length(); i++) {
                char c = S.charAt(i);
                add(c, 1);
            }
            
            // ZERO
            C[0] = value('Z');
            remove('Z', C[0]);
            remove('E', C[0]);
            remove('R', C[0]);
            remove('O', C[0]);
            
            // TWO
            C[2] = value('W');
            remove('T', C[2]);
            remove('W', C[2]);
            remove('O', C[2]);
            
            // FOUR
            C[4] = value('U');
            remove('F', C[4]);
            remove('O', C[4]);
            remove('U', C[4]);
            remove('R', C[4]);
            
            // ONE
            C[1] = value('O');
            remove('O', C[1]);
            remove('N', C[1]);
            remove('E', C[1]);
            
            // SIX
            C[6] = value('X');
            remove('S', C[6]);
            remove('I', C[6]);
            remove('X', C[6]);
            
            // SEVEN
            C[7] = value('S');
            remove('S', C[7]);
            remove('E', C[7]);
            remove('V', C[7]);
            remove('E', C[7]);
            remove('N', C[7]);
            
            // FIVE
            C[5] = value('V');
            remove('F', C[5]);
            remove('I', C[5]);
            remove('V', C[5]);
            remove('E', C[5]);

            // EIGHT
            C[8] = value('G');
            remove('E', C[8]);
            remove('I', C[8]);
            remove('G', C[8]);
            remove('H', C[8]);
            remove('T', C[8]);
            
            // THREE
            C[3] = value('H');
            remove('T', C[3]);
            remove('H', C[3]);
            remove('R', C[3]);
            remove('E', C[3]);
            remove('E', C[3]);
            
            // NINE
            C[9] = value('I');
            remove('N', C[9]);
            remove('I', C[9]);
            remove('N', C[9]);
            remove('E', C[9]);
            
            StringBuilder number = new StringBuilder();
            
            for (int d : D) {
                if (d != 0) {
                    throw new AssertionError();
                }
            }
            
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < C[i]; j++) {
                    number.append((char) ('0' + i));
                }
            }
            
            return number.toString();
        }
        
        static int value(char c) {
            return D[c - 'A'];
        }
        
        static void add(char c, int n) {
            D[c - 'A'] += n;
        }
        
        static void remove(char c, int n) {
            D[c - 'A'] -= n;
        }
    }
}

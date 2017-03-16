
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

import java.math.*;
import java.io.*;
import java.text.*;
import java.util.*;

public class Google1C_c {
    
//    private static final String INPUT_PATH = "C:\\Users\\Yasu\\Downloads\\C-large.in";

  private static final String INPUT_PATH = "C:\\Users\\Yasu\\Downloads\\C-small-attempt0.in";

//    private static final String INPUT_PATH = "C:\\Users\\Yasu\\Downloads\\googleCodeJam\\q1_test.txt";
    
    private static final String OUTPUT_PATH = "C:\\Users\\Yasu\\Downloads\\googleCodeJam\\q1_test_out.txt";

    int N;

    List<String> qList;
    List<String> answerList = new ArrayList<String>();
    
    public static void main(String[] args) {
        Google1C_c app = new Google1C_c();
        
        app.solve();
    }

    static final String WON = "Fegla Won";
    
    public void solve() { 
        try {
            br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(INPUT_PATH))));
            N = readInt();
            for (int testCase = 0; testCase < N; testCase++) {

                //answerList.add(isF ? WON : String.valueOf(total));
            
            }
            writeFile(OUTPUT_PATH, answerList);
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                br.close();
            } catch (Exception igunore) {}
        }
    }
    
    private static final String FORMAT = "Case #{0}: {1}";

    public static void writeFile(String filePath, List<String> solve) {
        BufferedWriter bufferedWriter = null;
        try {
            bufferedWriter = new BufferedWriter(
                    new OutputStreamWriter(new FileOutputStream(new File (filePath))));

            for (int i = 0; i < solve.size(); i++) {
                
                Object[] ans = new Object[2];
                
                ans[0] = String.valueOf(i + 1);
                ans[1] = solve.get(i);
                String write = MessageFormat.format(FORMAT, ans);
                
                bufferedWriter.write(write);
                bufferedWriter.newLine();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                bufferedWriter.close();
            } catch (Exception igunore) {
                igunore.printStackTrace();
            }
        }
    }

    BufferedReader br = null;

    private int readInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    private long readLong() throws IOException {
        return Long.parseLong(br.readLine());
    }

    private int[] readIntArray() throws IOException {
        String[] s = readStrArray();
        int cnt = s.length;
        int[] out = new int[cnt];
        for (int i = 0; i < cnt; i++) {
            out[i] = Integer.parseInt(s[i]);
        }
        return out;
    }

    private Integer[] convIntArray(int[] arg) {
        int len = arg.length;
        Integer[] res = new Integer[len];
        for (int i = 0; i < len; i++) {
            res[i] = arg[i];
        }
        return res;
    }
    
    private long[] readLongArray() throws IOException {
        String[] s = readStrArray();
        int cnt = s.length;
        long[] out = new long[cnt];
        for (int i = 0; i < cnt; i++) {
            out[i] = Long.parseLong(s[i]);
        }
        return out;
    }

    private String[] readStrArray() throws IOException {
        String[] s = br.readLine().split(" ");
        return s;
    }

    void generate(int[] p, int L, int R) {
        if (L == R) { // all numbers are set
          // do something with permutation in array p[]
            System.out.println(deepToString(convIntArray(p)));
        } else { // numbers at positions [0, L-1] are set, try to set L-th position
          for (int i = L; i <= R; i++) {
            int tmp = p[L]; p[L] = p[i]; p[i] = tmp;
            generate(p, L+1, R);
            tmp = p[L]; p[L] = p[i]; p[i] = tmp;
          }
        }
     }

    /***
     * Å‘åŒö–ñ”‚ð‹‚ß‚éŠÖ”
     * @param n1
     * @param n2
     * @return
     */
    private static long gcd(long n1, long n2) {
        return (n2 == 0)?n1:gcd(n2, n1%n2);
    }
    private static int gcd(int n1, int n2) {
        return (n2 == 0)?n1:gcd(n2, n1%n2);
    }

}


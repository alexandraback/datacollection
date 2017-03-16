
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Technobabble {

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
        public String solve() {          
            int N = scanner.nextInt();
            
            Map<String, Integer> A = new HashMap<>();            
            Map<String, Integer> B = new HashMap<>();
            
            List<Word> words = new ArrayList<>();
                    
            for (int i = 0; i < N; i++) {
                Word w = new Word();
                w.a = scanner.next();
                w.b = scanner.next();
                
                increase(w.a, A);
                increase(w.b, B);
                
                words.add(w);
            }
            
            int fakes = 0;
            for (Word w : words) {
                if (A.get(w.a) > 1 && B.get(w.b) > 1) {
                    fakes++;
                    remove(w.a, A);
                    remove(w.b, B);
                }
            }
            
            return Integer.toString(fakes);
        }
        
        static void increase(String w, Map<String, Integer> O) {
            int n;
            if (O.containsKey(w)) {
                n = O.get(w) + 1;
            } else {
                n = 1;
            }
            
            O.put(w, n);
        }
        
        static void remove(String w, Map<String, Integer> O) {
            int n;
            if (O.containsKey(w)) {
                n = O.get(w) - 1;
            } else {
                throw new AssertionError();
            }
            
            O.put(w, n);
        }
    }
    
    static class Word {
        public String a;
        public String b;
    }
}

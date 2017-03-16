import java.io.File;
import java.util.HashMap;
import java.util.Scanner;

public class A {
    private static final HashMap<String, Integer> countCache = new HashMap<String, Integer>();
    public A() {}
    
    private void solve() {
        Scanner sc = new Scanner(System.in);
        
        try { 
            sc = new Scanner(new File("bin/input.txt"));
//            sc = new Scanner(new File("bin/A-small-attempt0 (2).in"));
        } catch(Exception e) {}
        
        int numCases = sc.nextInt();
        sc.nextLine();
        
        long s = System.currentTimeMillis();
        for(int i = 0; i < numCases; i++) {
            String word = sc.next();
            int n = sc.nextInt();
//            
//            StringBuffer sb = new StringBuffer(word);
//            for(int j = 0; j < 100; j++) {
//                sb.append(word);
//            }
//            word = sb.toString();
            
            System.out.println("Case #" + (i + 1) + ": " + solve(word, n));
            sc.nextLine();
        }
    }
    
    private static final int getMaxN(String w, int start, int end) {
        int maxCount = 0;
        int count = 0;
        
        for(int i = start; i <= end; i++) {
            char ch = w.charAt(i);
            if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                count++;
                if(count > maxCount) maxCount = count;
            } else{
                count = 0;
            }
        }
        return maxCount;
    }
    
//    public int solve(String word, int n) {
//        int wcount = 0;
//        for(int i = 0; i < word.length() - n + 1; i++) {
//            boolean exit = false;
//            
//            for(int j = word.length() - 1; j >= i + n - 1 && !exit; j--) {
//                if(getMaxN(word, i, j) >= n) {
//                    wcount++;
//                } else {
//                    exit = true;
//                }
//            }
//        }
//        
//        return wcount;
//    }

    public int solve(String word, int n) {
        int wcount = 0;
        int count = 0;
        int index = 0;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                if(count == 0) index = i;
                count++;
                if(count == n) {
                    int previous = index;
                    int next = word.length() - (index + count);
                    
                    if(previous < 0) previous = 0;
                    if(next < 0) next = 0;
                    
                    wcount += previous;
                    wcount += next;
                    wcount++;
                    
                    count = n - 1;
                    index++; 
                }
            } else{
                count = 0;
            }
        }
        return wcount;
    }

    public static void main(String[] args) {
        A a = new A();
        a.solve();
    }
}

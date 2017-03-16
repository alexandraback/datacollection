import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class A {
    public A() {}
    
    private void solve() {
        Scanner sc = new Scanner(System.in);
        
//        try { 
//            sc = new Scanner(new File("bin/input.txt"));
//        } catch(Exception e) {}
        
        int numCases = sc.nextInt();
        sc.nextLine();
        
        for(int i = 0; i < numCases; i++) {
            System.out.println("Case #" + (i + 1) + ": " + solve(sc.next(), sc.nextInt()));
            sc.nextLine();
        }
    }
    
    private int getMaxN(String w, int start, int end) {
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
    
    public int solve(String word, int n) {
        int count = 0;
        for(int i = 0; i < word.length() - n + 1; i++) {
            for(int j = word.length() - 1; j >= i + n - 1; j--) {
                if(getMaxN(word, i, j) >= n) {
                    count++;
                }
            }
        }
        return count;
    }
    
    public static void main(String[] args) {
        A a = new A();
        a.solve();
    }
}

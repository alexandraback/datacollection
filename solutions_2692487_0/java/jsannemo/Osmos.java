package gcj13.oneb;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Johan Sannemo
 */
public class Osmos {
    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("C:\\Users\\Johan Sannemo\\Downloads\\A-small-attempt2.in"));
        System.setOut(new PrintStream("C:\\Users\\Johan Sannemo\\Downloads\\a-small3.out"));
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 1; i<=t; ++i){
            System.out.print("Case #"+i+": ");
            solve(sc);
        }
    }
    
    
    public static void solve(Scanner sc){
        int a = sc.nextInt();
        int n = sc.nextInt();
        int[] sizes = new int[n];
        for (int i = 0; i < n; i++) {
            sizes[i] = sc.nextInt();
        }
        int best = n;
        int added = 0;
        Arrays.sort(sizes);
        for (int i = 0; i < sizes.length; i++) {
            int j = sizes[i];
            if(a > j){
                a += j;
                best = Math.min(best, sizes.length - i - 1 + added);
            } else if(a > 1) {
                best = Math.min(best, sizes.length - i + added);
                while(a <= j){
                    added ++;
                    a += (a - 1);
                }
                a += j;
                best = Math.min(best, sizes.length - i - 1 + added);
            }
        }
        System.out.println(best);
    }
}

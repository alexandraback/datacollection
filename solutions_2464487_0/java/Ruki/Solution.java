import java.io.PrintStream;
import java.util.Scanner;

public class Solution {


    public static long solve(long r, long t) {
        r++;
        long count = 0;
        long requiredPaint;
        while(true)  {
            requiredPaint = r*r - (r-1)*(r-1);
            if (requiredPaint > t) {
                break;
            } else {
                t -=  requiredPaint;
                r += 2;
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        //try { System.setIn(new java.io.FileInputStream("A-small-attempt0.in")); } catch (java.io.FileNotFoundException e) { }
        //try { System.setOut(new PrintStream("A-small-attempt0.out")); } catch (java.io.FileNotFoundException e) { }
        Scanner scanner = new Scanner(System.in);
        long r, t;
        int cases, c;

        cases = scanner.nextInt();
        for (c = 1; c <= cases; c++) {
            r = scanner.nextLong();
            t = scanner.nextLong();
            System.out.println("Case #" + String.valueOf(c) + ": " + String.valueOf(solve(r, t)));
        };

    }
}

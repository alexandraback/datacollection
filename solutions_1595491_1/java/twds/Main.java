import java.io.FileInputStream;
import java.util.*;
import java.math.*;

public class Main {
    
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        //Scanner scan  = new Scanner(new FileInputStream("C:\\Users\\wd\\Desktop\\"));
        char[] map = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();
        int taskCount = scan.nextInt();
        scan.nextLine();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            int N = scan.nextInt();
            int S = scan.nextInt();
            int p = scan.nextInt();
            int result = 0;
            for (int i = 0; i < N; i++) {
                int val = scan.nextInt();
                if (val < 3 * p - 4) {
                    continue;
                }
                else if (val >= 3 * p - 2) {
                    result++;
                }
                else if (val >= p) {
                    if (S > 0) {
                        result++;
                        S--;
                    }
                }
            }
            System.out.println("Case #" + taskIndex + ": " + result);
        }
    }
}
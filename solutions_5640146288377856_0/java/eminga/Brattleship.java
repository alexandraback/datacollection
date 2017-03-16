import java.util.Scanner;

public class Brattleship {
    
    public static void main(String[] args) {  
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            int r = s.nextInt();
            int c = s.nextInt();
            int w = s.nextInt();
            int result = (c - w) / w;
            if ((c - w) % w != 0) {
                result++;                
            }
            result += w;
            result *= r;
            System.out.println("Case #" + i + ": " + result);
        }
    }
    
}

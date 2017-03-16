import java.util.Scanner;

public class MainA {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            long r = sc.nextLong();
            long t1 = sc.nextLong();
            long output = 0;
            for (long x = r; t1 > 0; x += 2) {
                t1 -= 1 + 2 * x;
                if(t1>=0){
                    output++;
                }
            }
            System.out.println("Case #" + t + ": " + output);
        }
    }
}

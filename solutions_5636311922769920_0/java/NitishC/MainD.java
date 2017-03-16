import java.util.Scanner;

public class MainD {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String output="";
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            int K = sc.nextInt();
            sc.nextInt();
            sc.nextInt();
            System.out.print("Case #" + t + ":");
            for(int i=1; i<=K; i++) {
                System.out.print(" " + i);
            }
            System.out.println();
        }
    }
}

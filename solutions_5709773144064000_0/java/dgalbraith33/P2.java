import java.util.Scanner;

public class P2 {
    public static Scanner stdin = new Scanner(System.in);

    public static void main(String[] args) {
        int numCases = Integer.parseInt(stdin.nextLine());

        for(int i = 1; i <= numCases; i++) {
            double result = execute();
            System.out.printf("Case #%d: %.7f\n",i,result);
        }
    }

    public static double execute() {
        double c = stdin.nextDouble();
        double f = stdin.nextDouble();
        double x = stdin.nextDouble();
        return getTime(c,f,x,2.0);
    }

    public static double getTime(double c, double f, double x, double r) {
        double tc1 = c / r;
        double tx1 = x / r;
        double tc2 = c / (r+f);
        double tx2 = x / (r+f);

        if (tx1 - tc1 < tx2) {
            return tx1;
        }

        return tc1 + getTime(c,f,x,r+f);
    }
}
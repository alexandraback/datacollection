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
        double time = 0;
        double rate = r;
        
        while (true) {
            double tc1 = c / rate;
            double tx1 = x / rate;
            double tx2 = x / (rate + f);
            
            if (tx1 - tc1 < tx2) {
                return time + tx1;
            }

            time += tc1;
            rate += f;

        }
    }
}
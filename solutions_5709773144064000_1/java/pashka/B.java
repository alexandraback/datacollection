
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        double c = in.nextDouble();
        double f = in.nextDouble();
        double x = in.nextDouble();
        double speed = 2;
        double time = 0;
        double best = x / 2;
        while (true) {
            time += c / speed;
            speed += f;
            best = Math.min(best, time + x / speed);
            if (time > best) break;
        }
        return "" + best;
    }
}
import java.io.*;
import java.util.*;
import java.math.*;

public class D {
    public static void main(String[] args) { 
        PrintWriter out = new PrintWriter(System.out);

        Application application = new Application();
        application.solve(System.in, out);

        out.close();
    }
}


class Application {
    public String check(int X, int R, int C) {
        if (X == 1) return "GABRIEL";
        if (X >= 7) return "RICHARD";

        if ((R*C) % X != 0) { return "RICHARD"; }

        if (X == 2) {
            return "GABRIEL";
        }
        if (X == 3) {
            if (R == 1 || C == 1) { return "RICHARD"; }
            return "GABRIEL";
        }
        if (X == 4) {
            if (R <= 2 || C <= 2) { return "RICHARD"; }
            return "GABRIEL";
        }
        return "GABRIEL";
    }
    public void solve(InputStream in, PrintWriter out) {
        Scanner scanner = new Scanner(in);

        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            int X = scanner.nextInt();
            int R = scanner.nextInt();
            int C = scanner.nextInt();

            System.out.println("Case #" + t + ": " + (check(X, R, C)));
        }
    }
}

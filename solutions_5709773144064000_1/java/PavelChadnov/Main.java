import java.io.*;
import java.util.*;

public class Main {

    static double solve(double c, double f, double x) {
        double res = 0;
        double rate = 2;
        for (; ; ) {
            double timeToFarm = c / rate;
            if (timeToFarm + x/(rate+f) < x / rate) {
                rate += f;
                res += timeToFarm;
            } else {
                break;
            }
        }
        res += x/rate;
        return res;
    }

    public static void main(String[] args) throws Exception {
        String name = "B-large";
        String path = "";

        Locale.setDefault(Locale.US);

        PrintWriter out = new PrintWriter(path + name + ".out");
        Scanner in = new Scanner(new File(path + name + ".in"));
//		Scanner in = new Scanner(new File("input.txt"));
//		PrintWriter out = new PrintWriter(System.out);
        int testCases = in.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
//            System.out.println(solve(in.nextDouble(), in.nextDouble(), in.nextDouble()));
            out.println(String.format("Case #%d: %.8f", testCase, solve(in.nextDouble(), in.nextDouble(), in.nextDouble())));
        }

        out.close();
        in.close();
    }
}
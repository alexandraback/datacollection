import java.io.*;

public class CodeJam2014Q2 {
    public static void main(String[] args) {
        try {
//            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-small.in")));
//            PrintWriter pw = new PrintWriter(new FileOutputStream("B-small.out"));
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-large.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("B-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                double C = Double.parseDouble(values[0]);
                double F = Double.parseDouble(values[1]);
                double X = Double.parseDouble(values[2]);

                double result = solve(C, F, X);

                pw.println("Case #" + (i + 1) + ": " + result);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static double solve(double C, double F, double X) {

        int k = 0;
        double wasted = 0;
        double min = Double.MAX_VALUE;
        double result = -1;

        while (result <= min) {
            result = wasted + X / (2 + F * k);
            wasted += C / (2 + F * k);
            if (result < min) {
                min = result;
            }
            k++;
        }

        return min;

    }
}

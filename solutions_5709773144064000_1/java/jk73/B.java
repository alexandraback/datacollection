import java.io.BufferedReader;
import java.nio.file.Files;
import java.nio.file.Paths;

public class B {

    public static void main(String[] args) throws Throwable {
        try (BufferedReader reader = Files.newBufferedReader(Paths.get("/Users/jk/B.in"))) {
            int numCases = Integer.parseInt(reader.readLine());

            for (int c = 1; c <= numCases; c++) {
                String[] split = reader.readLine().split(" ");
                solve(c, Double.parseDouble(split[0]), Double.parseDouble(split[1]), Double.parseDouble(split[2]));
            }
        }
    }

    private static void solve(int caseNum, double c, double f, double x) {
        double cookiesPerSecond = 2.0;

        double timeToX = x / cookiesPerSecond;
        double timeToC = c / cookiesPerSecond;

        while (timeToC < timeToX) {
            cookiesPerSecond += f;
            double timeToX2 = timeToC + x / cookiesPerSecond;
            if (timeToX2 > timeToX) {
                break;
            }
            timeToX = timeToX2;
            timeToC = timeToC + c / cookiesPerSecond;
        }
        System.out.format("Case #%d: %.7f%n", caseNum, timeToX);

    }
}
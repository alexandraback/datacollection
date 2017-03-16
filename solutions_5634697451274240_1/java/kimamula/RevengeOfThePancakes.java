import java.io.*;

public class RevengeOfThePancakes {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bi.readLine());
        final char minusChar = "-".charAt(0);

        for (int i = 1; i <= t; i++) {
            int boundaryCount = 0;
            char[] input = bi.readLine().toCharArray();
            int length = input.length;
            char latest = input[0];
            for (int pos = 1; pos < length; pos ++) {
                char current = input[pos];
                if (latest != current) {
                    latest = current;
                    boundaryCount += 1;
                }
            }
            int result = boundaryCount;
            if (latest == minusChar) {
                result += 1;
            }
            out.println("Case #" + i + ": " + result);
        }
        out.close();
    }
}

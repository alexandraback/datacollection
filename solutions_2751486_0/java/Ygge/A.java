import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class A {

    private static final String FILE_NAME = "A-small-attempt1";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] row = in.readLine().split(" ");
            String name = row[0];
            int len = Integer.parseInt(row[1]);

            List<Integer> vPos = new ArrayList<Integer>();
            for (int i = 0; i < name.length(); ++i) {
                char cc = name.charAt(i);
                if (cc == 'a' || cc == 'e' || cc == 'i' || cc == 'o' || cc == 'u') {
                    vPos.add(i);
                }
            }

            long count = 0;
            int currentPos = 0;
            int last = -1;
            for (int i = 0; i <= name.length()-len; ++i) {
                while (currentPos < vPos.size() && vPos.get(currentPos) < i) {
                    ++currentPos;
                }
                int nextVowelPos = currentPos < vPos.size() ? vPos.get(currentPos) : -1;
                if (nextVowelPos == -1 || nextVowelPos-i >= len) {
                    long start = i-last;
                    long end = name.length()-len-i+1;
                    count += start*end;
                    last = i;
                }
            }
            write(out, String.format("Case #%d: %d", c, count));
        }
        out.close();
    }

    private static void write(BufferedWriter out, String message) throws IOException {
        out.write(message);
        out.write("\n");
        System.out.println(message);
    }
}

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
    private static final String inFile = "C-small-1-attempt3.in";
    private static final String outFile = "C-out.txt";

    static class H {
        public int pos;
        public int time;

        public H(int pos, int time) {
            this.pos = pos;
            this.time = time;
        }

    }
    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);

        for (int t = 1; t <= T; ++t) {
            int n = scanner.nextInt();
            List<H> hikers = new ArrayList<H>();
            for (int i = 0; i < n; ++i) {
                int pos = scanner.nextInt();
                int cnt = scanner.nextInt();
                int time = scanner.nextInt();
                for (int j = 0; j < cnt; ++j) {
                    hikers.add(new H(pos, time + j));
                }
            }
            fw.write(String.format("Case #%d: %s\n", t, solve(hikers)));
        }
        fw.close();
    }

    static int solve(List<H> hikers) {
        if (hikers.size() < 2) {
            return 0;
        }
        H h1 = hikers.get(0);
        H h2 = hikers.get(1);
        if (h1.pos > h2.pos) {
            H t = h1;
            h1 = h2;
            h2 = t;
        }
        if ((720L - h2.pos)*h2.time <= (360L - h1.pos) * h1.time) return 1;
        return 0;
    }
}

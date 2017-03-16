import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Technobabble {
    public static void main(String[] args) throws FileNotFoundException {
        final Scanner reader = new Scanner(new File(args[0] + ".in"));
        final PrintWriter writer = new PrintWriter(new File(args[0] + ".out"));
        final int testsCount = reader.nextInt();
        for (int test = 0; test < testsCount; ++test) {
            final int topics = reader.nextInt();
            String[][] words = new String[topics][2];
            for (int i = 0; i < topics; ++i) {
                words[i][0] = reader.next();
                words[i][1] = reader.next();
            }
            int res = 0;
            for (int fakeSet = 0; fakeSet < (1 << topics); ++fakeSet) {
                Set<String> firsts = new HashSet<>();
                Set<String> seconds = new HashSet<>();
                for (int i = 0; i < topics; ++i) if ((fakeSet & (1 << i)) == 0) {
                    firsts.add(words[i][0]);
                    seconds.add(words[i][1]);
                }
                boolean ok = true;
                int bitcount = 0;
                for (int i = 0; i < topics; ++i) if ((fakeSet & (1 << i)) > 0) {
                    bitcount++;
                    if (firsts.contains(words[i][0]) && seconds.contains(words[i][1])) {
                        // ok
                    } else {
                        ok = false;
                    }
                }
                if (ok) res = Math.max(res, bitcount);
            }
            writer.write(String.format("Case #%d: %d\n", test + 1, res));
        }
        writer.close();
        reader.close();
    }
}

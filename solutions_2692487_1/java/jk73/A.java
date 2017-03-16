import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Collections;
import java.util.LinkedList;

public class A {

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = Files.newBufferedReader(Paths.get("A-large.in"), Charset.forName("UTF-8"));
             PrintWriter out = new PrintWriter(Files.newBufferedWriter(Paths.get("A-large.out"), Charset.forName("UTF-8")))) {
             //PrintWriter out = new PrintWriter(System.out)) {
            int numCases = Integer.parseInt(reader.readLine());

            for (int i = 0; i < numCases; i++) {
                String[] split = reader.readLine().split(" ");
                long size = Long.parseLong(split[0]);
                int n = Integer.parseInt(split[1]);
                LinkedList<Long> motes = new LinkedList<>();
                for (String s : reader.readLine().split(" ")) {
                    motes.add(Long.parseLong(s));
                }
                if (n != motes.size()) {
                    System.err.println("xxx");
                }
                Collections.sort(motes);
                if (n != motes.size()) {
                    System.err.println("xxx");
                }
                int x = 0;
                int y = -1;
                System.out.println(motes);
                while (!motes.isEmpty()) {
                    long m = motes.getFirst();
                    if (m < size) {
                        motes.removeFirst();
                        size += m;
                    } else {
                        x++;
                        size <<= 1;
                        size--;
                        if (y != -1 && x > y) {
                            x = y;
                            break;
                        }
                        if (y == -1) {
                            y = x + motes.size() - 1;
                        } else if (y > x + motes.size() - 1) {
                            y = x + motes.size() - 1;
                        }
                    }
                }
                out.println("Case #" + (i + 1) + ": " + x);
            }
        }
    }
}

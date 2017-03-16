import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.Set;

public class A {

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = Files.newBufferedReader(Paths.get("A-small.in"), Charset.forName("UTF-8"));
             PrintWriter out = new PrintWriter(Files.newBufferedWriter(Paths.get("A-small.out"), Charset.forName("UTF-8")))) {
             //PrintWriter out = new PrintWriter(System.out)) {
            int numCases = Integer.parseInt(reader.readLine());

            for (int i = 0; i < numCases; i++) {
                String[] split = reader.readLine().split(" ");

                String name = split[0];
                int n = Integer.parseInt(split[1]);

                int x = handle(name, n);
                out.println("Case #" + (i + 1) + ": " + x);
            }
        }
    }

    private static int handle(String name, int n) {
        byte[] bytes = name.getBytes();
        int len = bytes.length;

        Set<Range> ranges = new HashSet<>();

        int lastCons = -1;
        for (int i = 0; i < len; i++) {
            if (bytes[i] == 'a' || bytes[i] == 'e' || bytes[i] == 'i' || bytes[i] == 'o' || bytes[i] == 'u') {
                if (lastCons >= 0) {
                    if (i - lastCons >= n) {
                        for (int j = lastCons; i - j >= n; j++) {
                            ranges.add(new Range(j, i));
                        }
                    }
                    lastCons = -1;
                }
            } else {
                if (lastCons == -1) {
                    lastCons = i;
                    if (n == 1) {
                        ranges.add(new Range(i, i + 1));
                    }
                } else if (i + 1 - lastCons >= n) {
                    for (int j = lastCons; i + 1 - j >= n; j++) {
                        ranges.add(new Range(j, i + 1));
                    }
                }
            }
        }

        Set<Range> finalset = new HashSet<>();

        for (Range r : ranges) {
            for (int i = 0; i <= r.start; i++) {
                for (int j = r.end; j < len + 1; j++) {
                    finalset.add(new Range(i, j));
                }
            }
        }
        return finalset.size();
    }

    static class Range {
        int start;
        int end;

        public Range(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + end;
            result = prime * result + start;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            Range other = (Range) obj;
            if (end != other.end) {
                return false;
            }
            if (start != other.start) {
                return false;
            }
            return true;
        }
    }
}

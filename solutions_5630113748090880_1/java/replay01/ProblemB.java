
import java.io.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class ProblemB {

    private static final String INPUT = "B-large.in";

    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(ProblemA.class.getResourceAsStream(INPUT)));
                FileWriter out = new FileWriter(INPUT.replaceAll("\\.in$", ".out"))) {

            int t = Integer.parseInt(in.readLine());
            for (int i = 1; i <= t; i++) {
                int n = Integer.parseInt(in.readLine());
                int papers = (2 * n) - 1;
                Map<String, Integer> counts = new HashMap<>();
                for (int j = 0; j < papers; j++) {
                    for (String s : in.readLine().split(" ")) {
                        if (counts.containsKey(s)) {
                            counts.put(s, counts.get(s) + 1);
                        } else {
                            counts.put(s, 1);
                        }
                    }
                }

                List<Integer> missing = new LinkedList<>();
                Set<Map.Entry<String, Integer>> entrySet = counts.entrySet();
                for (Map.Entry<String, Integer> entry : entrySet) {
                    if (entry.getValue() % 2 != 0) {
                        missing.add(Integer.parseInt(entry.getKey()));
                    }
                }

                Collections.sort(missing);
                StringBuilder buf = new StringBuilder();
                for (Integer val : missing) {
                    buf.append(val).append(" ");
                }

                out.write("Case #" + i + ": " + buf.toString().trim());
                if (i != t) {
                    out.write("\n");
                }
            }
        }
    }
}

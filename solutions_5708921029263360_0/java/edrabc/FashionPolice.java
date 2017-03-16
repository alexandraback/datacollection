import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class FashionPolice {

    public void go(String file) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(file));
        int T = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= T; i++) {
            String[] parts = reader.readLine().split(" ");
            int J = Integer.parseInt(parts[0]);
            int P = Integer.parseInt(parts[1]);
            int S = Integer.parseInt(parts[2]);
            int K = Integer.parseInt(parts[3]);

            Set<String> result = solve(J, P, S, K);
            System.out.println("Case #" + i + ": " + result.size());
            for (String string : result) {
                System.out.println(string);
            }
        }
    }

    private Set<String> solve(int J, int P, int S, int K) {
        Map<String, Integer> visited = new HashMap<String, Integer>();
        Set<String> fits = new HashSet<String>();
        for (int i = 1; i <= J; i++) {
            for (int j = 1; j <= P; j++) {
                for (int k = 1; k <= S; k++) {
                    String k1 = "J" + i + "P" + j;
                    String k2 = "J" + i + "S" + k;
                    String k3 = "P" + j + "S" + k;
                    int c1 = (visited.containsKey(k1)) ? visited.get(k1) : 0;
                    int c2 = (visited.containsKey(k2)) ? visited.get(k2) : 0;
                    int c3 = (visited.containsKey(k3)) ? visited.get(k3) : 0;
                    if (c1 < K && c2 < K && c3 < K) {
                        fits.add(i + " " + j + " " + k);
                        visited.put(k1, ++c1);
                        visited.put(k2, ++c2);
                        visited.put(k3, ++c3);
                    }
                }
            }
        }
        return fits;
    }

    public static void main(String[] args) throws Exception {
        new FashionPolice().go(args[0]);
    }
}

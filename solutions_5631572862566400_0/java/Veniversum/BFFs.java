import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.*;

public class BFFs {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileReader("smallC.in"));
        PrintStream out = new PrintStream(new FileOutputStream("C.out"));
        int T = scanner.nextInt();
        scanner.nextLine();
        for (int t = 1; t <= T; t++) {
            int N = scanner.nextInt();
            HashMap<Integer,Integer> bff = new HashMap<>();
            HashMap<Integer,ArrayList<Integer>> rev = new HashMap<>();
            for (int i = 1; i <= N; i++) {
                int to = scanner.nextInt();
                bff.put(i, to);
                ArrayList<Integer> l = rev.compute(to, (k,v) -> v==null?new ArrayList<>() : v);
                l.add(i);
            }
            HashMap<Integer, ArrayList<Integer>> cycles = new HashMap<>();
            for (int i = 1; i <= N; i++) {
                ArrayList<Integer> cycle = new ArrayList<>();
                int cur = i;
                int n = 0;
                while (n < N) {
                    if (!cycle.contains(cur)) {
                        cycle.add(cur);
                        cur = bff.get(cur);
                        n++;
                    } else {
                        break;
                    }
                }
                if (n != N || cur == i){
                    cycles.put(i,cycle);
                }
            }
            int max = 0;
            for (Map.Entry e: cycles.entrySet()) {
                ArrayList<Integer> cycle = (ArrayList<Integer>) e.getValue();
                if (bff.get(cycle.get(cycle.size() - 1)) == cycle.get(cycle.size() - 2)){
                    int last = cycle.get(cycle.size() - 1);
                    for (int i : rev.get(last)) {
                        int cur = i;
                        int n = cycle.size();
                        while (!cycle.contains(cur)) {
                            n++;
                            cur = bff.get(cur);
                        }
                        max = Math.max(max, n);
                    }
                } else {
                    max = Math.max(max, cycle.size());
                }
            }

            out.println("Case #" + t + ": " + max);
        }
    }
}

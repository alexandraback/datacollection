import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class BC {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer cases = in.nextInt();
        for (Integer i = 0; i < cases; i ++) {
            Integer N = in.nextInt();
            in.nextLine();
            List<String> lines = new ArrayList<>();
            for (int k = 0; k < N; k++) {
                lines.add(in.nextLine());
            }
            List<String> best = new ArrayList<>();
            for (int len = 0; len < N; len++) {
                int bestCase = 0;
                List<String> cBest = new ArrayList<>();
                for (int insert = 0; insert <= best.size(); insert++) {
                    List<String> tmp = new ArrayList<>();
                    tmp.addAll(best);
                    tmp.add(insert, lines.get(len));
                    int tmpCase = worstCase(tmp, false);
                    if (tmpCase >= bestCase) {
                        cBest = tmp;
                        bestCase = tmpCase;
                    }
                }
                best = cBest;
            }
            System.out.println("Case #" + (i + 1) + ": " + worstCase(best, false));
        }
    }

    private static int worstCase(List<String> lines, Boolean print) {
        HashMap<String, Integer> first = new HashMap<>();
        HashMap<String, Integer> second = new HashMap<>();
        int sum = 0;
        for (int k = 0; k < lines.size(); k++) {
            String[] parts = lines.get(k).split(" ");
            if (first.containsKey(parts[0]) && second.containsKey(parts[1])) {
                if (print) {
                    System.out.println(parts[0] + " " + parts[1]);
                }
                sum++;
            }
            first.put(parts[0], first.containsKey(parts[0]) ? first.get(parts[0]) + 1: 1);
            second.put(parts[1], second.containsKey(parts[0]) ? second.get(parts[0]) + 1 : 1);
        }
        return sum;
    }
}

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class BFF {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("/home/mbroshi/Downloads/C-small-attempt0.in"));
        int numCases = sc.nextInt();
        StringBuffer output = new StringBuffer();
        for (int i = 1; i <= numCases; i++) {
            int numKids = sc.nextInt();
            int[] bff = new int[numKids + 1];
            boolean[] visited = new boolean[numKids + 1];
            for (int j = 1; j <= numKids; j++) {
                bff[j] = sc.nextInt();
            }
            int longest = 0;
            for (int j = 1; j <= numKids; j++) {
                if (visited[j]) {
                    continue;
                }
                Set<Integer> currentRun = new HashSet<>();
                int current = j;
                int next = bff[j];
                currentRun.add(current);
                visited[current] = true;
                while (!currentRun.contains(next)) {
                    currentRun.add(next);
                    visited[next] = true;
                    current = next;
                    next = bff[current];
                }

                // current is now "end" of cycle
                // next is now beginning of cycle

                int cycleLength = 1;
                while (current != next) {
                    next = bff[next];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    cycleLength = currentRun.size();
                    for (int k = 1; k <= numKids; k++) {
                        if (bff[k] == current && k != bff[current]) {
                            cycleLength++;
                            break;
                        }
                    }
                }
                if (longest < cycleLength) {
                    longest = cycleLength;
                }
            }

            output.append(String.format("Case #%d: %d\n", i, longest));
        }
        System.out.println(output);
        FileWriter fw = new FileWriter(new File("/home/mbroshi/Downloads/C-small.out"));
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write(output.toString());
        bw.close();
    }
}

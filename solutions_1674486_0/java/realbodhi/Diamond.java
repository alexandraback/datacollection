import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Diamond {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                System.out.println("Case #" + (i + 1) + ": " + find(br));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String find(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        ArrayList nodes[] = new ArrayList[n+1];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new ArrayList();
        }
        ArrayList<Integer> z = new ArrayList<Integer>();
        for(int i = 1; i <= n; i++) {
            String[] s = br.readLine().split(" ");
            int e = Integer.parseInt(s[0]);
            if (e == 0) z.add(i);
            for (int j = 1; j < s.length; j++) {
                nodes[Integer.parseInt(s[j])].add(i);
            }
        }
        int[] cnts = new int[n+1];
        for (Integer i : z) {
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(i);

            while (!q.isEmpty()) {
                int t = q.poll();
                for (Iterator iterator = nodes[t].iterator(); iterator.hasNext(); ) {
                    int s = (Integer) iterator.next();
                    cnts[s]++;
                    if (cnts[s] > 1) return "Yes";
                    q.add(s);
                }
            }
            Arrays.fill(cnts, 0);
        }
        return "No";
    }
}

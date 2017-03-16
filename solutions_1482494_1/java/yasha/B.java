import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class B {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("b.in")));
        PrintStream out = new PrintStream(new FileOutputStream("b.out"));
        long n = readInt(in);
        for (int i = 0; i < n; i++) {            
            int k = (int)readInt(in);
            String ans = "Too Bad";
            final int[][] d = new int[k][3];
            List<int[]> targets = new ArrayList<int[]>();
            List<Integer> ns = new ArrayList<Integer>();
            for (int j = 0; j < d.length; j++) {
                String[] s1 = in.readLine().split(" ");
                d[j][0] = Integer.parseInt(s1[0]);
                d[j][1] = Integer.parseInt(s1[1]);
                targets.add(new int[]{j, d[j][0], 1});
                targets.add(new int[]{j, d[j][1], 2});
                ns.add(d[j][0]);
                ns.add(d[j][1]);
            }

            Collections.sort(ns);
            boolean tooBad = false;
            for (int j = 0; j < ns.size(); j++) {
                Integer v = ns.get(j);
                if (v > j) {
                    tooBad = true;
                    break;
                }

            }

            if (!tooBad) {
                Collections.sort(targets, new Comparator<int[]>() {
                    @Override
                    public int compare(int[] o1, int[] o2) {
                        int d2 = o1[2] - o2[2];
                        if (d2 != 0)
                            return -d2;
                        return -d[o1[0]][1] + d[o2[0]][1];
                    }
                });

                int cur = 0;
                int s = 0;
                while (!targets.isEmpty()) {
                    for (Iterator<int[]> iterator = targets.iterator(); iterator.hasNext(); ) {
                        int[] next = iterator.next();
                        int pos = next[0];
                        if(d[pos][2] == 2) {
                            iterator.remove();
                            continue;
                        }
                        int req = next[1];
                        int level = next[2];
                        if (req <= s) {
                            cur++;
                            s += level - d[pos][2];
                            d[pos][2] = level;
                            iterator.remove();
                            break;
                        }
                    }
                }
                ans = "" + cur;
            }

            out.print("Case #" + (i + 1) + ": ");
            out.print(ans);
            out.println();
        }
        out.flush();
        out.close();

    }

    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }    
}

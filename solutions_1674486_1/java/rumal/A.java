package Round_1C_2012;

import Round_1B_2012.*;
import Round_1A_2012.*;
import Round_1A_2011.*;
import java.util.*;
import java.io.*;
import java.math.*;
import java.text.DecimalFormat;

public class A {

    public static void main(String[] args) throws Exception {
        String file = ".\\Files\\A-";
        if (true) {
            file += "small";
        } else {
            file += "large";
        }
        //file += "-attempt";
        //BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(file + ".in")));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(file + ".out")));
        StringTokenizer st;
        DecimalFormat twoDForm = new DecimalFormat("0.000000");
        int T = Integer.parseInt(in.readLine());
        for (int t = 1; t < T + 1; t++) {
            String testans = "";
            int N = Integer.parseInt(in.readLine());
            LinkedList<Integer>[] adj = new LinkedList[N + 1];
            for (int i = 1; i <= N; i++) {
                st = new StringTokenizer(in.readLine());
                adj[i] = new LinkedList<Integer>();
                int pp = Integer.parseInt(st.nextToken());
                for (int j = 0; j < pp; j++) {
                    adj[i].add(Integer.parseInt(st.nextToken()));
                }
            }
            //Arrays.sort(adj);
            TreeSet<Integer> visited = new TreeSet<Integer>();
            boolean s = false;
            l:
            for (int i = 1; i <= N; i++) {
                visited.clear();
                LinkedList<Integer> q = new LinkedList<Integer>();
                q.add(i);
                //visited.add(i);
                while (!q.isEmpty()) {
                    int y = q.poll();
                    if (visited.contains(y)) {
                        s = true;
                        break l;
                    }
                    visited.add(y);
                    for (int j : adj[y]) {
                        if (visited.contains(j)) {
                            s = true;
                            break l;
                        } else {
                            q.add(j);
                        }
                    }
//                    System.out.println(visited);
//                    System.out.println(q);
//                    System.out.println("");
                }
            }
            if (s) {
                testans = "Yes";
            } else {
                testans = "No";
            }
            out.append("\nCase #" + (t) + ": " + testans);

            System.out.println("Case #" + (t) + ": " + testans);
        }
        out.close();
    }
}

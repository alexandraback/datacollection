import java.util.*;
import java.io.*;

public class DiamondInheritance {

    class Testcase {
        String ans = "No";

        public Testcase() {
        }

        public Testcase(int seed) {
            Random rnd = new Random(seed);
        }

        boolean[][] graph;
        boolean[] visited;
        int N;
        List<Integer> parents = new LinkedList<Integer>();

        public void loadInput(Scanner sc) {
            N = sc.nextInt();
            graph = new boolean[N + 1][N + 1];
            visited = new boolean[N + 1];
            for (int i = 1; i <= N; i++) {
                int n1 = sc.nextInt();
                for (int j = 1; j <= n1; j++) {
                    int next = sc.nextInt();
                    graph[next][i] = true;
                 //   System.out.println(next + " is a super class of " + i);
                }
                if (n1 == 0) parents.add(i);
            }
        }

        public void solveSlow() {
        }

        public void solveFast() {
            for (int parent: parents) {
                Queue<Integer> q = new LinkedList<Integer>();
                Arrays.fill(visited, false);
                q.add(parent);
                visited[parent] = true;
                while(!q.isEmpty()) {
                    int curr = q.poll();
                   // System.out.println("retrieving " + curr);
                    for (int i = 1; i <= N; i++) {
                        if (graph[curr][i]) {
                            if (!visited[i]) {
                                visited[i] = true;
                                q.add(i);
                            } else {
                                ans = "Yes";
                                return;
                            }
                        }

                    }
                }
            }

        }

        public void printSelf(PrintWriter pw) {
            pw.println(ans);
        }

        public boolean sameAnswers(Testcase other) {
            return false;
        }
    }

    final String AFTER_CASE = " ";

    public void go() throws Exception {

        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("solving case " + caseNum);

            Testcase tc = new Testcase();

            tc.loadInput(sc);
            tc.solveFast();

            pw.print("Case #" + (caseNum + 1) + ":");
            pw.print(AFTER_CASE);

            tc.printSelf(pw);
        }

        pw.flush();
        pw.close();
        sc.close();
    }

    public void stresstest() {
        int it = 0;
        Random rnd = new Random();
        while (true) {
            it++;
            if (it % 1000 == 0)
                System.out.println(it + " iterations");

            int seed = rnd.nextInt();

            Testcase tc1 = new Testcase(seed);
            tc1.solveFast();

            Testcase tc2 = new Testcase(seed);
            tc2.solveSlow();

            if (!tc1.sameAnswers(tc2)) {
                System.out.println("ERROR: it failed");
                System.exit(0);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        new DiamondInheritance().go();
    }
}


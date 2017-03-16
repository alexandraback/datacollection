package gcj1c.task3;

import java.io.*;
import java.net.URL;
import java.util.*;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "C-small-attempt2.in";

        URL inFileUrl = TaskX.class.getResource(inFile);
        InputStream inputStream = new BufferedInputStream(new FileInputStream(inFileUrl.getFile()));
        Scanner in = new Scanner(inputStream);

        String outFile = inFile + ".out";
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)));

        System.err.printf("Class = [%s]\n", TaskX.class);
        System.err.printf("Input File = [%s]\n", inFileUrl);
        System.err.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.err.println("------------------");
            System.err.println("test " + (i+1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.err.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            int J = in.nextInt();
            int P = in.nextInt();
            int S = in.nextInt();
            int K = in.nextInt();

            Map<String, Integer> m = new HashMap<>();

            List<String> cs = new ArrayList<>();

            for (int j = 0; j < J; j++) {
                for (int p = j+1; p < P; p++) {
                    for (int s = p+1; s < S; s++) {

                        String c = "" + (j+1) + " " + (p+1) + " " + (s+1);

                        String combi1 = j + "_JJ_" + p;
                        String combi2 = j + "_PP_" + s;
                        String combi3 = p + "_SS_" + s;

                        if (!m.containsKey(combi1)) {
                            m.put(combi1, 0);
                        }
                        if (!m.containsKey(combi2)) {
                            m.put(combi2, 0);
                        }
                        if (!m.containsKey(combi3)) {
                            m.put(combi3, 0);
                        }

                        if (m.get(combi1) + 1 <= K && m.get(combi2) + 1 <= K && m.get(combi3) + 1 <= K) {
                            cs.add(c);
                            m.put(combi1, m.get(combi1)+1);
                            m.put(combi2, m.get(combi2)+1);
                            m.put(combi3, m.get(combi3)+1);
                        }
                    }
                }
            }

            for (int j = 0; j < J; j++) {
                for (int p = 0; p < P; p++) {
                    for (int s = 0; s < S; s++) {

                        String c = "" + (j+1) + " " + (p+1) + " " + (s+1);

                        String combi1 = j + "_JJ_" + p;
                        String combi2 = j + "_PP_" + s;
                        String combi3 = p + "_SS_" + s;

                        if (!m.containsKey(combi1)) {
                            m.put(combi1, 0);
                        }
                        if (!m.containsKey(combi2)) {
                            m.put(combi2, 0);
                        }
                        if (!m.containsKey(combi3)) {
                            m.put(combi3, 0);
                        }

                        if (m.get(combi1) + 1 <= K && m.get(combi2) + 1 <= K && m.get(combi3) + 1 <= K) {
                            cs.add(c);
                            m.put(combi1, m.get(combi1)+1);
                            m.put(combi2, m.get(combi2)+1);
                            m.put(combi3, m.get(combi3)+1);
                        }
                    }
                }
            }


            String s = "" + cs.size() + "\n";
            for (int i = 0; i < cs.size(); i++) {
                s += cs.get(i);
                if (i != cs.size()-1) {
                    s += "\n";
                }
            }

            return s;
        }
    }
}



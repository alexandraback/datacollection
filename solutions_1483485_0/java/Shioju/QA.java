import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Dictionary;

public class QA {

    static final String TASK_ID = "qa";
    static BufferedReader reader;
    static PrintWriter writer;
    static char[] map = new char[26];
    static String mapString = "yhesocvxduiglbkrztnwjpfmaq";

    public static void main(String[] args) {
        try {
            long now = System.currentTimeMillis();
            reader = new BufferedReader(new FileReader(TASK_ID + ".in"));
            writer = new PrintWriter(TASK_ID + ".out");

            int numTests = Integer.parseInt(reader.readLine());

/*            
            //build mapping
            String G1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
            String S1 = "our language is impossible to understand";
            
            String G2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
            String S2 = "there are twenty six factorial possibilities";
            
            String G3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
            String S3 = "so it is okay if you want to just give up";
            
            //init map array
            for (int i=0; i<26; i++) {
                map[i]='#';
            }

            //'a'==97
            for (int i=0; i<G1.length(); i++) {
                char g = G1.charAt(i);
                if (g==' ') continue;
                if (map[g-97]=='#') {
                    map[g-97]=S1.charAt(i);
                } else {
                    System.out.println("repeat: "+map[g-97]+" -> "+ S1.charAt(i));
                }
            }

            for (int i=0; i<G2.length(); i++) {
                char g = G2.charAt(i);
                if (g==' ') continue;
                if (map[g-97]=='#') {
                    map[g-97]=S2.charAt(i);
                } else {
                    System.out.println("repeat: "+map[g-97]+" -> "+ S2.charAt(i));
                }
            }

            for (int i=0; i<G3.length(); i++) {
                char g = G3.charAt(i);
                if (g==' ') continue;
                if (map[g-97]=='#') {
                    map[g-97]=S3.charAt(i);
                } else {
                    System.out.println("repeat: "+map[g-97]+" -> "+ S3.charAt(i));
                }
            }
            System.out.println(map);
*/


            for (int testId = 0; testId < numTests; testId++) {
                Solver solver = new Solver(testId);
                solver.readInput();
                solver.run();
                solver.printOutput();
            }

            reader.close();
            writer.close();
            System.out.println(System.currentTimeMillis() - now + "ms");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    static class Solver {

        private int testId;
        private String G, S;

        public Solver(int testId) {
            this.testId = testId;
        }

        public void run() {
            S = "";
            for (int i=0; i<G.length(); i++) {
                char g = G.charAt(i);
                if (g==' ') {
                    S = S+" ";
                } else {
                    S = S + mapString.charAt(g-97);
                }
            }
        }

        private void readInput() {
            try {
                G = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void printOutput() {
            writer.println("Case #"+(testId+1)+": "+ S);
        }
    }
}

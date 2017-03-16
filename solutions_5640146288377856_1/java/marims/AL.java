	
import java.io.*;
import java.util.*;
import static java.util.Arrays.*;

public class AL {
    static final boolean _PRACTICE = !true;
    static final boolean _SAMPLE = !true;
    static final boolean _SMALL = !true;
    static final String _PROBLEM = "A";

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();

        for (int k = 1; k <= testCase; k++) {
            System.out.printf("Case #%d: ", k);
            System.err.printf("Case #%d: ", k);

            int r = sc.nextInt();
            int c = sc.nextInt();
            int w = sc.nextInt();
            
            int count = (c / w) * r;
            count += (w - 1);
            if (c % w != 0) {
            	count++;
            }
            
            System.out.println(count);
            System.err.println(count);
            
        }
        sc.close();
    }

    public static void main(String... args) throws IOException {
        if (!_SAMPLE) {
            if (_SMALL) {
                int i = 0;
                while (new File(_SMALLNAME(i) + ".in").exists())
                    i++;
                i--;
                boolean test = false;
                if (new File(_SMALLNAME(i) + ".out").exists()) {
                    System.err.println("overwrite?(y/n)");
                    char c = (char) System.in.read();
                    test = c != 'y';
                }
                if (test) {
                    System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
                    System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
                    new AL().run();
                    FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
                    FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
                    BufferedReader br1 = new BufferedReader(f1);
                    BufferedReader br2 = new BufferedReader(f2);
                    for (int j = 1;; j++) {
                        String s1 = br1.readLine();
                        String s2 = br2.readLine();
                        if (s1 == null && s2 == null) {
                            System.err.println("OK!");
                            break;
                        }
                        if (s1 == null || s2 == null || !s1.equals(s2)) {
                            System.err.println("failed at line " + j);
                            System.err.println("expected " + s2);
                            System.err.println("but " + s1);
                            break;
                        }
                    }
                    br1.close();
                    br2.close();
                } else {
                    System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
                    System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
                    new AL().run();
                }
            } else {
                System.setIn(new FileInputStream(_LARGENAME() + ".in"));
                System.setOut(new PrintStream(_LARGENAME() + ".out"));
                new AL().run();
            }
        } else
            new AL().run();
    }

    private static String _LARGENAME() {
        return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
    }

    private static String _SMALLNAME(int a) {
        return _PROBLEM + "-small"
                + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
    }
}

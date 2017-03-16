import java.io.*;
import java.util.*;
import static java.util.Arrays.*;

public class B {
    static final boolean _PRACTICE = !true;
    static final boolean _SAMPLE = !true;
    static final boolean _SMALL = true;
    static final String _PROBLEM = "B";

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();

        for (int k = 1; k <= testCase; k++) {
            System.out.printf("Case #%d: ", k);
            System.err.printf("Case #%d: ", k);

            int diners = sc.nextInt();
            List<Integer> pancake = new ArrayList<Integer>();
            for (int i = 0; i < diners; i++) {
            	int p = sc.nextInt();
                pancake.add(p);
            }
            Collections.sort(pancake);
            int time = 0;
            while (pancake.get(pancake.size() - 1) > 3) {
            	List<Integer> newDiners = new ArrayList<Integer>();
            	for (int i = 0; i < pancake.size(); i++) {
            		int num = pancake.get(i);
            		int give = num / 2;
            		pancake.set(i, num - give);
            		newDiners.add(give);
            	}
            	time++;
            	pancake.addAll(newDiners);
            	Collections.sort(pancake);
            }
            time += pancake.get(diners - 1);
            
            System.out.println(time);
            System.err.println(time);
            
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
                    new B().run();
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
                    new B().run();
                }
            } else {
                System.setIn(new FileInputStream(_LARGENAME() + ".in"));
                System.setOut(new PrintStream(_LARGENAME() + ".out"));
                new B().run();
            }
        } else
            new B().run();
    }

    private static String _LARGENAME() {
        return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
    }

    private static String _SMALLNAME(int a) {
        return _PROBLEM + "-small"
                + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
    }
}

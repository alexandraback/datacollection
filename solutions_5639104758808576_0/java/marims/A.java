import java.io.*;
import java.util.*;
import static java.util.Arrays.*;

public class A {
    static final boolean _PRACTICE = !true;
    static final boolean _SAMPLE = !true;
    static final boolean _SMALL = true;
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

            int maxShyness = sc.nextInt();
            
            String shynessStr = sc.next();
            int[] shyness = new int[shynessStr.length()];
            for (int i = 0; i < shyness.length; i++) {
            	shyness[i] = Integer.valueOf(String.valueOf(shynessStr.charAt(i)));
            }
            
            int friend = 0;
            int standing = 0;
            for (int i = 0; i <= maxShyness; i++) {
            	standing += shyness[i];
            	if (i < maxShyness) {
//                	boolean hasRemaining = false;
//                	for (int j = i + 1; j <= maxShyness; j++) {
//                		if (shyness[j] > 0) {
//                			hasRemaining = true;
//                			break;
//                		}
//                	}
                	if (/*hasRemaining && */standing < i + 1) {
                		friend++;
                		standing++;
                	}
            	}
            }            
            
            System.out.printf("%d", friend);
            System.err.printf("%d", friend);
            
            System.out.println();
            System.err.println();
            
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
                    new A().run();
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
                    new A().run();
                }
            } else {
                System.setIn(new FileInputStream(_LARGENAME() + ".in"));
                System.setOut(new PrintStream(_LARGENAME() + ".out"));
                new A().run();
            }
        } else
            new A().run();
    }

    private static String _LARGENAME() {
        return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
    }

    private static String _SMALLNAME(int a) {
        return _PROBLEM + "-small"
                + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
    }
}

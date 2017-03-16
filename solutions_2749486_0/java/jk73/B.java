import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

public class B {

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = Files.newBufferedReader(Paths.get("B-small.in"), Charset.forName("UTF-8"));
             PrintWriter out = new PrintWriter(Files.newBufferedWriter(Paths.get("B-small.out"), Charset.forName("UTF-8")))) {
             //PrintWriter out = new PrintWriter(System.out)) {
            int numCases = Integer.parseInt(reader.readLine());

            for (int i = 0; i < numCases; i++) {
                System.out.println(i);
                String[] split = reader.readLine().split(" ");

                String name = split[0];
                int x = Integer.parseInt(split[0]);
                int y = Integer.parseInt(split[1]);

                String s = handle(x, y);
                out.println("Case #" + (i + 1) + ": " + s);
            }
        }
    }

    private static String handle(int x, int y) {
        StringBuilder sb = new StringBuilder(100);

        int xx = 0;
        int yy = 0;

        int len = 0;

        if (x < y) {
            if (x > 0) {
                while (xx != x) {
                    len++;
                    if (xx + len <= x) {
                        sb.append('E');
                        xx += len;
                    } else {
                        sb.append('W');
                        xx -= len;
                    }
                }
            } else if (x < 0) {
                while (xx != x) {
                    len++;
                    if (xx - len >= x) {
                        sb.append('W');
                        xx -= len;
                    } else {
                        sb.append('E');
                        xx += len;
                    }
                }
            }
            if (y > 0) {
                while (yy != y) {
                    len++;
                    if (yy + len <= y) {
                        sb.append('N');
                        yy += len;
                    } else {
                        sb.append('S');
                        yy -= len;
                    }
                }
            } else if (y < 0) {
                while (yy != y) {
                    len++;
                    if (yy - len >= y) {
                        sb.append('S');
                        yy -= len;
                    } else {
                        sb.append('N');
                        yy += len;
                    }
                }
            }
        } else {
            if (y > 0) {
                while (yy != y) {
                    len++;
                    if (yy + len <= y) {
                        sb.append('N');
                        yy += len;
                    } else {
                        sb.append('S');
                        yy -= len;
                    }
                }
            } else if (y < 0) {
                while (yy != y) {
                    len++;
                    if (yy - len >= y) {
                        sb.append('S');
                        yy -= len;
                    } else {
                        sb.append('N');
                        yy += len;
                    }
                }
            }
            if (x > 0) {
                while (xx != x) {
                    len++;
                    if (xx + len <= x) {
                        sb.append('E');
                        xx += len;
                    } else {
                        sb.append('W');
                        xx -= len;
                    }
                }
            } else if (x < 0) {
                while (xx != x) {
                    len++;
                    if (xx - len >= x) {
                        sb.append('W');
                        xx -= len;
                    } else {
                        sb.append('E');
                        xx += len;
                    }
                }
            }
        }
        return sb.toString();
    }
}

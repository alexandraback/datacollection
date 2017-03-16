import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by khabat95 on 12/04/14.
 */
public class MinesweeperMaster {

    public static String alg(int R, int C, int M) {
        StringBuilder strBuf = new StringBuilder();
        int empty = (R*C)-M;
        int emptyR = R, emptyC = C;
        int restM = M;
        int xRestM = 0;
        if (empty > 1) {
            if (R != 1 && C != 1) {
                while (restM >= emptyR || restM >= emptyC) {
                    if (emptyR < emptyC) {
                        restM -= emptyR;
                        emptyC--;
                    } else {
                        restM -= emptyC;
                        emptyR--;
                    }
                }
                if (emptyC == 1 || emptyR == 1) {
                    return "Impossible";
                } else if (restM != 0) {
                    if (emptyC == 2 || emptyR == 2) {
                        return "Impossible";
                    }
                    while (restM-xRestM+1 >= emptyR) {
                        xRestM++;
                    }
                    if (xRestM + 2 >= emptyC) {
                        return "Impossible";
                    }
                }
            }
        }

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (i == 0 && j == 0) {
                    strBuf.append('c');
                    empty--;
                } else if (empty > 0 && i < emptyR && j < emptyC) {
                    if (j == emptyC-1) {
                        if (i < emptyR-(restM-xRestM)) {
                            strBuf.append('.');
                            empty--;
                        } else {
                            strBuf.append('*');
                        }
                    } else if (i == emptyR-1) {
                        if (j < emptyC-xRestM-1) {
                            strBuf.append('.');
                            empty--;
                        } else {
                            strBuf.append('*');
                        }
                    } else {
                        strBuf.append('.');
                        empty--;
                    }
                } else {
                    strBuf.append('*');
                }
            }
            if (i != R-1)
                strBuf.append('\n');
        }

        return strBuf.toString();
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/Downloads/C-large.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/Downloads/C-large.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ":");
                pw.println(alg(sc.nextInt(), sc.nextInt(), sc.nextInt()));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}


import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class B {

    static int minStep;
    static HashSet<Config> history;

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "B-small-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int N = in.nextInt();
            int a[] = new int[N];
            int b[] = new int[N];
            for (int i = 0; i < N; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
            }
            minStep = Integer.MAX_VALUE;
            history = new HashSet<Config>();
            search(a, b, new boolean[N], new boolean[N], 0, 0);
            if (minStep == Integer.MAX_VALUE) {
                out.println("Case #" + t + ": Too Bad");
            } else {
                out.println("Case #" + t + ": " + minStep);
            }
        }

        out.close();
    }

    static void search(int a[], int b[], boolean usedA[], boolean usedB[], int star, int step) {
        ArrayList<Integer> doneB = new ArrayList<Integer>();
        while (true) {
            boolean changed = false;
            for (int i = 0; i < b.length; i++) {
                if (b[i] <= star && !usedB[i]) {
                    usedB[i] = true;
                    doneB.add(i);
                    step++;
                    if (usedA[i]) {
                        star += 1;
                    } else {
                        star += 2;
                    }
                    changed = true;
                }
            }
            if (!changed) {
                break;
            }
        }

        boolean complete = true;
        for (boolean uB : usedB) {
            if (!uB) {
                complete = false;
                break;
            }
        }
        if (complete) {
            minStep = Math.min(minStep, step);
        } else {
            Config config = new Config(usedA, usedB);
            if (!history.contains(config)) {
                history.add(config);
                for (int i = 0; i < a.length; i++) {
                    if (a[i] <= star && !usedA[i] && !usedB[i]) {
                        usedA[i] = true;
                        search(a, b, usedA, usedB, star + 1, step + 1);
                        usedA[i] = false;
                    }
                }
            }
        }

        for (int index : doneB) {
            usedB[index] = false;
        }
    }
}

class Config {

    boolean usedA[];
    boolean usedB[];

    Config(boolean theUsedA[], boolean theUsedB[]) {
        int n = theUsedA.length;
        usedA = new boolean[n];
        usedB = new boolean[n];
        System.arraycopy(theUsedA, 0, usedA, 0, n);
        System.arraycopy(theUsedB, 0, usedB, 0, n);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Config other = (Config) obj;
        if (!Arrays.equals(this.usedA, other.usedA)) {
            return false;
        }
        if (!Arrays.equals(this.usedB, other.usedB)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 53 * hash + Arrays.hashCode(this.usedA);
        hash = 53 * hash + Arrays.hashCode(this.usedB);
        return hash;
    }
}
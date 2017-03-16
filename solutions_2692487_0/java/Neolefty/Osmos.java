import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Osmos {
    public int a;
    public List<Integer> motes;

    public Osmos(Scanner in) {
        a = in.nextInt();
        motes = new ArrayList<>();
        int n = in.nextInt();
        for (int i = 0; i < n; ++i)
            motes.add(in.nextInt());
        Collections.sort(motes);

        // possible operations
        // - remove the next mote (greedy)
        // - insert a mote at the beginning (greedy)
    }

    int search() {
        Trial start = new Trial(a, motes);
        return start.best();
    }

    class Trial {
        int a;
        Deque<Integer> m;
        int changes = 0;

        Trial(int a, Collection<Integer> motes) {
            this.a = a;
            this.m = new ArrayDeque<>(motes);
        }

        Trial(Trial that) {
            this(that.a, that.m);
            this.changes = that.changes;
        }

        void run() {
            while (!m.isEmpty() && m.getFirst() < a)
                a += m.removeFirst();
        }

        int best() {
            run();
            if (isDone()) return changes;
            else if (a == 1 && m.getFirst() > 0) {
                remove();
                return best();
            }
            else {
                Trial a = new Trial(this);
                a.insert();
                Trial b = new Trial(this);
                b.remove();
                return Math.min(a.best(), b.best());
            }
        }

        void insert() {
            assert m.getFirst() >= a;
            m.addFirst(a - 1);
            ++changes;
        }

        void remove() {
            assert m.getFirst() >= a;
            m.removeFirst();
            ++changes;
        }

        public boolean isDone() { return m.isEmpty(); }
    }

    public static void main(String[] args) throws IOException {
        String name = new Scanner(System.in).next();
        Scanner in = new Scanner(Osmos.class.getResourceAsStream(name));
        int n = in.nextInt();
        long start = System.currentTimeMillis();
        File outFile;
        if (name.endsWith(".in"))
            outFile = new File(name.replace(".in", ".out"));
        else
            outFile = new File(name + ".out");

        FileOutputStream fout = new FileOutputStream(outFile);
        PrintWriter print = new PrintWriter(fout);
        for (int i = 1; i <= n; ++i) {
            String report = "Case #" + i + ": " + new Osmos(in).search();
            print.println(report);
            System.out.println(report);
        }
        print.flush();
        fout.close();
        System.out.println("Elapsed: " + (System.currentTimeMillis() - start));
    }
}

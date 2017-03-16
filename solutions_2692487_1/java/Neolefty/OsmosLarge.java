import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class OsmosLarge {
    public int a;
    public List<Integer> motes;

    public OsmosLarge(Scanner in) {
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
        Map<Deque<Integer>, Integer> map = new HashMap<>();
        map.put(start.pickle(), 0);
        return best(map, Integer.MAX_VALUE);
    }

    int best(Map<Deque<Integer>, Integer> map, int bestSoFar) {
        do {
            Map<Deque<Integer>, Integer> next = new HashMap<>();
            for (Map.Entry<Deque<Integer>, Integer> e : map.entrySet()) {
                Deque<Integer> d = e.getKey();
                Integer score = e.getValue();
                Trial t = new Trial(d, score);
                t.run();
                if (t.isDone()) {
                    if (t.changes < bestSoFar)
                        bestSoFar = t.changes;
                }
                else {
                    if (t.a > 1) {
                        Trial a = new Trial(t);
                        a.insert();
                        if (a.changes < bestSoFar)
                            addIfBetter(a, next);
                    }
                    t.remove();
                    if (t.changes < bestSoFar)
                        addIfBetter(t, next);
                }
            }
            map = next;
        } while(map.size() > 0);
        return bestSoFar;
    }

    private void addIfBetter(Trial t, Map<Deque<Integer>, Integer> map) {
        Deque<Integer> d = t.pickle();
        Integer now = map.get(d);
        if (now == null || now > t.changes)
            map.put(d, t.changes);
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

        public Trial(Deque<Integer> d, Integer score) {
            m = new ArrayDeque<>(d);
            a = m.removeFirst();
            this.changes = score;
        }

        void run() {
            while (!m.isEmpty() && m.getFirst() < a)
                a += m.removeFirst();
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

        public Deque<Integer> pickle() {
            Deque<Integer> result = new ArrayDeque<>(m);
            result.addFirst(a);
            return result;
        }
    }

    public static void main(String[] args) throws IOException {
        String name = new Scanner(System.in).next();
        Scanner in = new Scanner(OsmosLarge.class.getResourceAsStream(name));
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
            String report = "Case #" + i + ": " + new OsmosLarge(in).search();
            print.println(report);
            System.out.println(report);
        }
        print.flush();
        fout.close();
        System.out.println("Elapsed: " + (System.currentTimeMillis() - start));
    }
}

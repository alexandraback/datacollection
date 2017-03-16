import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;
import java.util.function.Function;

enum QuaternionTypes {
    one, i, j, k;

    static QuaternionTypes getType(char c) {
        switch (c) {
            case '1':
                return one;
            case 'i':
                return i;
            case 'j':
                return j;
            case 'k':
                return k;
        }
        throw new IllegalArgumentException();
    }
}

class Quaternion {
    static final int multiplyTable[][] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
    static final int signMultiplyTable[][] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};

    int value; // 0 -- 1, 1 -- i, 2 -- j, 3 -- k
    int sign;

    Quaternion() {
        this.value = 0;
        this.sign = 1;
    }

    Quaternion(QuaternionTypes a) {
        this.value = a.ordinal();
        this.sign = 1;
    }

    Quaternion(int value, int sign) {
        this.value = value;
        this.sign = sign;
    }

    Quaternion multiply(Quaternion b) {
        Quaternion a = this;
        Quaternion c = new Quaternion();
        return new Quaternion(multiplyTable[a.value][b.value], a.sign * b.sign * signMultiplyTable[a.value][b.value]);
    }

    public boolean equals(Quaternion q) {
        return value == q.value && sign == q.sign;
    }
}

class Input {
    int l;
    long x;
    String s;

    private Input() {}

    static Input getInput(FastScanner in) {
        Input res = new Input();
        res.l = in.nextInt();
        res.x = in.nextLong();
        res.s = in.next();
        return res;
    }
}

public class Task implements Runnable {
    FastScanner in;
    PrintWriter out;

    Function<Input, String> solver = input -> {
        int l = input.l;
        long x = input.x;
        String s = input.s;

        Quaternion cur;
        long i = 0;
        Quaternion qI = new Quaternion(QuaternionTypes.i);
        Quaternion qJ = new Quaternion(QuaternionTypes.j);
        Quaternion qK = new Quaternion(QuaternionTypes.k);

        cur = new Quaternion();
        while (!cur.equals(qI) && i < l * Math.min(x, 32)) {
            cur = cur.multiply(new Quaternion(QuaternionTypes.getType(s.charAt((int)(i++) % l))));
        }
        if (!cur.equals(qI)) {
            return "NO";
        }

        cur = new Quaternion();
        while (!cur.equals(qJ) && i < l * Math.min(x, 32)) {
            cur = cur.multiply(new Quaternion(QuaternionTypes.getType(s.charAt((int)(i++) % l))));
        }
        if (!cur.equals(qJ)) {
            return "NO";
        }

        cur = new Quaternion();
        while (i % l != 0) {
            cur = cur.multiply(new Quaternion(QuaternionTypes.getType(s.charAt((int)(i++) % l))));
        }

        int groups = (int)((x - i / l) % 4);

        Quaternion all = new Quaternion();
        for (i = 0; i < l;) {
            all = all.multiply(new Quaternion(QuaternionTypes.getType(s.charAt((int)(i++) % l))));
        }

        for (int j = 0; j < groups; j++) {
            cur = cur.multiply(all);
        }

        if (!cur.equals(qK)) {
            return "NO";
        }

        return "YES";
    };

    public void solve() throws IOException, InterruptedException {
        int tests = in.nextInt();
        List<Input> inputs = new ArrayList<Input>();
        for (int test = 1; test <= tests; test++) {
            inputs.add(Input.getInput(in));
        }

        ParallelMapper mapper = new ParallelMapper(4);
        List<String> ans = mapper.map(solver, inputs);
        mapper.close();

        for (int i = 0; i < ans.size(); i++) {
            out.printf("Case #%d: %s\n", i + 1, ans.get(i));
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

            solve();

            out.close();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new Thread(null, new Task(), "", 1 << 26).start();
    }
}


class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    FastScanner(File f) {
        try {
            br = new BufferedReader(new FileReader(f));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }
}

class ParallelMapper  {

    private volatile boolean isStopped;

    final private Queue<Consumer<Void>> queue = new ArrayDeque<>();

    final private Thread threads[];


    public ParallelMapper(int threads) {
        this.threads = new Thread[threads];
        for (int i = 0; i < threads; i++) {
            this.threads[i] = new Thread(new Runnable() {

                @Override
                public void run() {
                    while (true) {
                        if (isStopped) {
                            return;
                        }
                        Consumer<Void> action = null;
                        synchronized (queue) {
                            if (!queue.isEmpty()) {
                                action = queue.poll();
                            }
                        }
                        if (action == null) {
                            synchronized (queue) {
                                try {
                                    queue.wait();
                                    continue;
                                } catch (InterruptedException e) {
                                    return;
                                }
                            }
                        }
                        action.accept(null);
                    }
                }
            });
            this.threads[i].start();
        }
    }

    public <T, R> List<R> map(Function<? super T, ? extends R> f, List<? extends T> args) throws InterruptedException {
        if (isStopped) {
            throw new IllegalStateException("Mapper has already been closed");
        }
        List<R> result = new ArrayList<>();

        final AtomicInteger counter = new AtomicInteger(0);
        synchronized (queue) {
            for (int i = 0; i < args.size(); i++) {
                final int id = i;
                queue.add(new Consumer<Void>() {
                    @Override
                    public void accept(Void aVoid) {
                        R value = f.apply(args.get(id));
                        synchronized (result) {
                            result.set(id, value);
                        }
                        counter.incrementAndGet();
                        System.err.println(counter.get() + " tasks are done");
                        if (counter.get() == args.size()) {
                            synchronized (queue) {
                                queue.notifyAll();
                            }
                        }
                    }
                });
                result.add(null);
            }
            queue.notifyAll();
        }
        synchronized (queue) {
            while (counter.get() < args.size()) {
                queue.wait();
            }
        }

        return result;
    }

    public void close() throws InterruptedException {
        isStopped = true;
        for (Thread thread : threads) {
            thread.interrupt();
            thread.join();
        }
    }
}
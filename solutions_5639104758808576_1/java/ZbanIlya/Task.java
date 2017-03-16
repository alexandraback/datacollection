import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;
import java.util.function.Function;

class Input {
    int n;
    String s;

    private Input() {}

    static Input getInput(FastScanner in) {
        Input res = new Input();
        res.n = in.nextInt();
        res.s = in.next();
        return res;
    }
}

public class Task implements Runnable {
    FastScanner in;
    PrintWriter out;

    Function<Input, String> solver = input -> {
        int n = input.n;
        String s = input.s;

        for (int ans = 0;; ans++) {
            int curSum = ans;
            boolean ok = true;
            for (int i = 0; i <= n; i++) {
                ok &= curSum >= i;
                curSum += (s.charAt(i) - '0');
            }
            if (ok) {
                return Integer.toString(ans);
            }
        }
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
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
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
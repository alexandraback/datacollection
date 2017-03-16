package gcj14.r1c;

import java.io.BufferedInputStream;
import java.io.PrintStream;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class B {
    static class Reader {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));

        public String next() {
            return scanner.next();
        }

        public int nextInt() {
            return scanner.nextInt();
        }

        public long nextLong() {
            return scanner.nextLong();
        }

        public String nextLine() {
            return scanner.nextLine();
        }
    }

    static class Writer {
        PrintStream out = System.out;

        public void write(String s) {
            out.print(s);
        }

        public void write(char c) {
            out.print(c);
        }

        public void write(byte b) {
            out.print(b);
        }

        public void write(int i) {
            out.print(i);
        }

        public void write(long l) {
            out.print(l);
        }

        public void writeLine(String s) {
            out.println(s);
        }

        public void writeLine(char c) {
            out.println(c);
        }

        public void writeLine(byte b) {
            out.println(b);
        }

        public void writeLine(int i) {
            out.println(i);
        }

        public void writeLine(long l) {
            out.println(l);
        }
    }

    static class Data {
        int caseNum;
        int n;
        String[] cars;
        long ans;

        Data(int caseNum) {
            this.caseNum = caseNum;
        }

        void feed(Reader reader) {
            n =  reader.nextInt();
            cars = new String[n];
            for (int i = 0; i < n; i++) {
                cars[i] = reader.next();
            }
        }

        void print(Writer writer) {
            writer.write(String.format("Case #%d: ", caseNum));
            writer.writeLine(ans);
        }
    }

    static class Solver implements Runnable {
        Data data;

        Solver(Data data) {
            this.data = data;
        }

        boolean same(String str) {
            char c = str.charAt(0);
            for (int i = 1; i < str.length(); i++) {
                if (str.charAt(i) != c) {
                    return false;
                }
            }
            return true;
        }

        boolean valid(String str) {
            Set<Character> set = new HashSet<Character>();
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (!set.contains(c)) {
                    set.add(c);
                    while (i < str.length() && str.charAt(i) == c) {
                        i++;
                    }
                    i--;
                } else {
                    return false;
                }
            }
            return true;
        }

        int toPos(char c) {
            return c - 'a';
        }

        private void permutation(Data data, String prefix, String str) {
            int n = str.length();
            if (n == 0) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < prefix.length(); i++) {
                    sb.append(data.cars[toPos(prefix.charAt(i))]);
                }
                if (valid(sb.toString())) {
                    data.ans++;
                }
            }
            else {
                for (int i = 0; i < n; i++)
                    permutation(data, prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
            }
        }

        public void run() {
            data.ans = 0;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < data.n; i++) {
                char c = (char)('a' + i);
                sb.append(c);
            }
            permutation(data, "", sb.toString());
        }

        public void run2() {
            int n = data.n;
            int m = 1000000007;
            long[] p = new long[n + 1];
            p[0] = 1;
            for (int i = 1; i <= n; i++) {
                p[i] = p[i-1] * i % m;
            }

            List<Integer>[] startList = new List[26];
            for (int i = 0; i < 26; i++) {
                startList[i] = new ArrayList<Integer>();
            }

            List<Integer>[] endList = new List[26];
            for (int i = 0; i < 26; i++) {
                endList[i] = new ArrayList<Integer>();
            }

            List<Integer>[] oneList = new List[26];
            for (int i = 0; i < 26; i++) {
                oneList[i] = new ArrayList<Integer>();
            }

            Set<Integer>[] set = new Set[26];
            for (int i = 0; i < 26; i++) {
                set[i] = new HashSet<Integer>();
            }

            data.ans = 0;
            for (int i = 0; i < n ;i++) {
                String car = data.cars[i];
                if (!valid(car)) {
                    return;
                }

                for (int j = 0; j < car.length(); j++) {
                    set[toPos(car.charAt(j))].add(i);
                }

                int first = toPos(car.charAt(0));
                int last = toPos(car.charAt(car.length() - 1));
                if (same(car)) {
                    oneList[first].add(i);
                } else {
                    startList[first].add(i);
                    endList[last].add(i);
                    if (first == last) {
                        return;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                String car = data.cars[i];
                if (!same(car)) {
                    int s = 1;
                    int e = car.length() - 2;
                    while (car.charAt(s) == car.charAt(s - 1)) {
                        s++;
                    }
                    while (car.charAt(e) == car.charAt(e + 1)) {
                        e--;
                    }
                    for (int j = s; j <= e; j++) {
                        int pos = toPos(car.charAt(j));
                        if (set[pos].size() > 1) {
                            return;
                        }
                    }
                }
            }

            long ans = 1;
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (endList[i].size() > 1) {
                    return;
                } else if (endList[i].size() == 1) {
                    if (startList[i].size() > 1) {
                        return;
                    } else if (startList[i].size() == 0) {
                        cnt++;
                    }
                    ans = ans * p[oneList[i].size()] % m;
                } else {
                    if (startList[i].size() == 0 && oneList[i].size() > 0) {
                        ans = ans * p[oneList[i].size()] % m;
                        cnt++;
                    }
                }
            }

            ans = ans * p[cnt] % m;
            data.ans = ans;
        }
    }

    static class SingleThread {
        void execute() {
            Reader reader = new Reader();
            Writer writer = new Writer();

            int cases = reader.nextInt();
            for (int i = 1; i <= cases; i++) {
                Data data = new Data(i);
                data.feed(reader);
                new Solver(data).run();
                data.print(writer);
            }
        }
    }

    static class MultipleThread {
        int threads;

        MultipleThread(int threads) {
            this.threads = threads;
        }

        void execute() {
            Reader reader = new Reader();
            int cases = reader.nextInt();
            Data[] data = new Data[cases];
            Solver[] solvers = new Solver[cases];
            for (int i = 0; i < cases; i++) {
                data[i] = new Data(i + 1);
                data[i].feed(reader);
                solvers[i] = new Solver(data[i]);
            }

            Future[] futures = new Future[cases];
            ExecutorService executor = Executors.newFixedThreadPool(threads);
            for (int i = 0; i < cases; i++) {
                futures[i] = executor.submit(solvers[i]);
            }
            for (int i = 0; i < cases; i++) {
                if (!futures[i].isDone()) {
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
            executor.shutdown();

            Writer writer = new Writer();
            for (int i = 0; i < cases; i++) {
                data[i].print(writer);
            }
        }
    }

    public static void main(String[] args) {
        int threads = 1;
        if (args.length > 0) {
            try {
                threads = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                threads = 1;
            }
        }

        if (threads > 1) {
            new MultipleThread(threads).execute();
        } else {
            new SingleThread().execute();
        }
    }
}

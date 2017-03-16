import com.sun.tools.internal.ws.wsdl.document.soap.SOAPUse;

import java.io.BufferedInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
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
        int k, l, s;
        String keys;
        String target;
        double ans;

        Data(int caseNum) {
            this.caseNum = caseNum;
        }

        void feed(Reader reader) {
            k = reader.nextInt();
            l = reader.nextInt();
            s = reader.nextInt();
            keys = reader.next();
            target = reader.next();
        }

        void print(Writer writer) {
            writer.write(String.format("Case #%d: ", caseNum));
            writer.writeLine(String.format("%.8f", ans));
        }
    }

    static class Solver implements Runnable {
        Data data;
        private int total = 0;
        private int[] cnt = new int[26];
        private List<Integer> keys = new ArrayList<Integer>();

        Solver(Data data) {
            this.data = data;
        }

        @Override
        public void run() {
            int k = data.k;
            int l = data.l;
            int s = data.s;
            String keystr = data.keys;
            String target = data.target;

            for (int i = 0; i < keystr.length(); i++) {
                int key = keystr.charAt(i) - 'A';
                if (cnt[key] == 0) {
                    keys.add(key);
                }
                cnt[key]++;
            }

            int maxPrefix = 0;
            for (int i = 1; i < target.length(); i++) {
                if (target.substring(target.length() - i).equals(target.substring(0, i))) {
                    maxPrefix = i;
                }
            }

            total = 1 + (s - l) / (target.length() - maxPrefix);
            for (int i = 0; i < target.length(); i++) {
                if (cnt[target.charAt(i) - 'A'] == 0) {
                    total = 0;
                    break;
                }
            }
            search(0, new char[s]);
        }

        private void search(int d, char[] aux) {
            if (d == data.s) {
                int banana = 0;
                String str = new String(aux);
                for (int i = 0; i <= d - data.l; i++) {
                    if (str.substring(i, i + data.l).equals(data.target)) {
                        banana++;
                    }
                }
                double p = 1;
                for (int i = 0; i < d; i++) {
                    p *= 1.0 * cnt[aux[i] - 'A'] / data.k;
                }
                data.ans += (total - banana) * p;
                return;
            }
            for (int i = 0; i < keys.size(); i++) {
                aux[d] = (char) ('A' + keys.get(i));
                search(d + 1, aux);
            }
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

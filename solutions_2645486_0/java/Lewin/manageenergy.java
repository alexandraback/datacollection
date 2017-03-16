import java.util.*;
import java.io.*;

public class manageenergy {
    private static Reader in;
    private static PrintWriter out;
    public static final String NAME = "B-small-attempt2";

    private static int M;
    private static void main2() throws IOException {
        int E = in.nextInt(), R = in.nextInt(), N = in.nextInt();
        long [] arr = new long [N + 1];
        for (int i = 1; i <= N; i++) {
            arr [i] = in.nextInt();
        }
        M = 2 * N + 2;
        cap = new int [M][M];
        cost = new long [M][M];
        addEdge (0, 1, E, 0);
        addEdge (1, N + 1, E, 0);
        addEdge (N + 1, 2 * N + 1, E, -arr [1]);
        for (int i = 2; i <= N; i++) {
            addEdge (0, i, R, 0);
            addEdge (i, i + N, E, 0);
            addEdge (i + N, 2 * N + 1, E, -arr [i]);
            addEdge (i - 1 + N, i, E, 0);
        }
        out.println (-flow (0, 2 * N + 1) [1]);
    }
    
    private static int [][] cap;
    private static long [][] cost;
    
    private static void addEdge (int x, int y, int w, long c) {
        cap[x][y] = w;
        cost[x][y] = c;
        cost[y][x] = -c;
    }
    
    
    private static long [] flow (int source, int sink) {
        int ans_flow = 0;
        long ans_cost = 0;
        long [] pot = new long [M];
        
        while (true) {
            boolean [] used = new boolean [M];
            long [] dist = new long [M];
            int [] prev = new int [M];
            Arrays.fill (dist, 1 << 29);
            dist[source] = 0;
            
            while (true) {
                int x = -1;
                for (int i = 0; i < M; i++)
                    if (dist[i] != 1 << 29 && !used[i] && (x == -1 || dist[i] < dist[x]))
                        x = i;
                
                if (x == -1)
                    break;
                
                used[x] = true;
                for (int i = 0; i < M; i++)
                    if (cap[x][i] > 0
                            && dist[x] + cost[x][i] + pot[x] - pot[i] < dist[i]) {
                        dist[i] = dist[x] + cost[x][i] + pot[x] - pot[i];
                        prev[i] = x;
                    }
            }
            
            if (!used[sink])
                break;
            
            int ansf = 1 << 29, ansc = 0;
            for (int x = sink; x != source; x = prev[x])
                ansf = Math.min (ansf, cap[prev[x]][x]);
            
            ans_flow += ansf;
            for (int x = sink; x != source; x = prev[x]) {
                ansc += cost[prev[x]][x] * ansf;
                cap[prev[x]][x] -= ansf;
                cap[x][prev[x]] += ansf;
            }
            
            for (int i = 0; i < M; i++)
                pot[i] += dist[i];
            
            ans_cost += ansc;
        }
        
        return new long [] { ans_flow, ans_cost };
    }

    public static void main(String[] args) throws IOException {
        in = new Reader(NAME + ".in");
        out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

        int numCases = in.nextInt();
        for (int test = 1; test <= numCases; test++) {
            out.print("Case #" + test + ": ");
            main2();
        }

        out.close();
        System.exit(0);
    }

    /** Faster input **/
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[1024];
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            else
                return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            else
                return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10);
            }
            if (neg)
                return -ret;
            else
                return ret;
        }

        public char nextChar() throws IOException {
            char ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            return (char) c;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}

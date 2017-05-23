import java.io.*;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("/home/useruser/datacollection/input/1485488_0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};

    public void solve(int testNumber, MyScanner in, PrintWriter out) {
        System.err.println(testNumber);
        int H = in.nextInt();
        int N = in.nextInt(), M = in.nextInt();
        int[][] F = new int[N][M];
        int[][] C = new int[N][M];
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) C[i][j] = in.nextInt();
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) F[i][j] = in.nextInt();
        HashMap<Entry, Double> map = new HashMap<Entry, Double>();
        PriorityQueue<Entry> que = new PriorityQueue<Entry>();
        Entry init = new Entry(0, 0, H, 0);
        que.offer(init);
        map.put(init, 0.0);
        while (!que.isEmpty()) {
            Entry cur = que.poll();
            int x = cur.x;
            int y = cur.y;
            if (x == N - 1 && y == M - 1) {
                out.printf("Case #%d: %.12f\n", testNumber, cur.time);
                return;
            }
            int height = cur.height;
            int addTime = (cur.height - F[x][y] >= 20)? 1 : 10;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    int cF = Math.max(F[x][y], cur.height);
                    int cC = C[x][y];
                    int nF = Math.max(F[nx][ny], cur.height);
                    int nC = C[nx][ny];
                    if (nC - cF >= 50 && cC - nF >= 50 && nC - nF >= 50) {
                        Entry nxt = new Entry(nx, ny, height - addTime * 10, cur.time + addTime);
                        Double tmp = map.get(nxt);
                        if (tmp == null || tmp > nxt.time) {
                            map.put(nxt, nxt.time);
                            que.offer(nxt);
                        }
                        if (height == H) {
                            nxt = new Entry(nx, ny, height, cur.time);
                            tmp = map.get(nxt);
                            if (tmp == null || tmp > nxt.time) {
                                map.put(nxt, nxt.time);
                                que.offer(nxt);
                            }
                        }
                    } else if (nC - F[x][y] >= 50) {
                        int nHeight = nC - 50;
                        double waitTime = (height - nHeight) / 10.0;
                        if(nHeight < height){
                        Entry nxt = new Entry(x, y, nHeight, cur.time + waitTime);
                        Double tmp = map.get(nxt);
                        if (tmp == null || tmp > nxt.time) {
                            map.put(nxt, nxt.time);
                            que.offer(nxt);
                        }
                        }
                    }
                }
            }
        }
        throw new RuntimeException();
    }

    class Entry implements Comparable<Entry> {
        int x, y;
        int height;
        double time;

        Entry(int x, int y, int height, double time) {
            this.height = Math.max(0, height);
            this.time = time;
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Entry entry = (Entry) o;

            if (height != entry.height) return false;
            if (x != entry.x) return false;
            if (y != entry.y) return false;

            return true;
        }

        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            result = 31 * result + height;
            return result;
        }

        public int compareTo(Entry o) {
            return Double.compare(time, o.time);
        }
    }
}

class MyScanner {
    private final InputStream in;
    public MyScanner(InputStream in){
        this.in = in;
    }

    char[] buf = new char[2000000];
    int strLen;
	public String next() {
		try {
            strLen = 0;
            int c;
			do{
				c = in.read();
				if(c==-1)throw new NoSuchElementException();
			}while(Character.isWhitespace(c));
			do {
                buf[strLen++] = (char)c;
                c = in.read();
			} while (c!=-1 && !Character.isWhitespace(c));
            return new String(buf,0,strLen);
		} catch (IOException e) {
            throw new NoSuchElementException();
		}
	}

	public int nextInt(){
		try{
			int c=in.read();
			if(c==-1) return c;
			while(c!='-'&&(c<'0'||'9'<c)){
				c=in.read();
				if(c==-1) return c;
			}
			if(c=='-') return -nextInt();
			int res=0;
			do{
				res*=10;
				res+=c-'0';
				c=in.read();
			}while('0'<=c&&c<='9');
			return res;
		}catch(Exception e){
			return -1;
		}
	}


    }


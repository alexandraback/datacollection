import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		String name = "B-small";
		Scanner s = new Scanner(new File(name + ".in"));
		int c = s.nextInt();
		out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
//		out = new PrintWriter(System.out);
		for (int i = 1; i <= c; i++) {
			out.print("Case #" + i + ": ");
			int h = s.nextInt();
			int n = s.nextInt();
            int m = s.nextInt();
            int[][] u = new int[n][m];
            int[][] d = new int[n][m];
            for(int x=0; x<n; x++) {
                for(int y=0; y<m; y++) {
                    u[x][y] = s.nextInt();
                }
            }
            for(int x=0; x<n; x++) {
                for(int y=0; y<m; y++) {
                    d[x][y] = s.nextInt();
                }
            }
			double res = solve(h, n, m, u, d);
			out.print(String.format("%f", res));
			out.println();			
		}
		out.close();
	}

	static double solve(int h, int n, int m, int[][] u, int[][] d)  {
	    boolean[][] v = new boolean[n][m];
	    PriorityQueue<State> q = new PriorityQueue<State>();
	    q.add(new State(0, 0, 0));
	    int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
	    while(!q.isEmpty()) {
	        State s = q.poll();
	        int x = s.x;
	        int y = s.y;
	        double t = s.t;
	        if(x == n-1 && y == m-1) {
	            return s.t;
	        }
	        if(v[x][y]) continue;
	        v[x][y] = true;
	        double ch = h - 10 * t;
	        for(int i=0; i<4; i++) {
	            int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(Math.min(u[x][y], u[nx][ny])-Math.max(d[x][y], d[nx][ny])<50) continue;
                int th = Math.min(u[x][y], u[nx][ny]) - 50;
                if(t == 0 && h <= th) {
                    q.add(new State(0, nx, ny));                     
                } else if(ch <= th) { 
                    if(ch - d[x][y] >= 20) {
                        q.add(new State(t + 1, nx, ny));
                    } else {
                        q.add(new State(t + 10, nx, ny));                        
                    }
                } else { 
                    t += (ch - th) / 10;
                    if(th - d[x][y] >= 20) {
                        q.add(new State(t + 1, nx, ny));
                    } else {
                        q.add(new State(t + 10, nx, ny));                        
                    }
                }
	        }
	    }
	    return -1;
	}
	
	static class State implements Comparable<State> {

	    public double t = 0;
	    public int x = 0;
	    public int y = 0;
	    
	    public State(double t, int x, int y) {
	        this.t = t;
	        this.x = x;
	        this.y = y;
	    }
	    
        @Override
        public int compareTo(State a) {
            if(t<a.t) {
                return -1;
            }
            if(t>a.t) {
                return 1;
            }
            return 0;
        }
	    
	}

}

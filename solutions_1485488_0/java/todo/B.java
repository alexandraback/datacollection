import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class B{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	int h, n, m;
	int[][] cs, fs;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			h=sc.nextInt();
			n=sc.nextInt();
			m=sc.nextInt();

			cs=new int[n][m];
			for(int j=0; j<n; j++){
				for(int i=0; i<m; i++){
					cs[j][i]=sc.nextInt();
				}
			}

			fs=new int[n][m];
			for(int j=0; j<n; j++){
				for(int i=0; i<m; i++){
					fs[j][i]=sc.nextInt();
				}
			}
			solveSmall();
		}
	}

	void solveSmall(){
		PriorityQueue<P> que=new PriorityQueue<P>();
		que.offer(new P(0, 0, 0));

		boolean[][] visited=new boolean[n][m];
		visited[0][0]=true;

		double[][] ds=new double[n][m];
		for(int i=0; i<n; i++){
			fill(ds[i], Double.MAX_VALUE);
		}
		ds[0][0]=0;

		int[] dx={0, 0, -1, 1};
		int[] dy={-1, 1, 0, 0};

		for(; !que.isEmpty();){
			P p=que.poll();
			debug(p.x, p.y, p.t, caze);
			if(p.x==m-1&&p.y==n-1){
				debug(""+caze);
				answer(""+p.t);
				return;
			}
			if(p.t>ds[p.y][p.x]+EPS){
				continue;
			}
			for(int k=0; k<4; k++){
				int x=p.x+dx[k];
				int y=p.y+dy[k];
				if(x>=0&&x<m&&y>=0&&y<n&&ok(p.x, p.y, x, y)){
					double t=time(p.x, p.y, x, y, p.t);
					if(nowait(p.x, p.y, x, y, p.t)){
						debug("p", x, y);
						if(0+EPS<ds[y][x]){
							que.offer(new P(x, y, 0));
							ds[y][x]=0;
						}
					}else if(p.t+t+EPS<ds[y][x]){
						que.offer(new P(x, y, p.t+t));
						ds[y][x]=p.t+t;
					}
				}
			}
		}
	}

	// …‚ð‹C‚É‚¹‚¸”»’è
	boolean ok(int x1, int y1, int x2, int y2){
		boolean ok=true;
		ok&=cs[y2][x2]-fs[y2][x2]>=50;
		ok&=cs[y2][x2]-fs[y1][x1]>=50;
		ok&=cs[y1][x1]-fs[y2][x2]>=50;
		return ok;
	}

	// ‘Ò‚Â•K—v‚ ‚é‚©
	boolean nowait(int x1, int y1, int x2, int y2, double t){
		if(abs(t)>EPS){
			return false;
		}
		double t2=(50-cs[y2][x2]+h)/10.0;
		t2=max(t2, 0);
		return abs(t2)<EPS;
	}

	// …‚ª‚Ç‚±‚Ü‚Åˆø‚¯‚Î‚¢‚¢‚©
	double time(int x1, int y1, int x2, int y2, double t){
		double water=h-t*10;
		double t2=(50-cs[y2][x2]+water)/10.0;
		t2=max(t2, 0);
		water-=t2*10;
		if((water-fs[y1][x1])+EPS>20){
			t2+=1;
		}else{
			t2+=10;
		}
		return t2;
	}

	class P implements Comparable<P>{
		int x, y;
		double t;

		P(int x, int y, double t){
			this.x=x;
			this.y=y;
			this.t=t;
		}

		@Override
		public int compareTo(P p){
			return Double.compare(t, p.t);
		}
	}

	void solveLarge(){

	}

	void answer(String s){
		println("Case #"+caze+": "+s);
	}

	void println(String s){
		System.out.println(s);
	}

	void print(String s){
		System.out.print(s);
	}

	void debug(Object... os){
		System.err.println(deepToString(os));
	}

	public static void main(String[] args){
		try{
			System.setIn(new FileInputStream("dat/B-small.in"));
			System.setOut(new PrintStream(new FileOutputStream(
					"dat/B-small.out")));
		}catch(Exception e){}
		new B().run();
		System.out.flush();
		System.out.close();
	}
}

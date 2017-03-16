package gcj2012.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class B {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2012/r1b";
	final String PROBLEM = "B";
	
	int[][][] dist;
	int INF = 1<<29;
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[][] d = {{-1,0},{0,1},{1,0},{0,-1}};
		for(int CASE=1;CASE<=T;CASE++){
			int H = sc.nextInt(), h = sc.nextInt(), w = sc.nextInt();
			int[][] ceil = new int[h][w], floor = new int[h][w];
			for(int i=0;i<h;i++)for(int j=0;j<w;j++)ceil[i][j]=sc.nextInt();
			for(int i=0;i<h;i++)for(int j=0;j<w;j++)floor[i][j]=sc.nextInt();
			boolean[][] canReach = new boolean[h][w];
			canReach[0][0] = true;
			Queue<int[]> l = new LinkedList<int[]>();
			l.add(new int[]{0, 0});
			while(!l.isEmpty()){
				int[] V = l.poll();
				int pi = V[0], pj = V[1];
				for(int k=0;k<4;k++){
					int ni = pi+d[k][0], nj = pj+d[k][1];
					if(!(0<=ni&&ni<h&&0<=nj&&nj<w))continue;
					if(canReach[ni][nj])continue;
					int myF = Math.max(floor[pi][pj], H);
					int opF = Math.max(floor[ni][nj], H);
					if(myF<=ceil[ni][nj]-50&&opF<=ceil[ni][nj]-50&&opF<=ceil[pi][pj]-50){
						canReach[ni][nj] = true; l.add(new int[]{ni, nj});
					}
				}
			}
			dist = new int[h][w][H+1];
			for(int i=0;i<h;i++)for(int j=0;j<w;j++)for(int k=0;k<=H;k++)dist[i][j][k]=INF;
			PriorityQueue<int[]> q = new PriorityQueue<int[]>(h*w, new Comparator<int[]>() {
				public int compare(int[] o1, int[] o2) {
					return dist[o1[0]][o1[1]][o1[2]] - dist[o2[0]][o2[1]][o2[2]];
				}
			});
			for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(canReach[i][j]){
				dist[i][j][H]=0;
//				System.out.println("i:"+i+" j:"+j);
				q.add(new int[]{i, j, H});
			}
			while(!q.isEmpty()){
				int V[] = q.poll();
				int pi = V[0], pj = V[1], waterLevel = V[2], nowCost = dist[pi][pj][waterLevel];
				//stay here
				if(0<waterLevel&&nowCost+1<dist[pi][pj][waterLevel-1]){
					dist[pi][pj][waterLevel-1] = nowCost+1;
					q.add(new int[]{pi, pj, waterLevel-1});
				}
				int myF = Math.max(floor[pi][pj], waterLevel), restWater = Math.max(0, waterLevel-floor[pi][pj]);
				for(int k=0;k<4;k++){
					int ni = pi+d[k][0], nj = pj+d[k][1];
					if(!(0<=ni&&ni<h&&0<=nj&&nj<w))continue;
					int opF = Math.max(floor[ni][nj], waterLevel);
					if(myF<=ceil[ni][nj]-50&&opF<=ceil[ni][nj]-50&&opF<=ceil[pi][pj]-50){
						int W = nowCost;
						boolean speedy = 20<=restWater;
						if(speedy)W+=10;
						else W+=100;
						int nh = Math.max(0, waterLevel-(speedy?10:100));
						if(W < dist[ni][nj][nh]){
							dist[ni][nj][nh] = W;
							q.add(new int[]{ni, nj, nh});
						}
					}
				}
			}
			double min = INF;
			for(int i=0;i<=H;i++)min = Math.min(min, dist[h-1][w-1][i]/10.0);
			System.out.print("Case #"+CASE+": ");
			System.out.printf("%.6f\n", min);
		}
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}

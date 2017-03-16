import java.util.*;

class B{



	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();		
		for(int kase = 1; kase<=T; kase++){
			int N = sc.nextInt();
			int M = sc.nextInt();
			sc.nextLine();
			PriorityQueue<Point> pq = new PriorityQueue<Point>(N*M);
			int[][] lawn = new int[N][M];
			for(int i = 0; i<N; i++){
				for(int j = 0; j<M; j++){
					lawn[i][j] = sc.nextInt();
					pq.add(new Point(i,j,lawn[i][j]));
				}
				sc.nextLine();	
			}
			boolean ok = true;
			while(!pq.isEmpty()){
				Point p = pq.poll();
				if(!row(lawn, p.x,p.y) && !col(lawn, p.x,p.y)){ok = false;}//System.out.println("x:"+p.x+" y:"+p.y);}
			}
			if(ok) System.out.println("Case #"+kase+": YES");
			else System.out.println("Case #"+kase+": NO");
		}
	}

	static boolean row(int[][] l, int i, int j){
		for(int k = 0; k<l[0].length; k++)
			if(l[i][k]>l[i][j]) return false;
		return true;
	}
	static boolean col(int[][] l, int i, int j){
		for(int k = 0; k<l.length; k++)
			if(l[k][j]>l[i][j]) return false;
		return true;
	}
}
	class Point implements Comparable<Point>{
		int x;int y; int value;
		public Point(int x, int y, int v){
			this.x = x; this.y = y; this.value = v;
		}
		public int compareTo(Point p){
			return value-p.value;
		}
	}


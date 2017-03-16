import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Pogo{
	static int[] dx = {0, 1, 0, -1};
	static int[] dy = {1, 0, -1, 0};
	static int n;
	static boolean range(int i, int j){
		return i>=-1000 && j>=-1000 && i<=1000 && j<=1000;
	}
	public static void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(out));
		int t = Integer.valueOf(br.readLine());
		for(int tt=0; tt<t; tt++){
			String[] ss = br.readLine().trim().split("\\s+");
			int x = Integer.valueOf(ss[0]);
			int y = Integer.valueOf(ss[1]);
			boolean[][] visited = new boolean[2001][2001];
			int[][] pred = new int[2001][2001];
			LinkedList<Point> queue = new LinkedList<Point>();
			boolean found = false;
			int jump = 1;
			visited[1000][1000] = true;
			pred[1000][1000] = -1;
			queue.addLast(new Point(0, 0));
			
			for(int k=1; !found; k++){
				LinkedList<Point> tmp = new LinkedList<Point>();
				
				while(!found && !queue.isEmpty()){
					Point curr = queue.removeFirst();
					// out.printf("curr.x=%d curr.y=%d\n", curr.x, curr.y);
					for(int i=0; i<4; i++){
						Point next = new Point(curr.x+k*dx[i], curr.y+k*dy[i]);
						if(range(next.x, next.y) && !visited[next.x+1000][next.y+1000]){
							visited[next.x+1000][next.y+1000] = true;
							pred[next.x+1000][next.y+1000] = i;
							tmp.addLast(next);
							// out.printf("\tnext.x=%d next.y=%d pred=%d\n", next.x, next.y, pred[next.x+1000][next.y+1000]);
							if(next.x==x && next.y==y){
								found = true;
								jump = k;
								break;
							}
						}
					}
				}
				while(!tmp.isEmpty())	queue.addLast(tmp.removeFirst());
			}
			LinkedList<Character> path = new LinkedList<Character>();
			int xx = x, yy= y;
			while(true){
				// out.printf("xx=%d yy=%d pred=%d jump=%d\n", xx, yy, pred[xx+1000][yy+1000], jump);
				if(pred[xx+1000][yy+1000]==-1)	break;
				switch(pred[xx+1000][yy+1000]){
					case 0:
						path.addLast('N');
						yy-=jump;
					break;
					case 1:
						path.addLast('E');
						xx-=jump;
					break;
					case 2:
						path.addLast('S');
						yy+=jump;
					break;
					case 3:
						path.addLast('W');
						xx+=jump;
				}
				jump--;
			}
			out.printf("Case #%d: ", tt+1);
			while(!path.isEmpty())
				out.print(path.removeLast());
			out.println();
			// out.println(path);
			// out.println("???");
			
		}
		bw.flush();
	}
	static class Point{
		int x, y;
		Point(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
}

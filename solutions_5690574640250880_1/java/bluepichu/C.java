// Java Shell by Matthew Savage

import java.io.*;
import java.math.*;
import java.util.*;

public class C{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.println("Case #" + t + ":");
			StringTokenizer st = getst(br);
			
			int r = nextInt(st);
			int c = nextInt(st);
			int m = nextInt(st);
			
			char[][] grid = new char[r][c];
			
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					grid[i][j] = '*';
				}
			}
			
			int cnt = r*c-m;
			
			if(m != r*c-1){
				LinkedList<Point> queue = new LinkedList<Point>();
				LinkedList<Point> queue2 = new LinkedList<Point>();
				queue.add(new Point(0, 0));
				
				while(!queue.isEmpty() || !queue2.isEmpty()){
					Point p = null;
					boolean notFromQueue = false;
					if(!queue.isEmpty()){
						p = queue.poll();
					} else {
						p = queue2.poll();
						notFromQueue = true;
					}
					int tmp = 0;
					for(int dx = -1; dx <= 1; dx++){
						for(int dy = -1; dy <= 1; dy++){
							if(p.x + dx >= 0 && p.x + dx < r && p.y + dy >= 0 && p.y + dy < c){
								if(grid[p.x+dx][p.y+dy] == '*'){
									tmp++;
								}
							}
						}
					}
					if(tmp <= cnt){
						if((cnt-tmp)%2 == 0 || notFromQueue || cnt == r*c-m){
							for(int dx = -1; dx <= 1; dx++){
								for(int dy = -1; dy <= 1; dy++){
									if(p.x + dx >= 0 && p.x + dx < r && p.y + dy >= 0 && p.y + dy < c){
										if(grid[p.x+dx][p.y+dy] == '*'){
											grid[p.x+dx][p.y+dy] = '.';
											cnt--;
											queue.add(p.translate(dx, dy));
										}
									}
								}
							}
						} else {
							queue2.add(p);
						}
					}
					if(cnt == 0){
						break;
					}
				}
			} else {
				cnt = 0;
			}
			
			grid[0][0] = 'c';
			
			if(cnt == 0){
				for(int i = 0; i < r; i++){
					for(int j = 0; j < c; j++){
						pw.print(grid[i][j]);
					}
					pw.println();
				}
			} else {
				pw.println("Impossible");
			}
		}
		
		br.close();
		pw.close();
	}
	
	static class Point{
		public int x;
		public int y;
		
		public Point(int mx, int my){
			x = mx;
			y = my;
		}
		
		public Point translate(int dx, int dy){
			return new Point(x + dx, y + dy);
		}
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}
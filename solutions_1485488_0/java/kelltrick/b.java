import java.io.*;
import java.util.*;
public class b{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int nc = sc.nextInt();
		for(int tc = 1; tc <= nc; tc++){
			int h = sc.nextInt();
			int m = sc.nextInt();
			int n = sc.nextInt();
			
			int[][] celi = new int[n][m];
			int[][] floor = new int[n][m];
		
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					celi[i][j] = sc.nextInt();
				}
			}
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					floor[i][j] = sc.nextInt();
				}
			}
			
			int[][] minTime = new int[n][m];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					minTime[i][j] = 999999999;
				}
			}
			
			Queue<GridPoint> startbfs = new LinkedList<GridPoint>();
			startbfs.offer(new GridPoint(0,0,0));
			Queue<GridPoint> toDo = new LinkedList<GridPoint>();
			toDo.offer(new GridPoint(0,0,0));
			while(!startbfs.isEmpty()){
				GridPoint p = startbfs.poll();
				int i = p.x, j = p.y;
				if(minTime[i][j] == 999999999){
					minTime[i][j] = 1000000000;
					if(i > 0){
						if(isPassableWet(i, j, -1, 0, celi, floor, h)){
							toDo.offer(new GridPoint(i-1,j,0));				
							startbfs.offer(new GridPoint(i-1,j,0));							
						}
					}
					
					if(j > 0){
						if(isPassableWet(i, j, 0, -1, celi, floor, h)){
							
							toDo.offer(new GridPoint(i,j-1,0));	
							startbfs.offer(new GridPoint(i,j-1,0));										
						}
					}
										
					if(i + 1 < n){
						if(isPassableWet(i, j, 1, 0, celi, floor, h)){
							toDo.offer(new GridPoint(i+1,j,0));	
							startbfs.offer(new GridPoint(i+1,j,0));									
						}
					}
					
						
					if(j + 1 < m){
						if(isPassableWet(i, j, 0, 1, celi, floor,h )){
							toDo.offer(new GridPoint(i,j+1,0));		
							startbfs.offer(new GridPoint(i,j+1,0));				
						}
					}
				}
			}
			
			
			
			while(!toDo.isEmpty()){
				GridPoint p = toDo.poll();
				int i = p.x, j = p.y;
				if(minTime[i][j] > p.t){
					minTime[i][j] = p.t;
					if(i > 0){
						if(isPassable(i, j, -1, 0, celi, floor)){
							int passTime = getMinPassTime(i, j, -1, 0, celi, floor, h);
							int start = Math.max(passTime,p.t);
							int endTime = 0;
							if((h-start) - floor[i][j] >= 20) endTime = start + 10;
							else endTime = start + 100;
							
							toDo.offer(new GridPoint(i-1,j,endTime));							
						}
					}
					
					if(j > 0){
						if(isPassable(i, j, 0, -1, celi, floor)){
							int passTime = getMinPassTime(i, j, 0, -1, celi, floor, h);
							int start = Math.max(passTime,p.t);
							int endTime = 0;
							if((h-start) - floor[i][j] >= 20) endTime = start + 10;
							else endTime = start + 100;
							
							toDo.offer(new GridPoint(i,j-1,endTime));							
						}
					}
										
					if(i + 1 < n){
						if(isPassable(i, j, 1, 0, celi, floor)){
							int passTime = getMinPassTime(i, j, 1, 0, celi, floor, h);
							int start = Math.max(passTime,p.t);
							int endTime = 0;
							if((h-start) - floor[i][j] >= 20) endTime = start + 10;
							else endTime = start + 100;
							
							toDo.offer(new GridPoint(i+1,j,endTime));							
						}
					}
					
						
					if(j + 1 < m){
						if(isPassable(i, j, 0, 1, celi, floor)){
							int passTime = getMinPassTime(i, j, 0, 1, celi, floor, h);
							int start = Math.max(passTime,p.t);
							int endTime = 0;
							if((h-start) - floor[i][j] >= 20) endTime = start + 10;
							else endTime = start + 100;
							
							toDo.offer(new GridPoint(i,j+1,endTime));							
						}
					}
				}				
			}
			
			double ans = minTime[n-1][m-1]/10.0;
			
			System.out.printf("Case #%d: %.1f\n", tc, ans);
			
		}
	}
	public static boolean isPassable(int i, int j, int di, int dj, int[][] celi, int[][] floor){
		return (celi[i+di][j+dj] - floor[i+di][j+dj] > 50 && celi[i][j] - floor[i+di][j+dj] > 50 && celi[i+di][j+dj] - floor[i][j] > 50);
	}
	public static boolean isPassableWet(int i, int j, int di, int dj, int[][] celi, int[][] floor, int h){
		return (celi[i+di][j+dj] - Math.max(h,floor[i+di][j+dj]) > 50 && celi[i][j] - Math.max(h,floor[i+di][j+dj]) > 50 && celi[i+di][j+dj] - Math.max(h,floor[i][j]) > 50);
	}
	public static int getMinPassTime(int i, int j, int di, int dj, int[][] celi, int[][] floor, int h){
		int goToCheck = celi[i+di][j+dj] - 50;
		int headCheck = celi[i][j] - 50;
		int min = Math.min(goToCheck, headCheck);
		int ans = h - min;
		if(ans > 0) return ans;
		return 0;		
	}
}

class GridPoint{
	int x,y;
	int t;
	public GridPoint(int X, int Y, int T){
		x = X;
		y = Y;
		t = T;
	}
}

//n** {{4 200 1 2 250 233 180 100 100 3 3 500 500 500 500 500 600 500 140 1000 10 10 10 10 10 490 10 10 10 100 3 3 500 100 500 100 100 500 500 500 500 10 10 10 10 10 10 10 10 10 100 2 2 1000 1000 1000 1000 100 900 900 100}}

//n** {{1 200 1 2 250 233 180 100}}


//n** {{1 100 3 3 500 500 500 500 500 600 500 140 1000 10 10 10 10 10 490 10 10 10}}

//n** {{1 100 3 3 500 100 500 100 100 500 500 500 500 10 10 10 10 10 10 10 10 10}}

//n** {{1 100 2 2 1000 1000 1000 1000 100 900 900 100


import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Test1 {
	static int MAX_LEVEL = 100;
	static int MAX = MAX_LEVEL * 2;
	static int MAX_X = MAX;
	static int MAX_Y = MAX;
	static int OFFSET = MAX_LEVEL;
	static Point[][] arr = new Point[MAX_X+1][MAX_Y+1];
	
	public static void main(String args[]){
		for (int i = 0; i <= MAX_X; i++)
			for (int j = 0; j <= MAX_Y; j++)
				arr[i][j] = new Point(i-OFFSET,j-OFFSET);
		
		go(0, 0, 0, "");
		
		try {
			Scanner sc = new Scanner(new FileReader("input.txt"));
			int T = sc.nextInt();
			String p;
			int X,Y;
			for (int ccc=0;ccc<T;ccc++){
				X = sc.nextInt();
				Y = sc.nextInt();
				p = arr[X+OFFSET][Y+OFFSET].getMinPath();
				System.out.println("Case #"+(ccc+1)+": "+p);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		
		
//		String p;
//		for (int i1 = 0; i1 <= MAX_X; i1++){
//			for (int j1 = 0; j1 <= MAX_Y; j1++){
//				p = arr[i1][j1].getMinPath();
//				System.out.println("x:"+(i1-OFFSET)+",y:"+(j1-OFFSET)+",path:"+p);
//			}
//			System.out.println("");
//		}
		
		
//		arr[3+OFFSET][4+OFFSET].printPaths();
//		pr("");
//		arr[-3+OFFSET][4+OFFSET].printPaths();
	}
	
	static void go(int x, int y, int level, String route){
		int rx = x + OFFSET;
		int ry = y + OFFSET;
		if (level > MAX_LEVEL)
			return;
		if (rx > MAX_X || rx < 0)
			return;
		if (ry > MAX_Y || ry < 0)
			return;
		
		Point p = arr[rx][ry];
		boolean r = p.addRoute(route);
		if (!r)
			return;
		
//		int step = 2^(level);
		int step = level + 1;
		
		go(x, y+step, level + 1, route+"N");
		go(x, y-step, level + 1, route+"S");
		go(x+step, y, level + 1, route+"E");
		go(x-step, y, level + 1, route+"W");
	}
	
	static void pr(String s){
		System.out.println(s);
	}
	static void pr(int s){
		System.out.println(s);
	}
}

class Point{
	public int x;
	public int y;
//	public ArrayList<String> pathArr;
	public String minPath;
	Point (int x, int y){
		this.x = x;
		this.y = y;
//		pathArr = new ArrayList<String>();
		this.minPath = "";
	}
	public boolean addRoute(String r){
		if (this.minPath == ""){
			this.minPath = r;
			return true;
		}
		else if (this.minPath.length() > r.length()){
			this.minPath = r;
			return true;
		}
		return false;
//		this.pathArr.add(r);
	}
	public String getMinPath(){
		return this.minPath;
		
//		if (pathArr.size() == 0)
//			return "(empty)";
//		
//		int max = 999999999;
//		String minPath = "";
//		for(String p:this.pathArr){
//			if (p.length() < max){
//				max = p.length();
//				minPath = p;
//			}
//		}
//		return minPath;
	}
//	public void printPaths(){
//		for(String p:this.pathArr)
//			System.out.println(p);
//	}
}
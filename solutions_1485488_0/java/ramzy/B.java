import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;


public class B {

	static int H;
	static int N;
	static int M;
	
	static int[][] c;
	static int[][] f;
	
	static double t;
	
	static boolean[][] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader("src/B.in"));
		PrintWriter output = new PrintWriter("src/B.out");
		
		String line = input.readLine();
		int T = Integer.valueOf(line);
		for(int j = 1; j <= T; j++) {
			int[] arr = intArray(input.readLine());
			H = arr[0];
			N = arr[1];
			M = arr[2];
			c = new int[N][M];
			f = new int[N][M];
			visited = new boolean[N][M];
			for(int i = 0; i < N; i++) {
				c[i] = arr = intArray(input.readLine());
				Arrays.fill(visited[i], false);
			}
			for(int i = 0; i < N; i++) {
				f[i] = arr = intArray(input.readLine());
			}
			t = -1;
			visited[0][0] = true;
			start(0, 0, 0, H);
		
			String outputLine = "Case #" + j + ": " + t;
			output.println(outputLine);
			System.out.println(outputLine);
		}
		input.close();
		output.close();
	}
	
	static void start(int x, int y, double time, int water) {
		double T = time;
		int W = water;
		if(t == 0) return;
		if(x == N-1 && y == M-1) {
//			System.out.println(time);
			if(t < 0)
				t = time;
			else if(t > time)
				t = time;
			return;
		}
		int x1 = x+1;
		int y1 = y;
		if(canPass(x,y,x1,y1)) {
			visited[x1][y1] = true;
			double w = wait(x, y, x1, y1, water);
			time += w;
			if(time != 0) {
				water -= w*10;
				time++;
				if(water < 0) water = 0;
				if(water - f[x][y] < 20) {
					time += 9;
					water -= 90;
				}
				water -= 10;
			}
			start(x1,y1, time, water);
			visited[x1][y1] = false;
		}
		time = T;
		water = W;
		x1 = x-1;
		y1 = y;
		if(canPass(x,y,x1,y1)) {
			visited[x1][y1] = true;
			double w = wait(x, y, x1, y1, water);
			time += w;
			if(time != 0) {
				water -= w*10;
				time++;
				if(water - f[x][y] < 20) {
					time += 9;
					water -= 90;
				}
				water -= 10;
			}
			start(x1,y1, time, water);
			visited[x1][y1] = false;
		}
		time = T;
		water = W;
		x1 = x;
		y1 = y+1;
		if(canPass(x,y,x1,y1)) {
			visited[x1][y1] = true;
			double w = wait(x, y, x1, y1, water);
			time += w;
			if(time != 0) {
				water -= w*10;
				time++;
				if(water - f[x][y] < 20) {
					time += 9;
					water -= 90;
				}
				water -= 10;
			}
			start(x1,y1, time, water);
			visited[x1][y1] = false;
		}
		time = T;
		water = W;
		x1 = x;
		y1 = y-1;
		if(canPass(x,y,x1,y1)) {
			visited[x1][y1] = true;
			double w = wait(x, y, x1, y1, water);
			time += w;
			if(time != 0) {
				water -= w*10;
				time++;
				if(water - f[x][y] < 20) {
					time += 9;
					water -= 90;
				}
				water -= 10;
			}
			start(x1,y1, time, water);
			visited[x1][y1] = false;
		}
	}
	
	private static double wait(int x, int y, int x1, int y1, int water) {
		if(water <= 0) 
			return 0;
		if(c[x1][y1] - water >= 50) {
			return 0;
		} else {
			System.out.println((50 - c[x1][y1] + water) / 10.0);
			return (50 - c[x1][y1] + water) / 10.0;
		}
	}

	static boolean canPass(int i1, int i2, int j1, int j2) {
		if(j1 < 0 || j2 < 0 || j1 >= N || j2 >= M) return false;
		
		if(visited[j1][j2])
			return false;
		
		if(c[j1][j2] - f[i1][i2] < 50)
			return false;
		else if (c[j1][j2] - f[j1][j2] < 50)
			return false;
		else if (c[i1][i2] - f[j1][j2] < 50)
			return false;
		else
			return true;
	}
	
	static int[] intArray(String line) {
		String[] stringArray = line.split(" ");
		int[] intArray = new int[stringArray.length];
		for(int i = 0; i < stringArray.length; i++) {
			intArray[i] = Integer.valueOf(stringArray[i]);
		}
		return intArray;
	}
}

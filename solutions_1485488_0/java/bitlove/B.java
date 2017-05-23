import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class B {
	
	public static int[][] choices= {{-1 , 0}, {1, 0}, {0, 1} , {0 , -1}};
	
	public static double best = Double.MAX_VALUE;
	public static void solve(int N , int M , int[][] ceiling, int[][] floor, double t, double initwater, int i , int j, boolean[][] visited, boolean waterdown){
		if(i == M - 1 && j == 0){
			if(t < best){
				best = t;
			}
			return ;
		}

		if(t >= best)
			return;
		
		double water = initwater;
		if(waterdown)
			water = initwater - 10 * t < 0 ? 0 : initwater - 10 * t;
		double currc = ceiling[i][j];
		double currf = floor[i][j];
		for(int k = 0 ; k < 4 ; k ++){
			int nexti = i + choices[k][0];
			int nextj = j + choices[k][1];
			if(nexti >= 0 && nexti < M && nextj >= 0 && nextj < N){
				if(visited[nexti][nextj])
					continue;
				double nextc = ceiling[nexti][nextj];
				double nextf = floor[nexti][nextj];
				
				if(nextc - nextf < 50 || nextc - currf < 50 || currc - nextf < 50){
				}
				else if(nextc - water < 50){
					double nt = (water - nextc + 50) / 10.0;
					if(nextc - 50 - currf >= 20){
						nt = nt + 1.0;
					}else{
						nt = nt + 10.0;
					}
					visited[nexti][nextj] = true;
					solve(N , M , ceiling, floor, t + nt , initwater, nexti , nextj , visited, true);
					visited[nexti][nextj] = false;
				}else{
					double nt = 0;
					if(waterdown){
						if(water - currf >= 20){
							nt = 1.0;
						}else{
							nt = nt + 10.0;
						}
					}
					visited[nexti][nextj] = true;
					solve(N , M , ceiling, floor, t + nt , initwater, nexti , nextj , visited, waterdown);
					visited[nexti][nextj] = false;
				}
			}
		}
			
	}
	
	public static double solve(int H, int N , int M , int[][] ceiling, int[][] floor){
		best = Double.MAX_VALUE;
		int starti = 0, startj = N - 1;
		
		boolean[][] visited = new boolean[M][N];
		for(int i = 0 ; i < M ; i ++){
			for(int j = 0 ; j < N ; j ++){
				visited[i][j] = false;
			}
		}
		solve(N , M , ceiling , floor, 0 , (double)H , starti , startj , visited, false);
		return best;
	}
	
	public static void main(String args[]) throws IOException{
	//	BufferedReader reader = new BufferedReader(new FileReader(new File("/home/useruser/datacollection/input/1485488_0.in")));
		BufferedReader reader = new BufferedReader(new FileReader(new File("/home/useruser/datacollection/input/1485488_0.in")));
	//	BufferedReader reader = new BufferedReader(new FileReader(new File("/home/useruser/datacollection/input/1485488_0.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("B.txt")));
		String line = reader.readLine();
		int T = Integer.parseInt(line);
		for(int i = 0 ; i < T ; i ++){
			System.out.println(i);
			line = reader.readLine();
			String tokens[] = line.split("\\s+");
			int H = Integer.parseInt(tokens[0]);
			int N = Integer.parseInt(tokens[1]);
			int M = Integer.parseInt(tokens[2]);
			
			int[][] ceiling = new int[M][N];
			for(int j = 0 ; j < N ; j ++){
				line = reader.readLine();
				tokens = line.split("\\s+");
				for(int k = 0 ; k < M ; k ++){
					ceiling[k][N -1 - j] = Integer.parseInt(tokens[k]);
				}
			}
			
			int[][] floor = new int[M][N];
			for(int j = 0 ; j < N ; j ++){
				line = reader.readLine();
				tokens = line.split("\\s+");
				for(int k = 0 ; k < M ; k ++){
					floor[k][N -1 - j] = Integer.parseInt(tokens[k]);
				}
			}
			
			double result = solve(H , N , M, ceiling , floor);
			writer.write("Case #" + (i + 1) + ": " + result + "\r\n");
		}
		reader.close();
		writer.close();
	}

}

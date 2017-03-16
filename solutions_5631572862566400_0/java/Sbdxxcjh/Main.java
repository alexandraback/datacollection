import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner input = new Scanner(System.in);
		PrintWriter writer = new PrintWriter("output", "UTF-8");
		int T = input.nextInt();
		for(int i = 1; i <= T; i++){
			int N = input.nextInt();
			int BFF[] = new int[N+1];
			int dis[] = new int[N+1];
			for(int j = 1; j <= N; j++){
				BFF[j] = input.nextInt();
			}
			// start point
			int max = 0;
			for(int j = 1; j <= N; j++){
				for(int k = 1; k <= N; k++) dis[k] = -1;
				int curr = j;
				int count = 0;
				// not visited
				int prev = 0;
				while(dis[curr] == -1){
					dis[curr] = count++;
					prev = curr;
					curr = BFF[curr];
				}
				int distance = count - dis[curr];
				// form a small cycle
				if(distance == 2){
					distance = count;
					// reverse find who connects to prev
					distance += find(prev, dis, BFF);
					distance += find2(dis, BFF);
				}
				max = Math.max(max, distance);
			}
			writer.println(String.format("Case #%d: %d", i, max));
		}
		writer.close();
		input.close();
	}
	public static int find2(int dis[], int BFF[]){
		int[] newDis = dis.clone();
		int count = 0;
		for(int i = 1; i < newDis.length; i++){
			if(BFF[BFF[i]] == i && dis[i] == -1) count++;
		}
		return count;
	}
	public static int find(int idx, int dis[], int BFF[]){
		int count = 0;
		// base condition
		for(int i = 1; i < dis.length; i++){
			if(BFF[i] != idx || dis[i] != -1) continue;
			dis[i] = 0;
			count = Math.max(find(i, dis, BFF) + 1, count);
			dis[i] = -1;
		}
		return count;
	}
	public static void foo2(String[] args) throws Exception{
		Scanner input = new Scanner(System.in);
		PrintWriter writer = new PrintWriter("output", "UTF-8");
		int T = input.nextInt();
		for(int i = 1; i <= T; i++){
			int N = input.nextInt();
			// read each line
			boolean line[] = new boolean[2501];
			for(int j = 0; j < line.length; j++) line[j] = true;// true means even
			for(int j = 0; j < 2 * N - 1; j++){
				// read each int
				for(int k = 0; k < N; k++){
					int n = input.nextInt();
					line[n] = (line[n] == false);// flip the value
				}
				
			}
			writer.print("Case #" + i + ":");
			for(int j = 1; j < line.length; j++){
				if(line[j] == false) writer.print(" " + j);
			}
			writer.println();
		}
		input.close();
		writer.close();
	}
	
	public static void foo1(String[] args) throws Exception {
		Scanner input = new Scanner(System.in);
		PrintWriter writer = new PrintWriter("output", "UTF-8");
		
		int T = input.nextInt();
		for(int i = 1; i <= T; i++){
			String s = input.next();
			String re = "";
			for(int j = 0; j < s.length(); j++){
				if(j == 0) re = String.valueOf(s.charAt(j));
				else{
					char c = s.charAt(j);
					if(c >= re.charAt(0)){
						re = c + re;
					}else{
						re = re + c;
					}
				}
			}
			writer.println(String.format("Case #%d: %s", i, re));
			
		}
		writer.close();
		input.close();
	}
}

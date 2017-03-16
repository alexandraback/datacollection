import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class A {
	static boolean _gameFinished = true;
	static int i;
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		outer:
		for(i=1; i<=n; i++){
			// Build graph
			char[][] graph = new char[4][4];
			for(int line = 0; line<4; line++){
				graph[line] = br.readLine().toCharArray();
			}
			br.readLine();
			
			// Check who won
			_gameFinished = true;
			
			// Do rows
			for(int row = 0; row<4; row++){
				if(check(graph[row])!=0) continue outer;
			}
			
			// Do columns
			for(int col = 0; col<4; col++){
				char[] column = {graph[0][col],graph[1][col],graph[2][col],graph[3][col]};
				if(check(column)!=0) continue outer;
			}
			
			// Do diagnoals
			char[] diag1 = {graph[0][0],graph[1][1],graph[2][2],graph[3][3]};
			if(check(diag1)!=0) continue outer;
			
			char[] diag2 = {graph[0][3],graph[1][2],graph[2][1],graph[3][0]};
			if(check(diag2)!=0) continue outer;
			
			if(!_gameFinished) {
				System.out.println("Case #" + i +": Game has not completed");
			} else {
				System.out.println("Case #" + i +": Draw");
			}
		}
		
		
	}
	
	private static int check(char[] line){
		int x = 0, o = 0,t = 0;
		for(char c: line){ 
			if(c=='X') x++;
			if(c=='O') o++;
			if(c=='T') t++;
			if(c=='.') _gameFinished = false;
		}
		if (x+t == 4) {
			System.out.println("Case #" + i + ": X won");
			return 1;
		} else if (o+t == 4) { 
			System.out.println("Case #" + i +": O won");
			return -1;
		}
		return 0;
	}
	
}

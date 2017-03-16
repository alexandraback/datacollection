import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class C {
	public static void main(String[] args) throws Exception{
		int t = readInt();
		for(int i = 1; i <= t; i++){
			System.out.println("Case #" + i + ":");
			int r = readInt();
			int c = readInt();
			int m = readInt();
			boolean found = true;
			boolean[][] board = new boolean[r][c];
			int free = r*c-m;
			if(r == 1){
				for(int j = 0; j < free; j++){
					board[0][j] = true;
				}
			}
			else if(c == 1){
				for(int j = 0; j < free; j++){
					board[j][0] = true;
				}
			}
			else{
				found = false;
				if(free == 1){
					found = true;
				}
				else if(free == 2 || free == 3 || free == 5 || free == 7){
					found = false;
				}
				else if((c == 2 || r == 2) && m%2 == 1){
					found = false;
				}
				else{
					free-=4;
					board[0][0] = true;
					board[0][1] = true;
					board[1][0] = true;
					board[1][1] = true;
					int dist = c;
					for(int j = 2; j < c; j++){
						if(free == 3 || free == 0){
							dist = j;
							break;
						}
						board[0][j] = true;
						board[1][j] = true;
						free-=2;
					}
					if(free == 0){
						found = true;
					}
					else{
						for(int k = 2; k < r; k++){
							for(int j = 0; j < dist; j++){
								if(free == 0){
									found = true;
									break;
								}
								if(free == 2 && dist-j < 2){
									break;
								}
								else{
									board[k][j] = true;
									free--;
								}
							}
						}
						if(free == 0){
							found = true;
						}
					}
				}
			}
			if(found){
				for(int k = 0; k < r; k++){
					for(int j = 0; j< c; j++){
						if(k == 0 && j == 0){
							System.out.print("c");
						}
						else if(board[k][j]){
							System.out.print(".");
						}
						else{
							System.out.print("*");
						}
					}
					System.out.println();
				}
			}
			else{
				System.out.println("Impossible");
			}
		}
	}

	static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer(" ");
	static String readString() throws Exception{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}
	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
	static long readLong() throws Exception {
		return Long.parseLong(readString());
	}
}

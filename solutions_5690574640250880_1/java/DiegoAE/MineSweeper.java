import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MineSweeper {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static void print(char[][] m, boolean transpose){
		int r = m.length;
		int c = m[0].length;
		if (transpose){
			for(int j = 0; j < c; j++){
				for(int i = 0; i < r; i++)
					System.out.print(m[i][j]);
				System.out.println();
			}
		}
		else{
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++)
					System.out.print(m[i][j]);
				System.out.println();
			}
		}
		return;
	}
	
	static void fill(char[][] m, char c){
		for(int i = 0; i < m.length; i++)
			Arrays.fill(m[i], '*');
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c= 1; c <= T; c++){
			int row = sc.nextInt();
			int col = sc.nextInt();
			int R = Math.min(row, col);
			int C = Math.max(row, col);
			int M = sc.nextInt();
			int emptys = R * C - M;
			System.out.println("Case #" + c + ":");
			if (emptys == 1){
				char[][] array = new char[R][C];
				fill(array, '*');
				array[0][0] = 'c';
				print(array, R != row);
				continue;
			}
			if (R == 1){
				char[][] array = new char[R][C];
				fill(array, '*');
				for(int j = 0; j < emptys; j++)
					array[0][j] = '.';
				array[0][0] = 'c';
				print(array, row != R);
				continue;
			}
			if (R == 2){
				char[][] array = new char[R][C];
				fill(array, '*');
				if (emptys <= 2 || emptys % 2 != 0)
					System.out.println("Impossible");
				else{
					for(int j = 0; j * 2 < emptys; j++)
						array[0][j] = array[1][j] = '.';
					array[0][0] = 'c';
					print(array, row != R);
				}
				continue;
			}
			// R > 2 && C > 2
			if (emptys <= 3){
				System.out.println("Impossible");
				continue;
			}
			char[][] array = new char[R][C];
			fill(array, '*');
			array[0][0] = array[0][1] = array[1][0] = array[1][1] = '.';
			int xx = 2;
			int yy = 2;
			emptys -= 4;
			while(true){
				boolean sepudo = false;
				if (xx < R && emptys >= 2){
					array[xx][0] = array[xx][1] = '.';
					emptys-=2;
					xx++;
					sepudo = true;
				}
				if (yy < C && emptys >= 2){
					array[0][yy] = array[1][yy] = '.';
					emptys -= 2;
					yy++;
					sepudo = true;
				}
				if (!sepudo)
					break;
			}
			int disponible = (xx - 2) * (yy - 2);
			if (emptys > disponible){
				System.out.println("Impossible");
				continue;
			}
			// se puede
			for(int i = 2; i < xx && emptys > 0; i++)
				for(int j = 2; j < yy && emptys > 0; j++){
					array[i][j] = '.';
					emptys--;
				}
			array[0][0] = 'c';
			print(array, row != R);
		}
	}

}

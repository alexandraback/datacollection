import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class MineSweeper {
	public static void main(String[] args) throws Exception{
		

		
		FileWriter output = new FileWriter(new File("mineOut.txt"));
		
		Scanner s = new Scanner(new File("C-small-attempt7.in"));
		String firstLine = s.nextLine();
		int numCases = Integer.parseInt(firstLine);
		for(int c = 1;c<=numCases;c++) {
			String line = s.nextLine();
			String[] lineArr = line.split(" ");
			char[][] result = solvable(Integer.parseInt(lineArr[0]),Integer.parseInt(lineArr[1]),Integer.parseInt(lineArr[2]));
			System.out.print("Case #" + c + ":\n");
			output.write("Case #" + c + ":\n");
			if(result==null) {
				System.out.print("Impossible\n");
				output.write("Impossible\n");
			} else {
				System.out.print(render(result));
				output.write(render(result));
			}
		}
		output.flush();
		output.close();
	}
	public static String render(char[][] board) {
		StringBuilder result = new StringBuilder();
		for(int i = 0;i<board.length;i++) {
			for(int j = 0;j<board[i].length;j++) {
				result.append(board[i][j]);
			}
			result.append("\n");
		}
		return result.toString();
	}
	public static char[][] solvable(int r, int c, int m) {
		int free = r*c - m;
		if(free==1) {
			char[][] result = new char[r][c];
			for(int i = 0;i<r;i++) {
				for(int j = 0;j<c;j++) {
					result[i][j] = '*';
				}
			}
			result[0][0] = 'c';
			return result;
		}
	
		if(m==0) {
			char[][] result = new char[r][c];
			for(int i = 0;i<r;i++) {
				for(int j = 0;j<c;j++) {
					result[i][j] = '.';
				}
			}
			result[0][0] = 'c';
			return result;
		}
		
		if(r==1) {
			char[][] result = new char[r][c];
			result[0][0] = 'c';
			for(int i = 1;i<free;i++) {
				result[0][i] = '.';
			}
			for(int i = free;i<c;i++) {
				result[0][i] = '*';
			}
			return result;
		}
		if(c==1) {
			char[][] result = new char[r][c];
			result[0][0] = 'c';
			for(int i = 1;i<free;i++) {
				result[i][0] = '.';
			}
			for(int i = free;i<r;i++) {
				result[i][0] = '*';
			}
			return result;
		}
		if(free==4) {
			char[][] result = new char[r][c];
			for(int i = 0;i<r;i++) {
				for(int j = 0;j<c;j++) {
					result[i][j] = '*';
				}
			}
			result[0][0] = 'c';
			result[1][0] = '.';
			result[0][1] = '.';
			result[1][1] = '.';
			return result;
		}
		
		
		
		for(int a =2;a<=r;a++) {
			for(int b = 2;b<=c;b++) {
				if(a<3 && b<3) {
					continue;
				}
				
				int freeSpace = 0;
				if(a==2 && b==2) {
					freeSpace = 5;
				} else if(a==2) {
					freeSpace = b+3;
				} else if(b==2) {
					freeSpace = a+3;
				} else {
					freeSpace = a+b+1;
				}
				if(a==r || b==c) {
					freeSpace = 0;
				}
				
				int extra = free - a*b;
				
			
				if((extra < freeSpace && (extra>1||extra==0)) || (extra==0 && freeSpace ==0)) {
					System.out.println(free + " : " + a + "x" + b + " with " + extra + " of " + freeSpace);
					return draw(r,c,a,b,extra);
					
				}
				
			}
		}
		return null;
	}
	public static char[][] draw(int r, int c,int a, int b, int extra) {
		char[][] result = new char[r][c];
		for(int i = 0;i<a;i++) {
			for(int j = 0;j<b;j++) {
				result[i][j] = '.';
			}
		}
		
		if(extra>=5) {
			result[a][b] = '.';
			extra --;
			for(int offset = 1;offset<=Math.max(a,b) && extra>0;offset++) {
				if(offset<=a) {
					result[a-offset][b] = '.';
					extra--;
				}
				if(offset<=b && extra>0) {
					result[a][b-offset] = '.';
					extra--;
				}
			}
		} else {
			if(extra>0) {
			result[0][b] = '.';
			extra--;
			}
			if(extra>0) {
			result[1][b] = '.';
			extra--;
			}
			if(extra>0) {
				result[a][0] = '.';
				extra--;
			}
			if(extra>0) {
				result[a][1] = '.';
				extra--;
			}
		}
		
		/*else if(extra <=a) {
			for(int i = 0;i<extra;i++) {
				result[i][b] = '.';
			}
		} else {
			for(int i = 0;i<extra;i++) {
				result[a][i] = '.';
			}
		}*/
		result[0][0] = 'c';
		for(int i = 0;i<r;i++) {
			for(int j = 0;j<c;j++) {
				if(result[i][j] == 0) {
					result[i][j] = '*';
				}
			}
		}
		return result;
	}
}

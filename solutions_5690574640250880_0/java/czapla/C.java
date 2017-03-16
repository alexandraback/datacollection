import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class C {
	static void printRow(int notMines, int total){
		int i = 0;
		while(i < notMines){
			System.out.print('.');
			i++;
		}
		while(i < total){
			System.out.print('*');
			i++;
		}
		System.out.println();
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int tests = Integer.parseInt(line);
		for(int i = 1; i <= tests; i++){
			line = br.readLine();
			String[] split = line.split("\\s+");
			int R = Integer.parseInt(split[0]);
			int C = Integer.parseInt(split[1]);
			int M = Integer.parseInt(split[2]);
			int notMines = R*C - M;
			System.out.println("Case #" + i + ":");
			if(((notMines == 2 || notMines == 3 || notMines == 5 || notMines == 7) && R != 1 && C != 1) || notMines == 0
				|| (notMines <= 2*C && notMines % 2 == 1 && R == 2 && notMines != 1) || (C == 2 && notMines % 2 == 1 && notMines != 1))
				System.out.println("Impossible");
			else{
				System.out.print("c");
				if(R == 1)
					printRow(notMines-1, C-1);
				else if(C == 1){
					printRow(0, 0);
					notMines--;
					for(int j = 1; j < R; j++){
						if(notMines > 0)
							printRow(1, 1);
						else
							printRow(0, 1);
						notMines--;
					}
				}
				else if((notMines <= 2*C && notMines % 2 == 0) || notMines == 1){
					printRow((notMines+1)/2-1, C-1);
					printRow(notMines/2, C);
					for(int j = 2; j < R; j++)
						printRow(0, C);
				}
				else if(notMines <= 2*C){// && notMines % 2 == 1
					notMines -= 3;
					printRow(notMines/2-1, C-1);
					printRow(notMines/2, C);
					printRow(3, C);
					for(int j = 3; j < R; j++)
						printRow(0, C);
				}
				else if(notMines == 2*C + 1){
					printRow(C-2, C-1);
					printRow(C-1, C);
					printRow(3, C);
					for(int j = 3; j < R; j++)
						printRow(0, C);
				}
				else if(notMines % C == 1){
					printRow(C-1, C-1);
					notMines -= C;
					for(int j = 1; j < R; j++){
						if(notMines <= C)
							printRow(notMines, C);
						else if(notMines <= 2*C){
							printRow(C-1, C);
							notMines++;
						}
						else
							printRow(C, C);
						notMines = Math.max(0,  notMines-C);
					}
				}
				else{
					printRow(C-1, C-1);
					notMines -= C;
					for(int j = 1; j < R; j++){
						if(notMines <= C)
							printRow(notMines, C);
						else
							printRow(C, C);
						notMines = Math.max(0,  notMines-C);
					}
				}
			}
		}
	}
}

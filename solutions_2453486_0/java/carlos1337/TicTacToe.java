import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class TicTacToe {

	public static void main(String[] args) throws Exception{
		
		Scanner sc = new Scanner(new File("A-small-attempt0 (1).in"));
		PrintWriter pw = new PrintWriter(new File("ticTac.out"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			char[][] matriz = new char[4][4];
			boolean finished = true;
			for (int j = 0; j < 4; j++) {
				String ln = sc.nextLine();
				for (int k = 0; k < 4; k++) {
					char c = ln.charAt(k);
					matriz[j][k] = c;
					if(c == '.'){
						finished = false;
					}
				}
			}
			for (int j = 0; j < matriz.length; j++) {
				System.out.println(Arrays.toString(matriz[j]));
			}
			int winner = 0;			
			// Revisar triqui horizontal
			for (int j = 0; j < matriz.length && winner==0; j++) {
				int c1 = 0;
				int c2 = 0;
				for (int j2 = 0; j2 < matriz.length; j2++) {
					if(matriz[j][j2]=='X' || matriz[j][j2]=='T'){
						c1++;
					}
					if(matriz[j][j2]=='O' || matriz[j][j2]=='T'){
						c2++;
					}
				}
				if(c1==4){
					winner = 1;
				}
				else if(c2==4){
					winner = 2;
				}				
			}
			
			
			// Revisar triqui vertical
			for (int j = 0; j < matriz.length && winner==0; j++) {
				int c1 = 0;
				int c2 = 0;
				for (int j2 = 0; j2 < matriz.length; j2++) {
					if(matriz[j2][j]=='X' || matriz[j2][j]=='T'){
						c1++;
					}
					if(matriz[j2][j]=='O' || matriz[j2][j]=='T'){
						c2++;
					}
				}
				if(c1==4){
					winner = 1;
				}
				else if(c2==4){
					winner = 2;
				}				
			}			
						
			
			// Revisar diagonales
			int c1 = 0;
			int c2 = 0;
			for (int j = 0; j < matriz.length; j++) {
				if(matriz[j][j]=='X' || matriz[j][j]=='T'){
					c1++;
				}
				if(matriz[j][j]=='O' || matriz[j][j]=='T'){
					c2++;
				}

			}
			if(c1==4){
				winner = 1;
			}
			else if(c2==4){
				winner = 2;
			}				
			
			c1 = 0;
			c2 = 0;
			for (int j = 0; j < matriz.length; j++) {
				if(matriz[j][matriz.length-j-1]=='X' || matriz[j][matriz.length-j-1]=='T'){
					c1++;
				}
				if(matriz[j][matriz.length-j-1]=='O' || matriz[j][matriz.length-j-1]=='T'){
					c2++;
				}

			}
			if(c1==4){
				winner = 1;
			}
			else if(c2==4){
				winner = 2;
			}				
			String msg="";
			if(winner==0){
				if(finished)
					msg="Draw";
				else
					msg="Game has not completed";
			}else if(winner == 1){
				msg = "X won";
			}else if(winner == 2){
				msg = "O won";
			}
			pw.println("Case #"+i+": "+msg);
						
		}					
		pw.close();
	}
	
}

import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
public class TicTacToe{
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("a.in"));
		FileWriter fw = new FileWriter("a.out");
		int t = sc.nextInt();
		for ( int i = 0 ; i < t ; i++){
			int win = 0;
			boolean hasDot = false;
			char[][] a = new char[4][];
			for ( int j = 0; j < 4; j++){
				a[j] = new char[4];
				String str = sc.next();
				System.out.println(str);
				for ( int k= 0; k < 4; k++){
					a[j][k] = str.charAt(k);
					if ( str.charAt(k) == '.' ) hasDot = true;
				}
			}
			
			int digX = 0;
			int digO = 0;
			int digXB = 0;
			int digOB = 0;
			for ( int j = 0; j < 4 ;j++){
				int rowX = 0;
				int rowO = 0;
				int colX = 0;
				int colO = 0;
				if ( a[j][j] == 'X' ) digX ++;
				if ( a[j][j] == 'O' ) digO ++;
				if ( a[j][j] == 'T' ) {
					digX ++;
					digO ++;
				}
				int pos = 3-j;
				if ( a[pos][j] == 'X' ) digXB ++;
				if ( a[pos][j] == 'O' ) digOB ++;
				if ( a[pos][j] == 'T' ) {
					digXB ++;
					digOB ++;
				}
				for ( int k = 0; k < 4; k++){
					if ( a[j][k] == 'X' )  rowX ++;
					if ( a[j][k] == 'O' ) rowO ++;
					if ( a[j][k] == 'T' ){
						rowX ++;
						rowO ++;
					}
					if ( a[k][j] == 'X' ) colX ++;
					if ( a[k][j] == 'O' ) colO ++;
					if ( a[k][j] == 'T' ){
						colX++;
						colO++;
					}
					
				}
				if ( rowX == 4 || colX == 4 ) win = 1;
				if ( rowO == 4 || colO == 4 ) win = -1;
			}
			if ( digX == 4 || digXB == 4 ) win = 1;
			if ( digO == 4 || digOB == 4 ) win = -1;
			if (win == 0 && hasDot) win = 2;
			//....Do sth here
			fw.write("Case #" + (i+1) + ": ");
			if ( win == 1 ) fw.write("X won");
			else if ( win == -1 ) fw.write("O won");
			else if ( win == 0 ) fw.write("Draw");
			else if ( win == 2 ) fw.write("Game has not completed");
			fw.write("\n");
			System.out.println();
			//System.out.println(sc.next());
		}
		fw.close();
	}
}	

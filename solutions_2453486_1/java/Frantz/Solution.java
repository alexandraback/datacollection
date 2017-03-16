import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Solution {
	String[][] cases ;
	int T ;

	public Solution() {
		Scanner sc = null;
		try {
			sc = new Scanner(new FileReader("A-large.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		T = Integer.parseInt(sc.nextLine()) ;
		cases = new String[T][4] ;
		for(int i = 0 ; i < T ; i ++) {
			for (int j = 0 ; j < 4 ; j ++) {
				cases[i][j] = sc.nextLine();
				System.out.println(cases[i][j]) ;
			}
			sc.nextLine();
			System.out.println() ;
		}
		sc.close() ;
	}
	
	public static void main(String[] args) throws IOException {
		Solution s = new Solution() ;
		PrintWriter out = new PrintWriter(new FileWriter("result.txt")) ;
		for(int i = 0 ; i < s.T ; i ++) {
			out.println("Case #"+(i+1)+": "+s.getResult(i)) ;
		}
		out.flush();
		out.close() ;
	}

	private String getResult(int i) {
		int[][] scores = new int[2][10];
		String result ;
		boolean over = true ;
		for (int j = 0 ; j < 4 ; j ++) {
			for(int k = 0 ; k < 4 ; k ++) {
				char c = cases[i][j].charAt(k) ;
				int number = 0;
				switch(c) {
				case 'O':
					number = 0 ;
					break ;
				case 'X':
					number = 1 ;
					break ;
				case 'T':
					number = -1 ;
					break ;
				case '.':
					number = -2 ;
					over = false ;
					break ;
				}
				if((number != -1)&&(number != -2)) {
					setScores(scores,number,j,k) ;
				}
				else if(number != -2){
					setScores(scores,0,j,k) ;
					setScores(scores,1,j,k) ;
				}
			}
		}
		boolean OWon = false , XWon = false;
		for(int j = 0 ; j < 10 ; j ++) {
			if(scores[0][j]==4){
				OWon = true ;
			}
			if(scores[1][j]==4){
				XWon = true ;
			}
		}
		if (OWon) return("O won") ;
		if(XWon) return ("X won") ;
		if(over) return ("Draw") ;
		return ("Game has not completed") ;
	}

	private void setScores(int[][] scores ,int number,int j, int k) {
		scores[number][k] ++ ;
		scores[number][j + 4] ++ ;
		if(j == k) {
			scores[number][8] ++ ;
		}
		if(j == (3-k)) {
			scores[number][9] ++ ;
		}
	}
}

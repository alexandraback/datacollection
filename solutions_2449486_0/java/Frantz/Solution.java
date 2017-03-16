import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Solution {
	int[][][] cases ;
	int T ;

	public Solution() {
		Scanner sc = null;
		try {
			sc = new Scanner(new FileReader("B-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		T = Integer.parseInt(sc.nextLine()) ;
		cases = new int[T][][] ;
		String[] line ;
		for(int i = 0 ; i < T ; i ++) {
			line = sc.nextLine().split(" ") ;
			int n,m ;
			n = Integer.parseInt(line[0]) ;
			m = Integer.parseInt(line[1]) ;
			cases[i] = new int[n][m] ;
			for(int j = 0 ; j < n ; j ++) {
				line = sc.nextLine().split(" ") ;
				for(int k = 0 ; k < m ; k ++) {
					cases[i][j][k] = Integer.parseInt(line[k]) ;
				}
			}
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
		int[] row = new int[cases[i].length] ;
		int[] col = new int[cases[i][0].length] ;
		
		for(int j = 0 ; j < cases[i].length ; j ++) {
			for(int k = 0 ; k < cases[i][j].length ; k ++){
				if(cases[i][j][k]>row[j]) {
					row[j] = cases[i][j][k] ;
				}
				if(cases[i][j][k]>col[k]) {
					col[k] = cases[i][j][k] ;
				}
			}
		}
		for(int j = 0 ; j < cases[i].length ; j ++) {
			for(int k = 0 ; k < cases[i][j].length ; k ++){
				if((cases[i][j][k] < row[j])&&(cases[i][j][k] < col[k])) {
					return "NO" ;
				}
			}
		}
		return "YES";
	}
}

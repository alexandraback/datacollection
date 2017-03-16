import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	char[][] a = new char[4][4];
	
	public A(BufferedReader reader) throws IOException {
		for (int i=0; i<4; i++) {
			String line = reader.readLine();
			
			//StringTokenizer token = new StringTokenizer(line, " ");

			for (int j = 0; j < 4; j++) {
				char c = line.charAt(j); //token.nextToken();
				a[i][j] = c;
			}
		}
		reader.readLine();
	}
	
	public boolean compareXY(char c, char xy) {
		if (c==xy || c=='T') {
			return true;
		}
		return false;
	}
	
	public boolean solveXY(char xy) {
		for (int i = 0; i<4; i++) {
			if (compareXY(a[i][0], xy) 
			 && compareXY(a[i][1], xy)
			 && compareXY(a[i][2], xy)
			 && compareXY(a[i][3], xy)
			 )
			 {
					return true;
			 }
			if (compareXY(a[0][i], xy) 
					 && compareXY(a[1][i], xy)
					 && compareXY(a[2][i], xy)
					 && compareXY(a[3][i], xy)
					 )
					 {
							return true;
					 }
		}
		
		if (compareXY(a[0][0], xy) 
				 && compareXY(a[1][1], xy)
				 && compareXY(a[2][2], xy)
				 && compareXY(a[3][3], xy)
				 )
				 {
						return true;
				 }
		
		if (compareXY(a[3][0], xy) 
				 && compareXY(a[2][1], xy)
				 && compareXY(a[1][2], xy)
				 && compareXY(a[0][3], xy)
				 )
				 {
						return true;
				 }
		
		return false;
	}
	
	public boolean existsDot() {
		for (int i = 0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (a[i][j] == '.') {
					return true;
				}
			}
		}
		return false;
	}
	
	public String solve() {
		if (solveXY('X')) {
			return "X won";
		}
		if (solveXY('O')) {
			return "O won";
		}
		
		if (existsDot()) {
			return "Game has not completed";
		} else {
			return "Draw";
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile
				+ ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i = 1; i <= nrLines; i++) {
			A b = new A(reader);
			out.println("Case #" + i + ": " + b.solve());
		}
		reader.close();
		out.close();
	}
	
}

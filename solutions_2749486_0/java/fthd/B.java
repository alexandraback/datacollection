import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class B{
	
	public static void main(String[] args) throws Exception{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B-small-attempt0.out"));
		//PrintStream out = System.out;
	
		String line = br.readLine();
		int T = Integer.parseInt(line);		

		for(int i=1; i<=T; i++){
			line = br.readLine();
			String[] splitLine = line.split(" ");
			int X = Integer.parseInt(splitLine[0]);
			int Y = Integer.parseInt(splitLine[1]);
			out.println("Case #" + i + ": " + solve(X, Y));
		}
		
		br.close();
		out.close();
	}
	
	static String solve(int X, int Y){
		return solveHelper(0, 0, 0, X, Y);
	}
	
	static String solveHelper(int currX, int currY, int moves, int X, int Y){
		StringBuffer s = new StringBuffer();
		
		for(int i=0; i<Math.abs(X); i++){
			if(X > 0){
				s.append("WE");
			}
			else{
				s.append("EW");
			}
		}
		
		for(int i=0; i<Math.abs(Y); i++){
			if(Y > 0){
				s.append("SN");
			}
			else{
				s.append("NS");
			}
		}
		
		return s.toString();
	}
}
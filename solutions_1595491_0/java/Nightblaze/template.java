import java.io.*;

public class template {
	public static void main(String[] args) throws IOException {
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		//PrintWriter out = new PrintWriter("output.txt");
		
		in.nextToken(); int count = (int)in.nval;
		
		for(int c = 1 ; c <= count ; c++) {
			in.nextToken(); int googlers = (int) in.nval;
			in.nextToken(); int surprisings = (int) in.nval;
			in.nextToken(); int passScore = (int) in.nval;
			
			int pass = 0;
			int passWithSurprising = 0;			

			// loop through scores
			for(int i = 0 ; i < googlers ; i++) {
				in.nextToken(); int score = (int) in.nval;
				
				int division = score / 3;
				int modulo = score % 3;
				
				if (modulo > 0) division++;
				
				if (division >= passScore) {
					pass++;
				} else if (division+1 == passScore && modulo!=1 && score!=0) {
					passWithSurprising++;
				}
			}
			
			out.println("Case #" + c + ": " + (pass + Math.min(passWithSurprising, surprisings)));
		}
		
		out.flush();
		out.close();
	}
}

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class OminousOmino {
	public static boolean gWin(int X, int R, int C) {
		System.out.println(X + "\t" + R + "\t" + C + "\t" + (R*C) % X);
		if (X == 1) return true;
		if ((R*C) % X != 0) return false;
		if (X == 2) return true;
		if (X == 3) {
			return (Integer.min(R, C) >= 2);
		}
		if (X == 4) {
			if (Integer.max(R, C) < 4) return false;
			if (Integer.min(R, C) < 3) return false;
		} 
		return true;
	}
	
	public static void solution(String inputFile, String outputFile) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File(inputFile)));
		PrintWriter pw = new PrintWriter(new FileWriter(new File(outputFile)));
		String line = br.readLine();
		int N = Integer.parseInt(line);
		
		int id = 1;
		for (int i = 0; i < N; ++i) {
			String[] a = br.readLine().split(" ");
			boolean gWin =  gWin(Integer.parseInt(a[0]), Integer.parseInt(a[1]), Integer.parseInt(a[2]));
			if (gWin) 
				pw.println("Case #"+id+": "+"GABRIEL");
			else
				pw.println("Case #"+id+": "+"RICHARD");
			id++;
		}
		br.close();
		pw.close();
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "src/OminousOmino.in";
		String outputFile = "src/OminousOmino.out";
		OminousOmino.solution(inputFile, outputFile);
	}
}

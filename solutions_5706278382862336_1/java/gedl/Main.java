import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List<String> lines = null;
		try {
			lines = Files.readAllLines(
					Paths.get("./input/input.txt"), 
					StandardCharsets.UTF_8);
		} catch (IOException e1) {
			e1.printStackTrace();
		}

		int cases = Integer.parseInt(lines.get(0));

		try {
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

			for (int i=0; i<cases; i++) {

				double[] f = readFrac(lines.get(i+1));
				out.write(output(i+1, solve(f[0], f[1])));
				out.newLine();
			}
			out.close();
		} catch (IOException e) {};
	}
	
	private static int solve(double n, double d) {
		if (Math.pow(2, 40)*n/d != Math.floor(Math.pow(2, 40)*n/d))
			return -1;
		
		int gen=1;		
		while (n/d < 1.0/Math.pow(2, gen) && gen <= 40)
			gen++;
			
		return gen;
	}
	
	private static String output(int caseNum, int result) {
		return "Case #" + caseNum + ": " + ((result==-1) ? "impossible" : "" + result);
	}
	
	private static double[] readFrac(String s) {
		String[] st = s.split("/");
		return new double[]{Double.parseDouble(st[0]), Double.parseDouble(st[1])};
	}
}
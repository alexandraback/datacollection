import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Q3 {
	public static Problem[] probs;

	static class Problem {
		public int A;
		public int B;
	}
			
	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
		System.out.println("Execution time: " + (System.currentTimeMillis()-time)/1000.0);
	}
			
	
	private static int shift(int foo, int places) {
		String fooStr = "" + foo;
		String shiftStr = fooStr.substring(fooStr.length()-places) + fooStr.substring(0, fooStr.length()-places);
		return Integer.parseInt(shiftStr);
	}
	
	private static String solveProblem(Problem p) {
		int pairs = 0;
		if (p.A<10 && p.B<10) {
			return "0";
		}
		for (int n=p.A; n<p.B; n++) {
			int shiftNum = 1;
			int testM = shift(n, shiftNum);
			while (testM!=n) {
				if (testM>n && testM<=p.B) {
					pairs++;
				}
				shiftNum++;
				testM = shift(n, shiftNum);
			}
		}
		return "" + pairs;
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				probs[i].A = Integer.parseInt(pieces[0]);
				probs[i].B = Integer.parseInt(pieces[1]);
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

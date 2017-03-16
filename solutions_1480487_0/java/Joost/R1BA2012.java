import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class R1BA2012 {

	public static void main(String[] args) throws Exception {
		new R1BA2012();
	}
	
	static final String filename = "R1B/A-small-attempt6";
	int testcases;
	
	public R1BA2012() throws Exception {
		FileReader ifile = new FileReader(filename+".in");
		Scanner scanner = new Scanner(ifile);
		testcases = (scanner.nextInt());
		FileWriter ofile = new FileWriter(filename+".out");
		for (int i = 1; i <= testcases; i++) {
			ofile.write("Case #"+i+": "+solve(scanner)+(i != testcases ? "\n" : ""));
		}
		ofile.close();
		System.out.println("Finished");
	}

	private String solve(Scanner scanner) throws Exception {
		int N = scanner.nextInt();
		int[] s = new int[N];
		double X = 0;
		for (int i = 0; i < N; i ++) {
			s[i] = scanner.nextInt();
			X += s[i];
		}
		double[] result = new double[N];
		double sumrest = 0;
		double sumY = 0;
		double divisors = 0;
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) {
			result[i] = 100 * (2 * X/N - s[i]) / X;
			if (result[i] < 0) {
				sumrest -= result[i];
				result[i] = 0;
				divisors++;
				a.add(i);
			}
			else {
				sumY += result[i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (!a.contains(i))
				result[i] -= (1 / (N-divisors)) * sumrest;
		}
		StringBuilder str = new StringBuilder();
		for (int i = 0; i < N-1;i++)
			str.append(result[i]+" ");
		str.append(result[N-1]);
		return str.toString().replace(',', '.');
	}
}

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Q4 {
	public static void main(String[] args) throws Exception {
		File fin = new File("D-large.in");
		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"D-large.out")));

		int T = in.nextInt();

		// long startTime = 0;

		for (int i = 0; i < T; i++) {
			int numblocks = in.nextInt();
			
			List<Double> naomi = new ArrayList<Double>();
			List<Double> ken = new ArrayList<Double>();
			
			for (int j = 0; j < numblocks; j++) {
				naomi.add(in.nextDouble());
			}
			for (int j = 0; j < numblocks; j++) {
				ken.add(in.nextDouble());
			}
			
			Collections.sort(naomi);
			Collections.sort(ken);
			
			int deceitcount = 0;
			int normalcount = 0;
			
			int npos = 0;
			int kpos = 0;
			for (;npos < numblocks; npos++)
			{
				if (naomi.get(npos) > ken.get(kpos)){
					deceitcount++;
					kpos++;
				}
			}
			npos = 0;
			kpos = 0;
			for (;kpos < numblocks; kpos++)
			{
				if (naomi.get(npos) < ken.get(kpos)){
					normalcount++;
					npos++;
				}
			}
			
			out.printf("Case #%d: %d %d\n", i+1, deceitcount, numblocks - normalcount);
		}

		in.close();
		out.close();
	}
}

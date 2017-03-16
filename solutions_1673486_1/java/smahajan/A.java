import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;


public class A {

	public static void main(String[] args) throws NumberFormatException, IOException {
		File file = new File(args[0]);
		BufferedReader reader = new BufferedReader(new FileReader(file));
		PrintStream printer = new PrintStream(new File("A-large.txt"));

		int T = Integer.parseInt(reader.readLine());
		
		for (int t = 1 ; t < T+1; t++) {
			String line = reader.readLine();
			String numStrArr[] = line.split(" ");
			int a = Integer.parseInt(numStrArr[0]);
			int b = Integer.parseInt(numStrArr[1]);
			b = b-a;
			
			line = reader.readLine();
			numStrArr = line.split(" ");
			double[] p = new double[a];
			for (int i = 0 ; i < a ; i++)
				p[i] = Double.valueOf(numStrArr[i]);
			// enter right away
			double ans = a + b + 2.0;
			int numBsCan = (a+1)/2;
			// keystrokes if i keep typing
			int bs = numBsCan;
			double pcorrect = 1.0;
			for (int i = 0 ; i < a - bs;i++)
				pcorrect *= p[i];
			for(;bs >= 0; bs--) {
				double localP = pcorrect * (bs + bs + b + 1);
				localP += (1-pcorrect) * (bs + bs + b + 1 + a + b + 1);
				
				if (localP < ans) ans = localP;
				
				if (bs > 0)
					pcorrect *= p[a-bs];
			}
			printer.println("Case #" + t + ": " + ans);
		}
	}
	
}

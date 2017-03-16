import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;


public class A {

	public static void main(String[] args) throws NumberFormatException, IOException {
		File file = new File(args[0]);
		BufferedReader reader = new BufferedReader(new FileReader(file));
		PrintStream printer = new PrintStream(new File("A-small.txt"));

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
			while(numBsCan >= 0) {
				double pcorrect = 1.0;
				for (int i = 0 ; i < a - numBsCan; i++) {
					pcorrect *= p[i];
				}
				double localP = pcorrect * (numBsCan + numBsCan + b + 1);
				localP += (1-pcorrect) * (numBsCan + numBsCan + b + 1 + a + b + 1);
				
				if (localP < ans) ans = localP;
				numBsCan--;
			}
			printer.println("Case #" + t + ": " + ans);
		}
	}
	
}

import java.io.*;


public class Round1A_A {

public static void main(String[] args) {
		
		BufferedReader in;
		BufferedWriter out;
		int T, i;
		String line;
		
		try {
			in = new BufferedReader(new FileReader("A-large.in"));
			out = new BufferedWriter(new FileWriter("output.txt"));
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			return;
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}

		try {
			T = Integer.parseInt(in.readLine());

			for (i = 0; i < T; i++) {
				int a, b;
				double[] p;
				
				line = in.readLine();
				
				String[] ab = line.split(" ");
				
				a = Integer.parseInt(ab[0]);
				b = Integer.parseInt(ab[1]);
				
				p = new double[a];
				
				line = in.readLine();
				
				String[] Sp = line.split(" ");
				
				
				for (int j = 0; j < a; j++) {
					p[j] = Double.parseDouble(Sp[j]);
				}
				
				String lineToWrite = "Case #" + (i+1) + ": ";
				
				lineToWrite += String.valueOf(solve(a, b, p));
				
				out.write(lineToWrite + "\n");
				
			}
			in.close();
			out.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}
	}

	public static double solve(int a, int b, double[] p) {
		double[] prBackspaces = new double[a+1];
		double[] expected = new double[a+1];
		double best = b+2;
		for (int i = 0; i < a+1; i++) {
			prBackspaces[i] = 1;
			for (int j = 0; j < (a-i); j++) {
				prBackspaces[i] *= p[j];
			}
			
			expected[i] = (b - a + (i*2) + 1) * prBackspaces[i] + (b*2 - a + (i*2) + 2) * (1-prBackspaces[i]);
			
			if (expected[i] < best) best = expected[i];
			
		}
		
		return best;
		
	}
	
}

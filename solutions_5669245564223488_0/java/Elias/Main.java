import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BigInteger MOD = new BigInteger("1000000007");

	public Main() throws IOException {
		Scanner in = new Scanner(new File("B-small-attempt2.in"));
		//Scanner in = new Scanner(new File("B-test.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("B-small.txt"));

		int amountOfTasks = in.nextInt();
		for (int task = 0; task < amountOfTasks; task++) {
			System.out.println("TASK " + (task+1));
			int N = in.nextInt();
			Wagon[] cars = new Wagon[N];
			int[][] possStart = new int[26][2];
			boolean[] availableStart = new boolean[26];
			boolean[] startPoint = new boolean[26];
			for (int i = 0; i < 26; i++) {
				startPoint[i] = true;
			}
			int[][] possEnd = new int[26][2];
			boolean[] availableEnd = new boolean[26];
			boolean[] endPoint = new boolean[26];
			for (int i = 0; i < 26; i++) {
				endPoint[i] = true;
			}
			for (int tas = 0; tas < N; tas++) {
				String xyz = in.next();
				xyz = trimIt(xyz);
				cars[tas] = new Wagon(xyz);
				Wagon w = cars[tas];
				
				if (w.start == w.end)
					possStart[w.start - 'a'][1]++;
				else
					possStart[w.start - 'a'][0]++;
				if (w.end != w.start)
					startPoint[w.end - 'a'] = false;
				availableStart[w.start - 'a'] = true;
				
				if (w.start == w.end)
					possEnd[w.end - 'a'][1]++;
				else
					possEnd[w.end - 'a'][0]++;
				if (w.end != w.start)
					endPoint[w.start - 'a'] = false;
				availableEnd[w.end - 'a'] = true;
			}

			boolean succes = true;
			for (int i = 0; i < 26; i++) {
				if (possStart[i][0] >= 2 || possEnd[i][0] >= 2)
					succes = false;
			}
			for (int i = 0; i < N && succes; i++) {
				Wagon wag = cars[i];
				if (wag.start == wag.end && wag.w.length() > 1) {
					succes = false;
				}
			}
			if (!succes) {
				out.write("Case #" + (task + 1) + ": " + 0);
				out.newLine();
				System.out.println("Double starting point");
				continue;
			}

			int amountOfChains = 0;
			for (int i = 0; i < 26; i++) {
				if (availableStart[i] && startPoint[i])
					amountOfChains++;
			}
			if (amountOfChains == 0) {
				out.write("Case #" + (task + 1) + ": " + 0);
				out.newLine();
				System.out.println("No starting point");
				continue;
			}

			boolean possible = true;
			boolean[] containing = new boolean[26];
			boolean[] starting = new boolean[26];
			boolean[] ending = new boolean[26];
			for (int i = 0; i < N; i++) {
				Wagon car = cars[i];
				String s = car.w;
				for (int j = 1; j < s.length()-1; j++) {
					if (containing[s.charAt(j)-'a']) possible = false;
					containing[s.charAt(j) - 'a'] = true;
				}
				starting[car.start - 'a'] = true;
				ending[car.end - 'a'] = true;
			}
			for (int i = 0; i < 26; i++) {
				if (containing[i]) {
					if (starting[i] || ending[i])
						possible = false;
				}
			}
			if (!possible) {
				out.write("Case #" + (task + 1) + ": " + 0);
				out.newLine();
				System.out.println("Enclosed number");
				continue;
			}

			BigInteger sol = new BigInteger("1");
			for (int i = 0; i < 26; i++) {
				if (possStart[i][1] > 1) {
					System.out.println("AmountOfPermutations " + possStart[i][1]);
					BigInteger faculty = fac(new BigInteger("" + possStart[i][1]));
					sol = sol.multiply(faculty);
					sol = sol.mod(MOD);
				}
			}
			System.out.println("AmountOfChains: " + amountOfChains);
			sol = sol.multiply(fac(new BigInteger("" + amountOfChains)));
			sol = sol.mod(MOD);

			out.write("Case #" + (task + 1) + ": " + sol);
			out.newLine();
		}

		out.close();
		in.close();
	}
	
	public String trimIt(String s) {
		String ret = "" + s.charAt(0);
		for(int i = 1; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(i-1))
				ret += (""+s.charAt(i));
		}
		return ret;
	}

	public BigInteger fac(BigInteger b) {
		if (b.equals(BigInteger.ONE))
			return BigInteger.ONE;
		else
			return b.multiply(fac(new BigInteger("" + (b.longValue() - 1))));
	}

	class Wagon {
		String w;
		char start;
		char end;

		public Wagon(String w) {
			this.w = w;
			this.start = w.charAt(0);
			this.end = w.charAt(w.length() - 1);
		}
	}
}

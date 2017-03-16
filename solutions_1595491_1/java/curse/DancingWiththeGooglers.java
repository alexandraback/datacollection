import java.io.*;
import java.util.StringTokenizer;

public class DancingWiththeGooglers {
	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("B-large.in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("B.out"));
			int numCase = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCase; i++) {
				ofStream.println("Case #"+i+": "+dancingWiththeGooglers(ifStream.readLine()));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static int dancingWiththeGooglers(String input) {
		StringTokenizer st = new StringTokenizer(input, " ", false);
		int numGooglers = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		Googler[] Googlers = new Googler[numGooglers];
		int result = 0;
		int count = 0;

		for (int i=0; i<numGooglers; i++) {
			Googlers[i] = new Googler(Integer.parseInt(st.nextToken()));
			if (Googlers[i].best >= p) {
				result++;
			}
			if (Googlers[i].best == (p-1) && Googlers[i].remainder != 1 && Googlers[i].total != 0 && Googlers[i].total != 29 && Googlers[i].total != 30) {
				count++;
			}
		}

		if (count >= S) {
			result += S;
		}
		else {
			result += count;
		}

		return result;
	}
}

class Googler {
	int total;
	int remainder;
	int best;

	public Googler(int total) {
		this.total = total;
		this.remainder = total % 3;
		int n = total / 3;
		switch (remainder) {
			case 0: best = n; break;	// This is an intermediate value.
			case 1: best = n + 1; break;
			case 2: best = n + 1; break;	// So is this.
		}
	}
}

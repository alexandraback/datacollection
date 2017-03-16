import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new File("C1.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("C.out"));

			long[] fair = new long[1000];
			long i = 1;
			int total = 0;
			while (true) {
				long temp = i * i;
				if (temp > 200000000000000L)
					break;
				if (check(i) && check(temp)) {
					fair[++total] = temp;					
				}
				i++;
			}

				int T = in.nextInt();
				// Map<Long, Boolean> mp = new HashMap<>();
				for (int nCase = 1; nCase <= T; nCase++) {
					long A = in.nextLong();
					long B = in.nextLong();
					// double a = Math.sqrt(Long.valueOf(A).doubleValue());
					// long i = Double.valueOf(a).longValue();
					// while (i*i < A)
					// i++;
					int count = 0;
					int j = 0;
					while (fair[j] < A)
						j++;
					while (fair[j] <= B && j <100) {
						j++;
						count++;
					}

					out.write("Case #" + nCase + ": " + count);
					out.newLine();
				}

				in.close();
				out.close();
			
		} catch (Exception e) {
			System.out.println(e.toString());
		}

	}

	private static boolean check(long i) {
		String origin = String.valueOf(i);
		String reversed = new StringBuilder(origin).reverse().toString();
		if (reversed.equals(origin))
			return true;
		return false;
	}

}

import java.io.*;
import java.util.*;

class fairsquare {
	public static final long[] sols = {1L, 4L, 9L, 121L, 484L, 10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L, 4008004L, 100020001L, 102030201L, 104060401L, 121242121L, 123454321L, 125686521L, 400080004L, 404090404L, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L};
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("fairsquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fairsquare.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			long A = Long.parseLong(st.nextToken());
			long B = Long.parseLong(st.nextToken());
			int answer = 0;
			for (int j = 0; j < sols.length; j++) {
				if (A <= sols[j] && sols[j] <= B) answer++;
				if (sols[j] > B) break;
			}
			/**double A = Double.parseDouble(st.nextToken());
			double B = Double.parseDouble(st.nextToken());
			double sqrtA = Math.sqrt(A);
			double sqrtB = Math.sqrt(B);
			double logsqrtA = Math.log10(sqrtA);
			double logsqrtB = Math.log10(sqrtB);
			double floor = Math.ceil(logsqrtA);
			double ceil = Math.ceil(logsqrtB)+1;
			int answer = 0;
			for (double j = floor; j < ceil; j++) {
				ArrayList<Double> pals = new ArrayList<Double>();
				if (j == 1) for (double k = 2; k <= 9; k++) pals.add(k);
				else if (j != 0) pals = genPals(j);
				else pals.add(1.0);
				for (int k = 0; k < pals.size(); k++) {
					double cur = pals.get(k);
					if (isPal(Math.pow(cur, 2)) && Math.pow(cur, 2) >= A && Math.pow(cur, 2) <= B) {
						answer++;
						System.out.print((long)(Math.pow(cur, 2)) + "L, ");
					}
				}
			}**/
			out.println("Case #" + (i+1) + ": " + answer);
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
	public static ArrayList<Double> genPals(double dig) {
		ArrayList<Double> pals = new ArrayList<Double>();
		double numpart = -1;
		if (dig%2 == 0) numpart = dig/2;
		if (dig%2 == 1) numpart = (dig+1)/2;
		for (double i = Math.pow(10, numpart-1); i < Math.pow(10, numpart); i++) {
			pals.add(genPal(i, dig));
		}
		return pals;
	}
	public static double genPal(double i, double dig) {
		String pals = Integer.toString((int)i);
		if (dig%2 == 0) pals += reverse(pals);
		else pals += reverse(pals.substring(0, pals.length() - 1));
		return Double.parseDouble(pals);
	}
	public static boolean isPal(double num) {
		return reverse(Long.toString((long)num)).equals(Long.toString((long)num));
	}
	public static String reverse(String s) {
		String answer = "";
		for (int i = 0; i < s.length(); i++) {
			answer += s.charAt(s.length() - i - 1);
		}
		return answer;
	}
}


import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode3 {
	private static MyScanner in;
	private static PrintStream out;

	private static void solve() throws IOException
	{
		Init();
		int C = in.nextInt();
		for (int i = 0; i < C; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solveCase();
		}
	}

	private static void Init() {
		HashMap<Integer, ArrayList<Long>> palindrom = new HashMap<>();
		ArrayList<Long> palnums;
		palindrom.put(1, new ArrayList<Long>());
		ArrayList<Long> al = palindrom.get(1);
		for (Long i = 1L; i < 10; i++) {
			al.add(i);
		}
		palindrom.put(2, new ArrayList<Long>());
		al = palindrom.get(2);
		for (Long i = 1L; i < 10; i++) {
			al.add(11 * i);
		}

		for (int len = 3; len <= 8; len++) {

			if (len % 2 == 1) {
				ArrayList<Long> alprev = palindrom.get(len - 1);
				Long div = 1L;
				for (int i = 0; i < (len - 1) / 2; i++)
					div = div * 10;

				int alprevSize = alprev.size();
				palindrom.put(len, new ArrayList<Long>(alprevSize * 10));
				al = palindrom.get(len);
				for (int i = 0; i < alprevSize; i++) {
					Long n = alprev.get(i);
					Long nright = n % div;
					Long nleft = n - nright;
					for (int j = 0; j < 10; j++) {
						Long newx = nleft * 10 + j * div + nright;
						al.add(newx);
					}
				}
			}
			else {
				ArrayList<Long> alprev = palindrom.get(len - 2);
				Long div = 1L;
				for (int i = 0; i < (len - 2) / 2; i++)
					div = div * 10;

				int alprevSize = alprev.size();
				palindrom.put(len, new ArrayList<Long>(alprevSize * 10));
				al = palindrom.get(len);
				for (int i = 0; i < alprevSize; i++) {
					Long n = alprev.get(i);
					Long nright = n % div;
					Long nleft = n - nright;
					for (int j = 0; j < 10; j++) {
						Long newx = nleft * 100 + (11 * j) * div + nright;
						al.add(newx);
					}
				}
			}
		}
		Set<Integer> keys = palindrom.keySet();
		Long tot = 0L;
		for (Integer k : keys) {
			tot += palindrom.get(k).size();
		}
		palnums = new ArrayList<>();
		for (Integer k : keys) {
			ArrayList<Long> aa = palindrom.get(k);
			for (Long a : aa) {
				palnums.add(a);
			}
		}
		fspalnums = new ArrayList<>();
		for (Long p : palnums) {
			Long sq = p * p;
			if (isPalindrom(sq))
				fspalnums.add(sq);
		}
		Collections.sort(fspalnums);
		return;
	}

	private static boolean isPalindrom(Long sq) {
		String ssq = sq.toString();
		String revssq = (new StringBuffer(ssq)).reverse().toString();
		return ssq.equals(revssq);
	}

	static ArrayList<Long> fspalnums;

	private static void solveCase() throws IOException {
		long A = in.nextLong();
		long B = in.nextLong();
		int cnt = 0;
		Long x;
		for (int i = 0; i < fspalnums.size(); i++) {
			x = fspalnums.get(i);
			if (x < A)
				continue;
			else if (x <= B)
				cnt++;
			else
				break;
		}
		out.println(cnt);
	}

	public static void main(String[] args) throws IOException {
		// helpers for input/output
		boolean usingFileForIO = true;
		if (usingFileForIO) {
			// using input.txt and output.txt as I/O
			in = new MyScanner("E:\\zin.txt");
			out = new PrintStream("E:\\zout.txt");
		}
		else {
			in = new MyScanner();
			out = System.out;
		}

		solve();
	}

	// =====================================
	static class MyScanner {
		Scanner inp = null;

		public MyScanner() throws IOException
		{
			inp = new Scanner(System.in);
		}

		public MyScanner(String inputFile) throws IOException {
			inp = new Scanner(new FileInputStream(inputFile));
		}

		public int nextInt() throws IOException {
			return inp.nextInt();
		}

		public long nextLong() throws IOException {
			return inp.nextLong();
		}

		public double nextDouble() throws IOException {
			return inp.nextDouble();
		}

		public String nextString() throws IOException {
			return inp.next();
		}

		public String nextLine() throws IOException {
			return inp.nextLine();
		}
	}

}
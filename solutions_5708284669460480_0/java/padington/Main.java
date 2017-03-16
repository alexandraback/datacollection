import java.io.*;
import java.util.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author padington
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
	private int[] arr;
	private int K, S;
	private char[] keys;
	private String targetWord;
	private List<String> listOfWords;

	public void solve(int testNumber, Scanner in, PrintWriter out) {
		K = in.nextInt();
		final int L = in.nextInt();
		S = in.nextInt();
		keys = in.next().toCharArray();
		targetWord = in.next();

		listOfWords = new ArrayList<>();
		arr = new int[S];
		generate(0);

		int count = 0;
		int maxCurCount = 0;

		for (String word : listOfWords) {
			int curCount = 0;
			for (int i = 0; i <= S - L; i++) {
				curCount += word.substring(i, i + L).equals(targetWord) ? 1 : 0;
			}
			count += curCount;
			maxCurCount = Math.max(curCount, maxCurCount);
		}
		double ans = maxCurCount - (double) count / (double) listOfWords.size();
		out.println(String.format("Case #%d: %.6f", testNumber, ans));
	}

	void generate(int curInd) {
		if (curInd == S) {
			StringBuilder stringBuilder = new StringBuilder();
			for (int i = 0; i < S; i++) {
				stringBuilder.append(keys[arr[i]]);
			}
			listOfWords.add(stringBuilder.toString());
		} else {
			for (int i = 0; i < K; i++) {
				arr[curInd] = i;
				generate(curInd + 1);
			}
		}
	}
}


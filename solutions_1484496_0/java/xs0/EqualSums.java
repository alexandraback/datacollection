package codejam.round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.ArrayList;
import java.util.Arrays;

public class EqualSums {
	enum What {
		A, B
	}
	
	static long[] input;
	static What[] what;
	
	static ArrayList<Long>[] compute() {
		long sum = 0;
		for (long l : input)
			sum += l;
		
		Arrays.sort(input); {
			int a = 0, b = input.length - 1;
			while (a < b) {
				long t = input[a];
				input[a] = input[b];
				input[b] = t;
				a++; b--;
			}
		}

		what = new What[input.length];
		
		if (!go(0, 0, 0, sum))
			return null;
		
		ArrayList<Long> ra = new ArrayList<Long>();
		ArrayList<Long> rb = new ArrayList<Long>();
		for (int a = 0; a < input.length; a++) {
			if (what[a] == null)
				continue;
			if (what[a] == What.A) {
				ra.add(input[a]);
			} else {
				rb.add(input[a]);
			}
		}
		
		return new ArrayList[] {
			ra, rb	
		};
	}
	
	private static boolean go(int currIndex, long sumA, long sumB, long remain) {
		boolean same = false;
		if (sumA == sumB) {
			if (sumA != 0)
				return true;
			
			same = true;
		}
		
		if (currIndex >= input.length)
			return false;
		
		long curr = input[currIndex];
		remain -= curr;
		
		if (sumA + remain >= sumB) {
			if (go(currIndex + 1, sumA, sumB, remain))
				return true;
		}
		
		if (sumA + curr + remain >= sumB) {
			what[currIndex] = What.A;
			if (go(currIndex + 1, sumA + curr, sumB, remain))
				return true;
			what[currIndex] = null;
		}
		
		if (!same && (sumB + curr + remain >= sumA)) {
			what[currIndex] = What.B;
			if (go(currIndex + 1, sumA, sumB + curr, remain))
				return true;
			what[currIndex] = null;
		}

		return false;
	}

	public static void main(String[] args) throws IOException {
		File f = new File("/home/mitja/cj/C");
		for (File inFile : f.listFiles()) {
			if (inFile.isFile() && inFile.getName().endsWith(".in")) {
				File output = new File(f, inFile.getName() + ".out");
				
				FileWriter out = new FileWriter(output);
				
				long[][] lines = readLongs(inFile);
				
				int nCases = (int) lines[0][0];
				for (int c = 1; c <= nCases; c++) {
					long[] l = lines[c];
					EqualSums.input = new long[(int)l[0]];
					System.arraycopy(l, 1, input, 0, (int)l[0]);
					
					ArrayList<Long>[] res = compute();
					
					StringBuilder sb = new StringBuilder();
					sb.append("Case #").append(c).append(":").append("\n");
					if (res == null) {
						sb.append("Impossible\n");
					} else {
						for (int li = 0; li < 2; li++) {
							boolean first = true;
							for (Long i : res[li]) {
								if (first) {
									first = false;
								} else {
									sb.append(' ');
								}
								sb.append(i);
							}
							sb.append('\n');
						}
					}

					System.out.print(sb);
					out.append(sb);
				}
				
				out.close();
			}
		}
	}

	private static long[][] readLongs(File input) throws IOException {
		ArrayList<long[]> out = new ArrayList<long[]>();
		
		LineNumberReader lnr = new LineNumberReader(new FileReader(input));
		
		String l;
		while ((l = lnr.readLine()) != null) {
			String[] parts = l.trim().split(" ");
			
			long[] i = new long[parts.length];
			for (int a = 0; a < parts.length; a++)
				i[a] = Long.parseLong(parts[a]);
			
			out.add(i);
		}
		
		return out.toArray(new long[out.size()][]);
	}
}

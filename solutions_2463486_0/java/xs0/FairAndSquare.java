import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.math.BigInteger;
import java.util.Arrays;


public class FairAndSquare {
	static BigInteger minimum;
	static BigInteger maximum;
	static int minLen;
	static int maxLen;
	static long count;
	
	static void check(int[] buff, int lastPos, boolean odd) {
		int len = 2 * (lastPos + 1) - (odd ? 1 : 0);
		int sqLen = 2 * len - 1;
		if (sqLen < minLen)
			return;
		if (sqLen > maxLen)
			throw new IllegalStateException("Done");
		if (sqLen != minLen && sqLen != maxLen) {
			count++;
			return;
		}
		
		StringBuilder sb = new StringBuilder();
		for (int a = 0; a <= lastPos; a++)
			sb.append(buff[a]);
		for (int a = lastPos - (odd ? 1 : 0); a >= 0; a--)
			sb.append(buff[a]);
		
		BigInteger bi = new BigInteger(sb.toString());
		BigInteger sq = bi.multiply(bi);
		
		if (sq.compareTo(minimum) >= 0 && sq.compareTo(maximum) <= 0)
			count++;
	}
	
	static void generate(int[] buff, int lastPos, boolean odd) {
		Arrays.fill(buff, 0);
		
		int f = odd ? 1 : 2;
		if (lastPos == 0) {
			for (int a = 1; f * a * a <= 9; a++) {
				buff[0] = a;
				check(buff, lastPos, odd);
			}
			return;
		}

		buff[0] = 1;
		for (int mid = 0; mid <= (odd ? 2 : 1); mid++) {
			buff[lastPos] = mid;
			check(buff, lastPos, odd);
		}
		
		for (int p1 = 1; p1 < lastPos; p1++) {
			buff[p1] = 1;
			
			for (int mid = 0; mid <= (odd ? 2 : 1); mid++) {
				buff[lastPos] = mid;
				check(buff, lastPos, odd);
			}
			
			for (int p2 = p1 + 1; p2 < lastPos; p2++) {
				buff[p2] = 1;
				
				for (int mid = 0; mid <= 1; mid++) {
					buff[lastPos] = mid;
					check(buff, lastPos, odd);
				}
				
				for (int p3 = p2 + 1; p3 < lastPos; p3++) {
					buff[p3] = 1;
					
					for (int mid = 0; mid <= (odd ? 1 : 0); mid++) {
						buff[lastPos] = mid;
						check(buff, lastPos, odd);
					}
					
					buff[p3] = 0;
				}
				
				buff[p2] = 0;
			}
			
			buff[p1] = 0;
		}
		
		buff[0] = 2;
		for (int mid = 0; mid <= (odd ? 1 : 0); mid++) {
			buff[lastPos] = mid;
			check(buff, lastPos, odd);
		}
	}
	
	static long go(String a, String b) {
		minimum = new BigInteger(a);
		maximum = new BigInteger(b);
		minLen = a.length();
		maxLen = b.length();
		count = 0;
		
		int[] buff = new int[110];
		for (int len = Math.max(1, minLen / 2); len <= 110; len++) {
			int lastPos = (len + 1) / 2 - 1;
			boolean odd = (len & 1) == 1;
			
			try {
				generate(buff, lastPos, odd);
			} catch (IllegalStateException e) {
				break;
			}
		}
		
		return count;
	}
	
	static void go(String inputFile) throws IOException {
		LineNumberReader in = new LineNumberReader(new FileReader(inputFile));
		FileWriter out = new FileWriter(inputFile + ".out");
		
		int nCases = Integer.parseInt(in.readLine());
		for (int c = 1; c <= nCases; c++) {
			String[] tmp = in.readLine().trim().split(" ");
			long res = go(tmp[0], tmp[1]);
			out.write("Case #" + c + ": " + res + "\n");
		}
		out.close();
	}
	
	public static void main(String[] args) throws Exception {
		LineNumberReader sysIn = new LineNumberReader(new InputStreamReader(System.in));
		String line;
		while ((line = sysIn.readLine()) != null) {
			go(line.trim());
		}
	}
}

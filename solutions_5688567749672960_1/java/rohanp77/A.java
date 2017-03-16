import java.io.*;
import java.util.*;

public class A {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("A.in"));
		out = new PrintWriter(new FileWriter("A.out"));
		
		int qqq = nextInt();
		for (int qq=1; qq<=qqq; qq++) {
			out.printf("Case #%d: ", qq);
			
			long num = nextLong();
			if (num < 10) {
				out.println(num);
				continue;
			}
			String numS = String.valueOf(num);
			
			long count = 10;
			long goUp = 10;
			for (int i=2; i<numS.length(); i++) {
				goUp += increaseLen(count);
				count *= 10;
			}
			
			goUp += closeGap(count, num);
			
			out.println(goUp);
		}
		out.close();
	}

	private static long closeGap(long count, long num) {
		if (num == count) return 0;
		boolean flag = false;
		if (num % 10 == 0) {
			num--; flag = true;
		}
		char[] numS = String.valueOf(num).toCharArray();
		char[] countS = String.valueOf(count).toCharArray();
		long goUp = 0;
		
		long mult = 1;
		for (int i = countS.length-1; i >= (countS.length+1)/2; i--) {
			countS[i] = countS[countS.length-1-i];
			countS[countS.length-1-i] = numS[countS.length-1-i];
			goUp += (countS[countS.length-1-i] - '0') * mult;
			mult *= 10;
		}
		if (flag) num++;
		long oldCount = count;
		count = Long.parseLong(String.valueOf(countS));
		if (oldCount+1 == count) return num-oldCount;
		
		if (goUp > 0) goUp++;
		
		return goUp + num-count;
	}

	private static long increaseLen(long count) {
		char[] curr = String.valueOf(count).toCharArray();
		long target = 1;
		for (int i=0; i<curr.length; i++)
			target *= 10;
		long inc = 0;
		
		long mult = 1;
		for (int i=curr.length-1; i>=(curr.length+1)/2; i--) {
			inc += ('9'-curr[i]) * mult;
			mult *= 10;
			curr[i] = curr[curr.length-1-i];
			curr[curr.length-1-i] = '9';
		}
		count = Long.parseLong(String.valueOf(curr));
		
		if (inc >0) inc++;
		
		return inc + target-count;
	}
	
	
}

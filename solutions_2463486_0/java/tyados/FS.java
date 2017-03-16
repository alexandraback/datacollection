import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FS {

	static int caseNum;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(
				new FileInputStream("fs.in")));
		PrintWriter pw = new PrintWriter(new FileOutputStream("fs.out"));

		caseNum = Integer.parseInt(br.readLine());

		for (int CASE = 1; CASE <= caseNum; CASE++) {
			long A, B;
			StringTokenizer st = new StringTokenizer(br.readLine());
			A = Long.parseLong(st.nextToken());
			B = Long.parseLong(st.nextToken());

			long beforeX = ((long) Math.sqrt(A));
			long beforeA = beforeX * beforeX;

			if (beforeA < A) {
				beforeA += beforeX + beforeX + 1;
				beforeX++;
			}

			int count = 0;
			for (long t = beforeA; t <= B;) {
				
				if (palindrome(beforeX) && palindrome(t))
					count++;

				t += beforeX + beforeX + 1;
				beforeX++;
			}
			
			pw.println("Case #" + CASE + ": " + count);
		}
		
		br.close();
		pw.close();

	}
	
	static boolean palindrome(long a) {
		long b = a;
		long c = 0;
		while (b != 0) {
			c = c * 10 + (b % 10);
			b /= 10;
		}
		
		while (c != 0) {
			if (c % 10 != a % 10)
				return false;
			c /= 10;
			a /= 10;
		}
		return true;
	}

}

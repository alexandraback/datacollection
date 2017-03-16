import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Dancing {

	public static void main(String[] args) throws IOException {
		if (args.length < 2) {
			System.err
					.println("Please enter the Valid I/O Paths in the argument ");
			System.err.println("First Input , then OutPut ");
			System.exit(0);
		}
		File inFile = new File(args[0]);
		File outFile = new File(args[1]);
		BufferedReader in = new BufferedReader(new InputStreamReader(
				new FileInputStream(inFile)));
		PrintWriter out = new PrintWriter(new FileOutputStream(outFile));
		String myLine = in.readLine();
		int t = Integer.parseInt(myLine);
		int caseNum = 1;
		int n, s, p;
		while (t-- > 0) {
			myLine = in.readLine();
			String[] myStr = myLine.split(" ");
			n = Integer.parseInt(myStr[0]);
			s = Integer.parseInt(myStr[1]);
			p = Integer.parseInt(myStr[2]);

			int[] arr = new int[n];
			int min = (p - 2) * 3 + 2 > 0 ? (p - 2) * 3 + 2 : p;
			int min1 = 3*p - 2;
			int rem2 = 0;
			int normal = 0;
			int result = 0;
			if (p > 0) {
				for (int i = 0; i < arr.length; i++) {
					arr[i] = Integer.parseInt(myStr[i + 3]);
					if (arr[i] >= min && arr[i] < min1)
					rem2++;
					else if (arr[i] >= min1)
						normal++;
				}
				result = normal + (rem2 >= s ? s : rem2);
			} else {
				result = n;
			}
			out.println("Case #" + (caseNum) + ": " + result);
			caseNum++;
		}
		out.close();
	}
}

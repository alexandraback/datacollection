import java.io.*;
import java.math.*;
import java.util.*;

public class CbigJ {
	static public void main(String[] args) throws Exception {
		String fileName = "num.txt";
		Scanner scanner = new Scanner(new FileInputStream(fileName));
		PrintStream out = new PrintStream("sortnum.txt");

		ArrayList<BigInteger> ar = new ArrayList<BigInteger>();
		while (scanner.hasNextLine()) {
			String num = scanner.nextLine();
			BigInteger bigNum = new BigInteger(num);
			ar.add(bigNum);
		}
		
		Collections.sort(ar);
		
		for (int i = 0; i < ar.size(); i ++) {
			BigInteger sq = ar.get(i).multiply(ar.get(i));
			out.println(ar.get(i));
			out.println(sq);
			out.println();
		}
		
		out.close();
		scanner.close();
	}
}

/*
String file = "C-large-1.in";
		Scanner scanner = new Scanner(new FileInputStream(file));
		PrintStream ps = new PrintStream(file + ".out");
		
		int tot = scanner.nextInt();
		for (int tt = 0; tt < tot; tt ++) {
			long beg = scanner.nextLong();
			long end = scanner.nextLong();
			int idbeg = 0;
			int idend = 47;
			while (beg > arr[idbeg] && idbeg < 47) {
				idbeg ++;
			}
			while (end < arr[idend] && idend >= 0) {
				idend --;
			}
			ps.println("Case #" + (tt + 1) + ": " + (idend - idbeg + 1));
			
		}
		ps.close();

*/
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Recycle {

	static PrintStream O = System.out;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			long initTime = System.currentTimeMillis();
			PrintWriter out = new PrintWriter(new FileWriter("C.out"));
			BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			int cases = Integer.parseInt(in.readLine());
			for (int kase = 0; kase < cases; kase++){
				String input = in.readLine();
				int A = Integer.parseInt(input.split(" ")[0]);
				int B = Integer.parseInt(input.split(" ")[1]);
				out.println("Case #" + (kase + 1) + ": " + count(A, B));
			}
			//O.println(System.currentTimeMillis() - initTime);
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static int count (int A, int B){
		Set<Long> set = new TreeSet<Long>();
		int count = 0;
		char cA = Integer.toString(A).charAt(0);
		char cB = Integer.toString(B).charAt(0);
		for (long i = A; i < B; i++){
			String s = Integer.toString((int)i);
			long newN;
			for (int j = 1; j < s.length(); j++){
				if (s.charAt(j) >= cA && s.charAt(j) <= cB){
					String tmp = s.substring(j) + s.substring(0,j);
					newN = Integer.parseInt(tmp);
					if (newN != i && newN >= A && newN <= B){
						set.add(i << 21 | newN);
						set.add(newN << 21 | i);
					}
				}
			}
		}
		return set.size() / 2;
	}
}

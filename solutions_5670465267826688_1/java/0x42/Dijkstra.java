import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.HashMap;
import java.util.Map;

public class Dijkstra {

	public static void main(String[] args) throws Exception {
		Dijkstra object = new Dijkstra();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;
		
		st.resetSyntax();
		st.wordChars(0, 256);
		st.whitespaceChars(0, 32);

		for (int tc = 1; tc <= testCases; tc++) {

			st.nextToken();
			
			st.nextToken();
			long X = Long.parseLong(st.sval);
			
			st.nextToken();
			String S = st.sval;

			boolean result = object.solve(S, X);

			String output = (result == true) ? "YES" : "NO";

			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	boolean solve(String s, long x) {
		initMap();

		int count = (int) Math.min(s.length() * x, s.length() * 10);

		String curStart = "1";
		int firstEndsAt = -1;

		for (int i = 1; i < count; i++) {
			curStart = multiply(curStart, get(s, i - 1) + "");

			if (curStart.equals("i")) {
				firstEndsAt = i;
				break;
			}
		}

		if (firstEndsAt == -1)
			return false;

		String curEnd = "1";
		long lastStartsAt = -1;

		String revS = new StringBuilder(s).reverse().toString();

		for (int i = 1; i < count; i++) {
			curEnd = multiply(get(revS, i - 1) + "", curEnd);

			if (curEnd.equals("k")) {
				lastStartsAt = s.length() * x - i;
				break;
			}
		}

		if (lastStartsAt == -1)
			return false;
		
		if (firstEndsAt >= lastStartsAt)
			return false;

		return product(s, x, firstEndsAt, lastStartsAt).equals("j");
	}

	private String product(String s, long x, long from, long to) {

		long fromG = (from / s.length());
		long toG = (to / s.length());

		int fromM = (int) (from % s.length());
		int toM = (int) (to % s.length());

		if (fromG == toG) {
			// same group
			String res = "1";

			for (int i = fromM; i < toM; i++)
				res = multiply(res, get(s, i) + "");

			return res;
		}

		// else, it's different groups
		String res1 = "1";
		for (int i = fromM; i < s.length(); i++)
			res1 = multiply(res1, get(s, i) + "");

		String groupMult = getGroupMult(s);

		String res2 = bpow(groupMult, toG - fromG - 1);

		String res3 = "1";
		for (int i = 0; i < toM; i++)
			res3 = multiply(res3, get(s, i) + "");

		String result = multiply(res1, res2);
		result = multiply(result, res3);

		return result;

	}
	
	String bpow(String val, long power) {
		   if (power <= 0)
		      return "1";

		   String t = val;
		   String result = "1";

		   for (long i=0; i<60; i++) {
		       if (((1L << i) & power) != 0)
		              result = multiply(result, t);
		            
		      t = multiply(t, t);       
		   }

		   return result;
		}


	private String getGroupMult(String s) {
		String res = "1";

		for (int i = 0; i < s.length(); i++)
			res = multiply(res, get(s, i) + "");

		return res;
	}

	private char get(String s, int pos) {
		pos %= s.length();
		return s.charAt(pos);
	}

	Map<String, String> map;

	 String multiply(String a, String b) {

		int minuses = 0;

		if (a.startsWith("-")) {
			minuses++;
			a = new String(a.substring(1));
		}

		if (b.startsWith("-")) {
			minuses++;
			b = new String(b.substring(1));
		}

		String output = map.get(a + " x " + b);

		if (output.startsWith("-")) {
			minuses++;
			output = new String(output.substring(1));
		}

		if (minuses % 2 == 1)
			return "-" + output;

		return output;
	}

	private void initMap() {

		map = new HashMap<>();

		map.put("1 x 1", "1");
		map.put("1 x i", "i");
		map.put("1 x j", "j");
		map.put("1 x k", "k");

		map.put("i x 1", "i");
		map.put("i x i", "-1");
		map.put("i x j", "k");
		map.put("i x k", "-j");

		map.put("j x 1", "j");
		map.put("j x i", "-k");
		map.put("j x j", "-1");
		map.put("j x k", "i");

		map.put("k x 1", "k");
		map.put("k x i", "j");
		map.put("k x j", "-i");
		map.put("k x k", "-1");

	}

}



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class ProblemC {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static Map<String, String> mulMap = new HashMap<String, String>();
	static {
		mulMap.put("1 1", "1");
		mulMap.put("1 i", "i");
		mulMap.put("1 j", "j");
		mulMap.put("1 k", "k");
		
		mulMap.put("i 1", "i");
		mulMap.put("i i", "-1");
		mulMap.put("i j", "k");
		mulMap.put("i k", "-j");
		
		mulMap.put("j 1", "j");
		mulMap.put("j i", "-k");
		mulMap.put("j j", "-1");
		mulMap.put("j k", "i");
		
		mulMap.put("k 1", "k");
		mulMap.put("k i", "j");
		mulMap.put("k j", "-i");
		mulMap.put("k k", "-1");

	}
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			int[] params = readInts();
			int L = params[0];
			int X = params[1];
			
			if (X>8) {
				X = X % 4 + 8;
			}
			
			String baseWord = readString();
			String word = "";
			for (int i=0; i<X; i++) {
				word += baseWord;
			}
			
			boolean possible = false;
			if (reduce(word).equals("-1")) {
				String mul1 = "1";
				for (int i=0; i<word.length()-2; i++) {
					mul1 = mul(mul1, String.valueOf(word.charAt(i)));
					if (mul1.equals("i")) {
						String mul2 = "1";
						for (int j=i+1; j<word.length()-1; j++) {
							mul2 = mul(mul2, String.valueOf(word.charAt(j)));
							if (mul2.equals("j")) {
								possible = true;
							}
						}
					}
				}
			}
			
			System.out.println(String.format("Case #%d: %s", caseNum+1, possible ? "YES" : "NO"));
		}

	}
	
	private static String reduce(String w) {
		if (w.length()==1) return w;
		return mul(w.substring(0, 1), reduce(w.substring(1)));
	}

	private static String mul(String v, String w) {
		boolean sign = true;
		if (v.startsWith("-")) {
			v = v.substring(1);
			sign = !sign;
		}
		if (w.startsWith("-")) {
			w = w.substring(1);
			sign = !sign;
		}
		String result = mulMap.get(String.format("%s %s", v,w));
		if (!sign) {
			if (result.startsWith("-")) {
				result = result.substring(1);
			} else {
				result = "-" + result;
			}
		}
		return result;
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
	
	private static String readString() throws IOException {
		return br.readLine();
	}
}

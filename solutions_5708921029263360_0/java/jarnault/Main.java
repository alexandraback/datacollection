package CodeJam.CJ2016R1C_3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	private static InputReader in;
	private static PrintWriter out;
	public static boolean SUBMIT = true;
	public static final String NAME = "./src/CodeJam/CJ2016R1C_3/C-small-attempt3";

	private static void main2()throws IOException{
		int j = in.nextInt();
		int p = in.nextInt();
		int s = in.nextInt();
		int k = in.nextInt();
		Map<String, Integer> jp = new HashMap<>();
		Map<String, Integer> js = new HashMap<>();
		Map<String, Integer> ps = new HashMap<>();
		int tot = 0;
		List<String> sol = new ArrayList<>();
		for (int jj = 1 ; jj <= j ; jj++){
			for (int pp = 1 ; pp <= p ; pp++){
				int cpt = 0;
				for (int ss = pp + 1 ; cpt < s ; ss = (ss%s) + 1, cpt++){
					if (ss == (s + 1)){
						ss = 1;
					}
					if (!jp.containsKey(jj + " " + pp)){
						jp.put(jj + " " + pp, 0);
					}
					if (!js.containsKey(jj + " " + ss)){
						js.put(jj + " " + ss, 0);
					}
					if (!ps.containsKey(pp + " " + ss)){
						ps.put(pp + " " + ss, 0);
					}
					//					out.println("(" + jj + "," + pp + "," + ss + ")");
					//					out.println("jp : " + (jp.get(jj + " " + pp)));
					//					out.println("js : " + ((js.get(jj + " " + ss))));
					//					out.println("ps : " + ((ps.get(pp + " " + ss))));
					if ((jp.get(jj + " " + pp) < k) && (js.get(jj + " " + ss) < k) && (ps.get(pp + " " + ss) < k)){
						//out.println(">>>>>>>>><<OK");
						sol.add(jj + " " + pp + " "  + ss);
						jp.put(jj + " " + pp, jp.get(jj + " " + pp) + 1);
						js.put(jj + " " + ss, js.get(jj + " " + ss) + 1);
						ps.put(pp + " " + ss, ps.get(pp + " " + ss) + 1);
						tot++;
					}
				}
			}
		}
		out.println(tot);
		for (String str : sol){
			out.println(str);
		}
	}


	public static void main(String[] args) throws IOException {
		in = new InputReader(new FileInputStream(new File(NAME + ".in")));
		if (SUBMIT) {
			out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));
		} else {
			out = new PrintWriter(System.out, true);
		}

		int numCases = in.nextInt();
		for (int test = 1; test <= numCases; test++) {
			out.print("Case #" + test + ": ");
			main2();
		}

		out.close();
		System.exit(0);
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while ((tokenizer == null) || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}

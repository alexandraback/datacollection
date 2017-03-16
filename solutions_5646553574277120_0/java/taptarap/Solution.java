import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.*;

public class Solution {



	static Set<Integer> moni;
	static List<Integer> smoni;
	static Integer C; // how many times we can use coin


	static boolean canGet(Integer input) {
		int i = smoni.size() -1;
		int cinput = input;

		while(i > -1) {
			int c = C;
			int curmon = smoni.get(i);

			while(cinput - curmon >= 0 && c > 0) {
				c--;
				cinput-=curmon;
			}
			if(cinput == 0) {
				return true;
			}
			i--;
		}

		return false;
	}

	public static void main(String[] args) throws Throwable {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer tokenizer = new StringTokenizer(in.readLine());
		int tn = Integer.parseInt(tokenizer.nextToken());
		for (int test = 1; test <= tn; test++) {
			
			tokenizer = new StringTokenizer(in.readLine());

			/* start sol */



			int c = Integer.parseInt(tokenizer.nextToken());
			int d = Integer.parseInt(tokenizer.nextToken());
			int v = Integer.parseInt(tokenizer.nextToken());
			moni = new TreeSet<>();
			smoni = new ArrayList<>();
			C=c;
			tokenizer = new StringTokenizer(in.readLine());
			for(int i =0; i< d; ++i) {
				int inp = Integer.parseInt(tokenizer.nextToken());
				moni.add(inp);
			}
			smoni = new ArrayList<>(moni);
			int res = 0;

			for(int value = 1; value <= v ; ++value) {
				if(!canGet(value)) {
					moni.add(value);
					smoni = new ArrayList<>(moni);
					++res;
				}
			}


			out.print("Case #" + test + ": " + res);
			/* end sol */




			if(test < tn) {
				out.println();
			}


		}
		in.close();
		out.close();
	}
}
package carol.r1B15;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {

	static final String TYPE = "C";
	static String inputFile;
	static String outputFile;

	private static void Name(String s) {
		inputFile = s + ".in";
		outputFile = s + ".out";
	}

	public static void main(String[] args) throws FileNotFoundException {

		String root = "data/R1B2015";

		// Test
//		Name(TYPE + "-large");
//		Name(TYPE + "-test");
		Name("C-small-1-attempt0");

		Scanner in = new Scanner(new File(root, inputFile));
		PrintWriter out = new PrintWriter(new File(root, outputFile));

		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			
			int N = in.nextInt();
			ArrayList<Integer> D = new ArrayList<Integer>();
			ArrayList<Integer> M = new ArrayList<Integer>();

			for(int j = 0; j < N; j++){
				int di = in.nextInt();
				int hi = in.nextInt();
				int mi = in.nextInt();
				for(int t = 0; t < hi; t++){
					D.add(di);
					M.add(mi + t);
				}
			}
			int result = 0;
			
			for(int j = 0; j < D.size(); j++){
				System.out.println(D.get(j) + " " + M.get(j));
			}
			
			if(D.size() >= 2){
				int s1 = (int)D.get(0);
				int t1 = (int)M.get(0);
				int s2 = (int)D.get(1);
				int t2 = (int)M.get(1);
				result = calculate(s1, t1, s2, t2);
			}
			
			out.println("Case #" + (i + 1) + ": " + result);

		}

		in.close();
		out.close();

	}

	public static int calculate(int s1, int t1, int s2, int t2){
		if (t1  == t2) return 0;
		if ( t2 < t1){
			int tmp = t1;
			t1 = t2;
			t2 = tmp;
			tmp = s1;
			s1 = s2;
			s2 = tmp;
		}
		int dis = s2 - s1 + 360;
		if (dis * t1 > (360 - s2) * (t2 - t1)) return 0;
		return 1;
	}
}
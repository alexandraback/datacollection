package round1C.A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) {

		//String filename = "src/round1C/input-A";
		String filename = "src/round1C/A-small-attempt3";
		//String filename = "src/round1C/A-large-practice";

		FileInputStream file;
		int T;

		try {
			file = new FileInputStream(filename+".in");

			BufferedReader in = new BufferedReader(new InputStreamReader(file));


			T = Integer.parseInt(in.readLine());

			BufferedWriter bw = new BufferedWriter(new FileWriter(filename+".out"));

			for (int i=0; i<T; i++) {
				int ind = i+1;
				// parser
				String[] data = in.readLine().split(" ");
				int R = Integer.parseInt(data[0]);
				int C = Integer.parseInt(data[1]);
				int W = Integer.parseInt(data[2]);

				int res = 0;
				// calcul				
				int pp_row = C-W+1;
				//pour trouver une des cases
				res = R * ((pp_row-1)/W + 1);
				//pour trouver le reste
				if (W > 1) {
					res += W;
					if (W == C || C%W == 0)
						res--;
				}
				System.out.println("Result "+i+": "+res);
				bw.write("Case #"+ind+": "+res+"\n");
			}
			bw.close();

			in.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}

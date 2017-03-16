import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	private static Scanner in;

	static ArrayList<String> solve(int B, int M) {

		ArrayList<String> ret = new ArrayList<>();

		if (M <= B) {

			int c = 0;
			for (int i = 1; i < B && c < M; i++) {
				String tmp = "";
				for (int j = 0; j < B; j++) {
					tmp += ((i == j && c < M - 1) || j == B - 1 || (j == 0
							&& B == M && i == B - 1)) ? "1" : "0";
				}
				c++;
				ret.add(tmp);
			}
			for (; c < B; c++) {
				String tmp = "";
				for (int j = 0; j < B; j++)
					tmp += "0";
				ret.add(tmp);
			}
		} else if(B > 4 && M <= (2*B-3)){
			for(int i=1; i<=B; i++){
				String tmp = "";
				if(i==1)
					for (int j = 1; j <= B; j++)
						tmp += (j==2 || j==B) ? "1" : "0";
				else if(i==2)
					for (int j = 1; j <= B; j++)
						tmp += (j==3 || j==B) ? "1" : "0";
				else if(i==B-1)
					for (int j = 1; j <= B; j++)
						tmp += (j==1 || j==B) ? "1" : "0";
				else if(i==B)
					for (int j = 0; j < B; j++)
						tmp += "0";
				else {
					for (int j = 1; j <= B; j++)
						tmp += (j==i+1 || j==1) ? "1" : "0";
				}
					
				ret.add(tmp);
			}
		} else 
			return null;

		return ret;
	}

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		String filename = args[0];
		int T;

		FileReader fr = new FileReader(filename);
		BufferedReader br = new BufferedReader(fr);
		in = new Scanner(br);

		T = in.nextInt();

		int Ti;
		ArrayList<String> res;
		for (Ti = 0; Ti < T; Ti++) {
			/* init & parse */
			int B = in.nextInt();
			int M = in.nextInt();

			/* traitement */
			res = solve(B, M);

			/* résultat */
			if (res == null)
				System.out.print("Case #" + (Ti + 1) + ": IMPOSSIBLE\n");
			else {
				System.out.print("Case #" + (Ti + 1) + ": POSSIBLE\n");
				for (int i = 0; i < B; i++) {
					System.out.print(res.get(i) + "\n");
				}
			}
		}

	}

}

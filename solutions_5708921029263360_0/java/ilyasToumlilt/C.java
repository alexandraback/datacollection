import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class C {

	private static Scanner in;

	static ArrayList<String> solve(int J, int P, int S, int K) {
		ArrayList<String> ret = new ArrayList<>();
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		boolean possible = true;

		while (possible) {
			possible = false;
			for (int i = 1; i <= J; i++) {
				for (int j = 1; j <= P; j++) {
					for (int k = 1; k <= S; k++) {
						// System.out.println("-->" + map.toString());
						if ((map.containsKey("" + i + j + "0") && map.get(""
								+ i + j + "0") >= K)
								|| (map.containsKey("" + i + "0" + k) && map
										.get("" + i + "0" + k) >= K)
								|| (map.containsKey("" + "0" + j + k) && map
										.get("" + "0" + j + k) >= K)) {
							continue;
						} else if(ret.isEmpty() || 
								(!ret.isEmpty() &&
								!ret.get(ret.size()-1).equals("" + i + " " + j + " " + k))){
							if (map.containsKey("" + i + j + "0"))
								map.put("" + i + j + "0",
										map.get("" + i + j + "0") + 1);
							else
								map.put("" + i + j + "0", 1);
							if (map.containsKey("" + i + "0" + k))
								map.put("" + i + "0" + k,
										map.get("" + i + "0" + k) + 1);
							else
								map.put("" + i + "0" + k, 1);
							if (map.containsKey("" + "0" + j + k))
								map.put("" + "0" + j + k,
										map.get("" + "0" + j + k) + 1);
							else
								map.put("" + "0" + j + k, 1);
							ret.add("" + i + " " + j + " " + k);
							
							possible = true;
						}
					}
				}
			}
		}

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
			int J = in.nextInt();
			int P = in.nextInt();
			int S = in.nextInt();
			int K = in.nextInt();

			/* traitement */
			res = solve(J, P, S, K);

			/* résultat */
			System.out.print("Case #" + (Ti + 1) + ": " + res.size() + "\n");
			for (int i = 0; i < res.size(); i++)
				System.out.println(res.get(i));
		}

	}

}

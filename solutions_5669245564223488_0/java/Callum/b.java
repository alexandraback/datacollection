import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class b {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt1.in"));
		PrintWriter pw = new PrintWriter("B-small.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			br.readLine();
			String[] trains = br.readLine().split(" ");
			for (int i = 0; i < trains.length; i++) {
				trains[i] = setString(trains[i]);
			}
			pw.printf("Case #%d: %d%n", test, checkPossible(trains, new boolean[trains.length], new String(), 0));
		}
		
		br.close();
		pw.close();
	}
	
	public static int checkPossible(String[] trains, boolean[] used, String curTrain, int trainLength) {
		int ans = 0;
		if (trains.length == trainLength) {
			ArrayList<Character> found = new ArrayList<Character>();
			found.add(curTrain.charAt(0));
			for (int i = 1; i < curTrain.length(); i++) {
				if (found.contains(curTrain.charAt(i))) {
					if (curTrain.charAt(i - 1) != curTrain.charAt(i)) {
						return 0;
					}
				} else {
					found.add(curTrain.charAt(i));
				}
			}
			return 1;
		}
		for (int i = 0; i < used.length; i++) {
			if (!used[i]) {
				used[i] = true;
				ans += checkPossible(trains, used, curTrain + trains[i], trainLength + 1);
				used[i] = false;
			}
		}
		return ans;
	}
	
	public static String setString(String str) {
		String ans = "";
		for (int i = 0; i < str.length(); i++) {
			if (i == 0 || str.charAt(i) != str.charAt(i - 1)) {
				ans += str.charAt(i);
			}
		}
		return ans;
	}
}
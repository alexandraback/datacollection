import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class Third {
	
	public static void main(String[] args) throws FileNotFoundException{
		String name = "c-small-attempt3";
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		int tc = in.nextInt();
		for(int i = 1; i <= tc; i++){
			System.out.println(i);
			out.println("Case #" + i + ": " + solve(in));
		}
		out.close();
	}

	private static String solve(Scanner in) {
		int n = in.nextInt();
		HashMap<String, Integer> firstWords = new HashMap<String, Integer>();
		HashMap<String, Integer> secondWords = new HashMap<String, Integer>();
		String[][] ar = new String[n][2];
		for(int i = 0; i < n; i++){
			ar[i][0] = in.next();
			ar[i][1] = in.next();
			if(firstWords.containsKey(ar[i][0])){
				firstWords.put(ar[i][0], firstWords.get(ar[i][0]) + 1);
			}else{
				firstWords.put(ar[i][0], 1);
			}
			if(secondWords.containsKey(ar[i][1])){
				secondWords.put(ar[i][1], secondWords.get(ar[i][1]) + 1);
			}else{
				secondWords.put(ar[i][1], 1);
			}
		}
		return recur(ar, firstWords, secondWords, 0) + "";
	}
	
	public static int recur(String[][] ar, HashMap<String, Integer> hm1, HashMap<String, Integer> hm2, int ind){
		if(ind == ar.length){
			return 0;
		}
		int first = hm1.get(ar[ind][0]);
		int second = hm2.get(ar[ind][1]);
		int ori = recur(ar, hm1, hm2, ind + 1);
		if(first > 1 && second > 1){
			HashMap<String, Integer> copy1 = new HashMap<String, Integer>(hm1);
			HashMap<String, Integer> copy2 = new HashMap<String, Integer>(hm2);
			copy1.put(ar[ind][0], first - 1);
			copy2.put(ar[ind][1], second - 1);
			int rec = recur(ar, copy1, copy2, ind + 1) + 1;
			if(rec > ori){
				ori = rec;
			}
		}
		return ori;
	}
}

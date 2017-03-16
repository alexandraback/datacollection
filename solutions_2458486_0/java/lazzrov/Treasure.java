import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Treasure {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("D-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("treasure.out"));

		int T = in.nextInt();
		
		long start = System.currentTimeMillis();
		
		for (int t = 1; t <= T; t++) {
			int K = in.nextInt();
			int N = in.nextInt();
			
			ArrayList<Integer> startingKeys = new ArrayList<Integer>();
			for (int i = 0; i < K; i++) {
				startingKeys.add(in.nextInt());
			}
			
			openingKey = new int[N];
			has = new ArrayList[N];
			for (int i = 0; i < has.length; i++) {
				has[i] = new ArrayList<Integer>();
			}
			
			for (int i = 0; i < N; i++) {
				openingKey[i] = in.nextInt();
				int Ki = in.nextInt();
				for (int j = 0; j < Ki; j++) {
					has[i].add(in.nextInt());
				}
			}
			
			
			done = new int[N];
			result = "";
			found = false;
			states = new HashSet<String>();
			
			dfs(startingKeys, "", 0);
			
			if(found){
				out.println("Case #" + t + ": " + result);
				System.out.println("Case #" + t + ": " + result);
			}
			else {
				out.println("Case #" + t + ": IMPOSSIBLE");
				System.out.println("Case #" + t + ": IMPOSSIBLE");
			}
			
		}
		
//		System.out.println(System.currentTimeMillis() - start);
		out.close();

	}
	
	static int openingKey[];
	static ArrayList<Integer> has[];
	
	static int done[];
	
	static String result;
	static boolean found;
	static HashSet<String> states;
	
	private static void dfs(ArrayList<Integer> keys, String curr, int count) {
		Collections.sort(keys);
		String v = keys.toString() + Arrays.toString(done);
		if(states.contains(v)){
			return;
		}
		states.add(v);
//		System.out.println(v);
		if(found) return ;
		if(count == done.length){
			found = true;
			result = curr.substring(1);
		}
		for (int i = 0; i < done.length; i++) {
			if(done[i] == 0 && keys.contains(openingKey[i])){
				ArrayList<Integer> next = new ArrayList<Integer>(keys);
				
				for (int j = 0; j < next.size(); j++) {
					if(next.get(j) == openingKey[i]){
						next.remove(j);
						break;
					}
				}
				
				next.addAll(has[i]);
				done[i] = 1;
				dfs(next, curr + " " + (i+1), count + 1);
				done[i] = 0;
			}
		}
		
	}

}

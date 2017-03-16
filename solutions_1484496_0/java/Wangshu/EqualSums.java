import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class EqualSums {

	static final String input_path = "data/input.txt";
	
	/**
	 * Good luck, Wash :)
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			String line = in.readLine();
			String[] parts = line.split(" ");
			int N = Integer.parseInt(parts[0]);
			int[] S = new int[N];
			for (int i = 1; i <= N; i ++)
				S[i - 1] = Integer.parseInt(parts[i]);
			
			Integer[][] ans = solve(S);
			System.out.println(String.format("Case #%d:", caseIter + 1));
			if (ans == null)
				System.out.println("Impossible");
			else {
				for (int i = 0; i < ans[0].length; i++) {
					System.out.print(ans[0][i]);
					System.out.print(' ');
				}
				System.out.println();
				for (int i = 0; i < ans[1].length; i++) {
					System.out.print(ans[1][i]);
					System.out.print(' ');
				}
				System.out.println();
			}
		}
		in.close();
	}

	private static Integer[][] solve(int[] s) {
		int N = s.length;
		for (int i = 0; i < N - 1; i ++)		
			for (int j = i + 1; j < N; j ++) {
				if (s[i] > s[j]) {
					int tmp = s[i];
					s[i] = s[j];
					s[j] = tmp;
				}
			}
		
		Map<Integer, Set<Integer>> record = new HashMap<Integer, Set<Integer>>();
		
		record.put(0, new HashSet<Integer>());
		for (int i = 0; i < N; i++) {
			Map<Integer, Set<Integer>> newEntities = new HashMap<Integer, Set<Integer>>();
			for (int existsum : record.keySet()) {
				int newsum = existsum + s[i];
				if (!record.containsKey(newsum)) {
					Set<Integer> currentSet = record.get(existsum);
					Set<Integer> newSet = new HashSet<Integer>();
					newSet.addAll(currentSet);
					newSet.add(s[i]);
					newEntities.put(newsum, newSet);
				} else {
					Set<Integer> compareSet = record.get(newsum);
					Set<Integer> currentSet = record.get(existsum);
					
					Set<Integer> compareSet_new = new HashSet<Integer>();
					compareSet_new.addAll(compareSet);
					
					Set<Integer> currentSet_new = new HashSet<Integer>();
					currentSet_new.addAll(currentSet);
					
					for (Integer compareNum : compareSet) 
						for (Integer currentNum: currentSet) 
							if (compareNum.equals(currentNum)) {
								compareSet_new.remove(compareNum);
								currentSet_new.remove(currentNum);
							}
					
					Set<Integer> newSet = new HashSet<Integer>();
					newSet.addAll(currentSet_new);
					newSet.add(s[i]);
					
					Integer ans[][] = new Integer[2][];
					ans[0] = new Integer[compareSet_new.size()];
					ans[0] = compareSet_new.toArray(ans[0]);
					
					ans[1] = new Integer[newSet.size()];
					ans[1] = newSet.toArray(ans[1]);
					return ans;
				}
			}
			record.putAll(newEntities);
		}
		return null;
	}
}

import java.io.*;
import java.util.*;

public class C {
	private static void updatePossibleValues(int V, int C, Vector<Integer> denoms, int index, int sum, HashSet<Integer> set) {
		if (index == denoms.size())
			return;
		int length = denoms.size();
		for (int i = 0; i <= C; ++i) { 
			int temp = sum+i*denoms.get(index);
			if (!set.contains(temp)) {
				set.add(temp);
			}
			updatePossibleValues(V, C, denoms, index+1, temp, set);
		}
	}

	private static boolean containsAll(int V, HashSet<Integer> set) {
		for (int i = 1; i <= V; ++i) {
			if (!set.contains(i))		
				return false;
		}
		return true;
	}
		
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(args[1], "UTF-8");
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; ++t) {
			out.print("Case #"+t+": ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			int C = Integer.parseInt(st.nextToken());
			int D = Integer.parseInt(st.nextToken());
			int V = Integer.parseInt(st.nextToken());
			Vector<Integer> denoms = new Vector<Integer>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < D; ++i)
				denoms.add(Integer.parseInt(st.nextToken()));			
			HashSet<Integer> set = new HashSet<Integer>();
			updatePossibleValues(V, C, denoms, 0, 0, set);
			while(!containsAll(V, set)) {
				HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();
				int maxCount = -1;
				int denom = -1;
				for (int i = 1; i <= V; ++i) {
					if (!set.contains(i)) {
						temp.put(i, 1);
						for (int j = 1; j <= V; ++j) {
							if (set.contains(j)) {
								int key = i-j;
								if (!temp.containsKey(key))
									temp.put(key, 1);
								int count = temp.get(key);
								if (count > maxCount) {
									maxCount = count;
									denom = key;
								}
							}
						}
					}
				}
				denoms.add(denom);
				updatePossibleValues(V, C, denoms, 0, 0, set);
			}
			out.println(denoms.size()-D);
		}

		out.flush();
		out.close();

		System.exit(0);
	}
}
							
							  
				

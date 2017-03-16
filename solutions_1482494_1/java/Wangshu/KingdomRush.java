import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class KingdomRush {

	static final String input_path = "data/input.txt";
	
	static private class State {
		public int starEarned;
		public int[] levelReached;
		
		public State(int N) {
			starEarned = 0;
			levelReached = new int[N];
			for (int i = 0; i < N; i ++) 
				levelReached[i] = 0;
		}
		
		public State(int star, int[] level) {
			starEarned = star;
			levelReached = level;
		}
		
		public boolean checkNextMove(int level, int star, int[] a, int[] b) {
			if (star == 1 && this.starEarned < a[level])
				return false; 
			
			if (star == 2 && this.starEarned < b[level])
				return false;
			
			int current = this.levelReached[level];
			return (current < star);
		}
		
		public String toString() {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < levelReached.length; i ++)
				sb.append(levelReached[i]);
			return String.format("%d: %s", starEarned, sb.toString());
		}
		
		public String getStateStr() {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < levelReached.length; i ++)
				sb.append(levelReached[i]);
			return sb.toString();
		}
	}
	
	private static int solveEasy(int N, int[] a, int[] b) {
		List<State> st_lst = new ArrayList<State>();
		st_lst.add(new State(N));
		
		Set<String> checked = new HashSet<String>();
		
		int step = 0;
		while (true) {
			List<State> st_lst_new = new ArrayList<State>();
			
			for (State st : st_lst) {
				if (st.starEarned >= 2 * N)
					return step;
				for (int i = 0; i < N; i ++)
					for (int star = 1; star <= 2; star ++)
						if (st.checkNextMove(i, star, a, b)) {
							int current = st.levelReached[i];
							int[] levelReached_new = st.levelReached.clone();
							levelReached_new[i] = star;
							State st_new = new State(st.starEarned + star - current, levelReached_new);
							if (checked.contains(st_new.getStateStr()))
								continue;
							else {
								st_lst_new.add(st_new);
								checked.add(st_new.getStateStr());
							}
						}
			}
			
			if (st_lst_new.size() > 0) {
				st_lst = st_lst_new;
				
//				System.out.println(String.format("Step %d", step));
//				for (State st : st_lst) {
//					System.out.print(st.toString());
//					System.out.print(',');
//				}
//				System.out.println();
				
				step += 1;
			} else
				return -1;
		}
	}
	
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
			intext = in.readLine();
			
			int N = Integer.parseInt(intext);
			int[] a = new int[N];
			int[] b = new int[N];
			
			for (int i = 0; i < N; i  ++) {
				intext = in.readLine();
				String[] parts = intext.split(" ");
				a[i] = Integer.parseInt(parts[0]);
				b[i] = Integer.parseInt(parts[1]);
			}
			
			int ans = solveEasy(N, a, b);
			
			if (ans < 0)
				System.out.println(String.format("Case #%d: Too Bad", caseIter + 1));
			else
				System.out.println(String.format("Case #%d: %d", caseIter + 1, ans));
		}
		in.close();
	}

}

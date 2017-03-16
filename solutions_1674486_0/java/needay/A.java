import java.util.*;
import java.io.*;

public class A {
	
	public int number;
	
	public List< List<Integer>> inh;
	
	public static void main(String[] args) throws Exception {
		String inputfilename = args[0];
		String outputfilename = args[1];
		BufferedReader br = new BufferedReader(new FileReader(inputfilename));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outputfilename));
		int cases = Integer.valueOf(br.readLine());
		for(int i = 0; i < cases; i++) {
			A a = new A();
			
			
			String[] ele = br.readLine().split(" ");
			a.number = Integer.valueOf(ele[0]);
			a.inh = new ArrayList<List<Integer>>();
            for(int j = 0; j < a.number; j++)
            {
            	List<Integer> tmp = new ArrayList<Integer>();
            	ele = br.readLine().split(" ");
            	for(int k = 1; k < ele.length; k++) {
            		tmp.add(Integer.valueOf(ele[k]));
            	}
            	a.inh.add(tmp);
            }
			boolean result = a.solve();
			bw.write("Case #" + (i + 1) + ": ");
			if(result)
				bw.write("Yes\n");
			else
				bw.write("No\n");
		}
		br.close();
		bw.close();
	}
	
	public boolean solve() {
		for(int i = 1; i <= this.number; i++) {
			if(test(i)) {
				return true;
			}
		}
		return false;
	}
	
	public boolean test(int cur) {
		Set<Integer> inset = new HashSet<Integer>();
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(cur);
		inset.add(cur);
		while(!queue.isEmpty()) {
			int tmpc = queue.poll();	
			for(Integer next : this.inh.get(tmpc - 1)) {
				if(inset.contains(next)) {
					return true;
				} else {
					inset.add(next);
					queue.add(next);
				}
			}

		}
		return false;
	}
}

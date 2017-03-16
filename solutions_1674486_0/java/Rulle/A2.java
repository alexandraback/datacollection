import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class A2 {
	public static void main(String[] args) throws InterruptedException {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int casenum = 1;

		Thread.sleep(1000);
		while (T-- > 0) {
			String num = solve(sc);
			System.out.println("Case #" + casenum++ + ": " + num);
			
		}
	}

	private static String solve(Scanner sc) {
		

		int N = sc.nextInt();
		Leaf[] all = new Leaf[N];
		int[] M = new int[N];
		for (int i = 0; i < N; i++) {
			all[i] = new Leaf(i+1);
		}

		
		HashMap<Integer,String> s = new HashMap<Integer, String>();
		for (int i = 0; i < N; i++) {
			int Mi = sc.nextInt();
			for (int j = 0; j < Mi; j++) {
				all[i].leafs.add(all[sc.nextInt()-1]);
			}
		}
		for (int i = 0; i < N; i++) {
			if(addPaths(i+1,all[i],s,"")) return "Yes";
		}
		
		
		
		return "No";
	}

	private static boolean addPaths(int start, Leaf leaf, HashMap<Integer, String> s, String road) {
		road += leaf.id + "";
		int key = start *1000+leaf.id;
		
		if(s.containsKey(key) && !s.get(key).equals(road)){
			//System.out.println("We have a winner: " + road + " and " + s.get(key) + " :)");
			return true;
		}
		//System.out.println(key +  " - " + road );
		if(leaf.id != start) {
			
			s.put(key, road);
		}
		
		for (int i = 0; i < leaf.leafs.size(); i++) {
			if(addPaths(start, leaf.leafs.get(i),s,road + "-")) return true;
		}
		return false;
	}


}
class Leaf   {
	public ArrayList<Leaf> leafs = new ArrayList<Leaf>();
	public HashSet<Leaf> reach = new HashSet<Leaf>();
	public int id;

	public Leaf(int id) {
		this.id = id;
	}
	
	@Override
		public int hashCode() {
			return id;
		}
	@Override
		public boolean equals(Object obj) {
			return obj.hashCode() == hashCode();
		}

}
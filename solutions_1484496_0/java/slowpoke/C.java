import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class C {

	public static void main(String[] args) throws Exception {
//		Scanner sc = new Scanner(new File("C-large.in"));
//		pw = new PrintWriter("C-large.out");
		Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		pw = new PrintWriter("C-small-attempt0.out");
//		Scanner sc = new Scanner(new File("C-small.in"));
//		pw = new PrintWriter("C-small.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int N = sc.nextInt();
			int[] vals = new int[N];
			for(int i=0; i<N; i++){
				vals[i] = sc.nextInt();
			}
			pw.println("Case #" + t + ":");
			map.clear();
			if(!sum(vals, new ArrayList<Integer>(), 0, 0)){
				pw.println("Impossible");
			}
		}
		
		pw.close();
		sc.close();
	}
	
	static HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
	static PrintWriter pw = null;
	public static boolean sum(int[] vals, ArrayList<Integer> subset, int curSum, int cur){
		if(cur >= vals.length){
			if(map.containsKey(curSum)){
				ArrayList<Integer> list = map.get(curSum);
				for(int i=0; i<list.size(); i++){
					pw.print(list.get(i));
					if(i < list.size()-1)
						pw.print(" ");
				}
				pw.println();
				
				list = subset;
				for(int i=0; i<list.size(); i++){
					pw.print(list.get(i));
					if(i < list.size()-1)
						pw.print(" ");
				}
				pw.println();
				return true;
			}else{
				ArrayList<Integer> newList = new ArrayList<Integer>();
				newList.addAll(subset);
				map.put(curSum, newList);
				return false;
			}
		}
		
		boolean found = sum(vals, subset, curSum, cur+1);
		if(found) return true;
		subset.add(vals[cur]);
		found = sum(vals, subset, curSum+vals[cur], cur+1);
		subset.remove(subset.size()-1);
		return found;
	}

}

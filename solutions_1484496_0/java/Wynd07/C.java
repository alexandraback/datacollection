import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class C {
	HashMap<Integer, ArrayList<Integer>> map;
	int[] ar;
	boolean done;
	public static void main (String [] args) throws IOException {new C().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		int times = file.nextInt();
		for(int asdf = 0; asdf<times; asdf++){
			System.out.println (asdf);
			ar = new int[file.nextInt()];
			for(int i = 0; i<ar.length; i++)
				ar[i] = file.nextInt();
			map = new HashMap<Integer, ArrayList<Integer>>();
			int a1 = 0, a2 = 0;
			recur(0,0,0);
			outer: for(int i : map.keySet()){
				ArrayList<Integer> set = map.get(i);
				if( set.size() >= 2){
					for(int j = 0; j<set.size(); j++)
						for(int k = j+1; k<set.size(); k++)
							if( (set.get(j) & set.get(k) ) == 0 )
							{
								a1 = set.get(j);
								a2 = set.get(k);
								break outer;
							}
				}
			}
			out.println("Case #" + (asdf+1) + ":");
			if( a1 == 0 && a2 == 0)
				out.println("Impossible");
			else{
				TreeSet<Integer> t1 = new TreeSet<Integer>();
				TreeSet<Integer> t2 = new TreeSet<Integer>();
				for(int i = 0; i<ar.length; i++)
					if( (a1 & (1<<i)) != 0)
						t1.add(ar[i]);
				for(int i = 0; i<ar.length; i++)
					if( (a2 & (1<<i)) != 0)
						t2.add(ar[i]);
				out.println (t1.toString().replaceAll("[\\[\\],]",""));
				out.println (t2.toString().replaceAll("[\\[\\],]",""));
			}
		}
		out.close();
		System.exit(0);
	}
	void recur(int x, int cur, int sum){
		if( cur == ar.length){
			if( !map.containsKey(sum))
				map.put(sum, new ArrayList<Integer>());
			if(sum!=0)
				map.get(sum).add(x);
			return;
		}
		recur(x | (1<<cur), cur+1, sum+ar[cur]);
		recur(x, cur+1, sum);
	}
}
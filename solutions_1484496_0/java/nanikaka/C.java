package gcj2012.r1b;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class C {

	final boolean DEBUG = false;
	final boolean isSmall = true;
	final String PACKAGE = "gcj2012/r1b";
	final String PROBLEM = "C";
	
	void run(){
		if(!DEBUG){
			try {
				if(isSmall)System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
				else System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				if(isSmall)System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
				else System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int CASE=1;CASE<=T;CASE++){
			int N = sc.nextInt();
			int[] a = new int[N];
			for(int i=0;i<N;i++)a[i]=sc.nextInt();
			Map<Integer, Set<Integer>> ref = new HashMap<Integer, Set<Integer>>();
			for(int S=1;S<1<<N;S++){
				int s = 0;
				for(int j=0;j<N;j++)if(((S>>j)&1)>0)s+=a[j];
				if(ref.containsKey(s))ref.get(s).add(S);
				else{
					Set<Integer> set = new HashSet<Integer>();
					set.add(S);
					ref.put(s, set);
				}
			}
			boolean ok = false;
			int r1 = -1, r2 = -1;
			for(int key:ref.keySet()){
				Set<Integer> set = ref.get(key);
				for(int A:set)for(int B:set){
					if(ok)break;
					if((A&B)==0){
						ok = true; r1 = A; r2 = B;
						break;
					}
				}
				if(ok)break;
			}
			System.out.println("Case #"+CASE+":");
			if(!ok)System.out.println("Impossible");
			else{
				String res = "";
				for(int j=0;j<N;j++){
					if(((r1>>j)&1)>0){
						res+=a[j]+" ";
					}
				}
				System.out.println(res.substring(0, res.length()-1));
				res = "";
				for(int j=0;j<N;j++)if(((r2>>j)&1)>0)res+=a[j]+" ";
				System.out.println(res.substring(0, res.length()-1));
			}
		}
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}

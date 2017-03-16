import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class C {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("C-small-attempt0.in"));//
		PrintWriter out = new PrintWriter("out.txt");
		int T = in.nextInt();
		for(int i=1;i<=T;i++){
			int c  = in.nextInt();
			int d = in.nextInt();
			int v = in.nextInt();
			HashSet<Integer> set = new HashSet<Integer>();
			for(int j=0;j<d;j++){
				set.add(in.nextInt());
			}
			int res = solve(c,v,set);
			out.println("Case #"+i+": "+res);
		}
		
		out.close();
		in.close();

	}
	
	private static int solve(int c, int v, HashSet<Integer>set){
		int res = 0;
		int maxReach = 0;
		int cv = 1;
		while(cv<=v){
			if(!set.contains(cv)){
				set.add(cv);
				res++;
			}
			maxReach+=c*cv;
			int temp = sumSet(c,maxReach,set);
			while(temp>maxReach){
				maxReach = temp;
				temp = sumSet(c,maxReach,set);
			}
			cv=maxReach+1;
		}
		return res;
	}
	
	private static int sumSet(int c, int cv, HashSet<Integer> set){
		int res = 0;
		for(int i:set){
			if(i<=cv){
				res+=i;
			}
		}
		return res;
	}

}

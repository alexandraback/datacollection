import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Recycled {

	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new File("recycled.in"));
		System.setOut(new PrintStream(new File("recycled.out")));
		int T = sc.nextInt();
		LinkedList<Pair> p;
		Pair add = null;
		for(int set=1; set<=T; set++){
			p = new LinkedList<Pair>();
			int A = sc.nextInt();
			int B = sc.nextInt();
			for(int n=A; n<B+1; n++){
				String sA = n+"";
				for(int j = 1; j<sA.length(); j++){
					String sM = sA.substring(j)+sA.substring(0,j);
					int m = Integer.parseInt(sM);
					add = new Pair(n,m);
					if(A<= m && m<=B && n!=m && !p.contains(add)){
						p.add(add);
					}
				}
			}
			System.out.println("Case #"+set+": "+p.size());
		}
	}

}
class Pair{
	int small, large;
	public Pair(int i, int j){
		if(i<j){
			small = i; large = j;
		}
		else{
			small = j; large = i;
		}
	}
	public boolean equals(Object o){
		return ((Pair)o).small == small && ((Pair)o).large == large;
	}
}

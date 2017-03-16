package info.stephenn.codejam2012.round1c;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		sc.nextLine();
		for (int caseX = 1; caseX <= cases; caseX++){
			//String line = sc.nextLine();
			int n = sc.nextInt();
			List<List<Integer>> nhirachy = new ArrayList<List<Integer>>();
			for (int ni = 0; ni < n; ni++) {
				int mi = sc.nextInt();
				List<Integer> m = new ArrayList<Integer>();
				for (int i = 0; i < mi; i++) {
					m.add(sc.nextInt());
				}
				nhirachy.add(m);
			}
			
			boolean isdiamond = doit(nhirachy);
			
			if (isdiamond){
				System.out.println("Case #"+caseX+": Yes");
			} else{
				System.out.println("Case #"+caseX+": No");
			}
		}
	}
	
	public static boolean doit(List<List<Integer>> n){
		for (int ni=0; ni < n.size(); ni++){
			//does this n have two mapps to something.
			List<Integer> everythingForM = new ArrayList<Integer>();
			List<Integer> mh = n.get(ni);
			
			for(int mi: mh){
				everythingForM.addAll(everythingThatMapTo(n,mi));
			}
			
			if (doesListContainDuplicates(everythingForM))
				return true;
		}
		return false;
	}
	
	public static boolean doesListContainDuplicates(List<Integer> l){
		Collections.sort(l);
		for (int i=0; i< l.size()-1; i++){
			if (l.get(i) == l.get(i+1))
				return true;
		}
		return false;
	}
	
	public static List<Integer> everythingThatMapTo(List<List<Integer>> n, int m){
		List<Integer> everything = new ArrayList<Integer>();
		everything.add(m);
		for(int mi : n.get(m-1)){
			everything.addAll(everythingThatMapTo(n,mi));
		}
		return everything;
	}
}

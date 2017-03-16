import java.io.File;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Scanner;


public class B {
	
	static class Pair{
		int a;
		int b;
		int stat=0;
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B-large.in"));
		PrintWriter pw = new PrintWriter("B-large.out");
//		Scanner sc = new Scanner(new File("B-small-attempt0.in"));
//		PrintWriter pw = new PrintWriter("B-small-attempt0.out");
//		Scanner sc = new Scanner(new File("B-small.in"));
//		PrintWriter pw = new PrintWriter("B-small.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int N = sc.nextInt();
			LinkedList<Pair> sortByA = new LinkedList<Pair>();
			LinkedList<Pair> sortByB = new LinkedList<Pair>();
			for(int i=0; i<N; i++){
				Pair p = new Pair();
				p.a = sc.nextInt();
				p.b = sc.nextInt();
				sortByA.add(p);
				sortByB.add(p);
			}
			
			Collections.sort(sortByA, new Comparator<Pair>(){

				@Override
				public int compare(Pair lhs, Pair rhs) {
					if(lhs.a < rhs.a) return -1;
					if(lhs.a > rhs.a) return 1;
					return rhs.b-lhs.b; 
				}
			});
				
			Collections.sort(sortByB, new Comparator<Pair>(){

				@Override
				public int compare(Pair lhs, Pair rhs) {
					if(lhs.b < rhs.b) return -1;
					if(lhs.b > rhs.b) return 1;
					return 0; 
				}
			});
			
			int compete = 0;
			int stars = 0;
			while(true){
				if(sortByB.size() == 0){
					break;
				}
				Pair two = sortByB.get(0);
				if(two.stat == 2){
					sortByB.remove(0);
					continue;
				}
				if(two.b <= stars){
					stars += 2-two.stat;
					two.stat = 2;
					sortByB.remove(0);
					compete++;
					continue;
				}
				Pair chosen = null;
				int maxTwo = -1;
				int index = -1;
				for(int j=0; j<sortByA.size(); j++){
					Pair one = sortByA.get(j);
					if(one.stat != 0) continue;
					if(one.a <= stars){
						if(one.b > maxTwo){
							chosen = one;
							maxTwo = one.b;
							index = j;
						}
					}else{
						break;
					}
				}
				
				if(chosen != null){
					sortByA.remove(index);
					chosen.stat = 1;
					stars++;
					compete++;
				}else{
					break;
				}
			}
			
			if(stars == N*2)
				pw.println("Case #" + t + ": " + compete);
			else			
				pw.println("Case #" + t + ": Too Bad");
		}
		
		pw.close();
		sc.close();
	}

}

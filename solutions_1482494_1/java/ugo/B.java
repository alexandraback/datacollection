package gcj2012.R1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	static Scanner sc;
	public static void main(String[] f) throws FileNotFoundException{

		sc =  new Scanner(new File("/Users/jiohyoo/Desktop/B-large.in"));				
		long numCases = Long.parseLong(sc.nextLine());
		for(long kase = 0 ; kase < numCases ; kase++){
			int len = sc.nextInt();
			S[] stages = new S[len];
			for(int i = 0 ; i < len ; i++)
				stages[i] = new S(sc.nextInt(), sc.nextInt());
			
			Arrays.sort(stages);
			
//			System.out.println(Arrays.toString(stages));
			int ret = 0;
			int stars = 0;
			boolean ok = true;
			for(int com = 0 ; com < len ; com++){

				while(stages[com].s2 > stars){
					int found = -1;
					for(int i = len-1 ; i >= com ; i--){
//						System.out.println(" checking " + i + " " + stages[i]);
						if(stages[i].s1c || stages[i].s1 > stars) continue;
						else{found = i; break;}
					}
					if(found >= 0){
						stars += 1;
//						System.out.println("found " + found);
						ret++;
						stages[found].s1c = true;
					}else{
						ok = false;
						break;
					}
				}
				if(!ok){
					break;
				}
				
//				System.out.println("cleared " + com);
				ret++;
				stages[com].s2c = true;
				if(stages[com].s1c){
					stars++;
				}else{
					stars += 2;
				}
			}
			if(ok){
				System.out.println("Case #" + (kase+1) + ": " + ret);			
			}else{
				System.out.println("Case #" + (kase+1) + ": Too Bad");			
			}

		}
	}
	
	static class S implements Comparable<S>{
		public int s1, s2;
		public boolean s1c, s2c;
		public S(int a, int b){
			s1 = a; s2 = b;
			s1c = false; s2c = false;
		}
		@Override
		public int compareTo(S arg0) {
			if(s2 != arg0.s2){
				return s2 - arg0.s2;
			}else{
				return s1 - arg0.s1;
			}
		}
		
		public String toString(){
			return "(" + s1 + "," + s2 + ")";
		}
	}
}
/*
4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6	 
Case #1: 3
Case #2: 3
Case #3: Too Bad
Case #4: 6
*/


import java.util.ArrayList;
import java.util.Scanner;


public class Sums {
	static boolean done = false;
	static int[] ss;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for(int i = 1; i<= numCases; i++) {
			done = false;
			int n = scan.nextInt();
			int[] set = new int[n];
			ss = new int[n];
			for(int j = 0; j < n; j++) {
				set[j] = scan.nextInt();
				ss[j] = 0;
			}
			findsubsets(set,0,0,0);
			System.out.println("Case #" + i + ": ");
			if(!done) System.out.println("Impossible");
			else {
				ArrayList<Integer> a = new ArrayList<Integer>();
				ArrayList<Integer> b = new ArrayList<Integer>();
				for(int j = 0; j < n; j++) {
					//System.err.println(ss[j]);
					switch(ss[j]) {
					case 1: a.add(set[j]); break;
					case 2: b.add(set[j]); break;
					}
				}
				for(Integer inte:a) {
					System.out.print(inte + " ");
				}
				System.out.println();
				for(Integer inte:b) {
					System.out.print(inte + " ");
				}
				System.out.println();
			}
			//Print answer
		}
	}
	
	public static void findsubsets(final int[] set, int sumA, int sumB, int index) {
		if(done) return;
		if(index == set.length-1) {
			if(sumA == sumB && sumA!=0) {
				done = true;
				return;
			}
			if(sumA == sumB + set[index]) {
				ss[index] = 2;
				done = true;
				return;
			}
			if(sumA+set[index]==sumB) {
				ss[index] = 1;
				done=true;
			}
			return;
		}
		ss[index] = 0;
		findsubsets(set,sumA,sumB,index+1);
		if(done) return;
		ss[index] = 1;
		sumA+=set[index];
		findsubsets(set,sumA,sumB,index+1);
		if(done) return;
		ss[index] = 2;
		sumA-=set[index];
		sumB+=set[index];
		findsubsets(set,sumA,sumB,index+1);
	}
	
	
}

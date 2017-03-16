package info.stephenn.codejam2012.qualify;

import java.util.Scanner;

public class C {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseX=1; caseX <= cases; caseX+=1){
			int A = sc.nextInt();
			int B = sc.nextInt();
			System.out.println("Case #"+caseX+": "+doit(A,B));
		}
	}
	
	public static int doit(int A, int B){
		int count=0;
		for (int m = A+1; m <= B; m++){
			for (int n = A; n < m; n++){
				count += isRecycledString(Integer.toString(n), Integer.toString(m));
			}
		}
		return count;
	}
	
	public static int countRecycled(int n, int m){
		int count=0;
		
		System.out.println("countRecycled"+n+","+m);
		
		int split = 10;
		
		while (true){
			
			if (split > n) break;
			
			int front = n/ split;
			int behind = n %split;
			int behindInfront = behind * split;
			int t = behindInfront + front;
			
			if (t ==m){
				System.out.println(""+t+" == "+m+" split"+split+" n"+n);
				count +=1;
			}
			split = split * 10;
		}
		return count;
	}
	
	public static int isRecycledString(String n, String m){
		for (int split =1; split < n.length(); split++){
			String t = n.substring(split) + n.substring(0, split);
			if (t.equals(m))
				return 1;
		}
		return 0;
	}
}
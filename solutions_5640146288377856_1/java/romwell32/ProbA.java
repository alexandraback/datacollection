import java.util.Scanner;


public class ProbA {

	
	static int f(int R, int C, int W){
		int ans = (C/W)*R+(W-1);
		if ((C%W)>0){
			ans += 1;
		}
		return ans;
	}
	
	public static void main (String [] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i<T; i++){
			int R = sc.nextInt();
			int C = sc.nextInt();
			int W = sc.nextInt();
			System.out.println("Case #"+(i+1)+": "+f(R,C,W));		
		}
		
	}
	
}

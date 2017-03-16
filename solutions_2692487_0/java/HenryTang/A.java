import java.io.*;
import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.util.*;


public class A {
	public static void main (String[] args){
		Scanner sc = new Scanner (System.in);
		int T = sc.nextInt();
		for (int i=0;i<T;i++){
			System.out.print("Case #" + (1+i) + ": ");
			solve(sc);
			System.out.print("\n");
		}
	}

	private static void solve(Scanner sc) {
		int A = sc.nextInt();
		int N = sc.nextInt();
		int ans = 0;
		ArrayList<Integer> sizes = new ArrayList<Integer>();
		for (int i=0;i<N;i++){
			sizes.add(sc.nextInt());
		}
		Collections.sort(sizes);
		while (true){
			if (sizes.isEmpty()){
				break;
			}
			else if (A > sizes.get(0)){
				A=A+sizes.get(0);
				sizes.remove(0);
			}
			else break;
		}
		ans = calc (A, sizes);
		System.out.println(ans);
		

		
		
	}

	private static int calc(int A, ArrayList<Integer> sizes) {
		while (true){
			if (sizes.isEmpty()){
				break;
			}
			else if (A > sizes.get(0)){
				A=A+sizes.get(0);
				int temp = sizes.remove(0);
			}
			else break;
		}
		if (sizes.isEmpty()){
			return 0;
		}
		else {
			ArrayList<Integer> newlst = new ArrayList<Integer>(sizes);
			int temp = newlst.remove(0);
			int ans2 = calc(A, newlst);
			if (A==1){
				return 1 + ans2;
			}
			int ans1 = calc(A+A-1, sizes);
			
			return 1 + Math.min(ans1,  ans2);
	}
	}
}
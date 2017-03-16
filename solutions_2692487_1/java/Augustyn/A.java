//package b2;

import java.util.Arrays;
import java.util.Scanner;

public class A {
	static int a;
	static int n;

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		
		scanner.nextLine();
		for (int p = 0; p < t; p++) {

			a = scanner.nextInt();
			n = scanner.nextInt();
			int[] tab=new int[n];
			for(int i =0; i<n; i++)
				tab[i]=scanner.nextInt();
			Arrays.sort(tab);

			int res=0;
			fin:
			for(int i = 0; i<=n; i++)
				for(int j=0; j<=i; j++)
						if(solve(tab,j,i-j)){
							res = i;
							break fin;
						}
							
						
			System.out.println("Case #" + (p + 1 + ": ") + res);
		}

	}
	public static boolean solve(int[] tab, int add, int rem){
		int W = a;
		for(int i = 0; i<tab.length; i++){
			if(tab[i]<W)
				W+=tab[i];
			else {
				while(tab[i]>=W&&add>0){
					W+=W-1;
					add--;
				}
				if(tab[i]>=W){
					if(rem==0)
						return false;
					else
						rem--;
				}
				else{
					W+=tab[i];
				}
			}
		}
		return true;
	}

}

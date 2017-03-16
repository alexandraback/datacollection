package googleCodeJam2014r1b;

import java.util.Scanner;

public class B {

	static int A,B,K;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			A=sc.nextInt();
			B=sc.nextInt();
			K=sc.nextInt();
			int ans=0;
			for(int i=0;i<A;i++){
				for(int j=0;j<B;j++){
					int bit = i&j;
					if(bit<K){
						ans++;
					}
				}
			}
			System.out.println(ans);
		}
	}

}

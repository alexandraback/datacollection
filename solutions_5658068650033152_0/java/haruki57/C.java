package googleCodeJam2014r1c;

import java.util.Scanner;

public class C {

	static int N,M,K;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		L:for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			N=sc.nextInt();
			M=sc.nextInt();
			K=sc.nextInt();
			if(N<=2 || M<= 2 || K <= 4){
				System.out.println(K);
				continue;
			}
			int c=1,r=1;
			int sum=0,pre=0;;
			boolean f=true;
			int cnt=0;
			while(true){
				cnt++;
				if(cnt>=100000000){
					System.out.println(K);
					break;
				}
				if(c+3 <= N){
					c++;
				}
				pre=sum;
				sum=sum(c,r);
				if(sum >= K){
					System.out.println(r*2+c*2);
					break;
				}
				
				if(r+3 <= M){
					r++;
				}
				pre=sum;
				sum=sum(c,r);
				if(sum >= K){
					System.out.println(r*2+c*2);
					break;
				}
			}
		}
	}
	static int sum(int c,int r){
		return c*r + c*2 + r*2;
	}
}
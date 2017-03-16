import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			int D=sc.nextInt();
			int[] P=new int[D+1];
			int X=-1;
			for (int i=1;i<=D;i++){
				P[i]=sc.nextInt();
				if (P[i]>X){
					X=P[i];
				}
			}
			int ans=Integer.MAX_VALUE;
			for (int i=1;i<=X;i++){
				int tempAns=i;
				for (int j=1;j<=D;j++){
					if (P[j]<=i){
						continue;
					}else{
						tempAns+=P[j]/i-1;
						if (P[j]%i>0){
							tempAns++;
						}
					}
				}
				if (tempAns<ans){
					ans=tempAns;
				}
			}
			System.out.println("Case #"+t+": "+ans);
		}
	}
}

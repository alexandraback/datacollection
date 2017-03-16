import java.util.Scanner;

public class Fractiles_s {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			int K=sc.nextInt();
			int C=sc.nextInt();
			int S=sc.nextInt();//S==K
			
			long ans[]=new long[K];
			for(int i=0;i<K;i++)
				ans[i]=i+1;
			long ctr=K;
			for(int i=1;i<C;i++){
				for(int j=0;j<K;j++){
					ans[j]+=j*ctr;
				}
				ctr*=K;
			}
			System.out.print("Case #"+cn+":");
			for(int i=0;i<K;i++)
				System.out.print(" "+ans[i]);
			System.out.println();
		}
	}

}

import java.util.Scanner;

public class Fractiles {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			int K=sc.nextInt();
			int C=sc.nextInt();
			int S=sc.nextInt();
			
			boolean okay=K<=(C*S);
			if(okay){
				
				long ans[]=new long[S];
				int ctr=0;
				int done=0;
				for(int i=0;i<K&&done<K;i++){
					long n=0;
					for(int j=0;j<C;j++){
						n=(n)*K+ctr;
						if(ctr<K-1)
							ctr++;
						done++;
					}
					ans[i]=(n+1);						
				}
				System.out.print("Case #"+cn+":");
				for(int i=0;i<S&&ans[i]>0;i++){
					System.out.print(" "+ans[i]);
				}
				System.out.println();
			}
			else
				System.out.println("Case #"+cn+": IMPOSSIBLE");
		}
	}
}

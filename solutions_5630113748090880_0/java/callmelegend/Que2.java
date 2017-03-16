
import java.util.*;
 Que2 {
	public static void main(String [] args){
		Scanner s= new Scanner(System.in);
		int t=s.nextInt();
		for(int i=0;i<t;i++){
			int n=s.nextInt();
			int [] store1=new int [2506];
			int largest=0;
			for(int j=1;j<=2*n-1;j++){
				for(int m=1;m<=n;m++){
					int st=s.nextInt();
					if(st>largest){
						largest=st;
					}
					store1[st]=1+store1[st];
				}
			}
			int [] ans=new int[n];
			int k=0;
			for(int j=1;j<=largest;j++){
				if(store1[j]%2!=0){
					ans[k]=j;
					k++;
				}
			}
			Arrays.sort(ans);
			System.out.print("Case #");
			System.out.print(i+1);
			System.out.print(": ");
			for(int j=0;j<ans.length;j++){
				System.out.print(ans[j]+" ");
			}
			System.out.println();
		}
	}
}

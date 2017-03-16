
import java.util.*;
 class Que3 {
	public static void main(String [] args){
		Scanner s= new Scanner(System.in);
		int t= s.nextInt();
		for(int i=0;i<t;i++){
			int n=s.nextInt();
			int [] store=new int [n+1];
			for(int j=1;j<=n;j++){
				store[j]=s.nextInt();
			}
			int ans=0;
			for(int j=1;j<=n;j++){
				int itr=0;
				int [] seen = new int[n+2];
				seen[j]=1;
				itr++;
				int k=store[j];
				int val=0;
				while(seen[k]!=1){
					seen[k]=1;
					itr++;
					val=k;
					k=store[k];
				}
				int flag=0;
				if(k==store[val]&&val==store[k]){
					flag=1;
				}
				int earlier=itr;
				seen[val]=0;
				for(int m=1;m<=n;m++){
					if(m==val){
						continue;
					}
					if(seen[m]!=1){
						
						int itr2=1;
						int l=store[m];
						while(seen[l]!=1){
							seen[l]=1;
							itr2++;
							if(l==val){
								if(flag==1){
								itr=itr+itr2-1;
								}
							}
						}
						
					}
				}
				if(earlier==itr){
					if((store[val]!=j && val!=store[j])&&flag==0){
						itr=itr-1;
					}
				}
				if(itr>ans){
					ans=itr;
				}
			}
			System.out.println(ans);
		}
	}
}

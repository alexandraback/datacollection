import java.util.Scanner;
import java.util.TreeSet;

public class BFFs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			int N=sc.nextInt();
			int F[]=new int[N];
			for(int i=0;i<N;i++){
				F[i]=sc.nextInt()-1;
			}
			int ans=0;
			boolean done[]=new boolean[N];
			int pair[]=new int[N];
			int pairs[]=new int[N];
			for(int i=0;i<N;pair[i++]=-1);
			boolean paired[]=new boolean[N];
			for(int i=0;i<N;i++){
				if(F[F[i]]==i){
					pair[i]=F[i];
					paired[i]=true;
					paired[F[i]]=true;
					pairs[i]=1;
				}
			}
			
			for(int s=0;s<N;s++){
				if(done[s])
					continue;
				TreeSet<Integer> set=new TreeSet<Integer>();
				int cur=s;
				while(!set.contains(cur)){
					set.add(cur);
					cur=F[cur];
				}
				if(cur==s){
					for(int i:set){
						done[i]=true;
					}
					ans=Math.max(ans, set.size());
				}
				if(paired[cur]){
					pairs[cur]=Math.max(pairs[cur], set.size()-1);
				}
				done[s]=true;
			}
			int tot=0;
			for(int i=0;i<N;i++){
				if(paired[i]){
					tot+=pairs[i];
				}
			}
			ans=Math.max(ans, tot);
			System.out.println("Case #"+cn+": "+ans); 
		}
	}

}

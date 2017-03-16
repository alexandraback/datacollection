import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class ManageYourEnergy {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
				
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine());
			int E=Integer.parseInt(st.nextToken());
			int R=Integer.parseInt(st.nextToken());
			R=Math.min(R, E);
			int N=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(br.readLine());
			int v[]=new int[N];
			for(int i=0;i<N;i++){
				v[i]=Integer.parseInt(st.nextToken());
			}
			//greedy
			//from right to left, assign energy use to highest
			//note maximum carry of E per activity
			long ans=0;
			int carryleft[]=new int[N];
			Arrays.fill(carryleft, E);
			PriorityQueue<Pair> q=new PriorityQueue<Pair>();
			int en=0;
			for(int i=N-1;i>=0;i--){
				en+=R;
				if(i==0)
					en=E;
				q.add(new Pair(v[i],E,i));
				while(en>0){
					Pair p=q.poll();
					long use=Math.min(en, p.left);
					int min=Integer.MAX_VALUE;
					for(int j=i+1;j<=p.loc;j++){
						min=Math.min(min,carryleft[j]);
					}
					use=Math.min(use,min);
					if(use==0)
						continue;
					for(int j=i;j<=p.loc;j++){
						carryleft[j]-=use;
					}
					ans+=use*p.val;
//					System.out.println(use+" "+p.val);
					en-=use;
					if(use<p.left){
						p.left-=use;
						q.add(p);
					}
				}
//				System.out.println(Arrays.toString(carryleft));
			}
			bw.append("Case #"+cn+": "+ans+"\n");
//			System.out.println();
		}
		bw.flush();
	}
	static class Pair implements Comparable<Pair>{
		int val, left, loc;

		public Pair(int val, int left, int loc){
			this.val=val;
			this.left=left;
			this.loc=loc;
		}
		
		public int compareTo(Pair that) {
			if(this.val==that.val)
				return this.loc-that.loc;
			return that.val-this.val;
		}
	}
}

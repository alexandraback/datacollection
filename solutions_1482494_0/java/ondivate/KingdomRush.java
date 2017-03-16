import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class KingdomRush {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			int N=Integer.parseInt(br.readLine());
			int a[]=new int[N];
			int b[]=new int[N];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine());
				a[i]=Integer.parseInt(st.nextToken());
				b[i]=Integer.parseInt(st.nextToken());
			}
			//n^2 greedy
			int cur=0;
			int ctr=0;
			boolean star1[]=new boolean[N];
			boolean star2[]=new boolean[N];
			boolean okay=true;
			while(cur<2*N){
				boolean changed=false;
				for(int i=0;i<N;i++){
					if(cur>=b[i]&&!star2[i]){
						if(!star1[i]){
							star1[i]=true;
							cur++;
						}
						star2[i]=true;
						cur++;
						changed=true;
						ctr++;
//						System.out.println("mark2 "+i);
					}
				}
				int max=-1;
				int maxp=-1;
				for(int i=0;i<N&&!changed;i++){
					if(cur>=a[i]&&!star1[i]){
						if(b[i]>max){
							max=b[i];
							maxp=i;
						}
					}
				}
				if(maxp!=-1){
					int i=maxp;
					star1[i]=true;
					cur++;
					changed=true;
					ctr++;
//					System.out.println("mark1 "+i);
				}
				if(!changed){
					okay=false;
					break;
				}
			}
//			System.out.println(ctr+" "+okay);
			if(okay)
				bw.append("Case #"+cn+": "+ctr+"\n");
			else
				bw.append("Case #"+cn+": Too Bad\n");
		}
		bw.flush();
	}
	
}

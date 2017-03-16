import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class InfiniteHouseOfPancakes {

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
			int D=Integer.parseInt(br.readLine());
			int P[]=new int[D];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<D;i++){
				P[i]=Integer.parseInt(st.nextToken());
			}
			int ans=1000;
			for(int i=1;i<=1000;i++){
				int ctr=0;
				for(int j=0;j<D;j++){
					ctr+=(P[j]+i-1)/i-1;
				}
				ctr+=i;
				ans=Math.min(ans, ctr);
			}
			bw.append("Case #"+cn+": "+ans+"\n");
		}
		bw.flush();
	}

}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class DancingWithGooglers {

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
			st=new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken());
			int S=Integer.parseInt(st.nextToken());
			int P=Integer.parseInt(st.nextToken());
			int t[]=new int[N];
			for(int i=0;i<N;i++)
				t[i]=Integer.parseInt(st.nextToken());
			//start counting
			int ctr=0;
			for(int i=0;i<N;i++){
				int a=(int) Math.ceil(t[i]/3.0);
				if(a>=P)
					ctr++;
				else if(S>0&&t[i]%3!=1&&a+1>=P&&t[i]>=2&&t[i]<=28){
					ctr++;
					S--;
				}
			}
			bw.append("Case #"+cn+": "+ctr+"\n");
		}
		bw.flush();
	}

}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class HikingDeer {

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
			int D[]=new int[N];
			int H[]=new int[N];
			int M[]=new int[N];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine());
				D[i]=Integer.parseInt(st.nextToken());
				H[i]=Integer.parseInt(st.nextToken());
				M[i]=Integer.parseInt(st.nextToken());
			}
			//small case
			double d1, d2;
			double s1, s2;
			if(N==1){
				d1=D[0]; d2=D[0];
				s1=360/(M[0]*1.0); s2=1/(M[0]+1.0);
			}
			else{
				d1=D[0]; d2=D[1];
				s1=360/(M[0]*1.0); s2=1/(M[1]*1.0);
			}
			if(s1>s2){
				double te1=d1, te2=s1;
				d1=d2; s1=s2;
				d2=te1; s2=te2;
			}
			int ans=1;
			
			double d=d1-d2, s=Math.atan(Math.tan(s2)+Math.tan(s1));
			double inter=((1.0-d)/s);
			System.out.println(inter);
					
			if(inter>0)
				ans=0;
			bw.append("Case #"+cn+": "+ans+"\n");
		}
		bw.flush();
	}

}

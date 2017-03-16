import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class PasswordProblem {

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
			int A=Integer.parseInt(st.nextToken());
			int B=Integer.parseInt(st.nextToken());
			int diff=B-A;
			double p[]=new double[A];
			st=new StringTokenizer(br.readLine());
			p[0]=Double.parseDouble(st.nextToken());
			for(int i=1;i<A;i++)
				p[i]=Double.parseDouble(st.nextToken())*p[i-1];
			double ans=B+2;
			for(int i=0;i<A;i++){
				double temp=(diff+1+2*i)*p[A-1-i]+(diff+B+2+2*i)*(1-p[A-1-i]);
				ans=Math.min(ans, temp);
			}
			bw.append("Case #"+cn+": "+String.format("%.7f", ans)+"\n");
		}
		bw.flush();
	}

}

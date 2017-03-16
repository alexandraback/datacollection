import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class Bullseye {

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
			long r=Long.parseLong(st.nextToken());
			long t=Long.parseLong(st.nextToken());
			System.out.println(r+" "+t);
			int ans=0;
			while((2*r+1)<=t){
				t-=2*r+1;
				ans+=1;
				r+=2;
			}
			bw.append("Case #"+cn+": "+ans+"\n");
		bw.flush();
		}

	}

}

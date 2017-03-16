import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
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
			int N=Integer.parseInt(st.nextToken());
			int max[]=new int[E+1];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				int v=Integer.parseInt(st.nextToken());
				int nm[]=new int[E+1];
				for(int j=0;j<=E;j++){
					for(int k=j;k<=E;k++){
						nm[j]=Math.max(nm[j],max[k]+(v*(k-j)));
					}
				}
				for(int j=Math.min(R, E);j<=E;j++){
					max[j]=nm[j-Math.min(R, E)];
				}
			}
			bw.append("Case #"+cn+": "+max[Math.min(R, E)]+"\n");
		}
		bw.flush();
	}

}

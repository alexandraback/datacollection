import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;


public class Prob4 {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int cases=Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=cases;t++){
			String out="Case #"+t+":";
			String[] splts=br.readLine().trim().split(" ");
			
			int N=Integer.parseInt(splts[0]);
			int M=Integer.parseInt(splts[1]);
			
			long[][] a=new long[N][2];
			long[][] b=new long[M][2];
			
			
			splts=br.readLine().split(" ");
			for(int i=0;i<N;i++){
				a[i][0]=Long.parseLong(splts[2*i]);
				a[i][1]=Long.parseLong(splts[2*i+1]);
				
			}
			

			splts=br.readLine().split(" ");
			for(int i=0;i<M;i++){
				b[i][0]=Long.parseLong(splts[2*i]);
				b[i][1]=Long.parseLong(splts[2*i+1]);
				
			}
			
			long[][] dp=new long[N+1][M+1];
			long[][] con1=new long[N+1][M+1];
			long[][] con2=new long[N+1][M+1];
			long max=0;
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					
					long r1=a[i][0]-con1[i][j];
					long r2=b[j][0]-con2[i][j];
					long shift=Math.min(r1, r2);

					if(shift<=0)
						continue;

					//System.out.println("i : "+i+" j : "+j+" shift "+shift);
					if(a[i][1]==b[j][1]){
						long best=dp[i][j]+shift;
						int i1=(r1>shift?0:1);
						int i2=(r2>shift?0:1);
						long nc1=(i1==0)? con1[i][j]+shift: 0;
						long nc2=(i2==0)? con2[i][j]+shift: 0;
						
						if((i+i1)<=N && (j+i2)<=M && dp[i+i1][j+i2]<best){
							max=Math.max(best, max);
							dp[i+i1][j+i2]=best;
							con1[i+i1][j+i2]=nc1;
							con2[i+i1][j+i2]=nc2;
						}
					}
					else{
						long best=dp[i][j]+0;
						if((i+1)<=N && dp[i+1][j]<best){
							dp[i+1][j]=best;
							con1[i+1][j]=0;
							con2[i+1][j]=con2[i][j];
						}
						if((j+1)<=M && dp[i][j+1]<best){
							dp[i][j+1]=best;
							con1[i][j+1]=con1[i][j];
							con2[i][j+1]=0;
						}
						
					}
				}
			}
			
			out+=(" "+max);
			System.out.println(out);
		}
	}
	
	static void solve(){
		
	}

}

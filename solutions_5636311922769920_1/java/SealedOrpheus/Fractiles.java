import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Fractiles {
	
	public static void main(String args[])
	{
		try (BufferedReader br = new BufferedReader(new FileReader("D:\\D-large.in")))
		{
			FileWriter fileWriter =   new FileWriter("D:\\D-large.out");
			BufferedWriter bw =   new BufferedWriter(fileWriter);
			int loop = Integer.parseInt(br.readLine());
			int input=0;
			String output="";
			int K=0;
			int C=0;
			int S=0;
			for(int i=1;i<=loop;i++){
				bw.write("Case #"+i+":");
				StringTokenizer st= new StringTokenizer(br.readLine());
				K = Integer.parseInt(st.nextToken());
				C = Integer.parseInt(st.nextToken());
				S = Integer.parseInt(st.nextToken());
				output="";
				int x= (K+C-1)/C;
				if(x>S){
					output=" IMPOSSIBLE";
				}else{
					long[] powK = new long[101];
					powK[0]=1;
					for(int j=1;j<=(C-1);j++){
						powK[j]=powK[j-1]*K;
					}
					for(int k=1;k<=x;k++){
						long temp=0;
						for(int l=0;l<=Math.min(C-1, K-1);l++){
							temp += Math.min((k-1)*C+l,(K-1))*powK[C-1-l];
						}
						temp++;
						output+=" "+temp;
					}
				}
				bw.write(output);
				bw.newLine();
			}				
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		} 
	}
}

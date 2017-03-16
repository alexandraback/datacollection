import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class score {
	
	static int[][] allCase;
	
	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new FileReader("./text6.txt"));
		FileWriter fstream = new FileWriter("./out6.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		
		String str,str2;
		
		int i = 0;
		int numTestCase = Integer.parseInt(in.readLine());
		
		while ((str = in.readLine()) != null) {
			str2="";
			String[] toks;
			toks = str.split(" ");
			int nc = Integer.parseInt(toks[0]);
			double[] p = new double[nc];
			int[] c = new int[nc];
			int[] c1 = new int[nc];
			int sum = 0;
			for(int j = 0; j<nc;j++)
			{
				c[j] = Integer.parseInt(toks[j+1]);
			}
			for(int j = 0; j<nc;j++)
			{
				sum = sum+c[j];
			}
			int cnt=0;
			int sum2 =0;
			for(int j = 0; j<nc;j++)
			{
				if(c[j]<=2*sum/nc) {
					cnt++;
					c1[j] = c[j];
					sum2 += c[j];
				}
				else 
				{
					c1[j] = -1;
				}
				
			}
			int left;
			for(int j = 0; j<nc;j++)
			{
				if(c1[j]!= -1){
					left = sum2 - c1[j];
					p[j] = (((double)left/((cnt-1)*sum))+(1.0/(cnt-1))-(c1[j]/(double)sum))/(1+1.0/(cnt-1));
					//p[j] = sum2;
				}
				else p[j]=0;
			}
			
			
			
			str2 = "Case #" + (++i) + ":";
			for(int j = 0; j<nc;j++)
			{
				str2 += " "+p[j]*100;
			}
			str2 += "\n";
			out.append(str2);
			System.out.print(str2);
		}
		in.close();
		out.close();
	}


}

package jamC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbB extends Prob{

	public static void main(String[] args) {
		System.out.println((int)'A');
		ProbB pa= new ProbB();
		pa.fromFile("C:\\Users\\tchang\\Downloads\\B-large.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int cas=0;cas<T;cas++)
			{
				String ans="",line[]=br.readLine().split(" "),possibilityStr="";
				int B=Integer.parseInt(line[0]);
				long M=Long.parseLong(line[1]);
				String binStr=Long.toBinaryString(M);
				binStr=new StringBuilder(binStr).reverse().toString();
				boolean possib=binStr.length()<B-1||M==Math.pow(2, B-2);
				possibilityStr=(possib)?"POSSIBLE":"IMPOSSIBLE";
				

				int mat[][]=new int[B][B];//i j
				if(possib)
				{
					for(int jj=0;jj<B-1;jj++)
					{
						for (int i=0;i<jj;i++)
							mat[i][jj]=1;
					}
					if(M==Math.pow(2, B-2))
						for(int i=0;i<B-1;i++)
							mat[i][B-1]=1;
					else
						for(int i=0;i<binStr.length();i++)
						{
							mat[i+1][B-1]=Integer.parseInt(""+binStr.charAt(i));
						}

				}
				bw.write("Case #"+(cas+1)+": "+possibilityStr);
				bw.newLine();
				if(possib)
				{
					for(int i =0;i<B;i++)
					{
						for(int j =0;j<B;j++)
							bw.write(""+mat[i][j]);
						bw.newLine();
					}
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

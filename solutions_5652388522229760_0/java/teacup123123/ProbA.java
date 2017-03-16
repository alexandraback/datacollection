package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbA extends Prob{

	public static void main(String[] args) {
		ProbA pa= new ProbA();
		pa.fromFile("C:\\Users\\user\\Downloads\\A-small-attempt0.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int cas=0;cas<T;cas++)
			{
				int N=Integer.parseInt(br.readLine());int num=0;
				String str;
				if(N!=0){
					boolean counter[]=new boolean[10];int left=10;
					while(left>0)
					{
						num=num+N;
						String decstr=""+num;
						for(char c:decstr.toCharArray())
						{
							int digit=Integer.parseInt(""+c);
							if(!counter[digit])
							{
								counter[digit]=true;
								left--;
							}

						}
					}
					str=""+num;
				}
				else
				{
					str="INSOMNIA";
				}
				bw.write("Case #"+(cas+1)+": "+str);
				bw.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProbD extends Prob{

	public static void main(String[] args) {
		ProbD pa= new ProbD();
		pa.fromFile("C:\\Users\\user\\Downloads\\D-small-attempt1.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine()),K,C,S;
			for(int cas=0;cas<T;cas++)
			{
				String inl[]=br.readLine().split(" ");
				K=Integer.parseInt(inl[0]);
				C=Integer.parseInt(inl[1]);
				S=Integer.parseInt(inl[2]);
				String str="";
				
				int needed=(int) Math.ceil((0.0+K)/C);
				if(needed>S)
				{
					str=" IMPOSSIBLE";
				}else{
					int[] ca=new int[S*C];
					for(int i=0;i<K;i++)
						ca[i]=i;
					//reshape
					Arrays.sort(ca);
					

					for(int i=0;i<S;i++)
					{
						int num=0;
						for(int digInd=0;digInd<C;digInd++)
						{
							num*=K;
							num+=ca[i+digInd*S];
						}
						str=str+" "+(num+1);
					}
				}

				bw.write("Case #"+(cas+1)+":"+str);
				bw.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

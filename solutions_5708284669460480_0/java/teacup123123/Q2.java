package codeJam3;

import java.io.FileWriter;
import java.io.IOException;

public abstract class Q2 {

	public static void main(String[] args) throws IOException {
		R.init("B-small-attempt1.in");
		FileWriter out=W.init("out2");

		int rounds=R.Int();
		for(int i=0;i<rounds;i++)
		{
			long bananasTaken=0;
			int maxBananas=0;
			int k=R.Int();
			int l=R.Int();//target
			int s=R.Int();//times
			char keys[]=R.Word().toCharArray();
			char target[]=R.Word().toCharArray();
			int powed=M.power(k,s);
			char temp[]=new char[s];
			counting:
				for(int count=0;count<powed;count++)
				{
					int localBanana=0;
					int countcopy=count;
					for(int ss=0;ss<s;ss++)
					{
						int got=countcopy%k;
						countcopy=countcopy/k;
						temp[ss]=keys[got];
					}
					detectFromIndex:
					for(int index=0;index+l<=s;index++)
					{
						for(int ind=0;ind<l;ind++)
						{
							if(temp[index+ind]!=target[ind])
								continue detectFromIndex;
						}
						//yes
						localBanana++;
						bananasTaken++;
					}
					maxBananas=M.ax(maxBananas, localBanana);
				}
			double res=maxBananas-1.*bananasTaken/powed;
			out.write("Case #"+(i+1)+": "+res+'\n');
		}


		R.close();
		W.close();
	}
}

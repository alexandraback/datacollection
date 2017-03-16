package codeJam3;

import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public abstract class Q22 {

	public static void main(String[] args) throws IOException {
		R.init("B-large.in");
		FileWriter out=W.init("out22");

		int rounds=R.Int();
		round:
			for(int i=0;i<rounds;i++)
			{
				if(i==65)
					System.out.println("dd");
				int maxBananas=0;
				int k=R.Int();
				int l=R.Int();//target
				int s=R.Int();//times
				char keys[]=R.Word().toCharArray();

				int counts[]=new int[1000];
				for(char c:keys)
					counts[(int)c]++;

				char target[]=R.Word().toCharArray();
				int bestOverlap=0;
				overlapNum:
					for(int overlap=0;overlap<l;overlap++)
					{
						for(int ii=0;ii<overlap;ii++)
						{
							if(target[l-overlap+ii]!=target[ii])
							{
								//not overlap
								continue overlapNum;
							}
						}
						bestOverlap=overlap;
					}
				for(int index=0;index<l;index++)
				{
					if(counts[(int)target[index]]==0)
					{
						out.write("Case #"+(i+1)+": "+0+'\n');
						continue round;
					}
				}
				maxBananas+=1;
				int ss=s;
				ss-=l;
				maxBananas+=ss/(l-bestOverlap);
				double proba=1;
				for(int index=0;index<l;index++)
				{
					proba*=counts[(int)target[index]];
					proba/=k;
				}
				double res=maxBananas-proba*(s-l+1);
				out.write("Case #"+(i+1)+": "+res+'\n');
			}


		R.close();
		W.close();
	}
}

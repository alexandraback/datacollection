package codeJam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.SortedSet;
import java.util.TreeSet;

public class HousePanCakes {
	private static String readWord(FileReader r) {
		String res="";
		scanning:
			while(true)
			{
				try {
					int read=r.read();
					switch (read) {
					case -1:
						break scanning;
					case ' ':
						break scanning;
					case '\n':
						break scanning;
					default:
						res=res+(char)read;
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		return res;
	}
	public static void main(String[] args) {
		try(FileReader fr=new FileReader("B-small-attempt1.in"))
		{
			String word=readWord(fr);
			int T=Integer.valueOf(word);
			FileWriter fw=new FileWriter("out2");
			for(int i=0;i<T;i++)
			{
				int panHist[]=new int[10];
//				int panAcc[]=new int[10];//i -->  >i
				word=readWord(fr);
				int nonEmptyplates=Integer.valueOf(word);
				int maxPan=0;
				for(int j=0;j<nonEmptyplates;j++)
				{
					word=readWord(fr);
					int panNum=Integer.valueOf(word);
					panHist[panNum]+=1;
					maxPan=(maxPan>panNum)?maxPan:panNum;
				}
//				for(int upto=maxPan;upto>=1;upto--)
//				{
//					//score=upto+
//				}
//				for(int ii=0;ii<=maxPan;ii++)
//					panAcc[0]+=panHist[ii]*ii;
//				for(int ii=1;ii<=maxPan;ii++)
//					panAcc[ii]=panAcc[ii-1]-panHist[ii]*ii;
				int minScore=Integer.MAX_VALUE;
				for(int upto=maxPan;upto>=1;upto--)
				{
					int score=upto;
					for(int upto2=upto+1;upto2<=maxPan;upto2++)
					{
						score+=panHist[upto2]*(int) (Math.ceil((0.+upto2)/upto)-1);
					}
					minScore=(minScore<score)?minScore:score;
				}
				fw.write("Case #"+(i+1)+": "+minScore+'\n');
			}
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		};
	}
}

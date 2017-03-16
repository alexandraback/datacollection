package codeJam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Dij {
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
	// 1 -1 i -i j -j k -k
	static String sTable[]={"1","-1","i","-i","j","-j","k","-k"};
	static int table[][]={{0,1  ,2,3,  4,5,  6,7},{1,0  ,3,2,  5,4,  7,6},
		{2,3 ,1,0 ,6,7 ,5,4},{3,2 ,0,1 ,7,6 ,4,5},
		{4,5,7,6,1,0,2,3},{5,4,6,7,0,1,3,2},
		{6,7,4,5,3,2,1,0},{7,6,5,4,2,3,0,1}};
	static private int x(int... j)
	{
		int res=0;
		for(int jj:j)
			res=table[res][jj];
		return res;
	}
	static int pows[][]=new int[8][8];
	static private int pow(int x,int n)
	{
		if(pows[x][n%8]!=-1)
			return pows[x][n%8];
		if(n%8==0)
			return 0;
		else 
		{
			int res=pow(x, n-1);
			res=x(x,res);
			return res;
		}
	}
	public static void main(String[] args) {
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)pows[i][j]=-1;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				System.out.println(sTable[i]+" x "+sTable[j]+" = "+sTable[x(i,j)]);
		int ijk=x(2,4,6);
		System.out.println(ijk);
		try(FileReader fr=new FileReader("C-small-attempt1.in"))
		{
			String word=readWord(fr);
			int T=Integer.valueOf(word);
			FileWriter fw=new FileWriter("outDij");
			turns:
				for(int i=0;i<T;i++)
				{
					word=readWord(fr);
					int L=Integer.parseInt(word);
					word=readWord(fr);
					int X=Integer.parseInt(word);

					word=readWord(fr);
					int intRep[]=new int [word.length()];
					for(int ii=0;ii<intRep.length;ii++)
						switch (word.charAt(ii)) {
						case 'i':
							intRep[ii]=2;
							break;
						case 'j':
							intRep[ii]=4;
							break;
						case 'k':
							intRep[ii]=6;
							break;
						default:
							throw new Error();
						}
					int prodL=x(intRep);
					if(pow(prodL,X)!=ijk)
					{
						fw.write("Case #"+(i+1)+": "+"NO"+'\n');
						continue turns;
					}


					int mid1=0,mid2=L;
					int pre=0,post=0;
					int counts=0;
					while(pre!=2)
					{
						pre=x(pre,intRep[mid1]);
						mid1+=1;//advance
						if(mid1==L)
							mid1=0;
						counts++;
						if(counts>8*L||counts>L*X)
						{
							fw.write("Case #"+(i+1)+": "+"NO"+'\n');
							continue turns;
						}
					}
					while(post!=6)
					{
						mid2-=1;//back
						if(mid2==-1)
							mid2=L-1;
						post=x(intRep[mid2],post);
						
						counts++;
						if(counts>L*X)
						{
							fw.write("Case #"+(i+1)+": "+"NO"+'\n');
							continue turns;
						}
					};//back
						fw.write("Case #"+(i+1)+": "+"YES"+'\n');
				}
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		};
	}
}

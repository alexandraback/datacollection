package codeJam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
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
		try(FileReader fr=new FileReader("A-large.in"))
		{
			String word=readWord(fr);
			int T=Integer.valueOf(word);
			FileWriter fw=new FileWriter("out");
			for(int i=0;i<T;i++)
			{
				int stoodUp=0;
				int added=0;
				word=readWord(fr);
				int Smax=Integer.valueOf(word);
				word=readWord(fr);
				for(int j=0;j<=Smax;j++)
				{
					int s_i=Integer.valueOf(""+word.charAt(j));
					if(stoodUp+added<j)
						added+=(j-stoodUp-added);
					stoodUp+=s_i;
				}
				fw.write("Case #"+(i+1)+": "+added+'\n');
			}
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		};
	}
}

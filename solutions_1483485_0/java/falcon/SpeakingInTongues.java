package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class SpeakingInTongues 
{

	private static void fill(char src,char dest,char[] map)
	{
		map[src-'a']=dest;
	}
	private static void fill(String inp,String out,char[] map)
	{
		for(int i=0;i<inp.length();++i)
		{
			if(inp.charAt(i)==' ')
				continue;
			map[inp.charAt(i)-'a']=out.charAt(i);
		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		char[] map=new char[26];
		Arrays.fill(map,'#');
		fill("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand",map);
		fill("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities",map);
		fill("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up",map);
		fill('z','q',map);
		fill('q','z',map);	
		for(int t=1;t<=T;++t)
		{
			String G=br.readLine().trim();
			String out="";
			for(int i=0;i<G.length();++i)
			{
				char ch=G.charAt(i);
				if(ch==' ')
					out+=ch;
				else
					out+=map[ch-'a'];
			}
			System.out.println("Case #"+t+": "+out);
			
		}
		
		br.close();

	}

}

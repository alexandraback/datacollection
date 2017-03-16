import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;


public class dumbQual {

	static String eng[]={"our language is impossible to understandzq","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
	static String ggl[]={"ejp mysljylc kd kxveddknmc re jsicpdrysiqz","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};


	static Vector<Character> vec=new Vector<Character>();
	
	static char replace(char c)
	{
		int index=0;
		while(index<3)
		{
			int loca=ggl[index].indexOf(c);
			if(loca==-1)
				index++;
			else
				return eng[index].charAt(loca);
		}
		
		return '?';
	}
	
	
	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner in=new Scanner(new FileReader("inp.in"));
		PrintWriter pw=new PrintWriter("ans.txt");

		for(int i=0;i<26;i++)
		{
			vec.add((char)(i+'a'));
		}
		
		for(int i=0;i<26;i++)
		{
			char c=replace((char)(i+'a'));
			vec.removeElement((char)(c));
			System.out.println(i+" "+c);
		}
		
		
		int cases=in.nextInt();
		in.nextLine();
		
		for(int i=0;i<cases;i++)
		{
			String input=in.nextLine();
			
			String out="";
			
			for(int j=0;j<input.length();j++)
			{
				out=out+replace(input.charAt(j));
			}
			
			pw.println("Case #"+(i+1)+": "+out);
		}
		pw.close();
	}
}

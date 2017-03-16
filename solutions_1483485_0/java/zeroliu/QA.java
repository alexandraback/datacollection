import static java.util.Arrays.deepToString;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class QA {

	public static void main(String[] args) throws Exception 
	{
		new QA().run();
		
	}
	
	HashMap<Character, Character> createMap()
	{
		HashMap<Character, Character> hm = new HashMap<Character, Character>();
		
		String orig = new String("ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv");
		String target = new String("our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up");
		
		for(int i=0; i<orig.length(); i++)
		{
			hm.put(orig.charAt(i), target.charAt(i));
		}
		
		return hm;
	
	}
	
	String treatCode(String orig, HashMap<Character, Character> hm)
	{
		String res = "";
		
		for(int i=0; i<orig.length(); i++)
		{
			Character answer = hm.get(orig.charAt(i));
			
			if(answer == null)
			{
				answer = orig.charAt(i);
			}
			res += answer.toString();
			
		}
		
		return res;
	}
	
	void run() throws Exception 
	{
		HashMap<Character, Character> hm = new HashMap<Character, Character>();
		hm = createMap();
		hm.put('z', 'q');
		hm.put('q', 'z');

		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		
		FileWriter fstream = new FileWriter("out.in");
		BufferedWriter out = new BufferedWriter(fstream);
		
		
		//PrintWriter pw = new PrintWriter(new FileWriter("Asmall.out"));
		
		int ntest = Integer.valueOf(sc.nextLine());
		
		for(int test=1;test<=ntest;++test) 
		{
			String testText = sc.nextLine();
			String res = treatCode(testText, hm);
			debug(res);
			
			
			out.write("Case #" + test + ": ");
			out.write(res);
			out.write("\n");
		}
		out.close();
		sc.close();
	
	}
	
	void debug(Object...os) 
	{
		System.err.println(deepToString(os));
	} 
	
	void debugArray(Object[]...os) 
	{
		System.err.println(deepToString(os));
	} 
}

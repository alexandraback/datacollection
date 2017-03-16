import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class ProblemA {

	public static void main(String[] args) throws NumberFormatException, IOException{

		BufferedReader reader=new BufferedReader(new FileReader(new File(args[0])));

		int numTestCases=Integer.parseInt(reader.readLine());

		String in= "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvqz";
		String out="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upzq";
		
		char[] mapping=new char[27];
		
		for (int i=0; i<in.length(); i++){
			if (in.charAt(i)!=' ')
				mapping[in.charAt(i)-'a']=out.charAt(i);
		}
		
		for (int testCase=0; testCase<numTestCases; testCase++){
			StringBuilder sb=new StringBuilder();
			
			String line=reader.readLine();
			
			for (int i=0; i<line.length(); i++){
				sb.append(line.charAt(i)==' '?' ':mapping[line.charAt(i)-'a']);
			}
			
			System.out.println("Case #"+(testCase+1)+": "+sb.toString());
		}		
	}
}
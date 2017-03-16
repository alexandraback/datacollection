package j2012r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	public static String inputDirectory="src/j2012r1a/";
	public static String inputFile="A.in";
	public static String outputFile="A.out";
	public static PrintWriter output;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));

		Map<Character, Character> codeMap = new HashMap<Character, Character>();

		String source = "qzejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String result = "zqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

		for (int i = 0; i < source.length(); i++) {
			codeMap.put(source.charAt(i), result.charAt(i));
		}
		
		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			int typed = s.nextInt();
			int total = s.nextInt();
			int remain = total - typed;
			s.nextLine();
			double[] chance = new double[typed];
			for (int i=0;i<typed;i++) {
				chance[i] = s.nextDouble();
			}
			s.nextLine();
			
			double best = Math.min(2 + total, typed + 1 + total);
			
			double p = chance[0];
			for(int i=1;i<=typed; i++) {
				int deleted = typed - i;
				int rightStrokes = deleted * 2 + remain + 1;
				int wrongStrokes = rightStrokes + total + 1;
				//out(Case+": "+p + " right: "+ rightStrokes+ " wrong: " + wrongStrokes);
				double expected = p*rightStrokes + (1 - p)*wrongStrokes;
				best = Math.min(best, expected);
				//out(Case+": "+expected);
				if(i<typed) {
					p *= chance[i];
				}
			}

			output.printf("Case #%d: %f\n", Case, best);
		}
		output.flush();
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}

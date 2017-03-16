package codejam2012.qualification;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.CharBuffer;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class SpeakingInTongues {
	static String dir="/home/casatta/Scaricati/";
//	static String dir="/home/casatta/workspaces/workspaceForGlassfish/Competition/current/";
//	static String dir="data/";
	
	static String fname="A-small-attempt0.in";
	Map<Character,Character> mappa=new HashMap<Character, Character>();
	
	public void test(Scanner input, PrintWriter out, Long i) {
		String nextLine = input.nextLine();
		System.out.println(nextLine);
		char output[]= new char[nextLine.length()];
		char current;
		for(int j=0; j< nextLine.length(); j++) {
			current=nextLine.charAt(j);
			if(' ' == current)
				output[j]= ' ';
			else
				output[j]=mappa.get(current);
			
			
		}
		out.println("Case #" + (i+1) + ": " + new String(output));
	}
	
	
	public void run() {
		
		mappa.put('y', 'a');
		mappa.put('n', 'b');
		mappa.put('f', 'c');
		mappa.put('i', 'd');
		mappa.put('c', 'e');
		mappa.put('w', 'f');
		mappa.put('l', 'g');
		mappa.put('b', 'h');
		mappa.put('k', 'i');
		mappa.put('u', 'j');
		mappa.put('o', 'k');
		mappa.put('m', 'l');
		mappa.put('x', 'm');
		mappa.put('s', 'n');
		mappa.put('e', 'o');
		mappa.put('v', 'p');
		mappa.put('z', 'q');
		mappa.put('p', 'r');
		mappa.put('d', 's');
		mappa.put('r', 't');
		mappa.put('j', 'u');
		mappa.put('g', 'v');
		mappa.put('t', 'w');
		mappa.put('h', 'x');
		mappa.put('a', 'y');
		mappa.put('q', 'z');
		
		System.out.println("mappa.size()=" + mappa.size());
		
		
		
		try {
			String inputPath = dir + fname;

			Scanner input =new Scanner(new File(inputPath));
			FileWriter outFile = new FileWriter(inputPath + ".out");
			PrintWriter out = new PrintWriter(outFile);
			try {		
				Long testCases = input.nextLong();
				input.nextLine();

				for(Long i=0L ; i < testCases ; i++)
					test(input,out,i);
			}
			finally {
				input.close();
				out.close();
			}
		}
		catch (IOException ex){
			ex.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		SpeakingInTongues template = new SpeakingInTongues();
		template.run();
	}
	

}

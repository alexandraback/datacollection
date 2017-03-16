import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Scanner;


public class SpeakingInTongues {
	 String inputFilePath = "C:\\Temp\\Google\\A-small-attempt0.in";
	 String outputFilePath = "C:\\Temp\\Google\\output.txt";
	
	
	public static void main(String[] args)  throws NumberFormatException, IOException{

		new SpeakingInTongues().go();
		
	}
	
	Hashtable<Character, Character> d = new Hashtable<Character, Character>();
	
	public void go() throws NumberFormatException, IOException{
		
		BuildDictionary();
		FileReader input = new FileReader(inputFilePath);
		BufferedReader reader = new BufferedReader(input);
		
	   int numTests = Integer.parseInt(reader.readLine());
		
		ArrayList<String> results = new ArrayList<String>();
		
		
		for (int i = 0; i < numTests; i++){
			String googlerese = reader.readLine();
			results.add(translate(googlerese));
		}
		
		 PrintWriter out = new PrintWriter(new FileOutputStream(outputFilePath));
		for (int i = 0; i<results.size(); i++){
			String line = "Case #" +(i+1) + ": " + results.get(i) + "\r\n";
			out.write(line);
		}
		out.flush();
			
		System.out.println("Done");
	}

	private String translate(String googlerese) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i<googlerese.length(); i++){
			sb.append(d.get(googlerese.charAt(i)));
		}
		
		return sb.toString();
	}

	private void BuildDictionary() {
		d.put('y', 'a');
		d.put('n', 'b');
		d.put('f', 'c');
		d.put('i', 'd');
		d.put('c', 'e');
		d.put('w', 'f');
		d.put('l', 'g');
		d.put('b', 'h');
		d.put('k', 'i');
		d.put('u', 'j');
		d.put('o', 'k');
		d.put('m', 'l');
		d.put('x', 'm');
		d.put('s', 'n');
		d.put('e', 'o');
		d.put('v', 'p');
		d.put('z', 'q');
		d.put('p', 'r');
		d.put('d', 's');
		d.put('r', 't');
		d.put('j', 'u');
		d.put('g', 'v');
		d.put('t', 'w');
		d.put('h', 'x');
		d.put('a', 'y');
		d.put('q', 'z');
		d.put(' ', ' ');
		
	}
}

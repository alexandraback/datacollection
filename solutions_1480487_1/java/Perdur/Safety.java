package main;

import java.util.Vector;
import java.io.*;

public class Safety {
	
	static int numberOfElementForEachTest = 0;
	static int numberOfLinesPerTest = 1;
	
	public static void main(String[] args) {
		Vector<Double> elements = new Vector<Double>();
		numberOfElementForEachTest = 0;
		
		Reader.setFile("input.txt");
		Writer.setFile("output.txt");
		
		String s = Reader.readLine();
		int numberTest = Integer.parseInt(s);
		
		for (int i=0; i<numberTest; i++) {
			numberOfElementForEachTest = 0;
			elements = new Vector<Double>();
			
			double sommeVote = 0;
			
			s = Reader.readLine();
			String s1 = s.substring(0, s.indexOf(" "));
			s=s.substring(s.indexOf(" ")+1);
			numberOfElementForEachTest =  Integer.parseInt(s1);
			
			double nombreDeJoueurs = (double) numberOfElementForEachTest;
			
//			System.out.println(s);
			
//			s = Reader.readLine();
			for (int j=0; j<numberOfElementForEachTest-1; j++) {
				s1 = s.substring(0, s.indexOf(" "));
				s=s.substring(s.indexOf(" ")+1);
				double vote = Double.parseDouble(s1);
				elements.add(vote);
				sommeVote += vote;
			}
			double vote = Double.parseDouble(s);
			elements.add(vote);
			sommeVote += vote;
			
			double scoreDistribuable = 2 * sommeVote;
			double scoreMin = scoreDistribuable / nombreDeJoueurs;
			
			boolean hasMoved = true;
			
			while (hasMoved)
			{
				hasMoved = false;
				for (int j=0; j<elements.size(); j++)
				{
					if (elements.get(j)>scoreMin)
					{
						hasMoved = true;
						scoreDistribuable -= elements.get(j);
						nombreDeJoueurs --;
						scoreMin = scoreDistribuable / nombreDeJoueurs;
						elements.set(j, -1.);
					}
				}	
			}
			
			Writer.write("Case #" + (i+1) + ":");
			for (int j=0; j<elements.size(); j++)
			{
				double result = 0;
				if (elements.get(j)!= -1)
				{
					result = ((scoreMin - elements.get(j))/sommeVote)*100;
				}
//				if (result < 0) result = 0;
				Writer.write(" " + result);
			}
			Writer.writeln("");
			
			 
		}
		Writer.close();

	}
	
	public static final class Reader 
	{
		static BufferedReader in;
		
		public static void setFile(String fichier) {
			File file = new File(fichier);
			try {
				in =  new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
			}
		}

		public static String readLine() {
			String line = null;
			try {
				line =  in.readLine();
			}
			catch (IOException e) {}
			
			return line;
		}
		
		public static String readAll() {
			String text = "";
			String line = "";
			while (line != null) {
				try {
					line = in.readLine();
				} 
				catch (IOException e) {
				}
				if (line != null) text += line + "\n";
			}
			return text;
		}
	}
	
	public static final class Writer 
	{
		static BufferedWriter out;
		
		public static void setFile(String file) {
			try{
				FileWriter fstream = new FileWriter(file);
				out = new BufferedWriter(fstream);
			}
			catch (Exception e){}
		}
		
		public static void write(String ligne) {
			try {
				out.write(ligne);
			}
			catch (Exception e){}
		}
		public static void writeln(String ligne) {
			try {
				out.write(ligne);
				out.write("\n");
			}
			catch (Exception e){}
		}

		public static void close() {
			try {
				out.close();
			}
			catch (Exception e){}
		}
	}
		
}

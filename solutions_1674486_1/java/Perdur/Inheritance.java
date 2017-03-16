package main;

import java.util.Collections;
import java.util.Vector;
import java.io.*;

public class Inheritance {
	
	static int numberOfElementForEachTest = 0;
	static int numberOfLinesPerTest = 0;
	static Vector<AClass> elements = new Vector<AClass>();
	
	public static void main(String[] args) {
		numberOfElementForEachTest = 0;
		
		Reader.setFile("input.txt");
		Writer.setFile("output.txt");
		
		String s = Reader.readLine();
		int numberTest = Integer.parseInt(s);
		
		for (int i=0; i<numberTest; i++) {
			elements = new Vector<AClass>();
			String s1 = "";
			numberOfElementForEachTest = 0;
			
			s = Reader.readLine();
			numberOfLinesPerTest =  Integer.parseInt(s);
			
			for (int j=0; j<numberOfLinesPerTest; j++) {
				elements.add(new AClass(j+1));
//				System.out.println("elements.add(new AClass(j+1));" + (j+1));
			}
			
			for (int j=0; j<numberOfLinesPerTest; j++) {
				s = Reader.readLine();
				
				if (s.indexOf(" ")!=-1)
				{
					s1 = s.substring(0, s.indexOf(" "));
					s=s.substring(s.indexOf(" ")+1);
//					System.out.println(s);
					numberOfElementForEachTest =  Integer.parseInt(s1);
					for (int k=0; k<numberOfElementForEachTest-1; k++) {
						s1 = s.substring(0, s.indexOf(" "));
						s=s.substring(s.indexOf(" ")+1);
						elements.get(Integer.parseInt(s1)-1).addParent(j+1);
					}
//					System.out.println(Integer.parseInt(s)-1 + " has id " + elements.get(Integer.parseInt(s)-1).id);
					elements.get(Integer.parseInt(s)-1).addParent(j+1);
				}
			}
			
			for (int j=0; j<elements.size(); j++) System.out.print(elements.get(j));
			
			
			boolean hasDiamond = false;
			for (int j=0; j<elements.size() && !hasDiamond; j++) {
				hasDiamond = elements.get(j).compute();
			}
			System.out.println("");
			
			String toreturn = "No";
			if (hasDiamond) toreturn = "Yes";
					
			
			Writer.writeln("Case #" + (i+1) + ": " + toreturn);
			 
		}
		Writer.close();

	}
	
	public static class AClass {
		public Vector<Integer> directParents = new Vector<Integer>();
		public int id = 0;
		boolean isComputed = false;
		public Vector<Integer> allParents = new Vector<Integer>();
		
		public AClass(int j) {
			id = j;
		}

		public void addParent(int parentId)
		{
//			System.out.println("add parent " + parentId + " to " + id);
			directParents.add(parentId);
			allParents.add(parentId);
		}
		
		public String toString()
		{
			String s ="";
			for (int i=0; i<directParents.size(); i++)
			{
				s+=id + " has parent " + directParents.get(i) + "\n";
			}
			return s;
		}
		
		public boolean compute () {
			if (isComputed) return false;
			System.out.println("Compute for " + id);
//			System.out.println("allParents " + allParents);
			boolean hasDiamond = false;
			for (int i=0; i<directParents.size() && hasDiamond == false; i++)
			{
				AClass parent = Inheritance.elements.get(directParents.get(i)-1);
				if (parent.isComputed)
				{
					allParents.addAll(parent.allParents);
				}
				else
				{
					hasDiamond = parent.compute();
					allParents.addAll(parent.allParents);
				}
			}
			// none of my parents is a diamond			
			if (hasDiamond == false)
			{
				Collections.sort(allParents);
				for (int i=0; i<allParents.size()-1; i++)
				{
					if (allParents.get(i) == allParents.get(i+1)) hasDiamond = true;
				}
			}
			System.out.println("allParents for " + id + " " + allParents);
			
			isComputed = true;
			return hasDiamond;
		}
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

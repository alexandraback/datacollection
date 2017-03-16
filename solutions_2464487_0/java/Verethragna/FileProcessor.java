package verethragna.cjutils;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

public final class FileProcessor {
	public int cases;
	private int lwcase = 0;
	private BufferedReader in;
	private BufferedWriter out;
	private static String path = "C:\\Users\\Verethragna\\Desktop\\";
	
	public FileProcessor(boolean getCases){
		JFileChooser fc = new JFileChooser(path);
		fc.setFileFilter(new FileNameExtensionFilter("Code Jam Input", "in"));
		
		if(fc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION) System.exit(1);
		File inf = fc.getSelectedFile();
		try {
			in = new BufferedReader(new FileReader(inf));
			out = new BufferedWriter(new FileWriter(new File(path + inf.getName().substring(0, inf.getName().lastIndexOf('.')) + ".out")));
		} catch (IOException e) {
			System.err.println("Error: Couldn't open/create files.");
			e.printStackTrace();
			System.exit(1);
		}
		
		if(getCases)
			cases = getInt();
	}
	
	public static void setPath(String npath){
		path = npath;
	}
	
	public void finish(){
		try {
			in.close();
			out.close();
		} catch (IOException e) {
			System.err.println("Error: Couldn't close reader/writer.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
	}
	
	public void skipLine(){
		try {
			in.readLine();
		} catch (IOException e) {
			System.err.println("Error: Couldn't skip line.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
	}
	
	public String getString(){
		try {
			return in.readLine();
		} catch (Exception e) {
			System.err.println("Error: Couldn't read line.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
		return null;
	}
	
	public String[] getStringArray(){
		try {
			return in.readLine().split(" ");
		} catch (Exception e) {
			System.err.println("Error: Couldn't read line.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
		return null;
	}
	
	public char getChar(){
		try {
			return in.readLine().charAt(0);
		} catch (Exception e) {
			System.err.println("Error: Couldn't read line.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
		return 0;
	}
	
	public char[] getCharArray(){
		String[] s = getStringArray();
		char[] c = new char[s.length];
		for(int i = 0; i < s.length; i++)
			c[i] = s[i].charAt(0);
		return c;
	}
	
	public int getInt(){
		try {
			return Integer.parseInt(in.readLine());
		} catch (Exception e) {
			System.err.println("Error: Couldn't read integer.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
		return 0;
	}
	
	public int[] getIntArray(){
		try {
			String[] s = getStringArray();
			int[] c = new int[s.length];
			for(int i = 0; i < s.length; i++)
				c[i] = Integer.parseInt(s[i]);
			return c;
		} catch (Exception e) {
			System.err.println("Error: Couldn't read integer.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
		return null;
	}
	
	public int getLastWrittenCase(){
		return lwcase;
	}
	
	public void writeCase(int num, String text){
		try {
			lwcase = num;
			out.write("Case #" + String.valueOf(num) + ": " + text + "\n");
		} catch (IOException e) {
			System.err.println("Error: Couldn't write case.");
			e.printStackTrace();
			finish();
			System.exit(1);
		}
	}
	
	public void writeCase(String text){
		writeCase(lwcase + 1, text);
	}
}

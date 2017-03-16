import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Vector;


public class problemA {

	Vector<String> lines = new Vector<String>();
	
	public static void main(String[] a) {
		String gr = " abcdefghijklmnopqrstuvwxyz";
		problemA pa = new problemA();
		
		pa.lines = pa.readfile("C:\\eclipse\\Ashish\\files\\A-small-attempt0.in");
		int nooftestcases = Integer.parseInt(pa.lines.elementAt(0));
		System.out.println(nooftestcases);
		Vector<String> outlines = new Vector<String>();
		int j=1;
		for (int i=0; i<nooftestcases; i++) {
			String s = "Case #" + j + ": " + pa.solveit(pa.lines.elementAt(j));
			j++;
			outlines.add(s);
		}
		
		pa.writefile("C:\\eclipse\\Ashish\\files\\otesta.txt", outlines);
		System.out.println(gr);
		System.out.println(pa.solveit(gr));
		
	}
	
	public String solveit(String g) {
		int len = g.length();
		System.out.println(len);
		String e = "";
		for (int i=0; i<len; i++) {
			e = e + maptoen(g.substring(i, i+1));
		}
		return e;
	}
	
	public String maptoen(String g) {
		String gr = " ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyqeez";
		String en = " ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupazooq";
		System.out.println(String.valueOf(en.charAt(gr.indexOf(g))));
		return String.valueOf(en.charAt(gr.indexOf(g)));
	}
	
	public void writefile(String name, Vector<String> l) {
		try{
			   // Create file 
			   FileWriter fstream = new FileWriter(name);
			   BufferedWriter out = new BufferedWriter(fstream);
			   for (int i=0; i<l.size(); i++) {
				   out.write((l.elementAt(i) + System.getProperty("line.separator")));
			   }
			   //Close the output stream
			   out.close();
			   }catch (Exception e){//Catch exception if any
			   System.err.println("Error: " + e.getMessage());
		  }
	
	}
	
	public  Vector<String> readfile(String fp) {
		Vector<String> lines = new Vector<String>();
		try {
			FileReader fr = new FileReader(fp); 
			BufferedReader br = new BufferedReader(fr); 
			String s; 
			while((s = br.readLine()) != null) { 
				//System.out.println(s); 
				lines.addElement(s);
			} 
			fr.close(); 
			
		}
		catch (Exception e) {
			System.out.println(e);
		}
		return lines;
	} 
}

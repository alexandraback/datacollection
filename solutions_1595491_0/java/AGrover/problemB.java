import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Vector;


public class problemB {

	Vector<String> lines = new Vector<String>();
	
	public static void main(String[] a) {
		problemB pb = new problemB();
		
		pb.lines = pb.readfile("C:\\eclipse\\Ashish\\files\\B-small-attempt0.in");
		int nooftestcases = Integer.parseInt(pb.lines.elementAt(0));
		System.out.println(nooftestcases);
		Vector<String> outlines = new Vector<String>();
		//int j=1;
		for (int i=1; i<=nooftestcases; i++) {
			String[] s = pb.lines.elementAt(i).split(" ");
			int go = Integer.parseInt(s[0]);
			int su = Integer.parseInt(s[1]);
			int ms = Integer.parseInt(s[2]);
			Vector<Integer> sc = new Vector<Integer>();
			for (int j=0; j<go; j++) {
				//System.out.println(s[j+3]);
				sc.add(Integer.valueOf((s[j+3])));
				//System.out.println(sc.elementAt(j));
			}
			TestCaseB tc = new TestCaseB(go,su,ms,sc);
			int sol = pb.solveit(tc);
			String ol = "Case #" + i + ": " + sol;
			outlines.add(ol);
		}
		pb.writefile("C:\\eclipse\\Ashish\\files\\otestb.txt", outlines);
		
	}

	public int solveit(TestCaseB tc) {
		int howmany = 0;
		int remsurp = tc.surprises;
		for (int i=0; i<tc.googlers; i++) {
			double score = tc.scores.elementAt(i).doubleValue();
			
			double sd = score / 3;
			System.out.println("Score:" + score + " " + sd);
			if (tc.minscore - sd <= 0 || (tc.minscore - sd < 1 && tc.minscore - sd > 0)) {
				System.out.println("Yes");
				howmany++;
				continue;
			}				
	
			if (tc.minscore - sd > 1.5) {
				System.out.println("No");
				continue;
			}
			
			if (remsurp > 0 && sd !=0 ) {
				System.out.println("finally");
				howmany++;
				remsurp--;
			} else {
				System.out.println("Hard luck");
			}
			
		}
		
		
		return howmany;
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

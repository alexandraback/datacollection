import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Vector;


public class problemC {

	Vector<String> lines = new Vector<String>();
	
	public static void main(String[] arg) {
		problemC pc = new problemC();
		
		pc.lines = pc.readfile("C:\\eclipse\\Ashish\\files\\C-small-attempt0.in");
		int nooftestcases = Integer.parseInt(pc.lines.elementAt(0));
		System.out.println(nooftestcases);
		Vector<String> outlines = new Vector<String>();
		//int j=1;
		for (int i=1; i<=nooftestcases; i++) {
			String[] s = pc.lines.elementAt(i).split(" ");
			//int a = Integer.parseInt(s[0]);
			//int b = Integer.parseInt(s[1]);
			int k = pc.solveit(s[0], s[1]);
			String ol = "Case #" + i + ": " + k;
			outlines.add(ol);
			System.out.println(s[0] + " " + s[1] + ":" + k);
		}
		pc.writefile("C:\\eclipse\\Ashish\\files\\otestc.txt", outlines);
		
	}
	
	public int solveit(String fa, String fb) {
		int howmany =0;
		int len = fa.length();
		
		int ia=Integer.parseInt(fa);
		int ib=Integer.parseInt(fb);
			
		for (int cand=ia; cand<=ib; cand++) {
			String a = String.valueOf(cand);
			Vector<String> ms = new Vector<String>();
			
			System.out.println(a);
			String fno = a.substring(0, 1);
			//System.out.println(fno);
			int ifno = Integer.parseInt(fno);
			for (int i=1; i<len; i++) {
				String sno = a.substring(i, i+1);
				int isno = Integer.parseInt(sno);
				if (isno>ifno && isno !=0) {
					
					String rno = a.substring(i);
					String afno = a.substring(0, i);
					String nno = rno + afno;
					int inno = Integer.parseInt(nno);
					
					if (inno>cand && inno <= ib && ms.indexOf(nno) == -1) {
						ms.add(nno);
						howmany++;
						//System.out.println(" :" + nno);
					} else {
						//System.out.println("Rejected :" + nno);
					}
				} else if (isno==ifno && isno !=0) {
					String rno = a.substring(i);
					String afno = a.substring(0, i);
					String nno = rno + afno;
					int inno = Integer.parseInt(nno);
					if (inno>cand && inno <= ib && ms.indexOf(nno) == -1) {
						ms.add(nno);
						howmany++;
						String srno = a.substring(i);
						String safno = a.substring(0, i);
						String snno = rno + afno;
						//System.out.println(" :" + snno);						
					}
					
				}
				
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

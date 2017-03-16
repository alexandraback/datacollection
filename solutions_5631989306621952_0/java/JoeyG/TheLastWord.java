import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;

public class TheLastWord {
	
	public String lastWord(String s) {
		if(s==null||s.length()==0) return "";
		if(s.length()==1) return s;
		String re = ""+s.charAt(0);
		for(int i=1;i<s.length();i++) {
			if(s.charAt(i)>=re.charAt(0))
				re=s.charAt(i)+re;
			else
				re=re+s.charAt(i);
		}
		return re;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TheLastWord tlw =new TheLastWord();
		String fname="A-Small-attempt1";
		File file = new File("C:\\Users\\guanziwen\\Downloads\\"+fname+".in");
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(file));
		    int t = Integer.parseInt(br.readLine());
		    Writer writer = null;
		    try {
		        writer = new BufferedWriter(new OutputStreamWriter(
		              new FileOutputStream("C:\\Users\\guanziwen\\Downloads\\"+fname+".out"), "utf-8"));
		        for (int i = 1; i <= t; ++i) {
		        	String n = br.readLine();
		        	writer.write("Case #" + i + ": " + tlw.lastWord(n)+"\n");
		        }
		    } catch (IOException ex) {
		    } finally {
		    	if(writer!=null)
		       try {writer.close();} catch (Exception ex) {}
		    }
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			if(br!=null)
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
		}
		System.out.println("Done");
	}

}

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;


public class ST {

	/**
	 * @param args
	 */
	static char[] map={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	
	public static void main(String args[]) {
	try {
		BufferedReader br=new BufferedReader(new InputStreamReader(new FileInputStream("c:\\gcj\\A\\A-small-attempt0.in")));
		String line=br.readLine();
		PrintStream ps=new PrintStream("c:\\gcj\\A\\A-small.out");
		
		int n=Integer.parseInt(line);
			for(int i=1;i<=n;i++) {
				
				line=br.readLine();				
				ps.println("Case #"+i+": "+getOutput(line));
										
			}
		} 
		catch(Exception e) {
			e.printStackTrace();
		}
		
		
	}
	

	
	static String getOutput(String str)
	{
		str=str.toLowerCase();
		StringBuffer sb=new StringBuffer(str); 
		
		for(int i=0;i<str.length();i++) {
			char ch=str.charAt(i);
			if(ch!=' ') {
			 int ind=ch-'a';
			 sb.setCharAt(i, map[ind]);
			}
			
		}
		return sb.toString();
	}

}

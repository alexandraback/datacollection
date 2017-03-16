import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;



public class Consonants {

    public static void main( String[] args ) {
		try {
	    	BufferedReader in = new BufferedReader(new FileReader("in.txt"));
			BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
			String line = in.readLine();
			int total = new Integer(line);
			
			for (int i=1; i<=total; i++) {
				line = in.readLine();
				String[] s = line.split(" ");
				String l = s[0];
				int n = new Integer(s[1]);
				int val =0;
				for (int x=0; x<l.length(); x++)
					for (int y=l.length(); y>x; y--)
						if (isValid(l.substring(x, y), n)) val++;
				
				
				out.write("Case #"+i+": "+val+"\n");

			}
			
			
			in.close();
			out.flush();
			out.close();
	} catch (Exception e) {
		e.printStackTrace();
	}
	
    }
    
    private static boolean isValid(String s, int n) {
    	int consecutive = 0;
    	for (int i=0; i<s.length(); i++) {
    		if (s.charAt(i) == 'a' ||s.charAt(i) == 'e' ||s.charAt(i) == 'i' ||s.charAt(i) == 'o' ||s.charAt(i) == 'u')
    			consecutive = 0;
    		else {
    			consecutive++;
    			if (consecutive == n) return true; 
    		}
    	}
    	return false;
    }
}

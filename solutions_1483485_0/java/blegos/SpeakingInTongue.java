import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;

public class SpeakingInTongue {
	public static void main(String[] args) {
		int cases = 0;
		String[] dict = new String[]{
					" ", "y","h","e","s","o","c","v","x","d","u","i","g","l","b","k","r","z","t",
					"n","w","j","p","f","m","a","q"," "
				};
		
		try {
			FileWriter fstream = new FileWriter("A-small-attempt2.out");
			BufferedWriter out = new BufferedWriter(fstream);
			
			  
			BufferedReader br = readFile(new FileReader("A-small-attempt2.in"));
			
			String inline;
			int i = 0;
			while ((inline = br.readLine()) != null) {
				if (i++ == 0) {
					cases = Integer.parseInt(inline.trim());
				} else {
					String result = "Case #" + (i-1) + ": ";
					for(char o:inline.trim().toCharArray()) {
						result += dict[(((byte)o) - 96) < 0 ? 0 : (((byte)o) - 96)];
					}
					out.write(result + "\n");
				}
			}
			out.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private static BufferedReader readFile(FileReader in) throws FileNotFoundException {
		return new BufferedReader(in);
	}
}

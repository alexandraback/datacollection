import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;


public class ProblemA {
	static HashMap<Character,Character> map = new HashMap<Character,Character>();
	public static void main (String[] args) throws Exception{
		guess();
		///
		
		int ln = 1;
		BufferedReader fin = new BufferedReader(new FileReader("E:/A-small-attempt0.in"));
		String line = fin.readLine();
		BufferedWriter out = new BufferedWriter(new FileWriter("E:/A-small-attempt0.out"));
		while ((line = fin.readLine()) != null && line.trim().length() != 0){
			line = line.trim();
			out.write("Case #" + ln + ": ");
			for (int i = 0; i < line.length(); i++){
				if (map.containsKey(line.charAt(i)))
					out.write(map.get(line.charAt(i)));
				else
					out.write(line.charAt(i));
			}
			out.write("\n");
			ln++;
		}
		fin.close();
		out.close();
		
		
	}
	
	public static void guess() throws Exception{
		BufferedReader fin1 = new BufferedReader(new FileReader("E:/test.in"));
		BufferedReader fin2 = new BufferedReader(new FileReader("E:/test.out"));
		String line1;
		String line2;
		while ((line1 = fin1.readLine()) != null){
			line2 = fin2.readLine();
			for (int i = 0; i < line1.length(); i++){
				if (map.containsKey(line1.charAt(i)))
					continue;
				map.put(line1.charAt(i), line2.charAt(i));
			}
		}
		map.put('q', 'z');
		map.put('z', 'q');
	}
}
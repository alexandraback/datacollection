import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class ProblemC {
	public static void main (String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("E:/C-large.in"));
		String line = fin.readLine();
		BufferedWriter out = new BufferedWriter(new FileWriter("E:/C-large.out"));
		int ln = 1;
		while ((line = fin.readLine()) != null && line.length() != 0){
			
			line = line.trim();
			String[] parts = line.split("\\s+");
			int a = Integer.parseInt(parts[0]);
			int b = Integer.parseInt(parts[1]);
			int count = 0;
			for (int i = a; i < b; i++){
				String s = Integer.toString(i);
				ArrayList<Integer> list = new ArrayList<Integer>();
				for (int j = 1; j < s.length(); j++){
					String newString = s.substring(j) + s.substring(0,j);
					int newInt = Integer.parseInt(newString);
					if ((newInt > i) && (newInt <= b) && (list.contains(newInt) == false)){
						list.add(newInt);
						count++;
					}
				}
			}
			out.write("Case #" + ln + ": " + count);
			out.write("\n");
			ln++;
		}
		fin.close();
		out.close();
	}
}
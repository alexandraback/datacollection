import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class ProblemB {
	public static void main (String[] args) throws Exception{
		BufferedReader fin = new BufferedReader(new FileReader("E:/B-small-attempt0.in"));
		String line = fin.readLine();
		BufferedWriter out = new BufferedWriter(new FileWriter("E:/B-small-attempt0.out"));
		int ln = 1;
		while ((line = fin.readLine()) != null && line.length() != 0){
			line = line.trim();
			String[] parts = line.split("\\s+");
			int[] list = new int[parts.length];
			for (int i = 0; i < parts.length; i++){
				list[i] = Integer.parseInt(parts[i]);
			}
			int player = list[0];
			int s = list[1];
			int p = list[2];
			int gre = 0;
			int mid = 0;
			for (int i = 3; i < list.length; i++){
				if (list[i] >= (p * 3 - 2))
					gre++;
				else if (list[i] >= (p * 3 - 4) && list[i] >= 1)
					mid++;
			}
			int result = gre;
			if (mid > s)
				result += s;
			else
				result += mid;
			out.write("Case #" + ln + ": " + result);
			out.write("\n");
			ln++;
		}
		fin.close();
		out.close();
	}
}
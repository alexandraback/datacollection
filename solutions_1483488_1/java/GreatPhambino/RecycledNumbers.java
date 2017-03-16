import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;


public class RecycledNumbers {


	public static void main(String[] args) throws IOException 
	{
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-small-attempt0.in")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("C-large.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new FileWriter("RecycledNumbers.txt"));
		int cases = Integer.parseInt(reader.readLine());
		for(int i=1; i <= cases; i++)
		{
			String line = reader.readLine();
			int beg = Integer.parseInt(line.split(" ")[0]);
			int end = Integer.parseInt(line.split(" ")[1]);
			HashSet<Integer> h = new HashSet<Integer>();
			int count = 0;
			for(int j=beg; j<=end;j++) {
				String str = j+"";
				int c = 0;
				for(int m = str.length()-1; m>=0; m--) {
					str = str.substring(1) + str.charAt(0);
					int number = Integer.parseInt(str);
					if(number >= beg && number <= end && !h.contains(number)) {
						h.add(number);
						c++;
					}
				}
				count = count + ((c-1)*c)/2;
			}

			//out.write((p*3-2) + " " + (p*3-4) + "\n");
			System.out.print("Case #" + i+ ": " + count+"\n");
			out.write("Case #" + i+ ": " + count+"\n");
		}
		out.close();
	}



}



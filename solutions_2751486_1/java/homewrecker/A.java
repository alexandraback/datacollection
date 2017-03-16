import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class A {

	public static void main(String[] args) throws Exception {

		BufferedReader reader = new BufferedReader(new FileReader("/Users/jon/Downloads/A-large.in.txt"));

		BufferedWriter writer = new BufferedWriter(new FileWriter("/Users/jon/Documents/workspace/Codejam/out"));

		String line = reader.readLine();

		int T = Integer.parseInt(line);

		for (int i = 1; i <= T; i++) {
			writer.write("Case #" + i + ": ");

			line = reader.readLine();

			String[] flds = line.split(" ");

			String name = flds[0];
			int n = Integer.parseInt(flds[1]);
			
			char[] cc = name.toCharArray();

			List<int[]> nCombs = new ArrayList<int[]>();

//			Pattern pat = Pattern.compile("[^aeiou]{" + n + "}");
//			Matcher mat = pat.matcher(name);
			int idx = 0;
			outer: for(idx = n ; idx < cc.length ; idx++){
				for(int j = 0 ; j < n ; j++){
					if(cc[-j+idx] == 'a' || cc[-j+idx] == 'e' || cc[-j+idx] == 'i' || cc[-j+idx] == 'o' || cc[-j+idx] == 'u'){
						
					}
					else{
						break outer;
					}
				}
				nCombs.add(new int[] { idx - n + 1, idx });
			}
//			while (mat.find(idx)) {
//				nCombs.add(new int[] { mat.start(), mat.end() - 1 });
//				idx = mat.start() + 1;
//			}
			
			int count = 0;
			idx = 0;
			for(int[] x : nCombs){
				count += (x[0] + 1 - idx) * (name.length() - x[1]);
				
				idx = x[0]+1;
			}
			
			System.out.println("done " + i);

			writer.write(count + "\n");
		}

		writer.close();

	}

}

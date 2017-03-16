import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class R1CP2 {

	public static void main(String[] args) throws Exception{
		String file = "B-small-attempt1";
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader(file + ".in"));
		PrintStream ps = new PrintStream(new FileOutputStream(file + ".out"));
		int testcases = Integer.parseInt(br.readLine());
		for(int t = 0; t < testcases; t++){
			String[] ln = br.readLine().split(" ");
			int k = Integer.parseInt(ln[0]);
			int l = Integer.parseInt(ln[1]);
			int s = Integer.parseInt(ln[2]);
			String kb = br.readLine();
			String target = br.readLine();
			
			ArrayList<String> combs = new ArrayList<String>();
			combine(combs, "", kb, s);
			int maxFound = 0;
			int totalFound = 0;
			for(String str : combs){
				Pattern pattern = Pattern.compile(target);
				Matcher matcher = pattern.matcher(str);
				int count = 0;
				while (matcher.find()) count++;
				if(count > maxFound)
					maxFound = count;
				totalFound += count;
			}
			System.out.println(maxFound + " " + totalFound + " " + combs.size());
			double precalc = maxFound - ((double) totalFound / combs.size());
			ps.println("Case #" + (t + 1) + ": " + precalc);
		}
		

	}
	static void combine(ArrayList<String> add, String cstring, String instr, int s)
	{
		if(cstring.length() == s){
			add.add(cstring);
			return;
		}
		for(int i = 0; i < instr.length(); i++){
			String newstr = cstring + instr.charAt(i);
			combine(add, newstr, instr, s);
		}
		
	} 

	

}

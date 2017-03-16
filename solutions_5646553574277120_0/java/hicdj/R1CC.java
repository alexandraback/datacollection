import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class R1CC {

	public static ArrayList<Integer> numbers = new ArrayList<Integer>();
	
	public static int solve(String s1, String s2){
		
		numbers.clear();
		String[] str = s1.trim().split("\\s+");
		int C = Integer.parseInt(str[0]);
		int D = Integer.parseInt(str[1]);
		int V = Integer.parseInt(str[2]);
		
		String[] str2 = s2.trim().split("\\s+");
		for(String s: str2)
			numbers.add(Integer.parseInt(s));
		
		int c = 0;
		for(int i=1;i<=V;i++){
			if(!isPossible(i, 0)){
				numbers.add(i);
				c++;
			}
		}
		
		return c;
	}
	
	public static boolean isPossible(int v, int index){
		
		if(index>=numbers.size()) return false;
//		if(v<numbers.get(index)) return false;
		if(v==numbers.get(index)) return true;
		
		boolean exl = isPossible(v, index+1);
		boolean inc = false;
		if(v>numbers.get(index)) inc = isPossible(v-numbers.get(index), index+1);		
		
		return exl || inc;
	}
	
	public static void main(String[] args) {
		
		try {

			FileWriter fw = new FileWriter("data/R1C/C-small-attempt0.out");
			String out = "";

			BufferedReader br = new BufferedReader(new FileReader(
					"data/R1C/C-small-attempt0.in"));
			int count = Integer.parseInt(br.readLine());

			int caseno = 1;
			String str = null;
			while ((str = br.readLine()) != null && caseno <= count) {
				String s1 = str;
				String s2 = br.readLine();
				int res = solve(s1, s2);
				String output = "Case #" + caseno + ": " + res;
				caseno++;
				System.out.println(output);

				out += output + "\n";
			}

			fw.flush();
			fw.write(out);
			fw.flush();
			fw.close();

			br.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}

}

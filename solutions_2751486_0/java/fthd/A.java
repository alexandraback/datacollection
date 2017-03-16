import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class A{
	
	static Set<Character> vowels = new HashSet<Character>();
	
	public static void main(String[] args) throws Exception{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		//PrintStream out = System.out;
	
		String line = br.readLine();
		int T = Integer.parseInt(line);		
		
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');

		for(int i=1; i<=T; i++){
			line = br.readLine();
			String[] splitLine = line.split(" ");
			String name = splitLine[0];
			int N = Integer.parseInt(splitLine[1]);
			
			out.println("Case #" + i + ": " + solve(name, N));
		}
		
		br.close();
		out.close();
	}
	
	static int solve(String name, int N){
		ArrayList<Integer> endConsecutive = new ArrayList<Integer>();
		
		int cons = 0;
		for(int i=0; i<name.length(); i++){
			if(!vowels.contains(name.charAt(i))){
				cons++;
				if(cons >= N)
					endConsecutive.add(i);
			}
			else{
				cons = 0;
			}
		}
		
		int total = 0;
		int idx = 0;
		for(int i=0; i<name.length(); i++){
			int endSubstr = i+N-1;
			while(idx < endConsecutive.size()){
				if(endConsecutive.get(idx) >= endSubstr){
					break;
				}
				idx++;
			}
			
			if(idx >= endConsecutive.size()){
				break;
			}
			
			total += name.length()-endConsecutive.get(idx);
		}
		
		return total;
	}
}
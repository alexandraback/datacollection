import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class RecylcedNumbers {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.in"));
		BufferedWriter bfrw = new BufferedWriter(new FileWriter("output.out"));
		
		long N = in.nextLong();
		String output = "";
		for(long i = 0; i < N;i++){
			long A = in.nextLong();
			long B = in.nextLong();
			
			output += "Case #"+(i+1)+": " + solve(A,B) + "\n";
		}
		
		bfrw.write(output);
		in.close();
		bfrw.close();
	}
	
	private static long solve(long A,long B){
		long ans = 0;
		if(B <= 9) return 0;
		HashSet<String> set = new HashSet<String>();
		for(long i = A; i <=B; i++){
			String s = i+"";
			
			for(int j = 0; j < s.length();j++){
				String one = s.substring(s.length()-j);
				String two = s.substring(0,s.length()-j);
	
				if(Integer.parseInt(one+two) <= B && i < Integer.parseInt(one+two)) {
					ans++;
					//System.out.println(s + " --> " + one + two);
					set.add(i+","+Integer.parseInt(one+two));
				}
			}
		}
		
		return set.size();
	}
}

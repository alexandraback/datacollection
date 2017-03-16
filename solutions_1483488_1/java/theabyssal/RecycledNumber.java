import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class RecycledNumber {
	
//	static HashMap<Integer, ArrayList<Integer>> cache;

	public static void main(String[] args) throws IOException{
		
		String path = "C:\\Users\\Rapol Tongchenchitt\\Documents\\CodeJam\\";
		String year = "Qual2012\\";
		
		String test = "input.txt"; String outPath = "output.txt";
		String a = ""; String A = "";
		String b = ""; String B = "";
		String c = "C-large.in"; String C = "C-large.out";
		String d = ""; String D = "";
		
		String inName = path+year+c;
		String outName = path+year+C;
		
		Scanner in = new Scanner(new FileInputStream(inName));
		BufferedWriter out = new BufferedWriter(new FileWriter(outName));
		
		int caseCount = in.nextInt(); int currentCase = 0;
		
		while(currentCase++ < caseCount){
			
			int minNum = in.nextInt();
			int maxNum = in.nextInt();
			int ans = 0;
			
			for( int i = minNum; i <= maxNum; i++){
				ans += perform(i, minNum, maxNum);
			}
			
			out.write("Case #" + currentCase + ": " + ans);
			out.newLine();
		}
		
		out.close();
		
	}

	private static int perform(int in, int left, int right) throws IOException{
		if(in < 10){
			return 0;
		}
		
		HashSet<Integer> set = new HashSet<Integer>();
		int ans = 0;
		String now = in + "";
		for(int i = 1; i < now.length(); i++){
			if(now.charAt(i) >= now.charAt(0)){
				int shift = Integer.parseInt(now.substring(i) + now.substring(0,i));
				if(shift > in &&  shift <= right && shift >= left && !set.contains(shift)){
					ans++;
					set.add(shift);
				}
				
			}
		}
		
		return ans;
	}

}

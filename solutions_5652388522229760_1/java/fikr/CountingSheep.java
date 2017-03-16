// Google Code Jam Qualification Round 2016
// Problem A. Counting Sheep

import java.util.*;
import java.io.*;

public class CountingSheep{
	//static String filename = "A-small-attempt0";	// io filename here, change accordingly
	static String filename = "A-large";	
	static String inname = filename + ".in";    
	static String outname = filename + ".out";  
	static int n;
	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			int t = in.nextInt();
			in.nextLine();
			for (int cas = 1; cas <= t; cas++){
				String ans = "";
				int n = in.nextInt();
				int ret = solve(n);
				if (ret < 0) ans = "INSOMNIA";
				else ans += ret;
				System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	static int solve(int n){
		if (n == 0) return -1;
		HashSet<Integer> notSeen = new HashSet<Integer>(10);
		for (int i = 0; i < 10; i++){
			notSeen.add(i);
		}
		int toSee = n;
		int lastSeen = 0;
		while(!notSeen.isEmpty()){
			int curr = toSee;
			while(curr > 0){
				int digit = curr%10;
				notSeen.remove(digit);
				curr /= 10;
			}
			lastSeen = toSee;
			toSee = toSee+n;
		}
		return lastSeen;
	}
	
}
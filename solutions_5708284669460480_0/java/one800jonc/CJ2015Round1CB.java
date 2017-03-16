import java.io.*;
import java.util.*;


public class CJ2015Round1CB {
	public static double get_prob(String a, String[] letters){
		double count = 0;
		for (int i = 0; i < letters.length; i++){
			if (a.equals(letters[i])){
				count++;
			}
		}
		return count/letters.length;	
	}
	
	public static int get_rep(String[] letters){
		for (int i = 1; i < letters.length; i++){
			boolean match = true;
			for (int j = i; j<letters.length; j++){
				if (!letters[j].equals(letters[j-i])){
					match = false;
				}
			}
			if (match){
				return letters.length-i;
			}
		}
		return 0;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		//BufferedReader in = new BufferedReader(new FileReader("temp.txt"));
		PrintWriter out  = new PrintWriter(new File("2015Round1CBout.txt"));
		int T = Integer.parseInt(in.readLine());
		for(int a = 1; a < T+1; a++){
			String[] nums = in.readLine().split(" ");
			int S = Integer.parseInt(nums[2]);
			String[] key = in.readLine().split("");
			String[] target = in.readLine().split("");
			boolean poss = true;
			for (int i = 0; i < target.length; i++){
				if (get_prob(target[i],key)==0){
					poss = false;
				}
			}
			double ret = 0;
			if (poss){
				int rep = get_rep(target);
				int max;
				if (rep == 0) {
					max = S/target.length;
				} else {
					int add = target.length-rep;
					max = (S-rep)/add;
				}
				double prob = 1;
				for (int i = 0; i < target.length; i++){
					prob *= get_prob(target[i],key);
				}
				double exp = (S-target.length+1)*prob;
				ret = max-exp;
			}
			System.out.println("Case #"+a+": "+ret);
			out.println("Case #"+a+": "+ret);
		}
		in.close();
		out.close();
	}
}

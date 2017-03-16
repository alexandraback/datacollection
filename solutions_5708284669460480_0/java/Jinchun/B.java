import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class B {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-small-attempt0.in"));//
		PrintWriter out = new PrintWriter("out.txt");
		int T = in.nextInt();
		for(int i=1;i<=T;i++){
			int k = in.nextInt();
			int l = in.nextInt();
			int s = in.nextInt();
			in.nextLine();
			String dic = in.nextLine();
			String target = in.nextLine();
			if(!isPossible(dic,target)){
				out.println("Case #"+i+": 0.0");
				continue;
			}
			double res = solveSmall(k,l,s,dic,target);
			out.println("Case #"+i+": "+res);
		}
		
		out.close();
		in.close();

	}
	
	private static double solveSmall(int k, int l, int s, String dic, String target){
		double res = 0;
		int max = 0;
		ArrayList<String> strs = new ArrayList<String>();
		helper(dic,s,new StringBuilder(),strs);
		for(int i=0;i<strs.size();i++){
			int c = count(strs.get(i),target);
			res+=c;
			max=Math.max(max, c);
		}
		int fac = 1;
		for(int i=1;i<=s;i++){
			fac*=k;
		}
		return (double)max - res/(double)fac;
	}
	
	
	private static void helper(String dic, int s, StringBuilder item, ArrayList<String> res){
		if(item.length()==s){
			res.add(new String(item));
			return;
		}
		for(int i=0;i<dic.length();i++){
			item.append(dic.charAt(i));
			helper(dic,s,item,res);
			item.deleteCharAt(item.length()-1);
		}
	}
	
	private static int count(String s, String subs){
		int lastIdx = 0;
		int res = 0;
		while(lastIdx != -1){
			lastIdx = s.indexOf(subs,lastIdx);
			if( lastIdx != -1){
				res ++;
				lastIdx+=1;
			}
		}
		return res;
	}
	
	private static boolean isPossible(String dic, String target){
		for(int i=0;i<target.length();i++){
			StringBuilder strb = new StringBuilder();
			strb.append(target.charAt(i));
			if(!dic.contains(strb)){
				return false;
			}
		}
		return true;
	}

}

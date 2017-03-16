/**
 * 
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author rohit
 *
 */
public class QR16_B {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader(new File("/home/rohit/Desktop/codejam/b/large.in"));
		BufferedReader br = new BufferedReader(fr);
		
		FileWriter fw = new FileWriter(new File("/home/rohit/Desktop/codejam/b/large.out"));
		BufferedWriter bw = new BufferedWriter(fw);
		
		int tc = Integer.valueOf(br.readLine().trim());
		
		for(int i=0;i<tc;i++){
			String s = br.readLine().trim();
			
			long ans = solve(s); 
			
			bw.write("Case #" + (i+1) + ": " + ans);
			bw.write("\n");

		}
		
		bw.close();
		br.close();
		fw.close();
		fr.close();
	}
	private static long solve(String s) {
		char cur = s.charAt(0);
		int trans=0;
		for(int i=1;i<s.length();i++){
			if(s.charAt(i)!=cur){
				trans++;
				cur = s.charAt(i);
			}
		}
		if(s.charAt(s.length()-1)=='-')
			trans++;
		return trans;
	}
	
//	private static long solve(String s, long ans) {
//		if(mem.get(s)!= null)
//			return ans + mem.get(s);
//		
//		if(check(s)){
//			mem.put(s, 0L);
//			return ans;
//		}
//		
//		for(int i=1;i<=s.length();i++){
//			String ns = flip(s, i);
//			if(check(ns)){
//				mem.put(ns, 0L);
//				mem.put(s, 1L);
//				return ans+1;
//			} 
//		}
//		
//		if(isTerminal(s)){
//			int fp = 0;
//			for(;fp<s.length();fp++){
//				if(s.charAt(fp)=='+')
//					break;
//			}
//			int pl = 0;
//			int i=fp;
//			while(s.charAt(i)=='+'){
//				pl++;
//				i++;
//			}
//			s = flip(s, pl);
//			ans++;
//		}
//		int i=s.length()-1;
//		for(;i>=0;i--){
//			if(s.charAt(i)=='-')
//				break;
//			
//		}
//
//		String ns = flip(s, i+1);
//		long an = solve(ns, ans+1);
//		mem.put(s, an);
//		
//		return mem.get(s);
//	}
//
//	private static boolean isTerminal(String s) {
//		
//		if(s.length() < 2)
//			return false;
//		
//		int fm = s.length()-1;
//		for(;fm>=0;fm--){
//			if(s.charAt(fm)=='-')
//				break;
//		}
//		int ml = 0;
//		int i=fm;
//		while(s.charAt(i)=='-'){
//			ml++;
//			i--;
//		}
//		
//		
//		int fp = 0;
//		for(;fp<s.length();fp++){
//			if(s.charAt(fp)=='+')
//				break;
//		}
//		int pl = 0;
//		i=fp;
//		while(s.charAt(i)=='+'){
//			pl++;
//			i++;
//		}
//		
//		if(pl==ml)
//			return true;
//		return false;
//	}
//
//	private static boolean check(String ns) {
//		for(int i=0;i<ns.length();i++){
//			if(ns.charAt(i)=='-')
//				return false;
//		}
//			
//		return true;
//	}
//
//	private static String flip(String s, int ind) {
//		
//		StringBuffer sb = new StringBuffer();
//		for(int i=ind-1;i>=0;i--){
//			char c = s.charAt(i);
//			if(c=='+')
//				sb.append("-");
//			else
//				sb.append("+");
//		}
//		for(int i=ind;i<s.length();i++){
//			sb.append(s.charAt(i));
//		}
//		return sb.toString();
//	}

}

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Second {
	public static void main(String[] args) throws FileNotFoundException{
		String name = "b-large";
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		int tc = in.nextInt();
		for(int i = 1; i <= tc; i++){
			System.out.println(i);
			out.println("Case #" + i + ": " + solve(in.next(), in.next()));
		}
		out.close();
	}
	
	public static String solve(String c, String j){
		String[] rec = recur(0, 0, c, j);
		return rec[0] + " " + rec[1];
	}
	
	public static String[] brute(String c, String j, int ind){
		if(ind == c.length()){
			String[] ret = new String[2];
			ret[0] = c;
			ret[1] = j;
			return ret;
		}
		String[] min = null;
		if(c.charAt(ind) != '?' && j.charAt(ind) != '?'){
			min = brute(c, j, ind + 1);
		}
		else if(c.charAt(ind) == '?' && j.charAt(ind) == '?'){
			for(int i = 0; i < 10; i++){
				for(int k = 0; k < 10; k++){
					String[] recur = brute(c.substring(0, ind) + i + c.substring(ind + 1), 
							j.substring(0, ind) + k + j.substring(ind + 1), ind + 1);
					if(min == null || lessThan(recur, min)){
						min = recur;
					}
				}
			}
		}
		else if(c.charAt(ind) == '?'){
			for(int i = 0; i < 10; i++){
				String[] recur = brute(c.substring(0, ind) + i + c.substring(ind + 1), j, ind + 1);
				if(min == null || lessThan(recur, min)){
					min = recur;
				}
			}
		}else{
			for(int k = 0; k < 10; k++){
				String[] recur = brute(c, j.substring(0, ind) + k + j.substring(ind + 1), ind + 1);
				if(min == null || lessThan(recur, min)){
					min = recur;
				}
			}
		}
		return min;
	}
	
	public static String[] recur(int ci, int ji, String c, String j){
		if(c.length() == 0){
			String[] ret = new String[2];
			ret[0] = "";
			ret[1] = "";
			return ret;
		}
		char[] cc = new char[3];
		char[] jc = new char[3];
		if(c.charAt(0) != '?' && j.charAt(0) != '?'){
			cc[0] = c.charAt(0);
			jc[0] = j.charAt(0);
		}
		else if(c.charAt(0) == '?' && j.charAt(0) == '?'){
			if(ci == ji){
				cc[0] = '0';
				jc[0] = '0';
				cc[1] = '1';
				jc[1] = '0';
				cc[2] = '0';
				jc[2] = '1';
			}
			else if(ci > ji){
				cc[0] = '0';
				jc[0] = '9';
			}else{
				cc[0] = '9';
				jc[0] = '0';
			}
		}
		else if(c.charAt(0) == '?'){
			jc[0] = j.charAt(0);
			if(ci == ji){
				cc[0] = j.charAt(0);
				if(j.charAt(0) != '9'){
					jc[1] = j.charAt(0);
					cc[1] = (char)(j.charAt(0) + 1);
				}
				if(j.charAt(0) != '0'){
					jc[2] = j.charAt(0);
					cc[2] = (char)(j.charAt(0) - 1);
				}
			}
			else if(ci > ji){
				cc[0] = '0';
			}else{
				cc[0] = '9';
			}
		}
		else{
			cc[0] = c.charAt(0);
			if(ci == ji){
				jc[0] = c.charAt(0);
				if(c.charAt(0) != '9'){
					cc[1] = c.charAt(0);
					jc[1] = (char)(c.charAt(0) + 1);
				}
				if(c.charAt(0) != '0'){
					cc[2] = c.charAt(0);
					jc[2] = (char)(c.charAt(0) - 1);
				}
			}
			else if(ji > ci){
				jc[0] = '0';
			}else{
				jc[0] = '9';
			}
		}
		String[][] recur = new String[3][2];
		int min = 0;
		for(int i = 0; i < 3; i++){
			if(cc[i] != '\0'){
				recur[i] = recur(10 * ci + (cc[i] - '0'), 10 * ji + (jc[i] - '0'), c.substring(1), j.substring(1));
				recur[i][0] = cc[i] + recur[i][0];
				recur[i][1] = jc[i] + recur[i][1];
				if(i != 0 && lessThan(recur[i], recur[min])){
					min = i;
				}
			}
		}
		return recur[min];
	}
	
	static boolean lessThan(String[] s1, String[] s2){
		long c1 = Long.parseLong(s1[0]);
		long j1 = Long.parseLong(s1[1]);
		long c2 = Long.parseLong(s2[0]);
		long j2 = Long.parseLong(s2[1]);
		if(Math.abs(c1 - j1) < Math.abs(c2 - j2)){
			return true;
		}
		else if(Math.abs(c1 - j1) > Math.abs(c2 - j2)){
			return false;
		}else{
			if(c1 < c2){
				return true;
			}
			else if(c1 > c2){
				return false;
			}else{
				return j1 < j2;
			}
		}
	}
}

import java.io.*;
import java.util.*;

public class ProblemB{
	
		
	private static Scanner s = new Scanner(System.in);
	public static void main(String[] args){
		int t = Integer.parseInt(s.nextLine());
		
		for(int i = 0; i < t; i++){
			String testcase = s.nextLine();
			System.out.println("Case #"+(i+1)+": " + solve(testcase));
		}
	}
	
	public static String solve(String testcase){
		String answer = "";
		String[] tc = testcase.split(" ");
		int n = tc[0].length();
		int q1 = tc[0].length() - tc[0].replace("?","").length();
		int q2 = tc[1].length() - tc[1].replace("?","").length();
		int[] p1 = new int[(int)Math.pow(10,q1)];
		int[] p2 = new int[(int)Math.pow(10,q2)];
		String y = tc[0];
		if(p1.length>1){
			for(int i = 0; i < p1.length; i++){
				char[] x = String.format("%0"+q1+"d", i).toCharArray();
				y = tc[0];
				for(int j = 0; j < x.length; j++){
					y = y.replaceFirst("\\?",String.valueOf(x[j]));
				}
				p1[i] = Integer.parseInt(y);
			}
		}else{
			p1[0] = Integer.parseInt(tc[0]);
		}
		if(p2.length>1){
			for(int i = 0; i < p2.length; i++){
				char[] x = String.format("%0"+q2+"d", i).toCharArray();
				y = tc[1];
				for(int j = 0; j < x.length; j++){
					y = y.replaceFirst("\\?",String.valueOf(x[j]));
				}
				p2[i] = Integer.parseInt(y);
			}
		}else{
			p2[0] = Integer.parseInt(tc[1]);
		}
		int lowest = -1;
		for(int i = 0; i < p1.length; i++){
			for(int j = 0; j < p2.length; j++){
				int diff = Math.abs(p1[i] - p2[j]);
				String a = String.format("%0"+n+"d", p1[i])+ " " +
						String.format("%0"+n+"d", p2[j]);
				if(lowest==-1 || diff < lowest){
					lowest = diff;
					answer = a;
				}
			}
		}
		return answer;
	}
	
}
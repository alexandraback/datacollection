package CodeJam2016;

import java.util.Scanner;

public class round2_1 {

	public static String solution(String s)
	{
		StringBuilder sb = new StringBuilder();
		
		char pre = s.charAt(0);
		sb.append(pre);
		
		int index = 1;
		while(index<s.length()){
			char cur = s.charAt(index);
			if(cur>=pre)
			{
				sb.insert(0, cur);
				pre = cur;
			}
			else {
				sb.append(cur);
			}
			
			++index;
		}
		
		return sb.toString();
	}
	
	
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i=0;i<=n;++i)
		{
			String s = in.nextLine();
			System.out.println("CASE #" + (i+1+": ") + solution(s));
		}
	}
	

}

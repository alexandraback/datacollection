import java.io.*;
import java.util.*;

class cj{
	public static void main(String args[])throws IOException{
		int i,j,k,l,p;
		Scanner sc = new Scanner(System.in);
		String s, ans="";
		int t;
		t = Integer.parseInt(sc.nextLine());
		
		for(p=1;p<=t;p++){
			s = sc.nextLine();
			l = s.length();
			ans = "";
			ans += s.charAt(0);
			for(i=1;i<l;i++){
				if(s.charAt(i) < ans.charAt(0)){
					ans = ans + s.charAt(i);
				}
				else{
					ans = s.charAt(i) + ans;
				}
			}
			System.out.println("Case #"+p+": "+ans);
		}
	}
}

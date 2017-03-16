package gcj2015;

import java.io.*;
import java.util.*;

public class Rnd1B_a {

	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
//		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/A-large.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/Rnd1B_a.txt");
		
		int res,rep,i,j;
		long ans;
		int[] f = new int[1000001];
		int[] cl = new int[16];
		String s;
		String nine = "9999999999999999999999999999";
	
		cl[1] = 1;
		cl[2] = 10;
		cl[3] = 29;
		for(i=3;i<=15;i++) {
			
			int t = Integer.parseInt(nine.substring(0,i/2));
			cl[i] = cl[i-1] + Integer.parseInt(nine.substring(0,(i-1)/2)) + 1 +
					Integer.parseInt(nine.substring(0,i-1 - (i-1)/2));
		}
		res = sc.nextInt();
		s = sc.nextLine();
		for(rep=1;rep<=res;rep++){
			
			s = sc.nextLine();
			int l = s.length();
			String ri = s.substring(0,l/2);
			String le = s.substring(l/2,l);
			
			//move to digit num
			int ans2 = 0;
			if (l >= 1) ans2 = 1;
			if (l>=2) ans2 = 10;
			ans2 = cl[l];
			
	//		System.out.println(ans);
			if (Long.parseLong(s)<=20) {
				ans2 = Integer.parseInt(s);
			}
			else if (rev(Integer.parseInt(ri)) == 1) {
				
				ans2 += Integer.parseInt(le);
			}
			else if (Integer.parseInt(le) == 0) {
				int r = Integer.parseInt(ri);
				int t = rev(r-1);
				String st = Integer.toString(r-1) + le.substring(0, le.length()-1) + '1';
//				System.out.println(ans2);
//				System.out.println(st+"*");
				if (check(st)) ans2--;
				ans2 += t;
	//			if (r!=2) ans2 += 1;
				ans2+=1;
				ans2 += Long.parseLong(s) - Long.parseLong(st);
			}
			else{
//				System.out.println(ri);
//				System.out.println(le);
//				System.out.println(ans2);
			int r = Integer.parseInt(ri);
			ans2 += rev(r);
			ans2 ++;
			ans2 += Integer.parseInt(le) - 1;
			}
			System.out.println(ans2);
			ou.printf("Case #%d: ",rep);
			ou.println(ans2);
			
		}
		
		ou.close();
	}
	
	public static int rev(int a){
		
		String s = Integer.toString(a);
		String s2 = "";
		int i;
		for(i=0;i<s.length();i++) {
			s2 += s.charAt(s.length()-1-i);
		}
		
		return Integer.parseInt(s2);
	}
	
	public static boolean check(String s) {
		int i;
		
		for(i=0;i<=s.length()/2;i++) {
			if (s.charAt(i)!=s.charAt(s.length()-1-i)) return false;
		}
		
		return true;
	}
}

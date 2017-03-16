package gcj2015;

import java.io.*;
import java.util.*;

public class Quali1 {

	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
		//Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/A-large.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/qualiA.txt");
		int i,j,res,rep,t,smax,sta,ans;
		String s;
		String[] s2;
		
		res = sc.nextInt();
		s = sc.nextLine();
		for(rep=1;rep<=res;rep++){
			
			sta = 0; ans = 0;
			s = sc.nextLine();
			s2 = s.split(" ");
			smax = Integer.parseInt(s2[0]);
			for(i=0;i<=smax;i++){
				
				t = ((int) s2[1].charAt(i)) - ((int) '0');
				if (sta>=i) sta += t;
				else {
					ans += i - sta;
					sta = i + t;
				}
			}
			
	//		System.out.printf("Case #%d: %d\n",rep,ans);
			ou.printf("Case #%d: %d\n",rep,ans);
		}
		
		ou.close();
	}

}

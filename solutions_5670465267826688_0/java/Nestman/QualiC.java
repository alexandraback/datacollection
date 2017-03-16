package gcj2015;

import java.io.*;
import java.util.*;

public class QualiC {
	static final int mul[][] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
	static final int pow[][] = {{1,1,1,1},{1,2,3,4},{1,-1,-1,-1},{1,-2,-3,-4}};
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
		//Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/C-small-attempt1.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/qualiC.txt");
		
		long res,rep,x,ip,kp,totl;
		int pos,pro,i,l;
		boolean flag;
		String s;
		
		res = sc.nextInt();
		ip = kp =0;
		for(rep=1;rep<=res;rep++){
			
			flag = true;
			l = sc.nextInt(); x = sc.nextLong();
			totl = l*x;
			s = sc.nextLine();
			s = sc.nextLine();
			
			pro = 1;
			for(i = 0;i<l;i++) {
				
				int t = ((int) s.charAt(i)) - ((int) 'i') + 2;
				pro = quatmul(pro,t);
				
			}
			
//			System.out.println(pro+"*");
			int sp = (int) Math.signum(pro);
			if (x % 2 == 0) sp = sp*sp;
			pro = sp*pow[(int) (x % 4)][Math.abs(pro) - 1];
//			System.out.println(pro);
			if (pro != -1) flag = false;
			
			if (flag) {
				
				ip = 0; pos = 0; pro = 1;
				while ((ip<5*l)&&(ip<totl)) {
				
					int t = ((int) s.charAt(pos)) - ((int) 'i') + 2;
					pro = quatmul(pro,t);
			//		System.out.println(pro);
					if (pro == 2) break;
				
					if (pos == l-1) {
					
						if (pro == 1) break;
						pos = 0;
					}
					else pos++;
				
					ip++;
			}
			
			if (pro != 2) flag = false;
			}
			if (flag) {
				
				kp = totl - 1; pos = l-1; pro = 1;
				while ((kp>ip+1)) {
					
					int t = ((int) s.charAt(pos)) - ((int) 'i') + 2;
					pro = quatmul(t,pro);
					
					if (pro==4) break;
					
					if (pos==0) {
						
						if (pro==1) break;
						pos = l-1;
					}
					else pos--;
					
					kp--;
				}
				if (pro!=4) flag = false;
			}
			
			ou.printf("Case #%d: ", rep);
			
			if (flag) ou.println("YES");
			else ou.println("NO");
		}
		
		ou.close();
	}
	
	public static int quatmul(int x,int y) {
		
		int sx = (int) Math.signum(x), sy = (int) Math.signum(y);
		return sx*sy*mul[Math.abs(x)-1][Math.abs(y)-1];
		
	}
}

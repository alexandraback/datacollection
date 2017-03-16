import java.util.HashSet;
import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);

	private static void solve() {

		int T = sc.nextInt();
		for (int test = 1; test <= T; test++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			
			System.out.print("Case #" + test + ": ");
			int n = 1;
			while(true){
				long crtDist = Math.abs(x)+Math.abs(y);
				long d1 = Math.abs(x+n)+Math.abs(y);
				long d2  = Math.abs(x)+Math.abs(y+n);
				long d3 = Math.abs(x-n)+Math.abs(y);
				long d4 = Math.abs(x)+Math.abs(y-n);
				
				long min = Math.min(d1, Math.min(d2, Math.min(d3, d4)));
				//System.out.println("min "+min +" crt "+crtDist);
				boolean fl = false,fll=true;
				if((min == d1 || min == d3) && (min==d2||min==d4))fl =true;
				if(min >= crtDist)break;
				if(min == d1){
					if(!fl || x+n==0){System.out.print("W");x+=n;fll =false;}
				}if(min == d2 && fll){
					System.out.print("S");y+=n;fll =false;
				}if(min == d3 && fll){
					if(!fl || x-n==0){System.out.print("E");x-=n;fll =false;}
				} if(min == d4 && fll){
					System.out.print("N");y-=n;
				}
				n++;
			}
			
			if(x<0)for (int i = 0; i < Math.abs(x); i++) {
				System.out.print("EW");
			}
			else for (int i = 0; i < x; i++) {
				System.out.print("WE");
			}
			
			if(y<0)for (int i = 0; i < Math.abs(y); i++) {
				System.out.print("NS");
			}
			else for (int i = 0; i < y; i++) {
				System.out.print("SN");
			}
			
			
System.out.println();
		}

	}
	public static void main(String[] ar){
		solve();
	}
}

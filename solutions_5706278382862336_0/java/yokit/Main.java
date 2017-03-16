import static java.lang.System.*;
import java.util.*;

public class Main {
	static int check(int num) {
		while(num % 2 == 0) num /= 2;
		return num;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(in);

		int setnum = sc.nextInt();
		for(int seti=1; seti<=setnum; seti++) {
			String[] tmp = sc.next().split("/");
			int chi = new Integer(tmp[0]);
			int par = new Integer(tmp[1]);
			
			int other = check(par);
			if(chi % other != 0 || chi >= par) {
				out.println("Case #" + seti + ": impossible");
				continue;
			}
			
			chi /= other;
			par /= other;
			for(int i=1; i<=40; i++) {
				if(chi * 2 >= par) {
					out.println("Case #" + seti + ": " + i);
					break;
				}
				if(par == 1 || i==40) out.println("Case #" + seti + ": impossible");
				
				par /= 2;
			}
		}
	}

}

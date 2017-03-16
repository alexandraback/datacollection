import java.util.*;

public class GC1D_15{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			int x = sc.nextInt();
			int r = sc.nextInt();
			int c = sc.nextInt();

			boolean G = false;
			if(x == 1) G = true;
			else if(x == 2 && r*c % 2 == 0) G = true;
			else if(x == 3 && (r*c == 6 || r*c == 12 || r*c == 9)) G = true;
			else if(x == 4 && (r*c == 12 || r*c == 16)) G = true;

			if(G) System.out.printf("Case #%d: GABRIEL\n",ca);
			else System.out.printf("Case #%d: RICHARD\n",ca);
		}
	}
}
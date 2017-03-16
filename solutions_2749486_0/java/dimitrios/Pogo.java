import java.util.Vector;

public class Pogo {

	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			StringBuilder b = new StringBuilder();
			int X = sc.nextInt();
			int Y = sc.nextInt();
			if(X>0) {
				for(int x=0; x<X; x++) b.append("WE");
			} else if(X<0) {
				for(int x=0; x>X; x--) b.append("EW");
			}
			if(Y>0) {
				for(int y=0; y<Y; y++) b.append("SN");
			} else if(Y<0) {
				for(int y=0; y>Y; y--) b.append("NS");
			}
			System.out.printf("Case #%d: %s\n", t, b.toString());
		}
	}
}
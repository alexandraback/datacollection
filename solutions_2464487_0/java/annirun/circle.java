import java.util.Scanner;

//pi r r
public class circle {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		
		for (int i = 0; i < cases; i++) {
			int r = in.nextInt();
			double t = in.nextInt();
			
			
			int amt = 0;
			while (t >= 0) {
				double used = (area(r)); 
				t -= used;
				r +=2;
				amt++;
			}
			
			System.out.printf("Case #%d: %d\n", i+1, amt - 1);
		}
	}
	public static double area(int r) {
		return (2 * r + 1);
	}
}

import java.util.Scanner;


public class Jam2015_1CA {
	public int solve(int r, int c, int w) {
		int	total	= r*c;
		int	ret		= 0;
		
		//	scan
		ret	= r*(c/w);

		if(c % w == 0) {
			ret	+= w-1;
		} else if( w == 1) {
		} else {
			ret	+= w;
		}
		
		return	ret;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Jam2015_1CA	inst	= new Jam2015_1CA();
			int		r	= scanIn.nextInt();
			int		c	= scanIn.nextInt();
			int		w	= scanIn.nextInt();
			
			int	ret	= inst.solve(r, c, w);
			
			System.out.println("Case #" + (i+1) + ": " + ret);
		}
		
		scanIn.close();
	}
}

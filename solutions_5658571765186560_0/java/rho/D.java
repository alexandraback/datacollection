import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class D {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("D.in"));
		int numT = sc.nextInt();
		for(int test=1; test<=numT; ++test)
		{
			int X = sc.nextInt(), R = sc.nextInt(), C = sc.nextInt();
			int max = Math.max(R, C), min = Math.min(R, C);
			
			if(X<7 && max*min%X==0 && X<=max && (X+1)/2<=min && !(X==4 && min==2) && !(X==5 && max==5 && min==3) && !(X==6 && min==3))
				System.out.printf("Case #%d: GABRIEL\n", test);
			else
				System.out.printf("Case #%d: RICHARD\n", test);
		}
	}

}

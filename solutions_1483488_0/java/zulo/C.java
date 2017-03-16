import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class C {

	void start() {
		Scanner sc=new Scanner(System.in);
		int nt=sc.nextInt();
		for (int tc=1; tc<=nt; tc++) {
			int a=sc.nextInt(), b=sc.nextInt(), re=0;
			if (a<b && a>9) {
				int p=1;
				while (p*10<b) 
					p*=10;
				for (int x=a; x<=b; x++) {
					int z=x;
					do {
						z=z/10 + z%10*p;
						if (z>x && z>=a && z<=b) 
							re++;
					} while (z!=x);
				}
			}
			System.out.printf("Case #%d: %d\n", tc, re);
		}
	}

	public static void main(String[] args) throws Exception {
		new C().start();
	}
}
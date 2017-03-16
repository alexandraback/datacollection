import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import java.math.*;
import java.util.*;
public class B {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(in);
		int z = sc.nextInt();
		double R,H,B,A;
		for (int cas = 1; cas <= z; cas++) {
			double C = parseDouble(sc.next());
			double F = parseDouble(sc.next());
			double X = parseDouble(sc.next());
			for(H=0,A=X/(R=2);A>=(B=(H+=C/R)+X/(R+=F));A=B);
			out.printf("Case #%d: %.7f\n",cas,A);
		}
	}
}

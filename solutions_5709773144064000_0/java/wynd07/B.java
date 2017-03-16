import java.io.*;
import java.util.*;
import static java.lang.System.*;
public class B {
	public static void main (String [] args) throws Exception {new B().run();}
	public void run() throws Exception{
		Scanner file = new Scanner(new File("B-small-attempt0.in.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		int T = file.nextInt();
        for(int asdf = 0; asdf<T; asdf++){
            out.printf("Case #%d: ",asdf+1);
            double C = file.nextDouble(), F = file.nextDouble(), X = file.nextDouble();
            int N = (int)Math.ceil(X);
            double r = 2, t = 0, min = X/r;
            for(int i = 0; i<=N; i++){
                t += (C/r);
                r += F;
                min = Math.min(min, X/r+t);
            }
            out.printf("%.7f%n",min);
		}
		out.close();
	}
}
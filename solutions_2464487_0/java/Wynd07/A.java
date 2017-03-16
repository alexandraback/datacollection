import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;

public class A {
	public static void main (String [] args) throws IOException {new A().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		int T = file.nextInt();
        for(int aa = 0; aa<T; aa++){
            long r = file.nextLong(), t =file.nextLong();
            for(long i = 0; ; i+=10){
                long ans = val(r, i);
                //System.out.println(ans + " " + i);
                //new Scanner(System.in).nextLine();
                if( ans > t || ans < 0 ){
                    while(ans > t || ans < 0 ){
                        ans = val(r, i);
                        i--;
                    }
                    out.println("Case #"+(aa+1)+": "+(i+2));
                    System.out.println(aa);
                    break;
                }
            }
        }
		out.close();
		System.exit(0);
	}
    long val(long r, long n){
        return 2*n*n+2*n*r+3*n+2*r+1;
    }
}
import java.io.*;
import java.util.*;
import static java.lang.System.*;
public class D {
	public static void main (String [] args) throws Exception {new D().run();}
	public void run() throws Exception{
		Scanner file = new Scanner(new File("D-large.in.txt"));
		//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D.out")));
		int T = file.nextInt();
        for(int asdf = 0; asdf<T; asdf++){
            out.printf("Case #%d: ",asdf+1);
            int n = file.nextInt();
            double[][] a = new double[2][n];
            for(int j =0; j<2; j++){
                for(int i = 0; i<n; i++)
                    a[j][i] = file.nextDouble();
                Arrays.sort(a[j]);
            }
            int i = 0, j = 0;
            for(; i < n && j < n; i++, j++)
                for(; j<n && a[0][i] > a[1][j]; j++);
            int x = n-i;
            if(j == n+1 ) x++;
            i = 0; j = 0;
            for(; i<n; i++)
                if( a[0][i] > a[1][j] )
                    j++;
            out.println(j+ " "+ x);
		}
		out.close();
	}
}
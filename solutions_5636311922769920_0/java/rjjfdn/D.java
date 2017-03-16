import java.util.*;
import java.io.*;

public class D {

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("d.in"));
    	PrintWriter p = new PrintWriter(new FileWriter("d.out"));
    	int t = s.nextInt();
    	for(int q=0; q<t; q++) {
    		int k = s.nextInt();
    		int c = s.nextInt();
    		int g = s.nextInt();
    		p.print("Case #" + (q+1) + ":" );
    		for(int i=1; i<=k; i++)
    			p.print(" " + i);
    		p.println();
    	}
    	p.close();
    }
}

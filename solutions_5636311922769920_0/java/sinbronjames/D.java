import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner (System.in);
		Scanner in = new Scanner (new File ("D-small-attempt0.in"));
		PrintWriter out = new PrintWriter (new FileWriter ("D-small.txt"));
	    int T = in.nextInt();
	    for (int test = 1; test<=T; test++)
	    {
	    	int K = in.nextInt();
	    	int C = in.nextInt();
	    	int S = in.nextInt();
	    	out.print("Case #"+test+":");
	    	for (int i=1; i<=K; i++)
	    	{
	    		out.print(" ");
	    		out.print(i);
	    	}
	    	out.println();
	    }
		
     out.close();
	}

}

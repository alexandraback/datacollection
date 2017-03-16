
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	private static Scanner in;
	private static PrintWriter out;
	private static int T; //number of tests
	private static int X;
	private static int Y;
	
	
	static void solve()
	{
		for(int i = 1; i <= T; i++ )
		{
			readTest(i);
			solveTest(i);
		}
		
	}
	
    private static void solveTest(int C) {
    	int curSpeed = 1, x = 0, y=0;
    	StringBuilder b = new StringBuilder();
    	
    	while(x != X || y != Y)
    	{
    		if(X > x)
    		{
    			b.append('W');
    			curSpeed++;
    			b.append('E');
    			curSpeed++;
    			x++;
    		}
    		else if(X < x)
    		{
    			b.append('E');
    			curSpeed++;
    			b.append('W');
    			curSpeed++;
    			
    			x--;
    		}
    		if(Y > y)
    		{
    			b.append('S');
    			curSpeed++;
    			b.append('N');
    			curSpeed++;
    			y++;
    		}
    		else if(Y < y)
    		{
    			b.append('N');
    			curSpeed++;
    			b.append('S');
    			curSpeed++;
    			y--;
    		}
    	}
    	if(b.length() > 500)
    	{
    		throw new RuntimeException("incorrect solution!!");
    	}
    	out.println("Case #" + C + ": " + b.toString());
	}

	private static void readTest(int C) {
		X = in.nextInt();
		Y = in.nextInt();
	}

	static public void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("C:\\codejam\\b\\test.in"));
        out = new PrintWriter(new File("C:\\codejam\\b\\test.out"));

        T = in.nextInt();

        solve();
        out.flush();
        in.close();
        out.close();
    }
	
	private static void debug(String str)
	{
		System.out.println(str);
	}
	
	private static void debug(Object... objects)
	{
		debug(Arrays.toString(objects));
	}
}


import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {


	private static Scanner in;
	private static PrintWriter out;
	private static int T; //number of tests
	private static String name;
	private static int N;
//	private static int N;
	
	static char[] vowels = {'a', 'e', 'i', 'o', 'u'};
	
	static void solve()
	{
		for(int i = 1; i <= T; i++ )
		{
			readTest(i);
			solveTest(i);
		}
		
	}
	
    private static void solveTest(int C) {
    	int i;
    	int j;
    	int cnt = 0;
    	for (i = 1; i <= name.length(); i++) {
            for (j = 0; j + i <= name.length(); j++) {
                String ss = name.substring(j, j + i);
//                debug(ss);
                if(countCons(ss))
                {
                	cnt++;
                }
            }
        }
    	out.println("Case #" + C + ": " + cnt);
	}

	private static boolean countCons(String ss) {
		int cnt = 0;
		for(int i = 0; i <ss.length(); i++)
		{
			char c = ss.charAt(i);
			if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
			{
				cnt++;
			}
			else
			{
				cnt = 0;
			}
			if(cnt >= N)
				return true;
			
		}
		return false;
	}

	private static void readTest(int C) {
		name = in.next();
		N = in.nextInt();
		debug("name: " + name + " N: " + N);
	}

	static public void main(String[] args) throws FileNotFoundException {
		debug("starting");
        in = new Scanner(new File("C:\\codejam\\a\\test.in"));
        out = new PrintWriter(new File("C:\\codejam\\a\\test.out"));

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

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class RecycleNumbers {
	
	private static final Map<Integer,Integer> power = new HashMap<Integer,Integer>();
	
	static{
		power.put(0,1);
		power.put(1,10);
		power.put(2,100);
		power.put(3,1000);
		power.put(4,10000);
		power.put(5,100000);
		power.put(6,1000000);
	}
	
	private static int recycle(int b , int max)
	{
		int size =0 ,ret = 0;
		int a = b , rem = 0 , i = 0;
		while((size++ > -1) && ((a = a/10)!= 0));
		a = b;
		int myPower = power.get(size -1);
		Set<Integer> mySet = new HashSet<Integer>();
		for(i = 0 ; i < size-1; i++)
		{
			rem = a%10;
			a = rem * myPower + a/10;
			if(a > b && a <= max && !mySet.contains(a)) ret++;
			mySet.add(a);
		}
		return ret;
	}
	
	public static void main(String[] args) throws IOException {
		if (args.length < 2) {
			System.err.println("Please enter the Valid I/O Paths in the argument ");
			System.err.println("First Input , then OutPut ");
			System.exit(0);
		}
		File inFile = new File(args[0]);
		File outFile = new File(args[1]);
		BufferedReader in = new BufferedReader(new InputStreamReader(
				new FileInputStream(inFile)));
		PrintWriter out = new PrintWriter(new FileOutputStream(outFile));
		String myLine = in.readLine();
		int t = Integer.parseInt(myLine);
		int caseNum = 1 , result;
		int a , b;
		while (t-- > 0) {
			myLine = in.readLine();
			String[] myStr = myLine.split(" ");
			a = Integer.parseInt(myStr[0]);
			b = Integer.parseInt(myStr[1]);
			result = 0;
		    for(int i = a ; i < b ; i++)
		    	result += recycle(i,b);
			out.println("Case #" + (caseNum) + ": " + result);
			caseNum++;
		}
		out.close();
	}
}

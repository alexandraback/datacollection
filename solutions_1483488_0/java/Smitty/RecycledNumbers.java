import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;

public class RecycledNumbers {

	private final static String FILE_IN = RecycledNumbers.class.getSimpleName() + ".in";			
	private final static String FILE_OUT = RecycledNumbers.class.getSimpleName() + ".out";			
	
	public static void main(String[] args) throws Exception {
		final Scanner in = new Scanner(new File(FILE_IN));
		final PrintWriter out = new PrintWriter(FILE_OUT);
		final int testCnt = in.nextInt();
		for (int caseNum = 1; caseNum <= testCnt; ++ caseNum){
			final int a = in.nextInt();
			final int b = in.nextInt();			
			final int last [] = new int [b + 1];
			int result = 0;
			for (int i = a; i <= b; ++ i){
				final String s = String.valueOf(i);			
				for (int pos = 1; pos < s.length(); ++ pos){
					final String newNum = s.substring(pos) + s.substring(0, pos);
					final int newInt = Integer.valueOf(newNum);
					if (newInt > i && newInt <= b){
						if (last[newInt] != i){
							++ result;
							last[newInt] = i;
						}
					}
				}
			}
			out.println(String.format("Case #%d: %d", caseNum, result));
		}
		in.close();
		out.close();
	}

}

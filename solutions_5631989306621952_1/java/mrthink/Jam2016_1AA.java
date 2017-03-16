import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Jam2016_1AA {
	public char[] solve(char[] arr) {
		List<Character> ret = new LinkedList<Character>();
		int length = 0;
		
		for(char c : arr) {
			if(length == 0) {
				ret.add(c);
				length++;
				continue;
			}

			Character a = ret.get(0);
			
			if(a > c)
				ret.add(length, c);
			else
				ret.add(0, c);
			length++;
		}
		
		int j=0;
		char[] ret2 = new char[length];
		for(Character c: ret)
			ret2[j++] = c;
		
		return ret2;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Jam2016_1AA	inst	= new Jam2016_1AA();
			String		str		= scanIn.next();
			
			char[] ret = inst.solve(str.toCharArray());
			
			
			System.out.println("Case #" + (i+1) + ": " + new String(ret));
		}
		
		scanIn.close();
	}

}

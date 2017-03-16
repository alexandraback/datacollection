import java.io.*;


public class Main{
	
	
	private static boolean isConsonant(char c){
		return (c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u');
	}
	
	
	private static long solve(String s, int n){
		int consonantCount = 0;
		int i;
		for (i = 0; i < n; i++)
			if (isConsonant(s.charAt(i)))
				consonantCount++;
		
		long nValue = (consonantCount == n) ? 1 : 0;
		int lastConsecutiveN = (consonantCount == n) ? 0 : -1;
		for (; i < s.length(); i++){
			if (isConsonant(s.charAt(i-n)))
				consonantCount--;
			if (isConsonant(s.charAt(i)))
				consonantCount++;
			if (consonantCount == n)
				lastConsecutiveN = i-n+1;
			if (lastConsecutiveN != -1)
				nValue += lastConsecutiveN+1;
		};
		
		return nValue;
	}
	
	
	public static void main(String [] args){
		FastReader in = FastReader.SYSTEM_READER;
		int t = in.nextUnsignedInt();
		
		for (int tc = 0; tc < t; tc++){
			String s = in.nextUnspacedString();
			int n = in.nextUnsignedInt();
			
			System.out.printf("Case #%d: %d\n", tc+1, solve(s, n));
		}
	}
}

final class FastReader{
	
	public static final FastReader SYSTEM_READER = new FastReader(System.in);
	
	private final InputStream in;
	private final byte[] buffer = new byte[1<<16];
	private int pos, count;
	
	public FastReader(InputStream in){
		this.in = in;
		pos = count = 0;
	}
	
	public int nextUnsignedInt(){
		int c;
		while ((c = read()) < '0');
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return result;
	}
	
	public int nextInt(){
		int c;
		while (((c = read()) < '0') && (c != '-'));
		
		boolean isNegative = false;
		if (c == '-'){
			isNegative = true;
			c = read();
		}
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return isNegative ? -result : result;
	}
	
	
	public String nextUnspacedString(){
		StringBuilder s = new StringBuilder();
		int c;
		while ((c = read()) < 33);
		s.append((char)c);
		while ((c = read()) >= 33)
			s.append((char)c);
		return s.toString();
	}
	
	public char nextNonWhitespaceChar(){
		int c;
		while ((c = read()) < 33);
		return (char)c;
	}
	
    
	private boolean fillBuffer(){
		try{
			return (count = in.read(buffer, pos = 0, buffer.length)) > 0;
		} catch (Exception e){
			return false;
		}
	}
	
	
	public int read(){
		if (pos == count)
			if (!fillBuffer())
				return -1;
		return buffer[pos++];
	}
	
}


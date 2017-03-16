import java.io.*;
import java.util.*;

public class MainSmall{
	
	private static class Point{
		
		public final int x;
		public final int y;
		
		public Point(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		public int hashCode(){
			return x + 31*y;
		}
		
		public boolean equals(Object o){
			if (!(o instanceof Point))
				return false;
			
			Point p = (Point)o;
			return (p.x == x) && (p.y == y);
		}
		
	}
	
	
	private static final Map<Point, String> answers = new HashMap<Point, String>();
	
	private static String get(int x, int y){
		return answers.get(new Point(x, y));
	}
	
	private static void set(int x, int y, String s){
		answers.put(new Point(x, y), s);
	}
	
	private static boolean isValidLocation(int x, int y, int currentStep){
//		int max = 501*250 - (currentStep+1)*currentStep/2;
		int max = 500;
		return (x >= -max) && (x <= max) && (y >= -max) && (y <= max);
	}
	
	private static void maybeAdd(LinkedList<Point> queue, int x, int y, String s){
		if (isValidLocation(x, y, s.length()) && (get(x, y) == null)){
			set(x, y, s);
			queue.offer(new Point(x, y));
		}
	}
	
	private static void precompute(){
		LinkedList<Point> queue = new LinkedList<Point>();
		
		set(0, 0, "");
		queue.offer(new Point(0, 0));
		while (!queue.isEmpty()){
			Point p = queue.poll();
			int x = p.x;
			int y = p.y;
			String s = get(x, y);
			int step = s.length()+1;
			
			maybeAdd(queue, x+step, y, s + 'E');
			maybeAdd(queue, x-step, y, s + 'W');
			maybeAdd(queue, x, y+step, s + 'N');
			maybeAdd(queue, x, y-step, s + 'S');
		}
	}
	
	public static void main(String [] args){
		FastReader in = FastReader.SYSTEM_READER;
		int t = in.nextUnsignedInt();
		
		precompute();
		
		int unreachableCount = 0;
		for (int x = -100; x <= 100; x++)
			for (int y = -100; y <= 100; y++)
				if (get(x, y) == null)
					unreachableCount++;
//		System.out.printf("Unreachable=%d\n", unreachableCount);
		
		for (int tc = 0; tc < t; tc++){
			int x = in.nextInt();
			int y = in.nextInt();
			
			System.out.printf("Case #%d: %s\n", tc+1, get(x, y));
			
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


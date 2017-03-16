package qualification;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.Vector;

public class ProblemC {
	
	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {

		int cases = scan.nextInt();
		
		for ( int i = 1; i <= cases; i++ ) {
			
			System.out.println("Case #" + i + ": " + solveCase());
			
			
		}

	}
	
	public static int solveCase() {
		
		int A = scan.nextInt();
		int B = scan.nextInt();
		
		Map<Integer, Long> map = new HashMap<Integer, Long>();
		Integer[] digits;
		
		for ( int i = A; i <= B; i++ ) {
			digits = getDigits(i);
			addToMap(digits, map);
		}
		
		int result = 0;
		
		for ( Long l : map.values() ) {
			result += (l * (l-1)) / 2;
		}
		
		return result;
		
	}
	
	public static void addToMap(Integer[] n, Map<Integer, Long> map) {
		
		Vector<Integer> rots = getRotationSymmetricValues(n);
		// Remember to handle leading 0! All must have same length
		
		for ( Integer num : rots) {
			
			if ( map.containsKey(num) ) {
				map.put(num, map.get(num)+1);
				return;
			}
		}
		
		map.put(digitsToNum(n), 1L);
		
	}
	
	public static Vector<Integer> getRotationSymmetricValues(Integer[] n) {
		
		Vector<Integer> result = new Vector<Integer>();
		
		int origNum = digitsToNum(n);
		
		Queue<Integer> v = new LinkedList<Integer>();
		for ( int i = 0; i < n.length; i++ ) {
			v.add(n[i]);
		}
		
		while (true) {
			Integer first = v.poll();
			v.add(first);
			
			if ( v.peek() == 0 ) 
				continue;
			
			int num = 0;
			
			for ( Integer i : v) {
				num *= 10;
				num += i;
			}
			
			if ( num == origNum )
				break;
			
			result.add(num);
		}
		
		return result;
		
		
	}
	
	public static int digitsToNum(Integer[] digits) {
		
		int num = 0;
		
		for ( int i = 0; i < digits.length; i++ ) {
			num *= 10;
			num += digits[i];
		}
		
		return num;
	}
	
	static Comparator<Integer> comp = new Comparator<Integer>() {

		@Override
		public int compare(Integer arg0, Integer arg1) {

			if ( arg0 == 0 )
				return 1;
			else if ( arg1 == 0)
				return -1;
			else
				return arg0.compareTo(arg1);
			
		}
		
	};
	
	public static Integer[] getDigits(int n) {
		
		int numDigits = (int)Math.log10(n) + 1;
		
		Integer[] digits = new Integer[numDigits];
		
		for ( int i = 0; i < numDigits; i++ ) {
			
			digits[numDigits-1-i] = n % 10;
			n /= 10;
			
		}
		
		return digits;
		
	}
	
}

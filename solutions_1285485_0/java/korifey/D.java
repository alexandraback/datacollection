package gcj2012.qual;

import java.util.Arrays;
import java.util.HashSet;

import org.korifey.ffalg.NumberTheory;
import org.korifey.ffalg.Pair;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class D extends AbstractRunner {
			
	
	private Pair<Integer,Integer> norm(Pair<Integer, Integer> p) {
		if (p.A() == 0) return new Pair<Integer,Integer>(0, p.B()/ Math.abs(p.B()));
		if (p.B() == 0) return new Pair<Integer,Integer>(p.A()/ Math.abs(p.A()), 0);
		int gcd = (int)NumberTheory.gcd(Math.abs(p.A()), Math.abs(p.B()));
		return new Pair<Integer,Integer>(p.A()/gcd, p.B()/gcd);
	}
	
	private int dist2(int x0, int y0, int x, int y) {
		return (x0-x)*(x0-x) + (y0-y)*(y0-y);
	}
	
	@Override
	public void handleCase(int caseNumber) throws Exception {
		System.out.println("Case: "+caseNumber);
		int h = scanner.nextInt();
		int w = scanner.nextInt();
		int s = scanner.nextInt();
		
		scanner.nextLine();
		int x0 = 0, y0 = 0;
		for (int i=0; i<h; i++) {
			String ss = scanner.nextLine();
			int idx = ss.indexOf('X');
			if (idx >= 0) {
				y0 = 2*(i-1) + 1;
				x0 = 2 * (idx-1) + 1;  
			}
		}
		assert x0 != 0 && y0 !=0;
		
		h = (h - 2) * 2;
		w = (w - 2) * 2;
		s = s*2;
		
		int s2 = s*s;
		
		HashSet<Pair<Integer, Integer>> result = new HashSet<Pair<Integer, Integer>>(10000);
		
		for (int i=-52; i<= 52; i++) {
			for (int j= -52; j<=52; j++) {
				if (i!=0 || j!=0) {
					int x = i*w + ((i%2 ==0 ) ? x0 : w - x0); 
					int y = j*h + ((j%2 ==0 ) ? y0 : h - y0);
					if (dist2(x0, y0, x, y) <= s2) {
						result.add(norm(new Pair<Integer, Integer>(x-x0, y-y0)));
					}
				}
				
				{
					int x = i*w;
					int y = j*h;
					if (dist2(x0, y0, x, y)*4 <= s2) {
						result.add(norm(new Pair<Integer, Integer>(x-x0, y-y0)));
					}
				}
			}
		}
		
		out.write(Integer.toString(result.size()) +"\n");
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		new D().init(SIZE.small).execute();
	}

}

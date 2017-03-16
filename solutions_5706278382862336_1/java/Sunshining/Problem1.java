package round1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.CountDownLatch;

@SuppressWarnings("unused")
public class Problem1 implements Solution{
	long p;
	long q;
	@Override
	public String execute(BufferedReader in, PrintWriter log)
			throws IOException {
		// TODO Auto-generated method stub
		String line=in.readLine();
		String[] items=line.split("/");
		p = Long.parseLong(items[0]);
		q = Long.parseLong(items[1]);
		
		int result=process();
		if (result==-1) return " impossible";
		return " "+process();
	}
	
	int process() {
		int height=0;
		
		normalize();
		
		int[] shift=new int[1];
		if (!isPossible(shift)) return -1;
		
		long denominator = p<<shift[0];
		
		return highestBit(p, shift[0]);
	}
	
	void normalize() {
		while (true) {
			long cd = gcd(p, q);
			if (cd==1) break;
			p/=cd;
			q/=cd;
		}
	}
	
	long gcd(long p, long q) {		
		while (p<q) {
			long tmp = q%p;
			q = p;
			if (tmp==0) break;
			p = tmp;
		}
		return p;
	}

	boolean isPossible(int[] shift) {
		long result=2;
		for (int i=1;i<40;++i) {
			if (result==q) {
				shift[0]=i;
				return true;
			}
			result<<=1;
		}
		
		return false;
	}

	int highestBit(long p, int h) {
		int pos;
		
		for (pos=0;pos<40&&p>0;++pos) {
			p>>=1;
		}
		
		return h-(pos-1);
	}
}

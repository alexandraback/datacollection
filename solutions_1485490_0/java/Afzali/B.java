import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int A, B;
	long[][] a,b;	
	HashMap<Long, Long> ta = new HashMap<Long, Long>();
	HashMap<Long, Long> tb = new HashMap<Long, Long>();
	
	void read() {
		A = sc.nextInt();
		a = new long[A][2];
		B = sc.nextInt();
		b = new long[B][2];
		
		ta = new HashMap<Long, Long>();
		tb = new HashMap<Long, Long>();

		for (int i = 0; i < A; i++){
			long c = sc.nextLong();
			long t = sc.nextLong();
			a[i][0] = c;
			a[i][1] = t;
			
			if(ta.containsKey(t)){
				ta.put(t, ta.get(t)+c);
			}else{
				ta.put(t, c);
			}
		}

		for (int i = 0; i < B; i++){
			long c = sc.nextLong();
			long t = sc.nextLong();
			b[i][0] = c;
			b[i][1] = t;
			
			if(tb.containsKey(t)){
				tb.put(t, tb.get(t)+c);
			}else{
				tb.put(t, c);
			}
		}

		
	}
	
	void solve() {
		long r =0;
		int ai=0,bi=0;
		while(ai<A && bi<B){
			long Ta = a[ai][1];
			long Tb = b[bi][1];
			long ca = a[ai][0];
			long cb = b[bi][0];
			
			
			if(Ta == Tb){
				long rr = min(ca,cb);
				if(rr<0) System.out.print("sas");
				r+=rr;
				a[ai][0] -= rr;
				b[bi][0] -= rr;
				ta.put(Ta, ta.get(Ta)-rr);
				tb.put(Tb, tb.get(Tb)-rr);
				if(a[ai][0] == 0) ai++;
				if(b[bi][0] == 0) bi++;
			}else{
				long da = 0;
				int j=0;
				while(ai+j<A && (a[ai+j][1] != Tb)){
					da += min(a[ai+j][0], tb.containsKey(a[ai+j][1])? tb.get(a[ai+j][1]):0 );
					j++;
				}

				long db = 0;
				j=0;
				while(bi+j<B && (b[bi+j][1] != Ta)){
					db += min(b[bi+j][0], ta.containsKey(b[bi+j][1])? ta.get(b[bi+j][1]):0 );
					j++;
				}
				
				if(da<db){
					ta.put(Ta, ta.get(Ta)-ca);
					ai++;
				}else{
					tb.put(Tb, tb.get(Tb)-cb);
					bi++;					
				}
			}
		}
		System.out.print(r);
		System.out.printf("%n");
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : ("C-small-attempt3.in"))));
			System.setOut(new PrintStream(new FileOutputStream("C.out.txt")));
		} catch (Exception e) {
			e.printStackTrace();
		}
		new B().run();
	}
}

package round1c_14;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class A {
	
	//public static String theFile="-small.in";
	//public static String theFile="-small-attempt1.in";
	public static String theFile="-large.in";
	static long gcd(long m, long n){ // return greatest common divisor
		long tmp;
		while((tmp = m%n) != 0){
			m = n;
			n = tmp;
		}
		return n;
	}
	//input reader
	static class InputData {
		//declare vars
		long a,b;
		//parse input
		InputData(Scanner in) throws IOException {
			String s=in.next();
			String[] sp=s.split("/");
			a=Long.parseLong(sp[0]);
			b=Long.parseLong(sp[1]);
			long gcd = gcd(a,b);
			a /= gcd;
			b /= gcd;
		}

		String solve() {
			double nb = a*1.0/b;
			int generation = 1;
			while(nb<0.5) {
				nb*=2;
				generation++;
			}
			//System.out.println(generation+ " "+pow(2,generation));
			if(b% pow(2,generation) == 0) {
				b = (long)(b/ pow(2,generation));
				long gcd = gcd(a,b);
				a /= gcd;
				b /= gcd;
				if ((b & -b) == b)
					return Integer.toString(generation);
			}
			return "impossible";
		}
	}
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			return data.solve();
		}
		
	}
	
	public void run() {
		try {
			//System.out.println(System.getProperty("user.dir"));
			//File f= new File(pbLetter+theFile);
			//System.out.println(f.getAbsolutePath()+","+f.exists());
			
			Scanner sc = new Scanner( new BufferedReader(new FileReader(pbLetter+theFile)));
			out = new TeePrintStream(System.out,Folder+"/"+pbLetter + "-output.txt");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = sc.nextInt();
			@SuppressWarnings("unchecked")
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(sc)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				//System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
				out.println();
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Method m;
		try {
			m = currentClass.getMethod("run");
			m.invoke(currentClass.newInstance(),(Object[])null);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	static String pbLetter;
	static PrintStream out;
	static String Folder;
	
	static Class<?> currentClass;
	static {
		currentClass = new Object() { }.getClass().getEnclosingClass();
		pbLetter=currentClass.getName();
		Folder = currentClass.getPackage().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}
	static class TeePrintStream extends PrintStream {
		protected PrintStream parent;

		public TeePrintStream(PrintStream orig, OutputStream os, boolean flush)
				throws IOException {
			super(os, flush);
			parent = orig;
		}
		public TeePrintStream(PrintStream orig, String fn)
				throws IOException {
			this(orig, new FileOutputStream(fn), true);
		}

		public boolean checkError() {
			return parent.checkError() || super.checkError();
		}
		public void write(int x) {
			parent.write(x);
			super.write(x); 
		}

		/** override write(). This is the actual "tee" operation. */
		public void write(byte[] x, int o, int l) {
			parent.write(x, o, l); 
			super.write(x, o, l);
		}

		/** Close both streams. */
		public void close() {
			parent.close();
			super.close();
		}
		/** Flush both streams. */
		public void flush() {
			parent.flush();
			super.flush();
		}
	}
}

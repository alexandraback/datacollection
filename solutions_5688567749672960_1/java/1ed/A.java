package round1B_15;


import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

import javax.swing.DebugGraphics;

public class A {
	static int[] res = new int[1000001];
	
	static long theRes(long in) {
		if(in <=20 ) return in;
		int res=0;
		do	{
			long next = findNext(in);
			res += 1+in-next;
			in = swap(next);
		} while (in >20);
		return res+in;
	}
	static long findNext(long in) {
		if(in <=20) return in;
		String dec = Long.toString(in);
		byte[] b= dec.getBytes();
		for(int i=dec.length()/2 ;i <dec.length() -1; ++i) b[i]= '0';
		b[dec.length()-1] = '1';
		long res = Long.parseLong(new String(b));
		if(res>in) return findNext(in-1);
		if(swap(res) == res) return findNext(res-2);
		else return res;
	}
	static long swap(long in) {
		String dec = Long.toString(in);
		if(dec.charAt(dec.length()-1) == '0') return in;
		char[] rev = new char[dec.length()];
		int idx=0;
		for(int i=dec.length()-1; i>=0;--i) {
			rev[idx++]=dec.charAt(i);
		}
		//System.out.println(in+ " "+Integer.parseInt(new String(rev)));
		return Long.parseLong(new String(rev));
	}
	/*
	static{
		res[1]=1;
		int i=1;
		while( ++i < res.length) {
			int swap = swap(i);
			if(swap<i) res[i] = Math.min(res[i-1]+1, res[swap(i)]+1);
			else res[i] = res[i-1] +1;
			//if(res[i] != (1+res[i-1]))
				//System.out.println(i+" "+res[i]+" "+theRes(i)+" "+findNext(i));
			if(res[i] != theRes(i)) System.err.println(i+" "+res[i]+" "+theRes(i));
		}
	}
	*/
	
	//public static String theFile="-small.in";
	//public static String theFile="-small-attempt1.in";
	public static String theFile="-large.in";
	
	//input reader
	static class InputData {
		//declare vars
		long N;
		
		
		//parse input
		InputData(Scanner in) throws IOException {
			N = in.nextLong();
		}

		String solve() {
			return ""+theRes(N);
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
	
	static void debug(Object...os) {
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
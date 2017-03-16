package Qualif14;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;


public class D {
	// get Pb Letter for input/output file names.
	public static String pbLetter;
	static {
		pbLetter=new Object() { }.getClass().getEnclosingClass().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}

	public static void main(String[] args) throws Throwable {
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-small.in"));
		//System.out.println(System.getProperty("user.dir"));
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-small-attempt1.in"));

		Scanner sc = new Scanner(new File("./"+pbLetter+"-large.in"));

		TeePrintStream out= new TeePrintStream(System.out, "./output-"+pbLetter+".txt");

		int testCount = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCount; i++) {
			out.format("Case #%d: ",i );
			solve(sc, out);
		}
		out.close();
	}

	static void solve(Scanner sc, PrintStream out) {
		int  n=sc.nextInt();
		int count0=n,count1=n;
		Float[] me = new Float[n],him0 = new Float[n];
		for (int i = 0; i < n; i++) me[i]= sc.nextFloat();
		for (int i = 0; i < n; i++) him0[i]= sc.nextFloat();
		
		Arrays.sort(me);
		Arrays.sort(him0);
		LinkedList<Float> him = new LinkedList( Arrays.asList(him0));
		int found;
		for (Float f:me) {
			found =Collections.binarySearch(him, f);
			if(-found == him.size()+1) {
				break; 
				
			} else {
				him.remove(-found-1);
				count0--;
			}
		}

		int himidx=0;
		for(int i=0; i<n ;++i) {
			if(me[i] < him0[himidx]) {
				--count1;
			} else { himidx++;}
		}
		
		out.format("%d %d\n", count1,count0);
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
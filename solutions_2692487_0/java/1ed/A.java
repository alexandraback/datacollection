package round1b_13;


import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class A {
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
		Scanner sc = new Scanner(new File("./"+pbLetter+"-small-attempt0.in"));
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-large.in"));
		
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
		int A=sc.nextInt();
		int N = sc.nextInt();
		int[] motes = new int[N];
		sc.nextLine();
		for (int i = 0; i < motes.length; i++) {
			motes[i] = sc.nextInt();
		}
		sc.nextLine();
		int count=N;
		if(A==1) {
			out.println( N);
			return;
		}
		Arrays.sort(motes);
		int idx=0;
		while(idx <N && motes[idx] <A) {
			A+= motes[idx++];
			count--;
		}
		if(idx == N) {
			out.println(0);
			return;
		}
		int res=count;
		//System.out.println(res);
		for(int i = 0; i< count;++i) {
			A=2*A-1;
			while(idx <N && motes[idx] <A) {
				A+= motes[idx++];
			}
			res = Math.min(res, i+1+N-idx);
		}
		out.println(res);
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

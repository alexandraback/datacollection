import java.io.*;

public class B {
    int D;
    int[] cake;
    int[] cakeNew;
    int[] div;
    int time;
    int max;
    int Max;
    int maxNew;
    int timeNew;
    public B(In in) {
	D = in.readInt();
	cake = new int[D];
	cakeNew = new int[D];
	div = new int[D];
	for(int i=0;i<D;i++) {
	    cake[i] = in.readInt();
	    cakeNew[i] = cake[i];
	    div[i] = 1;
	}
	time = 0;
	Max = cake[findMaxIndex()];
	max = Max;
    }
    
    public void print() {
	for(int i=0;i<D;i++) {
	    System.out.println(cake[i]);
	}
    }
    
    public int findMaxIndex() {
	int tempI = 0;
	int tempM = cake[0];
	for (int i=1;i<D;i++) {
	    if(tempM<cake[i]) {
		tempM = cake[i];
		tempI = i;
	    }
	}
	return tempI;
    }
	
    public void operate() {
	for(int p=1;p<Max;p++) {
	    timeNew = 0;
	    maxNew = p;
	    for(int i=0;i<D;i++) {
		timeNew += (cake[i]-1)/p;
	    }
	    if(timeNew+maxNew<time+max) {
		time = timeNew;
		max = maxNew;
	    }
	}
    }
    public static void main(String[] args) throws IOException {
	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));

	int T = in.readInt();
	B solution;
	for(int t=1;t<=T;t++) {
	    solution = new B(in);
	    solution.operate();
	    pw.println("Case #" + t + ": " + (solution.max + solution.time));
	}
	pw.close();
    }
}

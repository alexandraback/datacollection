import java.io.*;

public class D {

    int X;
    int R;
    int C;
    int Max;
    int Min;
    public D(In in) {
	X = in.readInt();
	R = in.readInt();
	C = in.readInt();
	Max = (R>C) ? R:C;
	Min = (R<C) ? R:C;
    }
    public boolean RichardWin() {

	if(R*C%X!=0) {
	    return true;
	}
	else if(X>Max) {
	    return true;
	}
	else if(X>2*Min) {
	    return true;
	}
	else if(X==2*Min && X!=2 ) {
	    return true;
	}
	else {
	    return false;
	}
    }

    public static void main(String[] args) throws IOException {
	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	D solution;
	int T = in.readInt();
	for(int t=1;t<=T;t++) {
	    solution = new D(in);
	    if(solution.RichardWin()) {
		pw.println("Case #" + t + ": " + "RICHARD");
	    }
	    else {
		pw.println("Case #" + t + ": " + "GABRIEL");
	    }
	}
	pw.close();
    }
    
    
}

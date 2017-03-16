import java.io.*;
import java.lang.Math;
import java.util.ArrayList;
public class C {

    int L;
    int X;
    int N;
    int[] table = {1,2,3,4,1,-1,4,-3,3,-4,-1,2,4,3,-2,-1};
    String dijk;
    int[] dijkN;
    int state;
    
    public C(In in) {
	L = in.readInt();
	X = in.readInt();
	N = L*X;
	dijkN = new int[L*X];
	dijk = in.readString();
	state = 0;
    }

    public int f(int i,int j) {
	return i*j/Math.abs(i*j)*table[Math.abs(i)*4 + Math.abs(j) -5];
    }
    public void convert() {
	for(int x=0;x<X;x++) {
	    for(int l=0;l<L;l++) {
		dijkN[x*L+l] = (int)(dijk.charAt(l) - 'g');
		//System.out.println("Con " + (x*L+l) + " " + dijkN[x*L+l]);
	    }
	}
    }
    public void multiply() {
	for(int n=0;n<N-1;n++) {
	    dijkN[n+1] = f(dijkN[n],dijkN[n+1]);
	    //System.out.println(n+1 + " " +dijkN[n+1]);
	}
    }
    public void operate() {
	for(int n=0;n<N;n++) {
	    if(state==0 && dijkN[n]==2) {
		state = 1;
	    }
	    else if(state==1 && dijkN[n]==4) {
		state = 2;
	    }
	    else if(n==N-1 && state==2 && dijkN[n]==-1) {
		state = 3;
	    }
	}
    }
    public static void main(String[] args) throws IOException {
	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	int T = in.readInt();
	C solution;
	for(int t=1;t<=T;t++) {
	    solution = new C(in);
	    solution.convert();
	    solution.multiply();
	    solution.operate();
	    if(solution.state==3) {
		pw.println("Case #" + t + ": " + "YES");
	    }
	    else {
		pw.println("Case #" + t + ": " + "NO");
	    }
	}
	pw.close();
	
    }
    
}

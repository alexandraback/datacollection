import java.io.*;

public class A {

    int max;
    int N;
    String str;
    char[] numchar;
    int[] num;
    int Nf;
    int sum;
    public A(In in) {
	max = in.readInt();
	str = in.readString();
	N = str.length();
	numchar = new char[N];
	num = new int[N];
	for(int i=0;i<N;i++) {
	    numchar[i] = str.charAt(i);
	    num[i] = (int)(numchar[i] - '0');
	}
	Nf = 0;
	sum = 0;
    }
    public void operate() {
	for(int i=0;i<N;i++) {
	    if(num[i]!=0) {
		if(sum<i) {
		    Nf += (i-sum);
		    sum = i;
		}
		sum += num[i];
	    }
	}
    }
    
    public void printChar() {
	for(int i=0;i<N;i++) {
	    System.out.println(numchar[i]);
	}
    }
    public void printInt() {
	for(int i=0;i<N;i++) {
	    System.out.println(num[i]);
	}
    }
    public static void main(String[] args) throws IOException {

	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	int T = in.readInt();

	A solution;
	for(int t=1;t<=T;t++) {
	    solution = new A(in);
	    solution.operate();
	    pw.println("Case #" + t + ": " +solution.Nf);
	}
	pw.close();
    }
}

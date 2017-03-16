import java.io.*;
import java.lang.Math;

public class A {

    public long Answer;
    public long N;
    public long N2half;
    public long N1half;
    public long N1halfi;
    public int Ndigit;
    public long[] L9;
    public long[] M9;
    public int K = 14;
    public A(In in) {

	N = in.readLong();
	M9 = new long[K];
	L9 = new long[K];
	
	M9[0] = 9;
	L9[0] = 9;
	for(int i=1;i<K;i++) {
	    L9[i] = 10*L9[i-1] + 9;
	    M9[i] = M9[i-1] + 1 + L9[(i-1)/2] + L9[i/2] ;
	    System.out.println(L9[i] + ": " + M9[i]);
	}
    }

    public void calculate(PrintWriter pw) {
	long temp;

	Ndigit = 1;
	temp = N;
	while(temp/10>0) {
	    temp = temp/10;
	    Ndigit += 1;
	}
	N1halfi = 0;
	N1half = N/((long)Math.pow(10,(Ndigit+1)/2));
	N2half = N%((long)Math.pow(10,(Ndigit+1)/2));
    
	Answer = 0;
	if(N1half==1||N1half==10||N1half==100||N1half==1000||N1half==10000||N1half==100000
	   ||N1half==1000000||N1half==10000000) {
	    Answer = Answer-1;
	}
	else {
	    Answer = Answer;;
	}
	if(N2half!=0) {
	    while(N1half>0) {
		N1halfi = N1halfi*10 + N1half%10;
		N1half = N1half/10;
	    }
	    System.out.println(N1halfi);
	    if(N<=9)
		Answer = N;
	    else {
		Answer = Answer + M9[Ndigit-2] + 1 + N1halfi + N2half;
	    }
	    pw.println(Answer);
	}
	else{
	    N = N-1;
	    Ndigit = 1;
	    temp = N;
	    while(temp/10>0) {
		temp = temp/10;
		Ndigit += 1;
	    }
	    N1halfi = 0;
	    N1half = N/((long)Math.pow(10,(Ndigit+1)/2));
	    N2half = N%((long)Math.pow(10,(Ndigit+1)/2));
	    
	    Answer = 0;
	    if(N1half==1||N1half==10||N1half==100||N1half==1000||N1half==10000||N1half==100000
	       ||N1half==1000000||N1half==10000000) {
		Answer = Answer-1;
	    }
	    else {
		Answer = Answer;;
	    }
	      while(N1half>0) {
		N1halfi = N1halfi*10 + N1half%10;
		N1half = N1half/10;
	    }
	    System.out.println(N1halfi);
	    if(N<=9)
		Answer = N;
	    else {
		Answer = Answer + M9[Ndigit-2] + 1 + N1halfi + N2half;
	    }
	    pw.println(Answer+1);

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
	    pw.print("Case #" + t + ": ");
	    solution.calculate(pw);
	}
	pw.close();
    }
}

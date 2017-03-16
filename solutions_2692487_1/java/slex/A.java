import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class A {

	Scanner scan;
	InputStream in;
	PrintStream out;
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	int add(long x, int[] A, int n){
		int res =0;
		for(int i=0;i<n;i++){
			while(x<=A[i]){
				if(x==1)return 100000000;
				res++;
				x+=x-1;
			}
			x+=A[i];
		}
		return res;
	}
	
	long solve(){
		long res=100000000;
		long x = scan.nextLong();
		int n = scan.nextInt();
		int[]A = new int[n];
		for(int i=0;i<n;i++)A[i]=scan.nextInt();
		sort(A);
		for(int i=0;i<=n;i++){
			int r = add(x, A, i)+ n-i;
			res = min(res,r);
		}
		return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	A() throws Exception{
		String cn = A.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		String name = largeName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		scan = new Scanner(in);
		out = System.out;
		out = new PrintStream(new File(outName));
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new A().solveAll();
	}

}

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class A {

	Scanner scan;
	InputStream in;
	int[]s;
	int sum;
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	boolean trys(int p, double x){
		double add=0;
		for(int i=0;i<s.length;i++){
			if(i==p)continue;
			if(s[i]<s[p]+x){
				add+=s[p]+x-s[i];
			}
		}
		if(add+x>sum)return true;
		return false;
	}
	
	String solve(){
		
		int n = scan.nextInt();
		s = new int[n];
		sum=0;
		for(int i=0;i<n;i++){
			s[i]=scan.nextInt();
			sum+=s[i];
		}
		double[]res = new double[n];
		for(int i=0;i<n;i++){
			double a = 0,b=1;
			for(int k=0;k<100;k++){
				double c = (a+b)/2;
				if(trys(i,c*sum)) b=c;
				else a = c;
			}
			res[i]=a*100;
		}
		String R = "";
		double ss = 0;
		for(int i=0;i<n;i++){
			R+=res[i];
			if(i+1<n)R+=" ";
			ss+=res[i];
		}
	    return R;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			String r =solve();
			System.out.format("Case #%d: %s\n",i+1,r);
		}
	}
	
	A() throws Exception{
		String cn = A.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt1.in";
		String largeName = cn+"-large.in";
		InputStream in = new BufferedInputStream(new FileInputStream(largeName));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new A().solveAll();
	}

}

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class C {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	String set(int[]s, int m){
		String res = "";
		for(int i=0;i<s.length;i++){
			if ((m&(1<<i))==0)continue;
			res+=s[i]+" ";
		}
		return res.substring(0,res.length()-1);
	}
	
	String solve(){
		
		int n = scan.nextInt();
		int[]s = new int[n];
		for(int i=0;i<n;i++)s[i]=scan.nextInt();
		HashMap<Integer,Integer>T =new HashMap<Integer, Integer>(); 

	    for(int m=1;m<(1<<n);m++) {
	    	int sum=0;
	    	for(int i=0;i<s.length;i++){
				if ((m&(1<<i))==0)continue;
				sum+=s[i];
	    	}
	    	if(T.containsKey(sum)){
	    		String res = "\n"+set(s,T.get(sum))+"\n"+set(s,m);
	    		return res;
	    	}
	    	T.put(sum, m);
	    }
	    return "\nImpossible";
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			String r =solve();
			System.out.format("Case #%d: %s\n",i+1,r);
		}
	}
	
	C() throws Exception{
		String cn = C.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		InputStream in = new BufferedInputStream(new FileInputStream(smallName));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new C().solveAll();
	}

}

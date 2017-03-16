import java.io.*;
import static java.lang.Math.*;
import java.util.*;
public class A {
    char[] con = new char[]{'a','e','i','o','u'};
    String solve(String L,int n){
	int cnt=0;
	int[] l=new int[L.length()];
	Arrays.fill(l,1);
	for(int i=0;i<L.length();i++)
	    for(int j=0;j<con.length;j++) 
		if(L.charAt(i)==con[j]) {l[i]=0; break;}
	
	
	for(int i=0;i<l.length;i++)
	    for(int j=i+1;j<=l.length;j++)
		if(check(Arrays.copyOfRange(l,i,j),n)) cnt++;
	return cnt+"";
    }
    public boolean check(int[] l,int n){
	int cnt=0;
	for(int i=0;i<l.length;i++){
	    if(l[i]==0) cnt=0; else cnt+=1;
	    if(cnt>=n) return true;
	}
	return false;
    }
    public void run(String[] args) {
	try{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int T = Integer.parseInt(br.readLine());
	    for(int t=1;t<=T;t++){
		String[] line = br.readLine().split(" ");
		int n=Integer.parseInt(line[1]);
		System.out.printf("Case #%d: %s\n",t,solve(line[0],n));
	    }
	    
	}catch(Exception e){ e.printStackTrace(); }
    }
    public static void main(String[] args){
	Locale.setDefault(Locale.US);
	(new A()).run(args);
    }
}

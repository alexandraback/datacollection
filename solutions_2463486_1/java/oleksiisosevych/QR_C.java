import java.io.*;
import java.math.BigInteger;
import java.security.Policy;
import java.util.*;
public class QR_C {
    	
    	public static boolean polindrome(String a){
    	    for (int i = 0; i < a.length()/2; i++) {
		if(a.charAt(i)!=a.charAt(a.length()-1-i))
		    return false;
	    }
    	    return true;
    	}
//    	public static String next_polindrome(String courrent){
    	    
//    	}
	public static void main (String [] args) throws IOException {
	    // Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("C-large-1.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());
	    
	    int testn = Integer.parseInt(st.nextToken());    
	    int count=0;
	    BigInteger[] reach_and_beauty = new BigInteger[1000];
		BigInteger i = new BigInteger("1");
		String temp = "";
		for (int j = 0; j < 7; j++) {
		    temp+="9";
		}
		BigInteger one = new BigInteger("1");
		BigInteger max = new BigInteger(temp);
		for (; i.compareTo(max)==-1; i=i.add(one)) {
		    if(polindrome(i.toString())&&polindrome(i.pow(2).toString()+"")){
			System.out.println(i.toString() + " - "+ i.pow(2).toString());
		    reach_and_beauty[count++]=i.pow(2);}
		}
	    int caseno=1;
	    while(testn-->0) {
		int result=0;
		st = new StringTokenizer(f.readLine());
		BigInteger A = new BigInteger(st.nextToken());
		BigInteger B = new BigInteger(st.nextToken());
		for (int j = 0; j < count; j++) {
		    if(reach_and_beauty[j].compareTo(A)!=-1&&reach_and_beauty[j].compareTo(B)!=1)
			result++;
		}
	    	System.out.println(result);
	    	
	    out.println("Case #"+caseno+++": "+result);
	    }  
	    out.close();                                  
	    System.exit(0);                              
	  }
}
import java.io.*;
import java.util.*;
import java.math.*;
public class FairAndSquare {
	public static Scanner scan = null;
	public static PrintWriter out = null;
	public static boolean bug = false;
	static{
		try {
			scan = new Scanner(new FileReader("input3.txt"));
			out = new PrintWriter(new File("output3.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args){
		BigInteger ptr = new BigInteger(1+"");
		List<BigInteger> l1 = new ArrayList<>();
		for (;;){
			//System.out.println(i*i);
			//System.out.println(i+" "+i*i+" "+(isP(i)&&isP(i*i)));
			BigInteger temp = ptr;
			if (temp.multiply(temp).compareTo(new BigInteger(""+100000000000000l))>0 ){
				break;
			}
			if (isP(temp)&&isP(temp.multiply(temp))){
				System.out.println(temp+"     "+temp.multiply(temp));
				l1.add(temp.multiply(temp));
			}
			ptr=ptr.add(BigInteger.ONE);
		}
		int n1 = Integer.parseInt(scan.next());
		int count = 0;
		while (true){
			BigInteger a = new BigInteger(scan.next());
			BigInteger b = new BigInteger(scan.next());
			long total = 0;
			BigInteger i = a;
			/*
			while (true){
				BigInteger k1 = sqrt(i);
				if (i.compareTo(k1.multiply(k1))==0){
					if(isP(k1)&&isP(i)){
						if (bug) System.out.println(i);
						total++;
					}
				}
				
				i=i.add(BigInteger.ONE);
				if (i.compareTo(b)>0){
					break;
				}
			}
			*/
			for (BigInteger e: l1){
				if (e.compareTo(a)>=0
						&&e.compareTo(b)<=0){
					total++;
				}
			}
			out.println("Case #"+(count+1)+": "+total);
			out.flush();
			count++;
			if (n1-count<=0){
				break;
			}
		}
	}
	public static boolean isP(int n1){
		String k1 = ""+n1;
		for (int i=0;i<k1.length()/2;i++){
			if (k1.charAt(i)!=k1.charAt(k1.length()-i-1)){
				return false;
			}
		}
		if (k1.length()%2==0){
			
		}
		else {
			
		}
		return true;
	}
	public static boolean isP(BigInteger n1){
		String k1 = ""+n1.toString();
		//System.out.println("rep "+k1);
		for (int i=0;i<k1.length()/2;i++){
			if (k1.charAt(i)!=k1.charAt(k1.length()-i-1)){
				return false;
			}
		}
		if (k1.length()%2==0){
			
		}
		else {
			
		}
		return true;
	}
	  public static BigInteger sqrt(BigInteger n) {
		    BigInteger a = BigInteger.ONE;
		    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		    while(b.compareTo(a) >= 0) {
		      BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		      else a = mid.add(BigInteger.ONE);
		    }
		    return a.subtract(BigInteger.ONE);
		  }
}

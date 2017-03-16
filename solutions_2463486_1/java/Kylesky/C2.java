import java.util.*;
import java.math.*;

public class C2{
	static ArrayList<BigInteger> FnS = new ArrayList<BigInteger>();
	public static void main(String[] args){
		BigInteger LIMIT = BigInteger.TEN;
		LIMIT = LIMIT.pow(15);
		int maxlen = LIMIT.toString().length()/4;
		FnS.add(new BigInteger("1"));
		FnS.add(new BigInteger("4"));
		FnS.add(new BigInteger("9"));
		int num = 1;
		while(true){
			StringBuilder sb = new StringBuilder(Integer.toBinaryString(num));
			if(sb.length() > maxlen) break;
			String s1 = sb.toString();
			String s2 = sb.reverse().toString();
			BigInteger n = new BigInteger(s1+s2);
			n = n.pow(2);
			sb = new StringBuilder(n.toString());
			String s3 = sb.toString();
			String s4 = sb.reverse().toString();
			if(s3.equals(s4)){
				FnS.add(n);
			}
			for(int i=0; i<=2; i++){
				n = new BigInteger(s1+i+s2);
				n = n.pow(2);
				sb = new StringBuilder(n.toString());
				s3 = sb.toString();
				s4 = sb.reverse().toString();
				if(s3.equals(s4)){
					FnS.add(n);
				}
			}
			num++;
		}
		StringBuilder s1 = new StringBuilder("2");
		for(int i=0; i<maxlen; i++){
			StringBuilder sb = new StringBuilder(s1.toString());
			String s2 = sb.reverse().toString();
			BigInteger n = new BigInteger(s1.toString()+s2);
			n = n.pow(2);
			sb = new StringBuilder(n.toString());
			String s3 = sb.toString();
			String s4 = sb.reverse().toString();
			if(s3.equals(s4)){
				FnS.add(n);
			}
			for(int j=0; j<=1; j++){
				n = new BigInteger(s1.toString()+j+s2);
				n = n.pow(2);
				sb = new StringBuilder(n.toString());
				s3 = sb.toString();
				s4 = sb.reverse().toString();
				if(s3.equals(s4)){
					FnS.add(n);
				}
			}
			s1.append("0");
		}
		
		Collections.sort(FnS);
		
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for(int z=1; z<=cases; z++){
			BigInteger a = new BigInteger(sc.next());
			BigInteger b = new BigInteger(sc.next());
			
			int ai = binSearch(a);
			int bi = binSearch(b);
			if(b.compareTo(FnS.get(bi)) == 0) bi++;
			System.out.println("Case #"+z+": "+(bi-ai));
		}
	}
	
	public static int binSearch(BigInteger n){
		int s = 0;
		int e = FnS.size()-1;
		if(n.compareTo(FnS.get(s)) == 0) return s;
		if(n.compareTo(FnS.get(e)) == 0) return e;
		while(true){
			int m = (s+e)/2;
			if(m == s){
				if( n.compareTo(FnS.get(s)) > 0 && n.compareTo(FnS.get(e)) < 0 ){
					return e;
				}
			}
			int comp = n.compareTo(FnS.get(m));
			if( comp == 0 ) return m;
			if( comp < 0 ) e = m;
			if( comp > 0 ) s = m;
		}
	}
}
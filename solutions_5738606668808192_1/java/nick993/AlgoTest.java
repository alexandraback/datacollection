package v0;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class AlgoTest {
	
	public static BigInteger getDecValue(BigInteger n) {
		BigInteger res=new BigInteger("0");
		BigInteger zero=new BigInteger("0");
		BigInteger base2=new BigInteger("2");
		int cnt=0;
		BigInteger base10=new BigInteger("10");
		while(n.compareTo(zero)>0) {
			//System.out.println(n.mod(base10) + " : "+n.divide(base10));
			res=res.add((base10.pow(cnt++)).multiply((n.mod(base2))));
			n=n.divide(base2);
			//System.out.println(n.toString()+" : "+res);
		}
		return res;
	}
	
	
	public static BigInteger getBase(BigInteger num,BigInteger base) {
		BigInteger res=new BigInteger("0");
		BigInteger zero=new BigInteger("0");
		BigInteger base10=new BigInteger("10");
		int cnt=0;
		while(num.compareTo(zero)>0) {
			res=res.add((base.pow(cnt++)).multiply(num.mod(base10)));
			num=num.divide(base10);
		}
		return res;
	}
	
	public static BigInteger isComposite(BigInteger n) {
		BigInteger zero=new BigInteger("0");
		BigInteger base2=new BigInteger("2");
		if((n.mod(base2)).equals(zero))
			return base2;
		for(int i=3;i<=100;i+=2) {
			BigInteger base=new BigInteger(""+i);
			if(n.mod(base).equals(zero)){
				return base;
			}
		}
		return zero;
	}
	
	
	public static void main(String[] args) {
		long startVal=(1L<<31)+1;
		long endVal=1L<<32;
		int cnt=0;
		System.out.println("Case #1:");
		BigInteger zero=new BigInteger("0");
		for(long s=startVal;s<endVal;s+=2){
			boolean nosol=false;
			if(cnt==500)
				break;
			//System.out.println(s+"");
			List<BigInteger> myList=new ArrayList<>();
			BigInteger currVal=getDecValue(new BigInteger(""+s));
			for(int i=2;i<=10;i++) {
				//System.out.println(i+" : "+getBase(currVal, new BigInteger(""+i)));
				BigInteger tmpVal=getBase(currVal, new BigInteger(""+i));
				BigInteger tmpVal2=isComposite(tmpVal);
				if(tmpVal2.equals(zero)){
					nosol=true;
					break;
				}
				myList.add(tmpVal2);
				
			}
			if(nosol) {
				continue;
			}
			cnt++;
			System.out.print(currVal+" ");
			for(int i=0;i<myList.size();i++) System.out.print(myList.get(i)+" ");
			System.out.println();
			//System.out.println(getDecValue(new BigInteger(""+s)));
		}
	}
}

import java.io.File;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Bullseye {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(new File("Inputs/Bulleseye.in"));
		int testCasesNo=s.nextInt();
		BigInteger r=null;
		BigInteger t=null;
		BigInteger d=new BigInteger("4");
		BigInteger a0=null;
		BigInteger temp=null;
		BigInteger a=new BigInteger("4");
		BigInteger b=null;
		BigInteger c=null;
		BigInteger negOne=new BigInteger("-1");
		BigInteger ringsNo=null;
		
		for(int i=0;i<testCasesNo;i++){
			r=new BigInteger(s.next());
			t=new BigInteger(s.next());
			
			a0=getFirstTerm(r);
			
			temp=BigInteger.ONE;
			
			temp=temp.add(temp);
			
			temp=temp.multiply(a0);//2a
			
			temp=temp.subtract(d);//2a -4
			
			b=temp;
			
			temp=BigInteger.ONE;
			
			temp=temp.add(temp).multiply(t).multiply(negOne);
			
			c=temp;
			
			ringsNo=getPositiveRoot(a,b,c);
			System.out.println("Case #"+(i+1)+": "+ringsNo);
			
		}//test cases
		

	}
	public static BigInteger getFirstTerm(BigInteger r){
		BigInteger ret=null;
		
		BigInteger R = r.add(BigInteger.ONE);
		
		ret = R.multiply(R).subtract(r.multiply(r));
		
		return ret;
	}
	static public BigInteger getPositiveRoot(BigInteger a,BigInteger b,BigInteger c ){
		BigInteger fourac=a.multiply(c).multiply(new BigInteger("4"));
		BigInteger sqb=b.multiply(b);
		
		
        //Finding out the roots
		BigInteger temp1 = sqrt(sqb.subtract(fourac));
 
		BigInteger root1 = (b.multiply(new BigInteger("-1")).add(temp1).divide((a.multiply(new BigInteger("2"))))) ;
		BigInteger root2 = (b.multiply(new BigInteger("-1")).subtract(temp1).divide((a.multiply(new BigInteger("2"))))) ;
        
 
        if(root1.max(root2).equals(root1)){
        	return root1;
        }else{
        	return root2;
        }
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

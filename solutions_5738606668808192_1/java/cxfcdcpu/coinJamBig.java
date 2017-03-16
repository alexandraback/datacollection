import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class coinJamBig{
	
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
	
    for (int i = 1; i <= t; ++i) {
      int n = in.nextInt();
	  int j = in.nextInt();
	  boolean isPrime=false;
	  int c=0;
	  String starting="1";
	  for(int k=1;k<n-1;k++){
		  starting+="0";
	  }
	  starting+="1";
	  BigInteger startInt=new BigInteger(starting,2);
	  BigInteger[] div=new BigInteger[9];
	  System.out.println("Case #" + i + ": ");
	  while(c<j){
		//System.out.println("Current working on: "+starting);
		isPrime=false;
		for(int l=2;l<=10;l++){
			
			if(!isPrime){
				BigInteger current=new BigInteger(starting,l);
				div[l-2]=checkPrime(current);
				if(div[l-2].compareTo(new BigInteger("0"))==0)isPrime=true;
				//System.out.println("mmmm");
			}
		}
		//System.out.println("nnn"); 
		if(!isPrime){
			c++;
			System.out.print(starting);
			for(BigInteger d:div){
				System.out.print(" "+d.toString());
				
			}
			System.out.println("");
		}  
		 
		
		startInt=startInt.add(new BigInteger("2"));
		starting=startInt.toString(2);
		
	  }
	 
	  
	}
	
	
  }
  
  
  
  public static BigInteger checkPrime(BigInteger current){
	  BigInteger i=new BigInteger("2");
	  boolean bk=true;
	  BigInteger constant=new BigInteger("1");
	  int p=0;
	  while(bk&&p<3000){
		  //System.out.println(i.toString());
		  p++;
			if((i.multiply(i)).compareTo(current)>1)bk=false;
		  if(current.mod(i).compareTo(new BigInteger("0"))==0)return i;
		  i=i.add(constant);
	  }
	  return new BigInteger("0");
  }
  
}
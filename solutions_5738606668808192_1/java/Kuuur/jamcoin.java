package jamcoin;

import java.util.*;
import java.io.*;
import java.math.*;
public class jamcoin {
  public static void main(String[] args) throws IOException{
	  //FileReader inFileReader = new FileReader("Binary.txt");
      //Scanner inFile = new Scanner(inFileReader);
	  Scanner in = new Scanner(System.in);
      //PrintWriter outFile = new PrintWriter(new FileWriter("Check.txt"));
      int t = 1;
      
      for (int i = 1; i <= t; ++i) {
    	 int N= 32;
    	 int J= 500;
    	 System.out.println("Case #"+ t + ":");
    	 int[] digits = new int[N];
    	 digits[0]=1;
    	 digits[N-1]=1;
    	 int j = 0;
    	 int count= 0;
    	 BigInteger[] largest= new BigInteger[9];
    	 BigInteger Base= new BigInteger("1");
    	 for(int K= 0;K<9;K++){
    		 largest[K]=new BigInteger("1");
    		 Base= Base.add(BigInteger.ONE);
    		 for(int n=1; n<32;n++){
    			largest[K]=largest[K].multiply(Base);
    		 }
    	 }
    	 BigInteger bi; 
		 int diff[][]=new int[9][18];
		 for(int K= 0;K<9;K++){
    		 for(int n=0; n<18;n++){
    			 bi = BigInteger.valueOf(n+2);
    			diff[K][n]=(largest[K].remainder(bi)).intValue();
    		 }
    	 }
    	 while(j<J)
    	 {
    		 int c= count;
    		 for(int k=1;k<N-1;k++){
    			 digits[N-1-k]=c%2;
    			 c=c/2;
    		 }
    		 int primes[]=new int[9];
    		 for(int K=0;K<9;K++){
    			 //k is base
    			 int k= K+2;
    			 primes[K]=0;
    			 long numberInBase=0;
    			 long expTracker= 1;
    			 for(int l=1;l<=16;l++){
    				 //l is position in number
    				 numberInBase= numberInBase+ expTracker*digits[N-l];
    				 expTracker=expTracker*k;
    			 }
    			 for(int l = 2; l<20; l++){
    				 
    				 if(numberInBase%l+diff[K][l-2]==l){
    					 primes[K]=l;
    					 l=20;
    				 }
    			 }
    			 if(primes[K]==0)
    			 {
    				 K=9;
    			 }
    		 }
    		 boolean jamcoin= true;
    		 for(int K=0;K<9;K++){
    			 if(primes[K]==0){
    				 jamcoin=false;
    			 }
    		 }
    		 if(jamcoin){
    			 for(int l=0;l<N;l++){
    				 System.out.print(digits[l]);
    			 }
    			 for(int k=0;k<9;k++){
    				 System.out.print(" " + primes[k]);
    			 }
    			 System.out.println();
    			 j++;
    		 }
    		 count++;
    		 
    	 }
    	 
    	 //System.out.println(j);
    }
      
   
  }
}
package jamcoin;

import java.util.*;
import java.io.*;
public class jamcoin {
  public static void main(String[] args) throws IOException{
	  //FileReader inFileReader = new FileReader("Binary.txt");
      //Scanner inFile = new Scanner(inFileReader);
	  Scanner in = new Scanner(System.in);
      //PrintWriter outFile = new PrintWriter(new FileWriter("Check.txt"));
      int t = 1;
      
      for (int i = 1; i <= t; ++i) {
    	 int N= 16;
    	 int J= 50;
    	 System.out.println("Case #"+ t + ":");
    	 int[] digits = new int[N];
    	 digits[0]=1;
    	 digits[N-1]=1;
    	 int j = 0;
    	 int count= 0;
    	 long cc=0;
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
    			 for(int l=1;l<=N;l++){
    				 //l is position in number
    				 numberInBase= numberInBase+ expTracker*digits[N-l];
    				 expTracker=expTracker*k;
    			 }
    			 cc=numberInBase;
    			 for(int l = 2; l<100; l++){
    				 if(numberInBase%l==0){
    					 primes[K]=l;
    					 l=100;
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
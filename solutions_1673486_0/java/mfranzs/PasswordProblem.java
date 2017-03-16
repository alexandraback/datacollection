

///REMOVE ALL OUTPUT AND USE STRINGTOKENIZER!


/*
ID: mfranzs1
LANG: JAVA
TASK: PasswordProblem
*/
import java.io.*;
import java.util.*;

public class PasswordProblem {
	static BufferedReader f;
	static ArrayList<boolean []> testCases= new ArrayList<boolean []>();
	public static void main (String [] args) throws IOException {
		long unixTime = System.currentTimeMillis();
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		f = new BufferedReader(new FileReader("PasswordProblem.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("PasswordProblem.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    //StringTokenizer st = new StringTokenizer(f.readLine()," ");	    	
    	//int i = Integer.parseInt(st.nextToken());
	    
	    int tests = Integer.parseInt(f.readLine());
	    for(int test=0;test<tests;test++){
	    	StringTokenizer st = new StringTokenizer(f.readLine()," ");	    	
	    	int numTyped= Integer.parseInt(st.nextToken());
	    	System.out.println("typed"+numTyped);
	    	int length= Integer.parseInt(st.nextToken());
	    	double keepTyping=0;
	    	double [] back = new double [numTyped];
	    	double [] probRight = new double[numTyped];
	    	int enter=2+length;
	    	StringTokenizer st2 = new StringTokenizer(f.readLine()," ");
	    	for(int ch=0;ch<numTyped;ch++){
	    		System.out.println(ch);
	    		probRight[ch]= Double.parseDouble(st2.nextToken());
	    	}
	    	boolean [] t= new boolean [numTyped];
	    	addTestCase(t,0);
	    	int cases=testCases.size();
	    	
	    	while(testCases.size()>0){
	    		boolean [] testStr = testCases.remove(0);
	    		//ACCOUNT FOR ENTER
	    		int keepType=length-numTyped+1;
	    		int firstWrong=99999999;
	    		boolean keepTypee=true;
	    		
	    		double probOccur=1;
	    		
	    		for(int i=0;i<testStr.length;i++){
	    			if(testStr[i]==false&&keepTypee){
	    				keepTypee=false;
	    				firstWrong=i;
	    			}
	    			
	    			if(testStr[i]==false){
	    				probOccur*=(1-probRight[i]);
	    			}else{
	    				probOccur*=probRight[i];
	    			}
	    			System.out.print(testStr[i]);
	    		}
	    		
	    		
	    		
	    		if(!keepTypee){
	    			keepType+=length+1;
	    		}
	    		
	    		//
	    		
	    		keepTyping+=keepType*probOccur;
	    		
	    		//bak		
	    		for(int i=0;i<numTyped;i++){
	    			int numNeeded = numTyped-i;//backspaces
	    			numNeeded+=length-i;//forward
	    			numNeeded++;//enter
	    			if(i>firstWrong){//after
	    				numNeeded+=length+1;
	    			}
	    			System.out.println("BACK "+i+" "+numNeeded);
	    			back[i]+=numNeeded*probOccur;
	    		}
	    		System.out.println(testStr+" "+keepType+" "+numTyped);
	    	}
	    	
	    	double best = enter;
	    	//keepTyping/=cases;
	    	if(keepTyping<best)best=keepTyping;
	    	for(int i=0;i<back.length;i++){
	    		//back[i]/=cases;
	    		if(back[i]<best)best=back[i];
	    	}
	    	
	    	best = ((int)(best*Math.pow(10,6)))/Math.pow(10,6);
	    	
	    	String bestStr=best+"";
	    	StringTokenizer st3 = new StringTokenizer(bestStr,".");
	    	st3.nextToken();
	    	String after=st3.nextToken();;
	    	for(int i=0;i<6-after.length();i++){
	    		bestStr+=""+0;
	    	}
	    	System.out.println("Case #"+(test+1)+": "+bestStr);
	    	out.println("Case #"+(test+1)+": "+bestStr);
	    }
	    
	    out.close();                                  // close the output file
	    
	    System.out.println("Time elapsed (ms): "+(System.currentTimeMillis()-unixTime));
	    
	    System.exit(0);                               // don't omit this!
	  }
	public static void addTestCase(boolean [] current, int position)
	{
		if(position == current.length){
			testCases.add(current);			
		}else{
			boolean [] new1 = current.clone();
			boolean [] new2 = current.clone();
			new1[position]=true;
			new2[position]=false;
			addTestCase(new1,position+1);
			addTestCase(new2,position+1);
		}
	}
}
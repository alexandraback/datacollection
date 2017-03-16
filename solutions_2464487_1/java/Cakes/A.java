import java.io.*;
import java.awt.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class A {
	PrintWriter out;
	BufferedReader f;
	public void run()throws Exception{
		f = new BufferedReader(new FileReader("A-large.in"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<6000; x++){
	   		StringTokenizer a = new StringTokenizer(f.readLine());
	   		//BigInteger r = new BigInteger(a.nextToken()), t = new BigInteger(a.nextToken());
			long r = Long.parseLong(a.nextToken()), t = Long.parseLong(a.nextToken());
	    	System.out.print("Case #"+(x+1)+": ");
	    	out.print("Case #"+(x+1)+": ");
	    	long cnt = 0;
	    	/*
	    	BigInteger two = new BigInteger(""+2);
	    	while(t>0){
	    		long paintNeed;
	    		if(r>Math.sqrt(Math.pow(10,18))){
		    		BigInteger tar = new BigInteger(""+r).multiply(new BigInteger(""+r)), tar2 = new BigInteger(""+r).add(new BigInteger(""+1)).multiply(new BigInteger(""+r).add(new BigInteger(""+1)));
		    		paintNeed = Long.parseLong(tar2.subtract(tar).toString());
	    		}
	    		else{
	    			long tar = r*r, tar2 = (r+1)*(r+1);
	    			paintNeed = tar2-tar;
	    		}
	    		t -= paintNeed;
	    		if(t>=0)cnt++;
	    		r += 2;
	    		long tar = r*r, tar2 = (r+1)*(r+1);
	    		long paintNeed = tar2-tar;
	    		t -= paintNeed;
	    		if(t>=0)cnt++;
	    		r +=2;
	    	}
	    	*/
	    	//System.out.println(cnt);
	    	out.println(cnt);
	    }
	    out.close();
	    System.exit(0);
	}
	
    public static void main (String [] args) throws Exception {
		new A().run();
    }
}

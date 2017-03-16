import java.io.*;
import java.awt.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class A {
	PrintWriter out;
	BufferedReader f;
	public void run()throws Exception{
		f = new BufferedReader(new FileReader("A-small-attempt1.in"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<datasets; x++){
	   		StringTokenizer a = new StringTokenizer(f.readLine());
			long r = Long.parseLong(a.nextToken()), t = Long.parseLong(a.nextToken());
	    	out.print("Case #"+(x+1)+": ");
	    	ArrayList<Integer> circles = new ArrayList<Integer>();
	    	long cnt = 0;
	    	while(t>0){
	    		long tar = r*r, tar2 = (r+1)*(r+1);
	    		long paintNeed = tar2-tar;
	    		t-= paintNeed;
	    		if(t>=0)cnt++;
	    		r+=2;
	    	}
	    	out.println(cnt);
	    }
	    out.close();
	    System.exit(0);
	}
	
    public static void main (String [] args) throws Exception {
		new A().run();
    }
}

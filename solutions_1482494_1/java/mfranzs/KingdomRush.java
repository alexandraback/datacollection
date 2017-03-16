

///REMOVE ALL OUTPUT AND USE STRINGTOKENIZER!


/*
ID: mfranzs1
LANG: JAVA
TASK: KingdomRush
*/
import java.io.*;
import java.util.*;

public class KingdomRush {
	static BufferedReader f;
	public static void main (String [] args) throws IOException {
		long unixTime = System.currentTimeMillis();
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		f = new BufferedReader(new FileReader("KingdomRush.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("KingdomRush.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    //StringTokenizer st = new StringTokenizer(f.readLine()," ");	    	
    	//int i = Integer.parseInt(st.nextToken());
	    
	    int tests=Integer.parseInt(f.readLine());
	    for(int test=0;test<tests;test++){
	    	int levels = Integer.parseInt(f.readLine());
	    	levelInfo levelinfo[]= new levelInfo[levels];
	    	for(int i=0;i<levels;i++){
		    	StringTokenizer st = new StringTokenizer(f.readLine()," ");
	    		int onestar = Integer.parseInt(st.nextToken());
	    		int twostar = Integer.parseInt(st.nextToken());
	    		levelInfo l = new levelInfo();
	    		l.one=onestar;
	    		l.two=twostar;
	    		l.position=i;
	    		l.score=0;
	    		levelinfo[i]=l;
	    	}
	    	//if(test<12)continue;
	    	Arrays.sort(levelinfo);
	    	for(int i=0;i<levels;i++){
	    		//System.out.print("LEVEL: "+levelinfo[i].one+" "+levelinfo[i].two+" ");
	    	}
	    	int completed=0;
	    	int stars=0;
	    	boolean bad=false;
	    	int plays=0;
	    	while(completed<levels)
	    	{
	    		//System.out.println("test");
	    		boolean next=false;
	    		//2 stars, not completed
	    		for(int i=0;i<levels;i++){
	    			if(levelinfo[i].score==0){
		    			if(levelinfo[i].two<=stars)
		    			{
		    				//System.out.println("TWO "+levelinfo[i].position+" "+stars);
		    				stars+=2;
		    				levelinfo[i].score=2;
		    				next=true;
		    				completed++;
		    				plays++;
		    				break;
		    			}
	    			}
	    		}
	    		if(next)continue;
	    		//get 2nd 1 star
	    		for(int i=0;i<levels;i++){
	    			if(levelinfo[i].score==1){
	    				if(levelinfo[i].two<=stars)
		    			{
	    					//System.out.println("ONE2 "+levelinfo[i].position+" "+stars);
		    				stars++;
		    				next=true;
		    				levelinfo[i].score++;
		    				if(levelinfo[i].score>=2)completed++;
		    				plays++;
		    				break;
		    			}
	    			}
	    		}
	    		if(next)continue;
	    		//get 1st star
	    		for(int i=0;i<levels;i++){
	    			if(levelinfo[i].score==0){
	    				if(levelinfo[i].one<=stars)
		    			{
	    					//System.out.println("ONE "+levelinfo[i].position+" "+stars);
		    				stars++;
		    				next=true;
		    				levelinfo[i].score++;
		    				if(levelinfo[i].score>=2)completed++;
		    				plays++;
		    				break;
		    			}
	    			}
	    		}
	    		if(next)continue;
	    		bad=true;
	    		break;
	    	}
		    
		    if(bad){
		    	out.println("Case #"+(test+1)+": Too Bad");
		    }else{
		    	out.println("Case #"+(test+1)+": "+plays);
		    }
		    System.out.println(test);
	    }
	    
	    out.close();                                  // close the output file
	    
	    //System.out.println("Time elapsed (ms): "+(System.currentTimeMillis()-unixTime));
	    
	    System.exit(0);                               // don't omit this!
	  }
}
class levelInfo implements Comparable
{
	int one,two,position,score;
	public int compareTo(Object o){
		if(((levelInfo)o).two-two!=0){
			return ((levelInfo)o).two-two;
		}else{
			return ((levelInfo)o).two-two;
		}
	}
	public String toString(){return two+"";}
}
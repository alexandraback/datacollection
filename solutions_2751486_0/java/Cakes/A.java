import java.io.*;
import java.awt.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class A {
	
	PrintWriter out;
	BufferedReader f;

	public void run()throws Exception{
		f = new BufferedReader(new FileReader("A-small-attempt0.in"));
	    out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
	    int datasets = Integer.parseInt(f.readLine());
	    for(int x = 0; x<datasets; x++){
	    	out.print("Case #"+(x+1)+": ");
	   		StringTokenizer a = new StringTokenizer(f.readLine());
	   		
	   		char[] name = a.nextToken().toCharArray();
	   		int N = Integer.parseInt(a.nextToken());
	   		int[] consec = new int[name.length];
	   		String vowels = "aeiouAEIOU";
	   		int temp = 0;
	   		int sub = 0;
		   	int n_val = 0;
	   		while(sub<name.length){
		   		for(int y = 0; y<name.length-sub; y++){
		   			if(!vowels.contains(""+name[y])){
		   				int tb = y;
		   				//System.out.println(tb);
		   				while(y<name.length-sub&&!vowels.contains(""+name[y])){
		   					temp++;
		   					y++;
		   				}
		   				y--;
		   				//System.out.println(temp);
		   				for(;temp>0;temp--,tb++)consec[tb]=temp;
		   			}
		   			else{
		   				temp =0;
		   			}
		   		}
		   		//System.out.println(Arrays.toString(consec));
		   		for(int y = 0; y<=name.length-N-sub; y++){
		   			boolean hasN = false;
		   			for(int z = y; z<=name.length-N-sub; z++){
		   				if(consec[z]>=N){
		   					n_val++;
		   					hasN = true;
		   					break;
		   				}
		   			}
		   			if(!hasN)break;
		   		}
		   		sub++;
	    	}
	   		out.println(n_val);
	    }
	    out.close();
	    System.exit(0);
	}

    public static void main (String [] args) throws Exception {
		new A().run();
    }
}

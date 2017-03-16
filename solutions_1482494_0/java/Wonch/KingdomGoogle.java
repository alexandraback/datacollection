package com.dennis.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

class Star2 implements Comparable{
	int req; 
	int id;
	int sec;
	
	Star2(int a, int b, int c){
		req = a;
		id = b;
		sec = c;
	}


	@Override
	public int compareTo(Object arg0) {
		if(this.req== ((Star2)arg0).req)
			if(((Star2)arg0).sec>this.sec)
				return 1;
			else if(((Star2)arg0).sec<this.sec)
				return -1;
			else 
				return 0;
		else if(this.req >((Star2)arg0).req)
			return 1;
		else
			return -1;
	}
}

class Star1 implements Comparable{
	int req; 
	int id;
	int sec;
	
	Star1(int a, int b, int c){
		req = a;
		id = b;
		sec = c;
	}

	@Override
	public int compareTo(Object arg0) {
		if(this.req== ((Star1)arg0).req){
			if(((Star1)arg0).sec>this.sec)
				return 1;
			else if(((Star1)arg0).sec<this.sec)
				return -1;
			else 
				return 0;
		}
		else if(this.req >((Star1)arg0).req)
			return 1;
		else
			return -1;
	}
}


public class KingdomGoogle {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {

		BufferedReader fin = new BufferedReader(new FileReader("kingdom.in"));
		PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("kingdom.out")));

		StringTokenizer stringy;
		int num = Integer.parseInt(fin.readLine());
		
		for(int asdf = 0 ; asdf<num; asdf++){
			int numlevel = Integer.parseInt(fin.readLine());
			
			int numstars = 0;
			int games = 0;
			Star1[] onelist = new Star1[numlevel];
			Star2[] twolist = new Star2[numlevel];
			boolean[] did2 = new boolean[numlevel];
			boolean[] did1 = new boolean[numlevel];
			
			for(int a = 0; a<numlevel;a++){
				stringy=new StringTokenizer(fin.readLine());
				int one = Integer.parseInt(stringy.nextToken());
				int two = Integer.parseInt(stringy.nextToken());
				onelist[a]  = (new Star1(one, a, two));
				twolist[a]  = (new Star2(two, a,one));
			}
			
			Arrays.sort(onelist);
			Arrays.sort(twolist);
			
			int onedex = 0; 
			int twodex = 0;
			
			boolean success = true;
			loop:
			while(twodex<numlevel){
				if(twodex<numlevel && twolist[twodex].req<=numstars){
					if(did1[twolist[twodex].id])
						numstars+=1;
					else
						numstars+=2;
					did2[twolist[twodex].id] = true;
					twodex++;
					games++;
					continue;
				}
				else if(onedex<numlevel && did2[onelist[onedex].id]){
					onedex++;
					continue;
				}
				else if(onedex<numlevel && onelist[onedex].req<=numstars){
					numstars++;
					did1[onelist[onedex].id] = true;
					onedex++;
					games++;
					continue;
				}
				else{
					success = false;
					break loop;
				}
				
			}
			
			if(success)
				fout.println("Case #" + (asdf+1) + ": " +games);//asdfasdfasd
			else
				fout.println("Case #" + (asdf+1) + ": Too Bad" );//asdfasdfasd
		}

		
		
		
		fout.close();
		System.exit(0);
	}

}

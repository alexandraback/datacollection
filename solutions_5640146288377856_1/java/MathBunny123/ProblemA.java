/* Programming competition file template
Made by Horatiu Lazu */

import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;
import java.awt.geom.*;
import java.math.*;


public class ProblemA{
	public static void main (String [] args){
		new ProblemA();
	}

	public ProblemA(){
		try{
			BufferedReader in;
			//in = new BufferedReader (new InputStreamReader (System.in)); //Used for CCC
			in = new BufferedReader(new FileReader("A-large.in")); //Used for JDCC & others
			
			PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
			int testCases = Integer.parseInt(in.readLine());
			for(int qq = 0; qq < testCases; qq++){
				start:{
					StringTokenizer st = new StringTokenizer(in.readLine());
					int rows = Integer.parseInt(st.nextToken());
					int cols = Integer.parseInt(st.nextToken());
					int width = Integer.parseInt(st.nextToken());
					if (width == 1){
						System.out.println("Case #" + (qq+1) + ": " + (rows * cols));
						out.println("Case #" + (qq+1) + ": " + (rows * cols));
						break start;
					}
					else{
						//you need to do every other, minus the width..
						int x = 0;
						int y = 0;
						int hits = 0;
						while(true){
							if (x < cols){
								hits++;
								x += width;	
							}
							else{
								if (y < rows){
									y += 1;
								}	
								else{
									System.out.println("Case #" + (qq+1) + ": " + ((hits) + (width-1)));
									out.println("Case #" + (qq+1) + ": " + ((hits) + (width-1)));
									break start;	
								}
							}
						}	
						
					}
				}
			}
			
			out.close();
			
		}
		catch(IOException e){
			System.out.println("IO: General");
		}
	}
}
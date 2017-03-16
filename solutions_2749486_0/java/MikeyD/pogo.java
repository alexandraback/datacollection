import java.io.*;
import java.util.*;

public class pogo {

	public static String best;
	public static int x, y;
	public static void main(String[] args) throws Exception{
		
		Scanner In = new Scanner(System.in);
		
		int numCases = In.nextInt();
		
		for(int currCase = 1;currCase <= numCases;currCase++){
			
			best = "";
			
			x = In.nextInt();
			y = In.nextInt();
			
			int jumps = 1,currX = 0,currY = 0;
			
			if(x >= 0){
				while(currX+jumps <= x){
					currX += jumps;
					best += "E";
					jumps++;
				}	
				
				for(int i = 0;i < x-currX;i++){
					best+= "WE";
					jumps+=2;
				}
			}
			
			else{
				while(currX-jumps >= x){
					currX -= jumps;
					best += "W";
					jumps++;
				}	
				
				for(int i = 0;i <  Math.abs(x)-Math.abs(currX);i++){
					best+= "EW";
					jumps+=2;
				}
			}
			
			if(y >= 0){
				while(currY+jumps <= y){
					currY += jumps;
					best += "N";
					jumps++;
				}	
				
				for(int i = 0;i < y-currY;i++){
					best+= "SN";
					jumps+=2;
				}
			}
			
			else{
				while(currY-jumps >= y){
					currY -= jumps;
					best += "S";
					jumps++;
				}	
				
				for(int i = 0;i < Math.abs(y)-Math.abs(currY);i++){
					best+= "NS";
					jumps+=2;
				}
			}
			
			System.out.println("Case #"+currCase+": "+best);
			
		}
		
	}
	
}

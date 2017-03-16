/*
 * Author: Sébastien Speierer
 * Date: 12 mai 2013
 */

public class Exo02 {

	public static int jumpValue;
	
	public static int currentX;
	public static int currentY;
	
	public static int destX;
	public static int destY;
	
	public static String travel = "";
	
	public static void main(String[] args) {
		int numberTest = Integer.parseInt(args[0]);
		int cursor = 1;
		
		for(int i = 0; i< numberTest; i++){
				currentX = 0;
				currentY = 0;
				jumpValue = 1;
				travel = "";
				
				destX = Integer.parseInt(args[cursor++]);
				destY = Integer.parseInt(args[cursor++]);
				
				//System.out.println("dest: " + destX + "/" + destY);
				
				goX();
				goY();
				
				
				
				
			
				
				System.out.println("Case #" + (i+1) + ": " + travel);
				
		}
		// System.out.println(total);
		
	}
	
	public static void goX(){
		int dist = Integer.MAX_VALUE;
		do{
			
			dist = destX-currentX;
			int distAbs = Math.abs(dist);
			
			//System.out.println("On est à la position " + currentX + " / " + currentY + "    dist ->" + dist);
			
			if(distAbs >= jumpValue){
				if(dist < 0){	// go West
					currentX -= jumpValue;
					jumpValue++;
					travel += "W";
				}else{
					currentX += jumpValue;
					jumpValue++;
					travel += "E";
				}
			}else{
				if(dist < 0){	// go West
					currentX += jumpValue;
					jumpValue++;
					travel += "E";
				}else{
					currentX -= jumpValue;
					jumpValue++;
					travel += "W";
				}
			}
		}while(currentX != destX);
	}
	public static void goY(){
		do{
			int dist = destY-currentY;
			int distAbs = Math.abs(dist);
	
			if(distAbs >= jumpValue){
				if(dist < 0){	// go West
					currentY -= jumpValue;
					jumpValue++;
					travel += "S";
				}else{
					currentY += jumpValue;
					jumpValue++;
					travel += "N";
				}
			}else{
				if(dist < 0){	// go West
					currentY += jumpValue;
					jumpValue++;
					travel += "N";
				}else{
					currentY -= jumpValue;
					jumpValue++;
					travel += "S";
				}
			}
		}while(currentY != destY);
	}
	

}

import java.io.BufferedReader;
import java.io.FileReader;


public class Pogo {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("c:\\B-small-attempt0.in"));
		
		int testcase = Integer.parseInt(br.readLine());
		
		for(int i=0;i<testcase;i++){
			String[] inputs = br.readLine().split(" ");
			int x = Integer.parseInt(inputs[0]);
			int y = Integer.parseInt(inputs[1]);
			
			String ans = "";
			int jumpCount = 1;
			
			int currentX = 0;
			int currentY = 0;
			
			//adjust X
			while(currentX!=x){
				if(x<currentX){
					if(currentX-x>=jumpCount){
						ans += "W";
						currentX -= jumpCount++; 
					}
					else{
						ans += "EW";
						currentX--; 
						jumpCount += 2;
					}
				}
				else{
					if(x-currentX>=jumpCount){
						ans += "E";
						currentX += jumpCount++; 
					}
					else{
						ans += "WE";
						currentX++; 
						jumpCount += 2;
					}
				}
			}
			
			//adjust y
			while(currentY!=y){
				if(y<currentY){
					if(currentY-y>=jumpCount){
						ans += "S";
						currentY -= jumpCount++; 
					}
					else{
						ans += "NS";
						currentY--; 
						jumpCount += 2;
					}
				}
				else{
					if(y-currentY>=jumpCount){
						ans += "N";
						currentY += jumpCount++; 
					}
					else{
						ans += "SN";
						currentY++; 
						jumpCount += 2;
					}
				}
			}
			
			System.out.println("Case #"+(i+1)+": "+ans);
		}

	}

}

import java.io.*;
import java.util.Scanner;


public class DLarge {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		DLarge main = new DLarge();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("D-large.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("Dlarge.out", "UTF-8");
		for(int cas=1; cas<=T; cas++){
			String[] size = scan.nextLine().split(" ");
			int X = Integer.parseInt(size[0]);
			int R = Math.max(Integer.parseInt(size[1]), Integer.parseInt(size[2]));
			int C = Math.min(Integer.parseInt(size[1]), Integer.parseInt(size[2]));
			
			int dim1 = X/2+1;
			int dim2 = X/2;
			boolean possible = true;
			if(X >= 7){
				// C>=3 => hole
				// C<3 => 3x3
				possible = false;
			}else if(R*C % X != 0){
				possible = false;
			}else if(X>R){
				possible = false;				
			}else if(R*C <= 2){
				possible = true;
			}else if(dim2 > C || dim1 > R){
				possible = false;
			}else if(R*C/X<=2 && X>3){
				possible = false;
			}else if(X>=2*C+1){
				// U shape
				possible = false;
			}else if(C==3){
				if(X==6){
					possible = false;
				}else if(X==5&&R<=5){
					possible = false;
				}
			}else if(C==2){
				if(X>=4){
					possible = false;
				}
			}
			//scan.nextInt();
			
			if(!possible){
				writer.println("Case #"+cas+": "+"RICHARD");
				System.out.println("Case #"+cas+": "+"RICHARD");
			}else{
				writer.println("Case #"+cas+": "+"GABRIEL");
				System.out.println("Case #"+cas+": "+"GABRIEL");
			}
				
		}		
		writer.close();
	}
	
	
}

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class C1B {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try{
			Scanner myFile = new Scanner(new FileReader("D://alon//programming//codejam2013//C1//B-small-attempt0.in")); //check!!!  B-small-attempt0.in
			BufferedWriter out = new BufferedWriter(new FileWriter("D://alon//programming//codejam2013//C1//B-small-answers.txt")); //check!!!
			int T = myFile.nextInt();
			for(int t = 1; t<=T; t++){
				int X = myFile.nextInt();
				int Y = myFile.nextInt();
				int x = 0;
				int y = 0;
				int count = 1;
				String s = "";
				while(X != x){
					if(x-count == X){
						s+="W";
						x-=count;
						count++;
					}
					if(x+count == X){
						s+="E";
						x+=count;
						count++;
					}
					if((x+count != X)&&(x-count != X)){
						if(((X > x)&&(x+count<X))||((x > X)&&(x-count<X))){
							s+="E";
							x+=count;
							count++;
						}
						if(((X > x)&&(x+count>X))||(x > X)&&(x-count>X)){
							s+="W";
							x-=count;
							count++;
						}
					}
				}
				while(Y != y){
					if(y-count == Y){
						s+="S";
						y-=count;
						count++;
					}
					if(y+count == Y){
						s+="N";
						y+=count;
						count++;
					}
					if((y+count != Y)&&(y-count != Y)){
						if(((Y > y)&&(y+count<Y))||((y > Y)&&(y-count<Y))){
							s+="N";
							y+=count;
							count++;
						}
						if(((Y > y)&&(y+count>Y))||(y > Y)&&(y-count>Y)){
							s+="S";
							y-=count;
							count++;
						}
					}
				}
				out.write("Case #"+t+": "+s+'\n');
				System.out.println("Case #"+t+": "+s+" number: "+s.length());
			}
			out.close();
			myFile.close();
		}catch(FileNotFoundException e){
			System.out.println("file not found");
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}

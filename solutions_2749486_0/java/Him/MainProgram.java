import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class MainProgram {

	static BufferedReader in = null;
	static int T, X, Y;
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/Pogo/B-small-attempt0.in")); 
		int T = Integer.parseInt(in.readLine());
		for (int i=0; i<T; i++){
			readInput();
			System.out.println("Case #"+(i+1)+": "+getOutput());
		}
		in.close();
	}

	public static void readInput() throws IOException{
		String[] strA = in.readLine().split(" ");
		X = Integer.parseInt(strA[0]);
		Y = Integer.parseInt(strA[1]);
	}
	
	public static String getOutput(){
		String directions = "";
		int n = 1, x = 0, y = 0;
		while (true){
			if (x < X){
				x += n;
				directions += "E";
				n++;
				if (x + n >= X && x + n - X < X - x){
					x += n;
					directions += "E";
					n++;
				}
			}
			if (y < Y){
				y += n;
				directions += "N";
				n++;
				if (y + n >= Y && y + n - Y < Y - y){
					y += n;
					directions += "N";
					n++;
				}
			}
			if (x >= X && y >= Y)
				break;
		}
		for (int i=0; i<X-x; i++){
			directions += "WE";
		}
		for (int i=0; i<x-X; i++){
			directions += "EW";
		}
		for (int i=0; i<Y-y; i++){
			directions += "SN";
		}
		for (int i=0; i<y-Y; i++){
			directions += "NS";
		}
		
		return directions;
	}
	
}

import java.io.*;
import java.util.*;
public class  Main
{
	public static void main(String[] args) throws FileNotFoundException 
	{
	    FileInputStream psi = null;
	    PrintStream pso = null;
	    Scanner sc = null;
	    int num = 0;
	    byte[][] mtx = new byte[4][4];
	    psi = new FileInputStream("D:\\Users\\Rophyll\\Downloads\\B-small-attempt0.in");
		pso = new PrintStream(new FileOutputStream("D:\\Users\\Rophyll\\Downloads\\out1.in"));
		System.setIn(psi);
		System.setOut(pso);
		sc = new Scanner(System.in);
		
		num = sc.nextInt();
		for(int i = 0; i < num; i++){//each case
			int x = sc.nextInt();
			int y = sc.nextInt();
			System.out.println("Case #"+(i+1)+": " + calc(x, y));
		}
	}

	private static String calc(int x, int y) {
		// TODO Auto-generated method stub
		String result = "";
		if(x < 0){
			int xloop = 0 - x;
			for(int i = 0; i < xloop; i++)
				result += "EW";
		}else{
			for(int i = 0; i < x; i++){
				result += "WE";
			}
		}
		if(y < 0){
			int yloop = 0 - y;
			for(int i = 0; i < yloop; i++)
				result += "NS";
		}else{
			for(int i = 0; i < y; i++){
				result += "SN";
			}
		}
		return result;
	}
}
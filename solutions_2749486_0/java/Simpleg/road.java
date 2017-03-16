import java.util.*;
import java.io.*;
import java.lang.*;

public class road {	
	
    public static void main(String[] args) throws IOException {

        // Scanner in = new Scanner(new File("input.txt"));
		Scanner in = new Scanner(new File("B-small-attempt0.in"));
        // Scanner in = new Scanner(new File("B-large.in"));
		FileWriter fw = new FileWriter("output_small.txt");	
		// FileWriter fw = new FileWriter("output_large.txt");	
		int T = in.nextInt();
		
		for (int cases = 1; cases <= T; cases++){
			// read parameters for this case
			String result = "";
			int realx = in.nextInt();
			int realy = in.nextInt();
			int x = (realx > 0) ? realx : (0 - realx);
			int y = (realy > 0) ? realy : (0 - realy);
			int nowX = 0;
			int nowY = 0;
			int step = 1;
			while((nowX + step) < x){
				nowX += step;
				step++;
				result = result + "E";
			}
			while(nowX != x){
				nowX -= step;
				step++;
				result = result + "W";
				nowX += step;
				step++;
				result = result + "E";				
			}
			while(nowY != y){
				nowY -= step;
				step++;
				result = result + "S";
				nowY += step;
				step++;
				result = result + "N";				
			}
			
			char[] resultChar = result.toCharArray();
			
			if(realx < 0){
				for(int i = 0; i < resultChar.length; i++){
					if (resultChar[i] == 'E')
						resultChar[i] = 'W';
					else if (resultChar[i] == 'W')
						resultChar[i] = 'E';
				}
			}
			
			if(realy < 0){
				for(int i = 0; i < resultChar.length; i++){
					if (resultChar[i] == 'S')
						resultChar[i] = 'N';
					else if (resultChar[i] == 'N')
						resultChar[i] = 'S';
				}
			}
	
			fw.write("Case #" + cases + ": ");
			for(int i = 0; i < resultChar.length; i++){
				fw.write(resultChar[i]);
			}
			fw.write("\n");
		}
		fw.flush();
		fw.close();		
	}
	
}
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;


public class BSol {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Date d1 = new Date();
		solveC("B-small-attempt1.in", "B-small-attempt1.out");
		Date d2 = new Date();
		System.out.println("time: " + (d2.getTime() - d1.getTime()) + " ms");

	}

	private static void solveC(String in, String out) {
		try {
			FileReader fis = new FileReader(in);
			BufferedReader  dis = new BufferedReader (fis);
			
			FileWriter fw = new FileWriter(out);
			BufferedWriter bw = new BufferedWriter(fw);

			
			int t = Integer.parseInt(dis.readLine());
			for (int i = 0; i < t; i++) {
				String e = dis.readLine();
				String ee[] = e.split(" ");
			
				int x = Integer.parseInt(ee[0]);
				int y = Integer.parseInt(ee[1]);
				
				
				String result = solve(x, y);
				System.out.println(result);
				bw.write("Case #" + (i+1) + ": " + result + "\n");
			}
			
			
			bw.flush();
			bw.close();
			fw.close();
			dis.close();
			fis.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			
		}
	}

	private static String solve(int x, int y) {
		
		String result = "";
		
		int cx = 0;
		int cy = 0;
		int step = 1;
		while (true) {
			//System.out.println(cx + " " + cy + " " + step + " " + x + " " + y);
			if (cx > x) {
				result += "EW";
				cx -= 1;
				step++;
				step++;
			} else if (cx < x) {
				result += "WE";
				cx += 1;
				step++;
				step++;
			} else
				break;
		}
		
		
		//System.out.println(cx + " " + cy + " " + step + " " + x + " " + y);
		
		
		while (true) {
			//System.out.println(y + " " + cy + " " + step);
			if (cy > y) {
				result += "NS";
				cy -= 1;
				step++;
				step++;
			} else if (cy < y) {
				result += "SN";
				cy += 1;
				step++;
				step++;
			} else
				break;
		}
		
		
		//System.out.println(result +  " "+ step + " " + x + " " + y + " " + cx + " " + cy);
		
		System.out.println(result.length());
		
		// TODO Auto-generated method stub
		return result;
	}



	


}

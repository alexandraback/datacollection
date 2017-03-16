package Round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Bullseye {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br;
		try {
			int N;
			br = new BufferedReader(new FileReader("A-small-attempt0.in"));
			PrintWriter pw = new PrintWriter(new File("output"));
			String line = br.readLine();
			N = Integer.parseInt(line);
			int count = 1;
			while (count <= N) {
				line = br.readLine();
				String[] strs = line.split(" ");
				int r = Integer.parseInt(strs[0]);
				double t = Integer.parseInt(strs[1]);
				int circle = 0;
				boolean enoughPaint = true;
				double nextUse = ((r + 1) * (r + 1) - r * r);
				while(enoughPaint){
					nextUse = ((r + 1) * (r + 1) - r * r);
//					System.out.println(nextUse + " " + t);
					if(t < nextUse)
						enoughPaint = false;
					else{
						circle ++;
						t = t - nextUse;
						r += 2;
					}
				}
				
				
				System.out.println("Case #" + count + ": " + circle);
				pw.write("Case #" + count + ": " + circle + "\n");
				pw.flush();
				count++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


	}

}

import java.util.*;
import java.io.*;

public class pogo2 {

	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new File("pogo.in"));
		FileWriter fStream = new FileWriter("pogo.out");
		BufferedWriter out = new BufferedWriter(fStream);

		int numCases = in.nextInt();
		in.nextLine();

		for(int zCase = 1; zCase <= numCases; zCase++){
			int x = in.nextInt();
			int y = in.nextInt();

			int c = 1;
			String r = "";
			while(x > c || x < -c){
				if(x > 0){
					x-= c++;
					r += "E";
				} else{
					x += c++;
					r += "W";
				}
			}
			while(y > c || y < -c){
				if(y > 0){
					y-=c++;
					r += "N";
				} else{
					y+=c++;
					r += "S";
				}
			}

			if(x > 0){
				r += new String(new char[x]).replace("\0", "WE");
			} else if(x < 0){
				r += new String(new char[-x]).replace("\0", "EW");
			}

			if(y > 0){
				r += new String(new char[y]).replace("\0", "SN");
			} else if(y < 0){
				r += new String(new char[-y]).replace("\0", "NS");
			}
			String lineOut = "Case #" + zCase + ": " + r;
			System.out.println(lineOut);
			out.write(lineOut + "\n");

		}


		out.close();
		fStream.close();
		in.close();
	}
}
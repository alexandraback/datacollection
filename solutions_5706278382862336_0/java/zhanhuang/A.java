import java.util.Scanner;
import java.io.*;
import java.util.*;


public class A{
	public static void main(String[] args){
		Scanner sc = null;
		try{
			sc = new Scanner(new File("A-small-attempt0.in"));
		}
		catch(Exception ex){}

		String next;

		int cases = Integer.parseInt(sc.nextLine());
		int current = 0;

		try{
			FileWriter fs = new FileWriter("output.txt");
			BufferedWriter buff = new BufferedWriter(fs);
			while(current < cases){
				String nextLine = sc.nextLine();
				String[] fractionString = nextLine.split("/");
				int[] fraction = new int[2];
				fraction[0] = Integer.parseInt(fractionString[0]);
				fraction[1] = Integer.parseInt(fractionString[1]);

				int extra = fraction[1];
				while(extra%2 == 0){
					extra = extra/2;
				}

				if(fraction[0]%extra != 0){
					current++;
					buff.write("Case #" + current + ": impossible\n");
					continue;
				}else{
					fraction[0] = fraction[0]/extra;
					fraction[1] = fraction[1]/extra;
				}


				while(fraction[0]%2 == 0 && fraction[1]%2 == 0){
					fraction[0] = fraction[0]/2;
					fraction[1] = fraction[1]/2;
				}

				int out = 0;
				while(fraction[0] < fraction[1]){
					fraction[1] = fraction[1]/2;
					out++;
				}
				current++;
				buff.write("Case #" + current + ": " + out + "\n");
			}
			buff.close();
		}
		catch(Exception ex){}
	}
}
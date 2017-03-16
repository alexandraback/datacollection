import java.util.Scanner;
import java.io.*;
import java.util.*;


public class C{
	public static void main(String[] args){
		Scanner sc = null;
		try{
			sc = new Scanner(new File("C-large.in"));
		}
		catch(Exception ex){}

		String next;

		int cases = Integer.parseInt(sc.nextLine());
		int current = 0;

		try{
			FileWriter fs = new FileWriter("output.txt");
			BufferedWriter buff = new BufferedWriter(fs);
			while(current < cases){
				String line = sc.nextLine();
				String[] str = line.split(" ");
				int n = Integer.parseInt(str[0]);
				int m = Integer.parseInt(str[1]);
				int k = Integer.parseInt(str[2]);

				int mc = m - 2;
				int nc = n - 2;

				int stones = 0;
				int coverage = 0;

				while(coverage < k){
					stones++;

					coverage = 0;

					if(mc * nc > 0){
						int stonesRemaining = stones - 4;
						if(stonesRemaining >= 0){
							// first
							coverage = 1;
							if(mc >= 1 || nc >= 1){
								stonesRemaining -= 2;
								if(stonesRemaining >= 0){
									// second
									coverage ++;
									// others
									if(mc == 1 || nc == 1){
										coverage += Math.min(mc * nc - 2, stonesRemaining/2);
									} else{
										coverage += Math.min(mc * nc - 2, stonesRemaining);
									}
								}
							}
						}
					}
					coverage += stones;
				}

				current++;
				buff.write("Case #" + current + ": " + stones + "\n");
			}
			buff.close();
		}
		catch(Exception ex){}
	}
}
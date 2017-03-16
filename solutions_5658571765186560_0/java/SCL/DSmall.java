import java.util.*;
import java.io.*;

public class DSmall {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2015/io/D-small-attempt0.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2015/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] st = input.readLine().split(" ");
			int X = Integer.parseInt(st[0]);
			int R = Integer.parseInt(st[1]);
			int C = Integer.parseInt(st[2]);
			if(X == 1){
				pw.println("Case #"+(i+1)+": GABRIEL");
			}else if(X == 2){
				if((R * C) % 2 == 0){
					pw.println("Case #"+(i+1)+": GABRIEL");
				}else{
					pw.println("Case #"+(i+1)+": RICHARD");
				}
			}else if(X == 3){
				if((R == 2 && C == 3) || (R == 3 && C == 2) || (R == 3 && C == 3) || (R == 3 && C == 4) || (R == 4 && C == 3)){
					pw.println("Case #"+(i+1)+": GABRIEL");
				}else{
					pw.println("Case #"+(i+1)+": RICHARD");
				}
			}else if(X == 4){
				if((R == 3 && C == 4) || (R == 4 && C == 3) || (R == 4 && C == 4)){
					pw.println("Case #"+(i+1)+": GABRIEL");
				}else{
					pw.println("Case #"+(i+1)+": RICHARD");
				}
			}
		}
		pw.flush();
		input.close();
		pw.close();
	}
}

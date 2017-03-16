import java.util.*;
import java.io.*;

public class DSmall {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2015/io/D-large.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2015/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] st = input.readLine().split(" ");
			int X = Integer.parseInt(st[0]);
			int[] a = {Integer.parseInt(st[1]),Integer.parseInt(st[2])};
			Arrays.sort(a);
			if(X == 1){
				pw.println("Case #"+(i+1)+": GABRIEL");
			}else if(X == 2){
				if((a[0] * a[1]) % 2 == 0){
					pw.println("Case #"+(i+1)+": GABRIEL");
				}else{
					pw.println("Case #"+(i+1)+": RICHARD");
				}
			}else if(X >= 7){
				pw.println("Case #"+(i+1)+": RICHARD");
			}else if(X >= 3){
				if(a[0] >= (X / 2 + 1) && (a[0] % X == 0 || a[1] % X == 0)){
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

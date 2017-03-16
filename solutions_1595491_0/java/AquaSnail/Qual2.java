import java.io.*;
import java.util.*;

public class Qual2 {


	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		FileWriter fw = new FileWriter("B-output.txt");
		int total = sc.nextInt();
		for(int i = 1; i <= total; i++) {
			int n = sc.nextInt(), s = sc.nextInt(), p = sc.nextInt();
			int[] scores = new int[n];
			for(int j = 0; j < n; j++) scores[j] = sc.nextInt();
			int count = 0;
			for(int j = 0; j < n; j++) {
				int div = scores[j] / 3, rem = scores[j] % 3;
				if(rem == 0) {
					if(div >= p) count++;
					else if(div == p-1 && div > 0 && s > 0) {
						s--;
						count++;
					}
				}
				else if(rem == 1) {
					if(div + 1 >= p) count++;
				}
				else if(rem == 2) {
					if(div + 1 >= p) count++;
					else if(div + 2 >= p && s > 0) {
						s--;
						count++;
					}
				}
				/*if(div >= p) count++;
				else if(rem == 1 && div + rem >= p) count++;
				else if(rem == 2) {
					if(div + rem == p) {
						if(s > 0) {
							s--;
							count++;
						}
					}
					else if(div + rem > p) count++;
				}
				else if(rem == 0 && div == p-1 && s > 0) {
					s--;
					count++;
				}*/
			}
			fw.write("Case #" + i + ": " + count + "\n");
			System.out.println("Case #" + i + ": " + count);
		}
		fw.close();
	}

}

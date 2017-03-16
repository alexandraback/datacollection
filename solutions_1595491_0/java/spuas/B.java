import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {

	
	public static void main(String[] args) throws IOException {
//		Scanner in = new Scanner(new File("in/B/test.in"));
		Scanner in = new Scanner(new File("in/B/small.in"));
//		Scanner in = new Scanner(new File("in/B/big.in"));
//		BufferedWriter bw = new BufferedWriter(new FileWriter(
//				"out/B/test.out"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(
				"out/B/small.out"));
//		BufferedWriter bw = new BufferedWriter(new FileWriter(
//				"out/B/big.out"));
		int cases = in.nextInt();
		for(int c = 1; c <= cases; c++){
			int competitors = in.nextInt();
			int surprises = in.nextInt();
			int minNote = in.nextInt();
			int winners = 0;
			for(int i = 0; i < competitors; i++){
				int max = 0, normal = 0;
				int note = in.nextInt();
				System.err.println(note);
				if(note == 0){
					max = 0;
					normal = 0;
				}else if(note == 1){
					max = 1;
					normal = 1;
				}else if(note > 27){
					max = 10;
					normal = 10;
				}else{
					int mod = note%3;
					max = note/3 + (mod==0?1:mod);
					normal = max - (mod!=1?1:0);
				}
				if(normal >= minNote){
					winners++;
					continue;
				}
				if(max == minNote && surprises > 0){
					surprises--;
					winners++;
					continue;
				}
			}
			bw.write("Case #" + (c) + ": "+winners);
			System.err.println("Case #" + (c) + ": "+winners);
			bw.newLine();
		}
		in.close();
		bw.flush();
		bw.close();
	}
}

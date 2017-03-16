import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Ovation {

	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			String str = sc.next();
			int sum = 0;
			int need = 0;
			for ( int i = 0 ; i <= n ; i++ ){
				if ( sum < i ){
					need += i - sum;
					sum = i;
				}
				sum += str.charAt(i)-'0';
			}
			bw.write("Case #" + z + ": " + need + "\n");
		}
		bw.close();
		sc.close();
	}
}

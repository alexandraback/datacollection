import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Enclosure {

	
	public static void main( String[] args ) throws IOException{
		(new Enclosure()).enclosure();
	}
	
	public void enclosure() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			int r = 3;
			int c = 3;
			int g = 5;
			int ans = 4;
			bw.write("Case #" + z + ": ");
			int mm = Math.min(m, n);
			if ( mm < 3 || k < 5 ){
				bw.write(""+k+"\n");
				continue;
			}
			if ( k > m*n-4 ){
				ans = (m+n-4)*2 + (k-m*n+4);
				bw.write(""+ans + "\n");
				continue;
			}
			while ( g < k ){
				if ( r > c && c < mm ){
					c++;
					g += r;
				}
				else {
					r++;
					g += c;
				}
				ans+=2;
			}
			bw.write(""+ans+"\n");
		}
		
		bw.close();
		sc.close();
	}
}

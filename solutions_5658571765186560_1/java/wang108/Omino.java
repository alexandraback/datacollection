import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Omino {

	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int x = sc.nextInt();
			int r = sc.nextInt();
			int c = sc.nextInt();
			if ( r > c ){
				int t = r;
				r = c;
				c = t;
			}
			boolean flag = false;
			if ( x <= 2 )
				flag = true;
			else if ( x == 3 && r >= 2 )
				flag = true;
			else if ( x < 7 && r >= 3 )
				flag = true;

			if ( r*c%x != 0 )
				flag = false;
			
			if ( flag )
				bw.write("Case #" + z + ": GABRIEL\n");
			else 
				bw.write("Case #" + z + ": RICHARD\n");
		}
		bw.close();
		sc.close();
	}

}

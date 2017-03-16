import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.function.Function;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.function.ToLongFunction;


public class Pancakes {
	
	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int d = sc.nextInt();
			int[] p = new int[d];
			
			int max = 0;
			for ( int i = 0 ; i < d ; i++ ){
				p[i] = sc.nextInt();
				max = Math.max(p[i], max);
			}
			
			int ans = Integer.MAX_VALUE;
			for ( int i = 1 ; i <= max ; i++ ){
				int count = i;
				for ( int j = 0 ; j < d ; j++ )
					count += (p[j]-1)/i;
				if ( count < ans )
					ans = count;
			}

			bw.write("Case #" + z + ": " + ans + "\n");
		}
		bw.close();
		sc.close();
	}
}

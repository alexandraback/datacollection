import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class Dijkstra {
	
	Map<Character, Integer> map;
	int[][] matrix = {{},
			{0,1,2,3,4},
			{0,2,-1,4,-3},
			{0,3,-4,-1,2},
			{0,4,3,-2,-1}};
	
	int calc( int v, char c ){
		int sign = 1;
		if ( v < 0 ){
			v  = -v;
			sign = -1;
		}
		return sign*matrix[v][map.get(c)];
	}
	
	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		map = new HashMap();
		map.put('i', 2);
		map.put('j', 3);
		map.put('k', 4);
		for ( int z = 1 ; z <= cases ; z++ ){
			int l = sc.nextInt();
			long x = sc.nextLong();
			String str = sc.next();
			int pro = 1;
			for ( int i = 0 ; i < str.length() ; i++ ){
				pro = calc(pro, str.charAt(i));
			}

			if ( pro == 1 || pro == -1 && x%2 != 1 || Math.abs(pro) > 1 && x%4 != 2 ){
				bw.write("Case #" + z + ": NO\n");
				continue;
			}
			
			pro = 1;
			Set<Integer> set= new HashSet();
			int[] goal = {2, 3, 4};
			int index = 0;
			boolean flag = false;
			loop:
			for ( long k = 0 ; k < Math.min(x, 12) ; k++ )
				for ( int i = 0 ; i < str.length() ; i++ ){
					pro = calc(pro, str.charAt(i));
					if (pro == goal[index]){
						index++;
						if ( index == 3 ){
							flag = true;
							break loop;
						}
						pro = 1;
					}
				}
			if ( flag )
				bw.write("Case #" + z + ": YES\n");
			else 
				bw.write("Case #" + z + ": NO\n");
		}
		bw.close();
		sc.close();
	}

}

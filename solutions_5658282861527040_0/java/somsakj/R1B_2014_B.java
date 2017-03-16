import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class R1B_2014_B {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		FileWriter fw = new FileWriter("B-small-attempt0.out");
		int T = new Integer(in.readLine());
		for (int cases = 1; cases <= T; cases++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int A = new Integer(st.nextToken());
			int B = new Integer(st.nextToken());
			int K = new Integer(st.nextToken());
			
			int y = 0;
			for(int i=0; i< A; i++){
				for(int j=0; j< B; j++){
					int c = i & j;
					if( c < K){
						y++;
					}
				}	
			}
			
			
			fw.write("Case #" + cases + ": " + y +"\n");
			
		}
		fw.flush();
		fw.close();
		
		System.out.println("Done!");
	}

}


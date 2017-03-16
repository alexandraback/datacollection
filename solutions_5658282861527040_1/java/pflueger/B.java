import java.io.IOException;

//5/3/14 in competition.

public class B extends CodeJammer {

	@Override
	public void process() throws IOException {
		long[] line = reader.readLongArray();
		long al = line[0]-1;
		long bl = line[1]-1;
		long kl = line[2]-1;
		
		boolean[] a = new boolean[31]; //31 bits is enough.
		boolean[] b = new boolean[31];
		boolean[] k = new boolean[31];
		
		for (int i=30; i>=0; i--) {
			a[i] = (al%2 == 1);
			b[i] = (bl%2 == 1);
			k[i] = (kl%2 == 1);
			
			al /= 2;
			bl /=2;
			kl /=2;
		}
		
		for (int start = 30; start >= 0; start--) {
			for (int i=0; i<2; i++) for (int j=0; j<2; j++) for (int h=0; h<2; h++) {
				//Compute the first characters
				boolean x = (i == 1) || a[start];
				boolean y = (j == 1) || b[start];
				boolean z = (h == 1) || k[start];
				
				long val = 0;
				
				if (x && y && z) val += cache[i][j][h][start+1]; //Option of choosing a 1 in all places.
				//Else choose a 0 in the first place for the winning number...
				//These indices tell what i,j,h should become if I pick a digit 0 in teh first place.
				int newI = (x)? 1 : 0;
				int newJ = (y)? 1 : 0;
				int newH = (z)? 1 : 0;
				
				//Choose 0 from each of the first two places. Always possible.
				val += cache[newI][newJ][newH][start+1];
				//1 then 0
				if (x) val += cache[i][newJ][newH][start+1];
				//0 then 1
				if (y) val += cache[newI][j][newH][start+1];
				
				
				/*if (z) {
					if (!x || !y)  val += cache[i][j][1][start+1];
					if (x) val += cache[1][j][1][start+1];
					if (y) val += cache[i][1][1][start+1];
					if (x && y) val += cache[1][1][1][start+1] + cache[i][j][h][start+1];
				} else {
					if (!x || !y) val += cache[i][j][h][start+1];
					if (x) val += cache[1][j][h][start+1];
					if (y) val += cache[i][1][h][start+1];
					if (x && y) val += cache[1][1][h][start+1];
				}*/
				
				
				cache[i][j][h][start] = val;				
			}
		}
		
		/*output("");
		
		for (int start = 30; start >= 25; start--) {
			System.out.println("Last " + (31 - start) + " digits:");
			for (int i=0; i<2; i++) for (int j=0; j<2; j++) for (int h=0; h<2; h++) {
				System.out.print(" " + cache[i][j][h][start]);
			}
			System.out.println();
		}*/
		
		output(cache[0][0][0][0]);
	}
	
	public static long[][][][] cache = new long[2][2][2][32]; //Just reuse the same memory each time...

	public static void main(String[] args) {
		//Initialize the base cases in the cache
		for (int i=0; i<2; i++) for (int j=0; j<2; j++) for (int k=0; k<2; k++) cache[i][j][k][31] = 1;
		new B().run(args);
	}

}

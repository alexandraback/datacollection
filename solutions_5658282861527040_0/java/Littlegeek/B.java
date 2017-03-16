package round1B;
import java.util.*;
import java.io.*;
import java.lang.Math;
public class B {
	static final long POW[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912};
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File(args[0]));
		FileWriter out = new FileWriter(args[0].substring(0, args[0].length()-3) + ".out");
		int T = in.nextInt();
		
		for (int c = 1; c <= T; c++) {
			int A = in.nextInt(), B = in.nextInt(), K = in.nextInt();
			if (K > A || K > B) out.write("Case #" + c + ": " + A * B + "\n");
			else {
				int count = 0;
				for (int a = 0; a < A; a++) 
					for (int b = 0; b < B; b++) {
						if ((a & b) < K) count++;
					}
				out.write("Case #" + c + ": " + count + "\n");
			}
		}
		
		in.close();
		out.close();
	}

}

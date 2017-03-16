import java.io.*;

public class template {
	public static void main(String[] args) throws IOException {		
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		//PrintWriter out = new PrintWriter("output.txt");
		
	
		
		in.nextToken(); int count = (int)in.nval;
		
		for(int c = 1 ; c <= count ; c++) {
			int rotations = 0;
			
			in.nextToken(); int a = (int)in.nval;
			in.nextToken(); int b = (int)in.nval;
			
			/*
			ignore 0
			1 = 0 to 9 
			2 = 10 to 99
			...
			7 = 1 000 000 to 9 999 999
			 */
			int[] min = {0, 0, 10, 100, 1000, 10000, 100000, 1000000};
			int[] max = {0, 9, 99, 999, 9999, 99999, 999999, 9999999};
			// set limits
			for(int i = 1 ; i <= 7 ; i++) {
				min[i] = Math.max(min[i], a);
				max[i] = Math.min(max[i], b);
			}
			
			for(int len = 2 ; len <= 7 ; len++) {
				int exp = (int) Math.pow(10, len-1);
				for(int i = min[len] ; i <= max[len] ; i++) {
					int r = i;
					for(int j = 0 ; j < len-1 ; j++) {
						r = r % exp * 10 + (r/exp);
						if (r == i) break;
						if (r > i && r <= max[len] && i != r) rotations++;
					}
				}
			}
			out.println("Case #" + c + ": " + rotations);
		}
		
		
		out.flush();
		out.close();
	}
}

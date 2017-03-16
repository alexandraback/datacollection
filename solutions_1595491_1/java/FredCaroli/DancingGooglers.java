import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;


public class DancingGooglers {

	private static String in;
	private static String[] ins;
	private static BufferedReader buf;
	private static int cases;
	private static File arquivo = new File("output.txt");
	private static FileOutputStream fos;
	
	
	public static void main(String[] args) {
		buf = new BufferedReader(new InputStreamReader(System.in));
		try {
			fos = new FileOutputStream(arquivo);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			System.exit(0);
		}
		
		try {
			in = buf.readLine();
			cases = Integer.parseInt(in);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
		
		for (int i = 1; i <= cases; i++) {
			int result = 0;
			
			try {
				in = buf.readLine();
				ins = in.split(" ");
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
			
			int N = Integer.parseInt(ins[0]);
			int S = Integer.parseInt(ins[1]);
			int P = Integer.parseInt(ins[2]);
			int[] T = new int[N];
			
			for (int j = 3; j < N+3; j++) {
				T[j-3] = Integer.parseInt(ins[j]);
			}
			
			for (int j = 0; j < N; j++) {
				if (P == 0) {
					result = N;
					break;
				}
				
				else if (P == 1) {
					if (T[j] >= 1){
						result++;
						continue;
					}
				}
				
				else {
					if (T[j] >= 3*P - 2) {
						result++;
						continue;
					}
					

					if ((T[j] >= (3*P) - 4) && (S > 0)) {
						result++;
						S--;
						continue;
					}
					
				}
			}
			
			try {
				String res = "Case #" + i + ": " + result + System.getProperty("line.separator");
				fos.write(res.getBytes());
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
			
		}

	}

}

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Recycled {

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
			
			int A = Integer.parseInt(ins[0]);
			int B = Integer.parseInt(ins[1]);
			
			for (int numb = A; numb <= B; numb++) {
				result += reciclar(numb, A, B);
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
	
	
	
	public static int reciclar(int numb, int A, int B) {
		int result = 0;
		ArrayList<Integer> usados = new ArrayList<Integer>();
		char[] numbvec = String.valueOf(numb).toCharArray();
		
		
		for (int i = 1; i < numbvec.length; i++) {
			String rot = new String();
			for (int j = i; j < numbvec.length + i; j++) {
				if (j >= numbvec.length) {
					rot += numbvec[j-numbvec.length];
				}
				else {
					rot += numbvec[j];
				}
			}
			int numbrot = Integer.parseInt(rot);
			
			
			if (numbrot >= A && numbrot <= B && numb != numbrot && !usados.contains(numbrot)) {
				if (numb < numbrot){
					result++;
					usados.add(numbrot);
					System.out.println("(" + numb + "),(" +numbrot+ ")");
				}
			}
		}

		return result;
	}

}

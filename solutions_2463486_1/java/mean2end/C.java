import java.io.*;


public class C {
	public static void main(String[] args) {
		try {
			String filename = "C-large-1.in.txt";
			BufferedReader br = new BufferedReader(new FileReader(filename));
			String outname = filename.replace(".in.", ".out.");
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(outname)));
			int T = Integer.parseInt(br.readLine());
			for (int t = 1; t <= T; t++) {
				String nm = br.readLine();
				long N = Long.parseLong(nm.split(" ")[0]);
				long M = Long.parseLong(nm.split(" ")[1]);
				findFS(pw, t, N, M);
			}
			br.close();
			pw.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static boolean isP(long n) {
		String num = String.valueOf(n);
		boolean P = true;
		for (int j = 0; j < num.length()/2; j++)
			if (num.charAt(j) != num.charAt((num.length()-j-1))) {
				P = false;
				break;
			}
		if (P) return true;
		else return false;
	}
	
	public static void findFS(PrintWriter pw, int t, long A, long B) {
		int count = 0;
		for (long i = (long)Math.ceil(Math.sqrt(A)); i <= (long)Math.floor(Math.sqrt(B)); i++) {
			if (!isP(i)) continue;
			if (isP(i*i)) count++;
		}
		pw.println("Case #" + t + ": " + count);
	}
	
}

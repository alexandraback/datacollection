import java.io.*;

public class PartElf {
	private BufferedReader br;
	private PrintWriter out;
	
	public PartElf(String filename) throws IOException {
		br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(filename))));
		out = new PrintWriter(new PrintStream(new File(filename.replace(".in", ".out"))));
	}
	
	void solveMultiCase() throws IOException {
		int testCases = Integer.parseInt(br.readLine());
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneCase();
		}
		out.close();
	}

	void solveOneCase() throws IOException {
		String s = br.readLine();
		int a = Integer.parseInt(s.split("/")[0]);
		int b = Integer.parseInt(s.split("/")[1]);
		int k = satisfy(a, b, 0);
		if(k > 40) out.println("impossible");
		else out.println(min(a, b));
	}
	
	int min(int a, int b){
		int num = 0;
		while(a < b) {
			a = a*2;
			num++;
		}
		return num;
	}
	
	int satisfy(int a, int b, int num) {
		while(a < b) {
			a = a*2;
			num++;
			if(num > 40) return 41;
		}
		a = a-b;
		if(a == 0) return num;
		else return satisfy(a, b, num);
 	}
	
	public static void main(String[] args) throws IOException {
		PartElf template = new PartElf("A-small-attempt0.in");
		template.solveMultiCase();
	}
}

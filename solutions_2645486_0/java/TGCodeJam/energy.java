import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class energy {
	
	private static int gain;

	public static void main(String[] args) {
		
		try {
		Scanner sc = new Scanner(new FileReader("f:\\bb.in"));
        PrintWriter pw = new PrintWriter("f:/output.txt");		
        
	        int n = sc.nextInt();
	        sc.nextLine();
	        for (int c=0; c<n; c++) {
	            System.out.println("Test case " + (c+1) + "...");
	            pw.print("Case #" + (c+1) + ": ");
	            test(sc, pw);
	            pw.println();
	        }
	        pw.flush();
	        pw.close();
	        sc.close();  
	        System.out.println("done");
	        
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void test(Scanner sc, PrintWriter pw) {
		
		int E = sc.nextInt();
		int R = sc.nextInt();
		int N = sc.nextInt();
		sc.nextLine();
		int[]v = new int[N];
		
		for(int i = 0;i<N;i++)
			v[i]=sc.nextInt();
		
		
		for(int i = 0;i<=E;i++)
		{
			loop(E, E-i, R, 0, v, 0);
		}
				
		pw.print(gain);
		gain = 0;
		
	}

	private static void loop(int max, int E, int R, int N, int[] v, int g) {
		
		int thisgain = 0;
		
		if(N == v.length-1)
		{
			thisgain = v[N]*E;
			g+=thisgain;
			if(g>gain)
				gain = g;
		}
		else {
			
			for(int i = 0 ;i<=E;i++)
			{
				thisgain = v[N]*i;
				int e = Math.min(max, E-i+R);
				loop(max, e, R, N+1, v, g+thisgain);
			}
		}
		
	}
	

}

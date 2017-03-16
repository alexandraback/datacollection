import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class circle {

	public static void main(String[] args) {
		
		try {
		Scanner sc = new Scanner(new FileReader("f:\\aa.in"));
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
		
		long r = sc.nextLong();
		long t = sc.nextLong();
		
		long count = 0;
		long nextc = 2*r+1;
		
		while(t >= nextc)
		{
			count++;
			t-=nextc;
			nextc = 2*(r+count*2)+1;//(long) (Math.pow(r+(count+1)*2-1,2) - Math.pow(r+count*2,2));
			
		}
		
		pw.print(count);
		
	}
	
	
	

}

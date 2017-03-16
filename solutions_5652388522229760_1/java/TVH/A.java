import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		PrintWriter out = new PrintWriter(new File("A.out"));
		
		for(int t = 1; t<=T;t++){
		long n = in.nextInt();
		int seen = 0;
		int i = 0;
		if(n==0){
			out.printf("Case #%d: INSOMNIA\n",t);
			continue;
		}
		while(seen!=(1<<10)-1){
			String num = ++i*n+"";
			for(char c : num.toCharArray()){
				seen|=1<<Integer.parseInt(""+c);
			}
		}
		out.printf("Case #%d: %d\n",t,i*n);
		}
		//System.out.println("WOW");
		//System.out.println(max);
		out.close();
	}

}

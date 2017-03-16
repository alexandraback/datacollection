import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class fsquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("problem3_i.txt"));
		PrintWriter printer=new PrintWriter("problem3.txt");
		int T=Integer.parseInt(buf.readLine());
		for(int i=1;i<T+1;i++){
			
			String[] s=buf.readLine().split(" ");
			int a=Integer.parseInt(s[0]);
			int b=Integer.parseInt(s[1]);
			int c=0;
			for(int j=a;j<=b;j++)
				if(isPal(j)&&Math.sqrt(j)==Math.round(Math.sqrt(j))&&isPal(Math.sqrt(j)))
					c++;
			printer.println("Case #"+i+": "+c);
		}
		printer.close();
	}
	public static boolean isPal(double j){
		int a=(int)j;
		String p=a+"";
		for(int i=0;i<=p.length()/2;i++)
			if(p.charAt(i)!=p.charAt(p.length()-i-1))
				return false;
		return true;
	}

}

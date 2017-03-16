import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class PartElf {


	public static void main(String[] args) throws IOException {

		Scanner scanner = new Scanner(new File("A-small-attempt1.in"));
		int result1 = 0;
		int caseCounter = 0;
		int i=0;
		int p, q, size, a, tmp;
		String s;
		boolean d=true;
		caseCounter = scanner.nextInt();		
		BufferedWriter out = new BufferedWriter(new FileWriter("result2.out"));
		
		for(i=0;i<caseCounter;i++){
			
			d=true;
			result1 = 1;
			s=scanner.next();
			size = s.length();
			a=s.indexOf("/");
			p=Integer.parseInt(s.substring(0, a));
			q=Integer.parseInt(s.substring(a+1, size));
			
			tmp=q;
			while(tmp%2==0){
				tmp = tmp /2;
			}
			if(tmp != 1)
				d=false;
			
			while(d && q%2==0 && q/2>p){
				result1++;
				q=q/2;
					
			}
			
			
			if(!d){
				
				out.write("Case #" + (i+1) + ": " + "impossible");
			}else{
			out.write("Case #" + (i+1) + ": " + result1);
			}
			out.newLine();
		}
		
		out.close();
			
		
	}

}

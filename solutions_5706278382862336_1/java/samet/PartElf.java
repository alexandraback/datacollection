import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;



public class PartElf {


	public static void main(String[] args) throws IOException {

		Scanner scanner = new Scanner(new File("A-large.in"));
		int result1 = 0;
		int caseCounter = 0;
		int i=0;
		long p,q,gcm;
		int size, a, tmp;
		String s;
		boolean d=true;
		caseCounter = scanner.nextInt();		
		BufferedWriter out = new BufferedWriter(new FileWriter("result4.out"));
		Set<Long> set = new TreeSet<Long>();
		long dd = 2;
		for(i=0;i<40;i++){
			set.add(dd);
			dd = dd*2;
					
		}
		
		
		for(i=0;i<caseCounter;i++){
			
			d=true;
			result1 = 1;
			s=scanner.next();
			size = s.length();
			a=s.indexOf("/");
			p=Long.parseLong(s.substring(0, a));
			q=Long.parseLong(s.substring(a+1, size));
			
//			tmp=q;
//			while(tmp%2==0){
//				tmp = tmp /2;
//			}
//			if(tmp != 1)
//				d=false;
//			
			gcm =gcm(p,q);
			p=p/gcm;
			q=q/gcm;
			
			d=set.contains(q);
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
	
	public static long gcm(long a, long b) {
	    return b == 0 ? a : gcm(b, a % b); // Not bad for one line of code :)
	}


}

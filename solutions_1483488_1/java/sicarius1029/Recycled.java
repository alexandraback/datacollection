import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

public class Recycled {

	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new File("recycled.in"));
		System.setOut(new PrintStream(new File("recycled.out")));
		int T = sc.nextInt();
		HashSet<String> p;
		int A,B;
		String sA,sB,sN;
		for(int set=1; set<=T; set++){
			A = sc.nextInt();
			B = Integer.parseInt(sB = sc.next());
			char max = sB.charAt(0);
			p = new HashSet<String>((B-A)*4,.99f);
			for(int n=A; n<B+1; n++){
				sN = n+"";
				int size = sN.length();
				for(int j = 1; j<size; j++){
					if(sN.charAt(j)>max)
						continue;
					String sM = sN.substring(j)+sN.substring(0,j);
					int m = Integer.parseInt(sM);
					if(A-m<1 && m-B<1 && n!=m){
						int small, large;
						if(n<m){
							small = n; large = m;
						}
						else{
							small = m; large = n;
						}
						p.add(small+" "+large);
					}
						
				}
			}
			System.out.println("Case #"+set+": "+p.size());
		}
	}

}
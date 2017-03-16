import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;


public class B {
	public static void main(String ... args) throws Exception{
		Scanner in = new Scanner(new File("C-small-attempt0.in"));
		PrintStream out = new PrintStream(new File("C-small-attempt0.out"));
		
		
		int T = in.nextInt();
		in.nextLine();
		
		for(int t=0;t<T;t++){
			int A = in.nextInt();
			int B = in.nextInt();
			HashSet<String> set = new HashSet<String>();
			int found=0;
			for(int n=A;n<=B;n++){
				int high=(int)Math.log10(B);
				String orgNumber = new Integer(n).toString();
				do{
					String num = orgNumber;
					for(int i=0;i<num.length();i++){
						num = num.substring(num.length()-1) + num.substring(0,num.length()-1);
						int intNum = Integer.parseInt(num);
						if(intNum>n && intNum<=B && !set.contains(n+" "+intNum)){
							//System.out.println(n + " " + intNum);
							found++;
							set.add(n+" "+intNum);
						}
						
					}
					
					orgNumber = "0" + orgNumber;
				}while(orgNumber.length()<=high);
				
			}
			out.println("Case #" + (t+1) + ": " + found);
		}
		
		
	}
}

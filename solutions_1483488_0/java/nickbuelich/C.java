import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
public class C {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		int N = Integer.parseInt(sc.nextLine());
		for(int i=1;i<=N;i++){
			HashSet<String> HS = new HashSet<String>();
			int A = sc.nextInt();
			int B = sc.nextInt();
			for(int a=A;a<=B;a++){
				String x = a+"";
				for(int b=1;b<x.length();b++){
					String temp = x.substring(b)+x.substring(0,b);
					if(temp.charAt(0)=='0')continue;
					int other = Integer.parseInt(temp);
					if(other>=A&&other<=B&&other!=a){
						HS.add(x+" "+temp);
					}
				}
			}
			out.println("Case #"+i+": "+(HS.size()>>1));
		}
		out.close();
	}
}

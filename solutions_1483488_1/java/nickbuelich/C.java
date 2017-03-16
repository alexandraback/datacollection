import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
public class C {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("C.in"));
		long tt = System.currentTimeMillis();
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		HashSet<String> HS = new HashSet<String>();
		LinkedList<obj> LL = new LinkedList<obj>();
		int N = 1;
		
		for(int i=1;i<=N;i++){
			
			int A = 1;
			int B = 2000000;
			for(int a=A;a<=B;a++){
				String x = a+"";
				for(int b=1;b<x.length();b++){
					String temp = x.substring(b)+x.substring(0,b);
					if(temp.charAt(0)=='0')continue;
					int other = Integer.parseInt(temp);
					if(other>a&&other>=A&&other<=B){
						if(HS.contains(x+" "+temp))continue;
						HS.add(x+" "+temp);
						LL.add(new obj(a,other));
					}
				}
			}
		}
		//System.out.println(HS.size());
		N = sc.nextInt();
		for(int i=1;i<=N;i++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			int total = 0;
			for(obj x : LL){
				
				int T1 = x.x;
				int T2 = x.y;
				if(A<=T1&&T1<=B&&A<=T2&&T2<=B){
					total++;
				}
				//System.out.println(total);
			}
			out.println("Case #"+i+": "+total);
			//System.out.println("Case #"+i+": "+total);
		}
		out.close();
		//System.out.println(System.currentTimeMillis()-tt);
	}
	static class obj{
		int x; 
		int y;
		obj(int a, int b){
			x=a;
			y=b;
		}
	}
}

import java.util.*;
import java.io.*;
import java.text.*;

public class Q {
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input2.txt"));
		PrintStream out = new PrintStream("output.txt");
		
		int num = in.nextInt();
		in.nextLine();
		int[] as = new int[1001];
		int[] bs = new int[1001];
		for (int i=0;i<num;++i) {
			int n = in.nextInt();
			for (int j=0;j<n;++j){
				as[j]=in.nextInt();
				bs[j]=in.nextInt();
			}
			int[] fs=new int[1001];//0, not touched; 1: pass1; 2: pass2
			int k=0;
			int current=0;
			int res=0;
			while(true){
				int pos=-1, r=-1;
				for (int j=0;j<n;++j) {
					if (fs[j] ==2)continue;
					if (current>=bs[j]) {
						current+=2-fs[j];
						fs[j]=2;
						res++;
						pos=j;
						r=-1;
						break;
					} else if (current>=as[j] && fs[j] == 0 && bs[j] > r) {
						pos=j;
						r=bs[j];
					}
				}
				if (pos==-1)break;
				else if (r!=-1) {
					fs[pos]=1;
					current++;
					res++;
				}
			}
			for (int j=0;j<n;++j)if (fs[j]!=2)res=-1;

			StringBuilder builder = new StringBuilder("Case #" +(i+1)+": ");			
			builder.append(res>0?""+res : "Too Bad");
			System.out.println(builder.toString());
			out.println(builder.toString());
		}
		
		in.close();
		out.close();
	}	
}

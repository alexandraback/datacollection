import java.io.*;
import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Math.*;
public class CodeJamC {
	public static void main(String args[]) throws Throwable {
		System.setOut(new PrintStream("C-Large.out"));
		BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		for (int t=0,T=parseInt(in.readLine().trim());t++<T;) {
			StringTokenizer st=new StringTokenizer(in.readLine());
			int A=parseInt(st.nextToken()),B=parseInt(st.nextToken());
			TreeSet<int[]> set=new TreeSet<int[]>(new Comparator<int[]>() {
				public int compare(int[] o1, int[] o2) {
					return o1[0]!=o2[0]?o1[0]-o2[0]:o1[1]-o2[1];
				}
			});
			for(int i=A;i<=B;i++){
				String a=i+"";
				for(int j=a.length()-1;j>0;j--){
					int b=parseInt(a.substring(j)+a.substring(0,j));
					if(i!=b&&b>=A&&b<=B&&(b+"").length()==a.length()){
						set.add(new int[]{min(i,b),max(i,b)});
					}
				}
			}
			sb.append("Case #"+t+": "+set.size()+"\n");
		}
		System.out.print(new String(sb));
	}
}
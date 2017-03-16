import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class C {
	public static ArrayList[] leftAr, rightAr;
	public static boolean[] used;
	public static int[] mt;
	
	public static boolean try_kuhn (int v) {
		if (used[v])  return false;
		used[v] = true;
		for (int i=0; i<leftAr[v].size(); ++i) {
			int to = (int) leftAr[v].get(i);
			if (mt[to] == -1 || try_kuhn (mt[to])) {
				mt[to] = v;
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new File("C-large.txt"));
		int T = in.nextInt();
		in.nextLine();
		for (int t =0; t<T; t++){
			int n  = in.nextInt();
			in.nextLine();
			leftAr= new ArrayList[1000]; 
			rightAr = new ArrayList[1000];
			for (int j = 0; j<1000; j++){
				leftAr[j] = new ArrayList();
				rightAr[j] = new ArrayList();
			}
			String[] left = new String[1000], right = new String[1000];
			int l =0, r=0;
			for (int k = 0; k<n; k++){
				String s = in.nextLine();
				int d = s.indexOf(' ');
				String s1 = s.substring(0, d);
				String s2 = s.substring(d+1, s.length());
				boolean q = false;
				int lind=0, rind=0;
				for (int i=0; i<l; i++){
					if (s1.equals(left[i])){
						q =true;
						lind = i;
						break;
					}
				}
				if (!q){
					lind = l;
					l++;
					left[lind]=s1;
				}
				q = false;
				for (int i=0; i<r; i++){
					if (s2.equals(right[i])){
						q =true;
						rind = i;
						break;
					}
				}
				if (!q){
					rind = r;
					r++;
					right[rind]=s2;
				}
				leftAr[lind].add(rind);
				rightAr[rind].add(lind);				
				
			}
			mt = new int[r];
			used = new boolean[l];
			for (int i =0; i<mt.length; i++){
				mt[i]=-1;
			}
			int trAr = 0;
			for (int v=0; v<l; ++v) {
				used= new boolean[l];
				if (try_kuhn (v)){
					trAr++;
				}
			}
			
			out.print("Case #"+(t+1)+": ");
			out.println(n-r-l+trAr);
			
		}
		out.close();
	}
}

import java.io.*;
import java.util.*;
import java.math.*;

public class codejam{
	
	static String i0 = "dummy.in";
	static String o0 = "dummy.out";
	
	static String i1 = "small.in";
	static String o1 = "small.out";
	
	static String i2 = "large.in";
	static String o2 = "large.out";
	
	public static void main(String[] args) throws Exception{
		
		Scanner r = null;
		BufferedWriter w = null;
		
		r = new Scanner(new FileReader(i0));
		w = new BufferedWriter(new FileWriter(new File(o0)));

		
		int t = r.nextInt();
		for (int i=0;i<t;i++){
			System.out.println("Case #"+(i+1)+"--------------");
			
			long result = 0;
			
			w.write("Case #"+(i+1)+": ");
			
			int k = r.nextInt();
			int c = r.nextInt();
			int s = r.nextInt();
			
			int n = 0;
			if (k%c == 0)
				if (s < k/c){
					w.write("IMPOSSIBLE\n");
					continue;
				}
				else
					n = k/c;
			else
				if (s < k/c+1){
					w.write("IMPOSSIBLE\n");
					continue;
				}
				else
					n = k/c+1;
			
			System.out.println(n);
			long _n = 0;
			int _c = 0;
			for (int j=0;j<n;j++){
				_n = 0;
				for (int l=0;l<c;l++){
					if (_c == k)
						_n *= k;
					else{
						_n = _n*k + _c;
						_c++;
					}
				}
				if (j == n-1)
					w.write(String.valueOf(_n+1));
				else
					w.write(String.valueOf(_n+1)+" ");
			}
			
			//w.write(String.valueOf(tmp));
			w.write("\n");
		}
		w.close();
	}
}



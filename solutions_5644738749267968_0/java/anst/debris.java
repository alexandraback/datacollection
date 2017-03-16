import static java.lang.System.*;import static java.lang.Math.*;import static java.lang.Character.*;import java.io.*;import java.text.*;import java.util.*;import java.util.regex.*;import java.math.*;
public class debris {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("debris.dat"));
		int dS = Integer.parseInt(sc.nextLine());
		for (int xxy = 0; xxy < dS; xxy++) {
			int x = Integer.parseInt(sc.nextLine());
			ArrayList<Double> n = new ArrayList<Double>();
			ArrayList<Double> k = new ArrayList<Double>();
			
			String[] nn = sc.nextLine().split("\\s+");
			String[] kk = sc.nextLine().split("\\s+");

			for(String nnn:nn) n.add(Double.parseDouble(nnn));
			for(String kkk:kk) k.add(Double.parseDouble(kkk));

			Collections.sort(n);
			Collections.reverse(n);
			Collections.sort(k);
			Collections.reverse(k);

			int sN = 0;
			for(int a = 0,b=0; a<n.size()&&b<k.size();) {
				if(n.get(a)>k.get(b)) {
					a++; sN++;
				}
				b++;
			}
			int sK = 0;
			for(int a = 0,b=0; a<k.size()&&b<n.size();) {
				if(k.get(a)>n.get(b)) {
					a++; sK++;
				}
				b++;
			}
			sK = x-sK;

			System.out.println("Case #"+(xxy+1)+": "+sN+" "+sK);
		} 
	}

}
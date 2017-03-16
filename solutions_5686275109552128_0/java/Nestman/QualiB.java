package gcj2015;

import java.io.*;
import java.util.*;

public class QualiB {
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
		//Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/B-small-attempt0.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/qualiB.txt");
		
		int res,rep,i,j,d,ans,tall,l,r,mid;
		ArrayList<Integer> p1 = new ArrayList<Integer>();
		
		
		res = sc.nextInt();
		for(rep=1;rep<=res;rep++){
			
			p1 = new ArrayList<Integer>();
			d = sc.nextInt();
			for(i=0;i<d;i++)
				p1.add(sc.nextInt());
			
			Collections.sort(p1);
			Integer p[] = new Integer[1001];
			p = p1.toArray(p);
			
			tall = p[p1.size()-1];
			ans = tall;
			for(i=1;i<tall;i++) {
				
				l = 0; r = tall; 
				
				while (r-l>1) {
					mid = (l+r) / 2;
					if (check(p1,mid,i)) r = mid;
					else l = mid;
				}
				
				ans = Math.min(ans,i+r);
			}
			
			System.out.printf("Case #%d: %d\n",rep,ans);
			ou.printf("Case #%d: %d\n",rep,ans);
		}
		
		ou.close();
	}
	
	public static boolean check(ArrayList<Integer> p1, int h, int sl) {
		int i , cuts = 0;
		
		i = p1.size() - 1;
		while ((i>=0) && (p1.get(i)>h)) {
			
			cuts += (int) Math.ceil(((double) (p1.get(i) - h)) / ((double) h));
			if (cuts>sl) return false;
			i--;
		}
		
		return true;
	}
}

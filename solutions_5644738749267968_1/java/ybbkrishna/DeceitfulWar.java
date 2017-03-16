import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int j=0;j<n;j++) {
			List<Double> p1 = new ArrayList<Double>();
			List<Double> p2 = new ArrayList<Double>();
			int chances = sc.nextInt();
			for(int i=0;i<chances;i++) {
				p1.add(sc.nextDouble());
			}
			for(int i=0;i<chances;i++) {
				p2.add(sc.nextDouble());
			}
			Collections.sort(p1);
			Collections.sort(p2);
			System.out.println("Case #"+(int)(j+1)+": "+cheat(p1, p2)+" "+opt(p1, p2));
		}
	}
	public static int cheat(List<Double> p1,List<Double> p2) {
		int count =0,j=0,k=p1.size()-1;
		int len =p1.size();
		for(int i=0;i<p1.size();i++) {
			if(p1.get(i)>p2.get(j)) {
				count++;
				j++;
			}
			else {
				k--;
			}
		}
		return count;
	}
	public static int opt(List<Double> p1,List<Double> p2) {
		//System.out.println(p1);
		//System.out.println(p2);
		int count =0,j=0,k=p1.size()-1;
		for(int i=p1.size()-1;i>=0;i--) {
			if(p1.get(i)>p2.get(k)) {
				count++;
			}
			else {
				j++;
				k--;
			}
		}
		return count;
	}
}

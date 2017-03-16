import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;


public class G {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 1 ; i <= t; i++) {
			int n = sc.nextInt();
			SortedMap<Integer, ArrayList<Integer>> map = new TreeMap<Integer, ArrayList<Integer>>(); 
			for (int j = 0 ; j < n; j++){
				int di = sc.nextInt();
				int ni = sc.nextInt();
				int wi = sc.nextInt();
				int ei = sc.nextInt();
				int si = sc.nextInt();
				int ddi = sc.nextInt();
				int dpi = sc.nextInt();
				int dsi = sc.nextInt();
				for (int k = 0; k < ni; k++){
					int newd = (di + (k * ddi));
					if (!map.containsKey(newd)) {
						map.put(newd, new ArrayList<Integer>());
					}
					ArrayList<Integer> al = map.get(newd);
					al.add(wi + (k * dpi));
					al.add(ei + (k * dpi));
					al.add(si + (k * dsi));
					map.put(newd, al);
				}
			}
			HashMap<Integer, Integer> height = new HashMap<Integer, Integer>();
			int count = 0;
			for (int j: map.keySet()){
				ArrayList<Integer> al = map.get(j);
				HashMap<Integer, Integer> newheight = (HashMap<Integer, Integer>) height.clone();
//				System.out.println("Day "+j);
				for (int k = 0 ; k < al.size(); k += 3) {
//					System.out.println("Attack " + al.get(k) + " "+ al.get(k+1) + " "+ al.get(k+2));
					boolean fail = false;
					for (int h = al.get(k) * 2; h <= al.get(k+1) * 2; h++) {
						if ((!height.containsKey(h)) || (height.get(h) < al.get(k+2))) {
							fail = true;
							newheight.put(h, al.get(k+2));
						}
					}
					if (fail) {
//						System.out.println("Succeeded");
						count += 1;
					}
				}
				height = newheight;
			}
			System.out.println("Case #" + i + ": " + count);
		}
	}

}

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
public class HikingDeer {

	static final String filename = "C-small-1-attempt1.in";

	static Scanner seer;
	static int T;
	static int n;
	static int i;
	static ArrayList<int[]> hlist; //hikerlist
	
	static ArrayList<Double> plist; //pointlist

	public static void main(String[] args) throws FileNotFoundException {
		//seer = new Scanner(System.in);
		seer = new Scanner(new File(filename));
		T = seer.nextInt();
		for(i = 0; i < T; i++){
			n = seer.nextInt();
			hlist = new ArrayList<int[]>();
			plist = new ArrayList<Double>();
			for(int g = 0; g < n; g++){
				int start = seer.nextInt();
				int nh = seer.nextInt();
				int t = seer.nextInt(); //time that takes
				for(int h = 0; h < nh; h++){
					int[] hiker = {start,t+h};
					double point = hiker[1]*(360.0 - start)/360.0;
					plist.add( point );
					plist.add( point + hiker[1] );
					hlist.add(hiker);
				}
			}
			System.out.printf("Case #%d: %d\n",i+1,hike());
		}
	}
	private static int hike() {
		if(plist.size() < 3)
			return 0;
		
		if(plist.get(2) >= plist.get(1))
			return 1;
		
		if(plist.get(0) >= plist.get(3))
			return 1;
		
		return 0;
		
	}

}

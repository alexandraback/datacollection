import java.util.*;
import java.io.*;

public class wall {

	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new File("wall.in"));
		FileWriter fStream = new FileWriter("wall.out");
		BufferedWriter out = new BufferedWriter(fStream);

		int numCases = in.nextInt();
		in.nextLine();

		for(int zCase = 1; zCase <= numCases; zCase++){
			int nTribes = in.nextInt();
			ArrayList<Tribe> tribes = new ArrayList<Tribe>();
			for(int a = 0; a < nTribes; a++){
				tribes.add(new Tribe(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt()));
		//		System.out.println(tribes.get(tribes.size() - 1));
			}
			ArrayList<Integer> wallVals = new ArrayList<Integer>();
			ArrayList<Double> wallPoints = new ArrayList<Double>();

			int losses = 0;
			while(tribesLeft(tribes)){
				int nSkip = numSkippable(tribes);
				ArrayList<Integer> oldWallVals = cloneAL(wallVals);
				ArrayList<Double> oldWallPoints = cloneAL2(wallPoints);

				for(Tribe t : tribes){
					if(t.n == 0) continue;
					boolean loss = false;
					if(t.d == 0){
					//	System.out.println("--");
						for(double loc = t.w; loc <= t.e; loc+= .5){
							if(dblIndex(wallPoints, loc) != -1){
								wallVals.set(dblIndex(wallPoints, loc), Math.max(wallVals.get(dblIndex(wallPoints, loc)), t.s));
							} else {
								wallPoints.add(loc);
								wallVals.add(t.s);
							}
							if(dblIndex(oldWallPoints, loc) != -1){
								if(oldWallVals.get(dblIndex(oldWallPoints, loc)) < t.s){
							//		System.out.println("Loss: " + loc + ", " + t.s + ".");
									loss = true;
								}
							} else {
						//		System.out.println("Loss: " + loc + ", " + t.s);
								loss = true;
							}
						}
						if(loss) losses++;

						t.n--;
						t.d = t.delta_d;
						t.s += t.delta_s;
						t.w += t.delta_p;
						t.e += t.delta_p;
					}
					t.d-= nSkip;
				}
			}


			String lineOut = "Case #" + zCase + ": " + losses;
			System.out.println(lineOut);
			out.write(lineOut + "\n");

		}


		out.close();
		fStream.close();
		in.close();
	}
	public static boolean tribesLeft(ArrayList<Tribe> tribes){
		for(Tribe t : tribes) if(t.n > 0) return true;
		return false;
	}
	public static ArrayList<Integer> cloneAL(ArrayList<Integer> arr){
		ArrayList<Integer> res = new ArrayList<Integer>();
		for(Integer a : arr){
			int b = a;
			res.add(b);
		}
		return res;
	}
		public static ArrayList<Double> cloneAL2(ArrayList<Double> arr){
		ArrayList<Double> res = new ArrayList<Double>();
		for(Double a : arr){
			double b = a;
			res.add(b);
		}
		return res;
	}
	public static int dblIndex(ArrayList<Double> arr, double val){
		for(int a = 0; a < arr.size(); a++){
			if(Math.abs(arr.get(a) - val) < .1) return a;
		}
		return -1;
	}
	public static int intIndex(ArrayList<Integer> arr, int val){
		for(int a = 0; a < arr.size(); a++){
			if(Math.abs(arr.get(a) - val) == 0) return a;
		}
		return -1;
	}
	public static int numSkippable(ArrayList<Tribe> tribes){
		int min = tribes.get(0).d;
		for(int a = 1; a < tribes.size(); a++){
			min = Math.min(min, tribes.get(a).d);
		}
		return Math.max(min - 1, 1);
	}
}
class Tribe{
	public int d = 0;
	public int n = 0;
	public int w = 0;
	public int e = 0;
	public int s = 0;
	public int delta_d = 0;
	public int delta_p = 0;
	public int delta_s = 0;
	public Tribe(int _d, int _n, int _w, int _e, int _s, int _delta_d, int _delta_p, int _delta_s){
		d = _d;
		n = _n;
		w = _w;
		e = _e;
		s = _s;
		delta_d = _delta_d;
		delta_p = _delta_p;
		delta_s = _delta_s;
	}
	public String toString(){
		return d + " " + n + " " + w + " " + e + " " + s + " " + delta_d + " " + delta_p + " " + delta_s;
	}
}
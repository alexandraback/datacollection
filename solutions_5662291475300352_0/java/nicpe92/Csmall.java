import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;


public class Csmall {


public static void main(String[] args) throws Exception{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(in.readLine());
	for (int cas = 1; cas <=T; cas++) {
		int N = Integer.parseInt(in.readLine());
		ArrayList<Integer> initialP = new ArrayList<Integer>();
		ArrayList<Integer> speed = new ArrayList<Integer>();
		int slowest = -1;
		int slowestS = -1;
		for (int i = 0; i < N; i++) {
			String[] spl = in.readLine().split(" ");
			int D = Integer.parseInt(spl[0]);
			int H = Integer.parseInt(spl[1]);
			int M = Integer.parseInt(spl[2]);
			for (int j = 0; j < H; j++) {
				initialP.add(D);
				speed.add(M+j);
			}
			if(M+H-1 > slowestS)
			{
				slowestS = M;
				slowest = initialP.size()-1;
			}
		}
		double timeR = ((360-initialP.get(slowest))/360.0)*slowestS;
		boolean can0 = true;
		for (int i = 0; i < initialP.size(); i++) {
			if(i!=slowest)
			{
				double place = initialP.get(i) + timeR*360/speed.get(i);
				if(place>= 720)
					can0 = false;
			}
		}
		int ans = can0? 0:1;
		System.out.println("Case #"+cas+": "+ans);
	}
}

}

import java.util.*;
import java.io.*;

public class Osmos {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int cases = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<= cases; i++){
			st = new StringTokenizer(in.readLine());
			int armin = Integer.parseInt(st.nextToken());
			int others = Integer.parseInt(st.nextToken());
			ArrayList<Integer> motes = new ArrayList<Integer>();
			st = new StringTokenizer(in.readLine());
			for(int n=0; n < others; n++){
				motes.add(Integer.parseInt(st.nextToken()));
			}
			Collections.sort(motes);
			
			int minMove = others;
			
			for(int n=0; n < others; n++){
				int moves = n + minAdditions(armin, motes);
				if(moves < minMove)
					minMove = moves;
				motes.remove(motes.size() - 1);
			}
			
			out.println("Case #" + i + ": " + minMove);
		}
		
		out.close();
	}
	
	public static int minAdditions(int armin, ArrayList<Integer> motes){
		if(armin == 1) return 100000000;
		int additions = 0;
		for(Integer myMote: motes){
			while(armin <= myMote){
				armin += armin - 1;
				additions++;
			}
			armin += myMote;
		}
		return additions;
	}
}

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class KingdomRush {
		
	public static void main(String[] args) throws NumberFormatException, IOException {				
		FileInputStream inFile = new FileInputStream(new File("resources/codejam/KingdomRush.in"));			
		DataInputStream in = new DataInputStream(inFile);

		FileOutputStream outFile = new FileOutputStream(new File("resources/codejam/KingdomRush.out"));
		DataOutputStream out = new DataOutputStream(outFile);

		int cases = Integer.parseInt(in.readLine());
		
		for(int i=0;i<cases;i++) {
			doCase(i+1, in, out);
			if(i != cases - 1) {
				out.writeBytes("\n");
			}
		}
	}

	private static void doCase(int caseNo, DataInputStream in, DataOutputStream out) throws IOException {
		StringBuilder sb = new StringBuilder();
		sb.append("Case #");
		sb.append(caseNo);
		sb.append(": ");
		
		int levels = Integer.parseInt(in.readLine());
		ArrayList<Level> levelList = new ArrayList<Level>(levels);
		
		for(int i = 0; i < levels; i++) {
			String[] parts = in.readLine().split(" ");
			int firstStar = Integer.parseInt(parts[0]);
			int secondStar = Integer.parseInt(parts[1]);
			Level l = new Level();
			l.first = firstStar;
			l.second = secondStar;	
			levelList.add(l);
		}
		
		int completed = 0;
		int finished = 0;
		int stars = 0;
		
		
		while(true) {
			Level chosen = null;
			int target = -1;
			for(Level l : levelList) {			
				if(l.second <= stars) {
					if(l.claimed != 2) {
						//best case
						chosen = l;
						target = 2;					
						break;
					}
				}
				if(l.first <= stars) {
					if(l.claimed == 0 ) {
						if(chosen != null && chosen.second > l.second) {
							continue;
						}
						chosen = l;
						target = 1;
					}
				}
			}
			if(chosen == null) {
				//fail			
				break;
			} else {
				int claim = 0;
				completed++;
				if(target == 1) {					
					claim = 1;
				} else {					
					claim = 2 - chosen.claimed;
					finished++;					
					if(finished == levels) {						
						break;
					}
				}
				
				stars += claim;
				chosen.claimed += claim;
			}
		}
		if(finished == levels) {
			sb.append(completed);
		} else {
			sb.append("Too Bad");
		}
		
		out.writeBytes(sb.toString());
	}
	
	private static class Level {
		public int first;
		public int second;
		public int claimed = 0;
	}
}

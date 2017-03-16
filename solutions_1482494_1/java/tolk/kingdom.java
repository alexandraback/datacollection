import java.io.*;
import java.util.*;

class kingdom {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("kingdom.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("kingdom.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			int levels = Integer.parseInt(br.readLine());
			boolean[] levelsdone = new boolean[levels];
			boolean[] levelsdone1star = new boolean[levels];
			int[][] levelreqs = new int[levels][2];
			boolean haszero = false;
			int levelzero = -1;
			int levelzeromax = -1;
			int levelzero2star = -1;
			for (int j = 0; j < levels; j++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				levelreqs[j][0] = Integer.parseInt(st.nextToken());
				levelreqs[j][1] = Integer.parseInt(st.nextToken());
				if (levelreqs[j][1] == 0) {
					levelzero2star = j;
					haszero = true;
				} else if (levelreqs[j][0] == 0 && levelzeromax < levelreqs[j][1]) {
					levelzeromax = levelreqs[j][1];
					levelzero = j;
					haszero = true;
				}
				if (levelreqs[j][1] > 2*levels) {
					haszero = false;
				}
			}
			if (!haszero) {
				out.println("Case #" + (i+1) + ": Too Bad");
				continue;
			}
			int answer = 0;
			int numstars = 0;
			if (levelzero2star != -1) {
				int first = levelzero2star;
				levelsdone[first] = true;
				answer++;
				numstars += 2;
				while (true) {
					boolean done = true;
					for (int k = 0; k < levels; k++) {
						if (!levelsdone[k]) {
							done = false;
						}
					}
					if (done) { 
						break; 
					}
					done = false;
					for (int k = 0; k < levels; k++) {
						if (!levelsdone[k] && levelreqs[k][1] <= numstars && !levelsdone1star[k]) {
							numstars += 2;
							answer++;
							levelsdone[k] = true;
							done = true;
							continue;
						}
					}
					if (done) { 
						continue; 
					}
					
					for (int k = 0; k < levels; k++) {
						if (!levelsdone[k] && levelreqs[k][1] <= numstars && levelsdone1star[k]) {
							numstars += 1;
							answer++;
							levelsdone[k] = true;
							done = true;
							continue;
						}
					}
					if (done) { 
						continue; 
					}
					int max = -1;
					int desired = -1;
					for (int k = 0; k < levels; k++) {
						if (!levelsdone1star[k] && levelreqs[k][0] <= numstars && levelreqs[k][1] > max && !levelsdone[k]) {
							desired = k;
							max = levelreqs[k][1];
							done = true;
						}
					}
					if (done) { 
						numstars += 1;
						answer++;
						levelsdone1star[desired] = true;
						continue; 
					}			
					if (!done) {
						answer = Integer.MAX_VALUE;
						break;
					}
				}
			} else {
				int first = levelzero;
				levelsdone1star[first] = true;
				answer++;
				numstars += 1;
				while (true) {
					boolean done = true;
					for (int k = 0; k < levels; k++) {
						if (!levelsdone[k]) {
							done = false;
						}
					}
					if (done) { 
						break; 
					}
					done = false;
					for (int k = 0; k < levels; k++) {
						if (!levelsdone[k] && levelreqs[k][1] <= numstars && !levelsdone1star[k]) {
							numstars += 2;
							answer++;
							levelsdone[k] = true;
							done = true;
							continue;
						}
					}
					if (done) { 
						continue; 
					}
					for (int k = 0; k < levels; k++) {
						if (!levelsdone[k] && levelreqs[k][1] <= numstars && levelsdone1star[k]) {
							numstars += 1;
							answer++;
							levelsdone[k] = true;
							done = true;
							continue;
						}
					}
					if (done) { 
						continue; 
					}
					int max = -1;
					int desired = -1;
					for (int k = 0; k < levels; k++) {
						if (!levelsdone1star[k] && levelreqs[k][0] <= numstars && levelreqs[k][1] > max && !levelsdone[k]) {
							desired = k;
							max = levelreqs[k][1];
							done = true;
						}
					}
					if (done) { 
						numstars += 1;
						answer++;
						levelsdone1star[desired] = true;
						continue; 
					}
					if (!done) {
						answer = Integer.MAX_VALUE;
						break;
					}
				}
			}
			if (answer == Integer.MAX_VALUE) {
				out.println("Case #" + (i+1) + ": Too Bad");
			} else {
				out.println("Case #" + (i+1) + ": " + answer);
			}
			out.flush();
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
}


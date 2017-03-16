package qualification;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class D1 {

	static int[] chestkeys;
	static int[] keycounts;
	static int keycountsc;
	static int[][] chestkeysin;
	static boolean[] chestopen;
//	static int[][] keysinchests;
//	static ArrayList<Hash>
	
	static boolean isKeystateCovered(int[] keystate) {
		for (int i = 0; i < keycountsc; i++) {
			if (keycounts[i] < keystate[i]) {
				return false;
			}
		}
		return true;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int K = sc.nextInt();
			int N = sc.nextInt();
			
			int[] solution = new int[N];
			int solcount = 0;
			
			
			keycounts = new int[200];
			for (int j = 0; j < K; j++) {
				int key = sc.nextInt();
				keycountsc = Math.max(keycountsc, key);
				keycounts[key-1]++;
			}
			
			chestkeys = new int[N];
			chestkeysin = new int[N][];
			chestopen = new boolean[N];
			for (int j = 0; j < N; j++) {
				int key = sc.nextInt();
				keycountsc = Math.max(keycountsc, key);
				chestkeys[j] = key-1;
				int keysinc = sc.nextInt();
				chestkeysin[j] = new int[keysinc];
				for (int l = 0; l < keysinc; l++) {
					key = sc.nextInt();
					keycountsc = Math.max(keycountsc, key);
					chestkeysin[j][l] = key-1;
				}
			}
			
//			keysinchests = new int[keycountsc][];
			
			boolean impossible = false;
			
			o:
			while (solcount < N) {
				int chr = N - solcount;
				int chi = 0;
				int[] usedchests = new int[chr];
				int currcheststate = 0;
				boolean[][] cheststate = new boolean[chr][2];
				for (int j = 0; j < N; j++) {
					if (!chestopen[j]) {
						usedchests[chi] = j;
						cheststate[chi++][currcheststate] = true;
					}
				}
				
				int[] keystate = new int[keycountsc];
				PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
				
				d:
				do {
					Arrays.fill(keystate, 0);
					for (int j = 0; j < chi; j++) {
						cheststate[j][1-currcheststate] = false;
					}
					for (int j = 0; j < chr; j++) {
						int chest = usedchests[j];
						if (cheststate[j][currcheststate]) {
							keystate[chestkeys[chest]]++;
						}
					}
					
					if (isKeystateCovered(keystate)) {
						for (int j = 0; j < chi; j++) {
							if (cheststate[j][currcheststate]) {
								queue.add(usedchests[j]);
							}
						}
						break d;
					}
					
					for (int j = 0; j < chr; j++) {
						int chest = usedchests[j];
						for (int j2 = 0; j2 < chestkeysin[chest].length; j2++) {
							int key = chestkeysin[chest][j2];
							if (keystate[key] > 0) {
								if (cheststate[j][currcheststate]) {
									cheststate[j][1-currcheststate] = true;
								}
							}
						}
					}
					
					
					boolean nochange = true;
					for (int j = 0; j < chr; j++) {
						if (cheststate[j][0] != cheststate[j][1]) {
							nochange = false;
							break;
						}
					}
					if (nochange) {
						impossible = true;
						break o;
					}
					
					currcheststate = 1 - currcheststate;
					for (int j = 0; j < chr; j++) {
						if (!cheststate[j][currcheststate] && cheststate[j][1-currcheststate]) {
							int chest = usedchests[j];
							int key = chestkeys[chest];
							if (keycounts[key] >= keystate[key] && keycounts[key] > 0) {
								queue.add(chest);
							}
						}
					}
					
					
				} while (!isKeystateCovered(keystate));
				
				if (queue.isEmpty() && solcount < N) {
					impossible = true;
					break o;
				}
				
				int selectedChest = queue.poll();
				chestopen[selectedChest] = true;
				solution[solcount++] = selectedChest;
				keycounts[chestkeys[selectedChest]] -= 1;
				for (int j = 0; j < chestkeysin[selectedChest].length; j++) {
					int key = chestkeysin[selectedChest][j];
					keycounts[key] += 1;
				}
			}
			
			if (impossible) {
				System.out.println("Case #" + i + ": IMPOSSIBLE");
			} else {
				StringBuilder sb = new StringBuilder();
				sb.append("Case #" + i + ":");
				for (int k = 0; k < solcount; k++) {
					sb.append(" " + (solution[k]+1));
				}
				System.out.println(sb.toString());
			}
		}
	}

}

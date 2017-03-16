import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;


public class ManageYourEnergy {
	static int E;
	static int R;
	static LinkedList<Pair> sortedList = new LinkedList<Pair>();

	public static void main(String[] args) throws IOException {
		BufferedWriter bw;
		FileOutputStream fos = new FileOutputStream("C:\\Users\\Administrator\\Downloads\\codejam.out");
		bw = new BufferedWriter(new OutputStreamWriter(fos));
		Scanner reader = new Scanner (System.in);
		int nCases = reader.nextInt();
		reader.nextLine();
		for(int i=1; i<=nCases; i++) {
			E = reader.nextInt();
			R = reader.nextInt();
			int N = reader.nextInt();
			int maxGainFullE = 0;
			int maxGain = 0;
			reader.nextLine();
			if(R >= E) {
				for(int j=0; j<N; j++) {
					int cur = reader.nextInt();
					maxGain += cur * E;
				}
			} else {
				for(int j=0; j < N; j++) {
					int cur = reader.nextInt();
					int newMaxGain = getMaxGain(maxGain, maxGainFullE, cur);
					if(j != N-1) {
						int newMaxGainFullE = getMaxGainFullE(maxGainFullE, cur);
						maxGainFullE = newMaxGainFullE;
					}
					maxGain = newMaxGain;
				}
			}
			sortedList.clear();
			String line ="Case #" + i + ": " + maxGain;
			System.out.println(line);
			bw.write(line);
			bw.newLine();
		}
		bw.close();
	}

	private static int getMaxGainFullE(int maxGainFullE, int cur) {
		if(sortedList.size() == 0) {
			sortedList.add(new Pair(cur, R, E));
			maxGainFullE += R * cur;
		} else {
			int tempR = R;
			for(int i=0; i<sortedList.size(); i++) {
				if(cur > sortedList.get(i).value) {
					sortedList.add(i, new Pair(cur, 0, E));
					break;
				}
			}
			for(int i=0; i<sortedList.size(); i++) {
				Pair curPair = sortedList.get(i);
				if(tempR > 0 && curPair.spendEnergy < E && curPair.remainEnergy > 0) {
					if(curPair.spendEnergy + tempR >= E) {
						if (curPair.remainEnergy >= tempR || curPair.spendEnergy + curPair.remainEnergy >= E) {
							maxGainFullE += (E - curPair.spendEnergy) * curPair.value;
							tempR -= (E - curPair.spendEnergy);
							curPair.remainEnergy -= (E - curPair.spendEnergy);
							curPair.spendEnergy = E;
						} else {
							maxGainFullE += curPair.remainEnergy * curPair.value;
							curPair.spendEnergy += curPair.remainEnergy;
							tempR -= curPair.remainEnergy;
							curPair.remainEnergy = 0;
						}
					} else {
						if (curPair.remainEnergy <= tempR) {
							maxGainFullE += curPair.remainEnergy * curPair.value;
							curPair.spendEnergy += curPair.remainEnergy;
							tempR -= curPair.remainEnergy;
							curPair.remainEnergy = 0;
						} else {
							maxGainFullE += tempR * curPair.value;
							curPair.spendEnergy += curPair.remainEnergy;
							curPair.remainEnergy -= tempR;
							tempR = 0;
						}
					}
				}
				if(tempR == 0) {
					break;
				}
				if(tempR < 0) {
					System.out.println("error");
				}
			}
		}
		return maxGainFullE;
	}

	private static int getMaxGain(int maxGain, int maxGainFullE, int cur) {
		int res1 = maxGain + cur * R;
		int res2 = maxGainFullE + cur * E;
		return res1 > res2 ? res1 : res2;
	}
	
	private static class Pair {
		public Pair(int value, int spendEnergy, int remainEnergy) {
			this.value = value;
			this.spendEnergy = spendEnergy;
			this.remainEnergy = remainEnergy;
		}
		int value;
		int spendEnergy;
		int remainEnergy;
	}
}

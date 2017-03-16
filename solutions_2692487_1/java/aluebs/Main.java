package aluebs;

import java.io.*;
import java.util.*;
import java.lang.Math;

class Main {
	public static void main(String[] args) {
		try{
			FileInputStream fis = new FileInputStream(args[0]);
			DataInputStream dis = new DataInputStream(fis);
			BufferedReader br = new BufferedReader(new InputStreamReader(dis));
			//STARTIN
			Integer T = Integer.parseInt(br.readLine());
			Integer[] A = new Integer[T];
			Integer[] N = new Integer[T];
			List<Integer[]> motes = new ArrayList<Integer[]>();
			for(int t = 0; t < T; t++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				A[t] = Integer.parseInt(st.nextToken());
				N[t] = Integer.parseInt(st.nextToken());
				st = new StringTokenizer(br.readLine());
				Integer[] tmp = new Integer[N[t]];
				for(int n = 0; n < N[t]; n++) {
					tmp[n] = Integer.parseInt(st.nextToken());
				}
				Arrays.sort(tmp);
				motes.add(tmp);
			}
			//STOPIN
			dis.close();
			//STARTPROCESS			
			Integer[] y = new Integer[T];
			for(int t = 0; t < T; t++) {
				if(A[t] == 1) {
					y[t] = motes.get(t).length;
				} else {
					y[t] = getOperations(motes.get(t), 0, A[t]);
				}
			}
			//STOPPROCESS
			FileWriter fw = new FileWriter("out.txt");
			BufferedWriter bw = new BufferedWriter(fw);
			//STARTOUT
			for(int t = 0; t < T; t++) {
				bw.write("Case #" + (t + 1) + ": " + y[t]);
				bw.newLine();
			}
			//STOPOUT
			bw.close();
		} catch (Exception e) {}
	}
	
	private static Integer getOperations(Integer[] motes, Integer n, Integer A) {
		Integer y;
		if(n == motes.length) {
			y = 0;
		} else {
			y = getJump(A, motes[n]);
			for(int i = 0; i < y; i++) {
				A += (A - 1);
			}
			y += getOperations(motes, n + 1, A + motes[n]);
			if(y > (motes.length - n)) {
				y = motes.length - n;
			}
		}
		return y;
	}
	
	private static Integer getJump(Integer A, Integer mote) {
		Integer y = 0;
		while(A <= mote) {
			A += (A - 1);
			y++;
		}
		return y;
	}
}


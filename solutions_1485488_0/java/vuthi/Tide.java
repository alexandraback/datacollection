package r1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Vector;

import com.sun.org.apache.xalan.internal.xsltc.runtime.Hashtable;


public class Tide {

	double bestTime = Double.MAX_VALUE;
	double [][]timeHere;
	boolean flagWait = false;
	
	public static void main(String[] args) {
		System.err.println("Ver 4");
		
		if(args.length != 1) {
			System.out.println("Usage: <inputfile>");
			System.exit(0);
		}

		File iFile = new File(args[0]);
		if(!iFile.exists()) {
			System.out.println("Input file not found: "+args[0]);
			System.exit(0);
		}

		Tide solver = new Tide();
		solver.processFile(iFile);

	}

	public void processFile(File iFile) {
		try {
			FileReader fr = new FileReader(iFile);
			BufferedReader br = new BufferedReader(fr);
			String line = br.readLine();
			int n = Integer.parseInt(line);
			System.err.println("Cases "+ n);

			for(int j=0;j<n;j++) {
				bestTime = Double.MAX_VALUE;
				line = br.readLine();
				String cols[] = line.split(" ");
				
				int H = Integer.parseInt(cols[0]);
				int N = Integer.parseInt(cols[1]);
				int M = Integer.parseInt(cols[2]);
				int ceil[][] = new int[N][M];
				int floor[][] = new int[N][M];
				 timeHere = new double[N][M];
				
				for(int i=0;i<N;i++) {
					line = br.readLine();
					String cc[] = line.split(" ");
					for(int k=0;k<M;k++) {
						ceil[i][k] = Integer.parseInt(cc[k]);
						timeHere[i][k]=Double.MAX_VALUE;
					}
				}
				for(int i=0;i<N;i++) {
					line = br.readLine();
					String cc[] = line.split(" ");
					for(int k=0;k<M;k++)
						floor[i][k] = Integer.parseInt(cc[k]);
				}
				
				find(0, 0, H, N, M, ceil, floor, 0, false);
				System.out.println("Case #"+(j+1)+": "+String.format("%.4f", bestTime));
			}
			br.close();
			fr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public void find(int row, int col, 
			int H, int N, int M, int[][] ceil, int [][]floor, double curTime, boolean didWait) {

		if(curTime > bestTime)
			return;

		if(row == N-1 && col==M-1) {
			if(curTime < bestTime)
				bestTime = curTime;
			return;
		}

		if(curTime >= timeHere[row][col])
			return;

		
		timeHere[row][col] = curTime;
		
		double curWater = H-10*curTime;
		if(curWater < 0)
			curWater = 0;
		
		if(col<M-1) {
			flagWait = false;
			double ttg = timeToGo(ceil[row][col],floor[row][col],ceil[row][col+1],floor[row][col+1],curWater, didWait);
			if(flagWait)
				didWait = true;
			if(ttg>=0)
				find(row,col+1,H,N,M,ceil,floor,curTime+ttg, didWait);
		}
		if(col>0) {
			flagWait = false;
			double ttg = timeToGo(ceil[row][col],floor[row][col],ceil[row][col-1],floor[row][col-1],curWater, didWait);
			if(flagWait)
				didWait = true;
			if(ttg>=0)
				find(row,col-1,H,N,M,ceil,floor,curTime+ttg, didWait);
		}
		if(row<N-1) {
			flagWait = false;
			double ttg = timeToGo(ceil[row][col],floor[row][col],ceil[row+1][col],floor[row+1][col],curWater, didWait);
			if(flagWait)
				didWait = true;
			if(ttg>=0)
				find(row+1,col,H,N,M,ceil,floor,curTime+ttg, didWait);
		}
		if(row>0) {
			flagWait = false;
			double ttg = timeToGo(ceil[row][col],floor[row][col],ceil[row-1][col],floor[row-1][col],curWater, didWait);
			if(flagWait)
				didWait = true;
			if(ttg>=0)
				find(row-1,col,H,N,M,ceil,floor,curTime+ttg, didWait);
		}
		
	
	}
	
	double timeToGo(int c1, int f1, int c2, int f2, double water, boolean didWait) {
		if(c2-f2<50)
			return -1;
		if(c2-f1<50)
			return -1;
		if(c2<50)
			return -1;
		if(c1-f2<50)
			return -1;
		if(c2-water>=50)
			return didWait?((water-f1>=20)?1:10):0;
		
		int nwater = c2-50;
		
		if(nwater < 0)
			return -1;

		flagWait = true;
		return (water-nwater)/10.0+((nwater-f1>=20)?1:10);
	}
}

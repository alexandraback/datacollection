package mirrors;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class Small {
	
	public static double calcPente(double x, double y){
		/*if(x == 0 && y == 0)
			return 0;
		if(x == 0)
			return sign(y) * Integer.MAX_VALUE;
		return (int) (x / (Math.sqrt(x*x + y*y)) * 1000) * sign(y);*/
		if(x == 0 && y == 0)
			return Integer.MAX_VALUE;
		double res = (Math.acos(x / (Math.sqrt(x*x + y*y))));
		if(y < 0){
			res *= -1;
		}
		return res;
	}
	
	public static int sign(double y){
		if(y >= 0)
			return 1;
		return -1;
	}
	
	public static double dist(double x, double y){
		return Math.sqrt(x*x + y*y);
	}
	
	public static void buildGrid(HashSet<Double> pentes, double x, double y, double g, double d, double h, double b, int D){
		double pente = calcPente(x, y);
		if(dist(x, y) <= D && !pentes.contains(pente)){
			/*System.out.println("x: " + x + " y: " + y);
			System.out.println("dist: " + dist(x, y));
			System.out.println("pente: " + pente);*/
			pentes.add(pente);
			buildGrid(pentes, x + d + d, y, d, g, h, b, D);
			buildGrid(pentes, x - g - g, y, d, g, h, b, D);
			buildGrid(pentes, x, y + h + h, g, d, b, h, D);
			buildGrid(pentes, x, y - b - b, g, d, b, h, D);
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String fileName = args[0];
		String fileName = "mirrors/D-small-attempt3.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int T = sC.nextInt();
		int H, W, D;
		
		String line;
		char[] charA;
		
		int posh, posw;
		
		HashSet<Double> pentes = new HashSet<Double>();
		
		for(int i = 0; i < T; i++){
			pentes.clear();
			
			H = sC.nextInt();
			W = sC.nextInt();
			D = sC.nextInt();
			
			posh = 0;
			posw = 0;
			
			for(int j = 0; j < H; j++){
				line = sC.next();
				charA = line.toCharArray();
				for(int k = 0; k < W; k++){
					if(charA[k] == 'X'){
						posh = j;
						posw = k;
						break;
					}
				}
			}
			
			//System.out.println((posw + 0.5 - 1) + " " + (W - posw - 0.5 - 1) + " " + (posh + 0.5 - 1) + " " + (H - posh - 0.5 - 1) + " " + D);
			
			buildGrid(pentes, 0., 0., posw + 0.5 - 1, W - posw - 0.5 - 1, posh + 0.5 - 1, H - posh - 0.5 - 1, D);
			
			
			System.out.println("Case #" + (i + 1) + ": " + (pentes.size() - 1));
		}

	}

}

package qr2014D;

import java.util.*;
import java.io.*;

import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {

//	Scanner sc = new Scanner(in);
	Scanner sc; 
	
	int calc(List<Double> a, List<Double> b) {
		int n = a.size();
		int res = 0;
		for (int i = 0; i < n; i++) {
			double d = a.get(i);
			int index = -Collections.binarySearch(b, d)-1;
			if (index == b.size()) {
				res++;
			} else {
				b.remove(index);
			}
		}
		return res;
	}
	
	void run() {
		try {
			sc = new Scanner(new File("/Users/ryo/Documents/procon/D-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		List<Double> naomi = new ArrayList<Double>();
		List<Double> ken = new ArrayList<Double>();
		
		int t = sc.nextInt();
		for (int w = 1; w <= t; w++) {
			int n = sc.nextInt();
			double[] naomia = new double[n];
			double[] kena = new double[n];
			naomi.clear();
			ken.clear();
			for (int i = 0; i < n; i++) {
				double d = sc.nextDouble();
				naomi.add(d);
				naomia[i] = d;
			}
			for (int i = 0; i < n; i++) {
				double d = sc.nextDouble();
				ken.add(d);
				kena[i] = d;
			}
			Collections.sort(naomi);
			Collections.sort(ken);
			
			int z = calc(naomi, ken);
			
			ken.clear();
			for (int i = 0; i < n; i++)
				ken.add(kena[i]);
			Collections.sort(ken);
			
			int y = calc(ken, naomi);
			
			out.printf("Case #%d: %d %d\n", w, n-y, z);
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}
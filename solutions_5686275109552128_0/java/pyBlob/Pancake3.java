

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;

public class Pancake3 {
	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = parseInt(s.nextLine());
		
		for (int i=1 ; i<=n ; i++) {
			System.out.print("Case #" + i + ": ");
			
			run();
		}
	}
	
	public static class Stats {
		// cakes[i] = x  => x diners have i cakes each
		public final int[] cakes = new int[10];
		public int offset = 0, max = 0;
		
		public void update() {
			max = 0;
			for (int i=offset ; i<cakes.length ; i++) {
				if (cakes[i] > 0) {
					max = i - offset;
				}
			}
		}
		
		public void eat() {
			offset++;
			
			// update
			max--;
		}
		public void vomit() {
			offset--;
			
			// update
			max++;
		}
		
		public int fork(int id, int h) {
			int n = cakes[offset + id];
			
			cakes[offset + id] = 0;
			
			cakes[offset + h] += n;
			cakes[offset + id - h] += n;
			
			if (id == max) {
				while (cakes[offset + max] == 0 && max > 0) {
					max--;
				}
			}
			
			return n;
		}
		public void unfork(int id, int h, int n) {
			cakes[offset + id] = n;
			
			cakes[offset + h] -= n;
			cakes[offset + id - h] -= n;
			
			// update
			if (id > max) {
				max = id;
			}
		}
	}
	
	public static void run() {
		Stats stats = new Stats();
		
		int seats = parseInt(s.nextLine());
		
		String line[] = s.nextLine().split(" ");
		for (int i=0 ; i<seats ; i++) {
			int v = parseInt(line[i]);
			
			stats.cakes[v]++;
		}
		
		debug(Arrays.toString(line));
		
		stats.update();
		cutoff = stats.max;
		
		System.out.println(multiverse(stats));
	}
	
	public static int cutoff;
	public static int multiverse(Stats stats) {
		if (stats.max > 3) {
			int id, n;
			
			id = stats.max;
			
			// universe A-X
			for (int h=1 ; h<id ; h++) {
				n = stats.fork(id, h);
				
				cutoff = Math.min(cutoff, n + multiverse(stats));
				
				stats.unfork(id, h, n);
			}
			
			// universe Y
			stats.eat();
			cutoff = Math.min(cutoff, 1 + multiverse(stats));
			stats.vomit();
			
			return cutoff;
		} else {
			return stats.max;
		}
	}
	
	public static void debug(String string) {
		System.out.flush();
		
		System.err.println(string);
		System.err.flush();
	}
}

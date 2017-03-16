package pl.helman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Wall {

	public static void main(String[] args) throws IOException {

		FileReader fr = new FileReader("d:\\cj\\wall.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\cj\\wall.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {
			System.out.println(c);

			line = br.readLine();
			int n = Integer.parseInt(line);

			List<Attack> attacks = new ArrayList<Attack>(n * 1000);

			for (int i = 0; i < n; i++) {
				line = br.readLine();
				String[] elems = line.split(" ");

				int d = Integer.parseInt(elems[0]);
				int ni = Integer.parseInt(elems[1]);
				int w = Integer.parseInt(elems[2]);
				int e = Integer.parseInt(elems[3]);
				int s = Integer.parseInt(elems[4]);
				int deltaD = Integer.parseInt(elems[5]);
				int deltaP = Integer.parseInt(elems[6]);
				int delatS = Integer.parseInt(elems[7]);

				for (int j = 0; j < ni; j++) {
					attacks.add(new Attack(d, w, e, s));

					d += deltaD;

					w += deltaP;
					e += deltaP;

					s += delatS;
				}
			}

			Collections.sort(attacks);

			int dayStart = 0;
			int dayEnd = 1;
			
			Heights h = new Heights();
			int ret = 0;

			while (dayStart < attacks.size()) {

				while (dayEnd < attacks.size() && attacks.get(dayEnd).day == attacks.get(dayStart).day) {
					dayEnd++;
				}
				
				for (int i = dayStart; i < dayEnd; i++) {
					if (h.attack(attacks.get(i))) {
						ret++;
					}
				}
				
				h.commitDay();
				
				dayStart = dayEnd;
				dayEnd = dayStart + 1;
			}


			System.out.println("Case #" + c + ": " + ret);
			f0.write("Case #" + c + ": " + ret + "\r\n");
		}

		fr.close();
		f0.close();
	}

	public static class Attack implements Comparable<Attack> {
		int day;
		int w;
		int e;
		int s;

		public Attack(int day, int w, int e, int s) {
			this.day = day;
			this.w = w;
			this.e = e;
			this.s = s;
		}

		@Override
		public int compareTo(Attack o) {
			return day < o.day ? -1 : day == o.day ? 0 : 1;
		}
	}
	
	public static class Heights {
		
		int h[] = new int[600];
		int center = 300;
		
		List<Attack> daily = new LinkedList<Wall.Attack>();
		
		boolean attack(Attack a) {
		
			daily.add(a);
			
			for (int p = a.w; p < a.e; p++) {
				if (h[center + p] < a.s) {
					return true;
				}
			}
			
			return false;
		}

		void commitDay() {
			for (Attack a : daily) {
				for (int p = a.w; p < a.e; p++) {
					if (h[center + p] < a.s) {
						h[center + p] = a.s;
					}
				}
			}
		}
	}

}

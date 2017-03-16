package google2012.qualy;

import java.io.*;
import java.util.*;

import org.apache.commons.io.FileUtils;

/**
 * Funciona para o small
 * @author thiago
 *
 */

public class QualyBLarge {
	int n;
	int s;
	int max;
	int notas[];
	QualyBPossib h[] = new QualyBPossib[31];
	
	public static void main(String[] args) throws Exception {
		new QualyBLarge();
	}
	
	public QualyBLarge() throws Exception {
		Scanner sc = new Scanner(new File("2012/qualy/b/B-large.in"));
		int N = sc.nextInt();
		for (int i = 0; i <= 30; i++) {
			h[i] = new QualyBPossib(i);
		}
		for (int i = 0; i <= 10; i++) {
			for (int j = 0; j <= 10; j++) {
				for (int k = 0; k <= 10; k++) {
					int total = i+j+k;
					//System.out.println(i+" "+j+" "+k);
					h[total].addTriplet(new int[]{i,j,k});
				}
			}
		}
		for (int i = 0; i <= 30; i++) {
			h[i].setTriplets();
		}
		/*for (int i = 0; i < h.length; i++) {
			System.out.println("NOTA "+i);
			System.out.println("nnnn");
			for (Iterator it = h[i].getSet(false).iterator(); it.hasNext();) {
				QualyBTriplet t = (QualyBTriplet) it.next();
				System.out.println(t);
			}
			System.out.println("ssss");
			for (Iterator it = h[i].getSet(true).iterator(); it.hasNext();) {
				QualyBTriplet t = (QualyBTriplet) it.next();
				System.out.println(t);
			}
		}*/
		StringBuffer resposta = new StringBuffer();
		for (int i = 0; i < N; i++) {
			n = sc.nextInt();
			s = sc.nextInt();
			max = sc.nextInt();
			notas = new int[n];
			for (int j = 0; j < n; j++) {
				notas[j] = sc.nextInt();
			}
			int resp = 0;
			Arrays.sort(notas);
			for (int j = 0; j < notas.length; j++) {
				int nota = notas[j];
				int maxn = h[nota].getMaxn();
				int maxs = h[nota].getMaxs();
				if (maxn>=max) resp++;
				else if (s>0 && maxs>=max) {
					s--;
					resp++;
				}
			}
			String out = "Case #"+(i+1)+": "+resp+"\n";
			System.out.println(out);
			resposta.append(out);
		}
		FileUtils.writeStringToFile(new File("2012/qualy/b/B-large.out"), resposta.toString());
		System.exit(0);
	}
	
	static public String vprint(int n[]) {
		StringBuffer b = new StringBuffer();
		for (int i = 0; i < n.length; i++) {
			b.append(n[i]);
			b.append(" ");
		}
		return b.toString();
	}
	
	private class QualyBPossib {
		int nota;
		Set<QualyBTriplet> tn = new HashSet<QualyBLarge.QualyBTriplet>();
		Set<QualyBTriplet> ts = new HashSet<QualyBLarge.QualyBTriplet>();
		
		QualyBTriplet tripn;
		QualyBTriplet trips;
		public QualyBPossib(int nota) {
			this.nota = nota;
		}
		void addTriplet(int notas[]) {
			int max = Math.max(notas[0], Math.max(notas[1], notas[2]));
			int min = Math.min(notas[0], Math.min(notas[1], notas[2]));
			int dif = max-min;
			Arrays.sort(notas);
			if (dif<=1) {
				boolean add = tn.add(new QualyBTriplet(notas, max, false));
				//if(add) System.out.println("Adicionou "+vprint(notas)+" a "+nota);
			}
			else if(dif==2) {
				boolean add = ts.add(new QualyBTriplet(notas, max, true));
				//if(add) System.out.println("Adicionou s "+vprint(notas)+" a "+nota);
			}
			//else não faz nada
		}
		
		void setTriplets() {
			if (tn.size()>0) tripn = (QualyBTriplet)tn.toArray()[0];
			if (ts.size()>0) trips = (QualyBTriplet)ts.toArray()[0];
		}
		
		int getMaxn() {
			return tripn==null ? 0:tripn.max;
		}

		int getMaxs() {
			return trips==null ? 0:trips.max;
		}
	}

	private class QualyBTriplet {
		int nota[];
		int max;
		boolean s;
		public QualyBTriplet(int[] nota, int max, boolean s) {
			this.nota = nota;
			this.max = max;
			this.s = s;
		}
		@Override
		public boolean equals(Object obj) {
			for (int i = 0; i < nota.length; i++) {
				if (nota[i] != ((QualyBTriplet)obj).nota[i]) return false;
			}
			return true;
		}
		@Override
		public int hashCode() {
			return Arrays.hashCode(nota);
		}
		@Override
		public String toString() {
			return "QualyBTriplet [nota=" + Arrays.toString(nota) + ", max="
					+ max + "]";
		}
	}
}

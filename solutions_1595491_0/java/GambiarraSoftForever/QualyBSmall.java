package google2012.qualy;

import google.CombinationGenerator;

import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;

import org.apache.commons.io.FileUtils;

public class QualyBSmall {
	int n;
	int s;
	int max;
	int notas[];
	QualyBPossib h[] = new QualyBPossib[31];
	
	public static void main(String[] args) throws Exception {
		new QualyBSmall();
	}
	
	public QualyBSmall() throws Exception {
		Scanner sc = new Scanner(new File("2012/qualy/b/B-small-attempt0.in"));
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
			int m = 0;
			if (s==0) {
				m = cenario(new int[]{0,0,0});
				if(m>resp) resp = m;
			}
			else if (s==1) {
				m = cenario(new int[]{0,0,1});
				if(m>resp) resp = m;
				m = cenario(new int[]{0,1,0});
				if(m>resp) resp = m;
				m = cenario(new int[]{1,0,0});
				if(m>resp) resp = m;
			}
			else if (s==2) {
				m = cenario(new int[]{0,1,1});
				if(m>resp) resp = m;
				m = cenario(new int[]{1,0,1});
				if(m>resp) resp = m;
				m = cenario(new int[]{1,1,0});
				if(m>resp) resp = m;
			}
			else {
				m = cenario(new int[]{1,1,1});
				if(m>resp) resp = m;
			}
			String out = "Case #"+(i+1)+": "+resp+"\n";
			System.out.println(out);
			resposta.append(out);
		}
		FileUtils.writeStringToFile(new File("2012/qualy/b/B-small-attempt0.out"), resposta.toString());
		System.exit(0);
	}
	
	private int cenario(int bs[]) {
		int ret = 0;
		for (int j = 0; j < n; j++) {
			int nota = notas[j];
			Set<QualyBTriplet> set = h[nota].getSet(bs[j]);
			int mt = 0;
			for (Iterator it = set.iterator(); it.hasNext();) {
				QualyBTriplet triplet = (QualyBTriplet) it.next();
				if (triplet.max>mt) mt = triplet.max;
			}
			if (mt>=max) ret++;
		}
		return ret;
	}
	
	static public String vprint(int n[]) {
		StringBuffer b = new StringBuffer();
		for (int i = 0; i < n.length; i++) {
			b.append(n[i]);
			b.append(" ");
		}
		return b.toString();
	}
	
	static void tabelaVerdade(int qtd) {
		try {  
			int qtdNumeros = (int) Math.pow(2, qtd);  
			Vector<StringBuffer> valores = new Vector<StringBuffer>(qtdNumeros);  

			for (int i = 0; i < qtdNumeros; i++) {  
				valores.add(new StringBuffer("|"));  
			}  

			for (int j = 0; j < qtd; j++) {  
				int passo = (int) Math.pow(2, j);  
				boolean zero = false;  

				for (int i = 0; i < qtdNumeros; i++) {  
					if (i % passo == 0) {  
						zero = !zero;  
					}  

					if (zero)  
						valores.get(i).append("0|");  
					else  
						valores.get(i).append("1|");  
				}  
			}  

			for (int i = 0; i < qtdNumeros; i++) {  
				System.out.println(valores.get(i).reverse());  
			}  
		} catch (Exception e) {  
			e.printStackTrace();  
		}
	}
	
	private class QualyBPossib {
		int nota;
		Set<QualyBTriplet> tn = new HashSet<QualyBSmall.QualyBTriplet>();
		Set<QualyBTriplet> ts = new HashSet<QualyBSmall.QualyBTriplet>();
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
		
		Set<QualyBTriplet> getSet(boolean s) {
			if(s) return ts;
			return tn;
		}
		Set<QualyBTriplet> getSet(int s) {
			if(s==0) return tn;
			return ts;
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

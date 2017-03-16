package google2012.qualy;

import java.io.*;
import java.util.*;

import org.apache.commons.io.FileUtils;


import java.io.File;
import java.util.Scanner;

public class QualyCLarge {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("2012/qualy/c/C-large.in"));
		HashMap<Integer, QualyCTupla> h = new HashMap<Integer, QualyCTupla>();
		int N = sc.nextInt();
		StringBuffer resposta = new StringBuffer();
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int res = 0;
			//System.out.println("A="+a+" B="+b);
			for (int n = a; n <= b; n++) {
				char num[] = Integer.toString(n).toCharArray();
				int prim = num[0];
				int j=1;
				for (; j < num.length; j++) if(num[j]!=prim) break;
				if(j==num.length) continue;
				QualyCTupla tupla = h.get(n);
				if (tupla==null) {
					tupla = new QualyCTupla(b);
					h.put(n, tupla);
					//System.out.println("Novo para "+n);
					res += count(num, n, b, tupla);
				}
				else if(tupla.b>=b && tupla.max<=b) {
					//System.out.println("Usando novamente "+n+" = "+tupla.cont);
					res += tupla.cont;
				}
				else {
					tupla.reset(b);
					res += count(num, n, b, tupla);
					//System.out.println("Repetindo cálculo para "+n+" = "+tupla.cont);
				}
			}
			String out = "Case #"+(i+1)+": "+res+"\n";
			System.out.println(out);
			resposta.append(out);
		}
		FileUtils.writeStringToFile(new File("2012/qualy/c/C-large.out"), resposta.toString());
		System.exit(0);
	}
	
	public static int count(char num[], int n, int b, QualyCTupla tupla) {
		int f = num[num.length-1]!='0' ? num.length:num.length-1;
		Set<Integer> set = new HashSet<Integer>();
		for (int j=0; j < f; j++) {
			StringBuffer buf = new StringBuffer();
			for (int k = j+1; k < num.length; k++) {
				buf.append(num[k]);
			}
			for (int k = 0; k <= j; k++) {
				buf.append(num[k]);
			}
			int t = Integer.parseInt(buf.toString());
			if (t>n && t<=b) {
				boolean add=set.add(t);
				//if(add)System.out.println(n+" "+t);
				if (t>tupla.max) tupla.max = t;
			}
		}
		tupla.cont = set.size();
		return tupla.cont;
	}
}

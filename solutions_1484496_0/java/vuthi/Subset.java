package r1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Vector;

import com.sun.org.apache.xalan.internal.xsltc.runtime.Hashtable;


public class Subset {

	public static void main(String[] args) {
		System.err.println("Ver 3");
		
		if(args.length != 1) {
			System.out.println("Usage: <inputfile>");
			System.exit(0);
		}

		File iFile = new File(args[0]);
		if(!iFile.exists()) {
			System.out.println("Input file not found: "+args[0]);
			System.exit(0);
		}

		Subset solver = new Subset();
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
				line = br.readLine();
				String cols[] = line.split(" ");

				int nn = Integer.parseInt(cols[0]);
				int x[] = new int[nn];
				for(int jj=0; jj<nn ;jj++) {
					x[jj] = Integer.parseInt(cols[1+jj]);
				}

				System.out.println("Case #"+(j+1)+":");
				find(x);
			}
			br.close();
			fr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public void find(int []x) {
		int max = 1<<x.length;
		System.err.println("Max "+max);
		Hashtable ht = new Hashtable();
		
		for(int i=1;i<max;i++) {
			int sum = 0;
			for(int j=0;j<x.length;j++) {
				if((i & (1<<j))!=0) {
					sum += x[j];
				}
			}
			if(ht.containsKey(sum)) {
				prSet(x, (Integer)ht.get(sum));
				prSet(x, i);
				return;
			}
			ht.put(sum, i);
		}
	}

	public void prSet(int []x, int i) {
		String out = "";
		for(int j=0;j<x.length;j++) {
			if((i & (1<<j))!=0) {
				out += " "+x[j];
			}
		}
		System.out.println(out);
	}
	
	public void solve(int i, String input) {
		System.out.println("Case #"+i);
		System.out.println("output("+input+")");

	}
}

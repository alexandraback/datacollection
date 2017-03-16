package r1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Vector;


public class SafetyNum {

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

		SafetyNum solver = new SafetyNum();
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
				double sum = 0;
				
				for(int jj=0; jj<nn ;jj++) {
					sum += Double.parseDouble(cols[jj+1]);
				}
				double avg = 2*sum/nn;
				String out = "";
				int nnn = nn;
				double sub = 0;
				int map[] = new int[nn];
				for(int jj=0; jj<nn ;jj++) {
					double val = (avg-Double.parseDouble(cols[jj+1]))*100/sum;
					map[jj] = 0;
					if(val<0) {
						val = 0;
						nnn--;
						map[jj]=1;
						sub +=Double.parseDouble(cols[jj+1]);
					}
					out += " "+val;
				}

				int nnnn = nn;
				if(nnn<nn) {
					nnnn = nnn;
					out = "";
					avg = (2*sum-sub)/nnn;
					for(int jj=0; jj<nn ;jj++) {
						if(map[jj]==1)
							out += " 0";
						else {
							double val = (avg-Double.parseDouble(cols[jj+1]))*100/sum;
							out += " "+val;
							if(val<0) {
								val = 0;
								nnnn--;
								map[jj]=1;
								sub +=Double.parseDouble(cols[jj+1]);
							}
						
						}
					}
				}
				
				if(nnnn<nnn) {
					out = "";
					avg = (2*sum-sub)/nnnn;
					for(int jj=0; jj<nn ;jj++) {
						if(map[jj]==1)
							out += " 0";
						else {
							double val = (avg-Double.parseDouble(cols[jj+1]))*100/sum;
							out += " "+val;
							if(val<0) {
								System.err.println("Error");
							}
						
						}
					}
				}
				System.out.println("Case #"+(j+1)+":"+out);

			}




			br.close();
			fr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public void solve(int i, String input) {
		System.out.println("Case #"+i);
		System.out.println("output("+input+")");

	}
}

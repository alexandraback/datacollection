import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class BoxFactory {
	public static void main(String args[]) {
		try {
			FileInputStream fstream = new FileInputStream("in.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter ofstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(ofstream);
	
			int t = Integer.parseInt(br.readLine());
			for (int i = 0; i < t; ++i) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(st.nextToken());
				int m = Integer.parseInt(st.nextToken());
				long[] counta = new long[n];
				int[] typea = new int[n];
				long[] countb = new long[m];
				int[] typeb = new int[m];
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j<n;++j) {
					counta[j] = Long.parseLong(st.nextToken());
					typea[j] = Integer.parseInt(st.nextToken());
				}
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j<m;++j) {
					countb[j] = Long.parseLong(st.nextToken());
					typeb[j] = Integer.parseInt(st.nextToken());
				}
				long max = 0;
				for (int j = 0; j < n; ++j) {
					for (int l = 0; l < m; ++l) {
						if (typea[j] == typeb[l]) {
							long mm = Math.min(counta[j], countb[l]);
							int pa = j + 1;
							int pb = l + 1;
							while (pa < n && pb < m && typea[pa] == typeb[pb]
									&& counta[pa] == countb[pb]) {
								mm += counta[pa];
								++pa;
								++pb;
							}
							long ca = 0;
							long cb = 0;
							if (pa < n && pb < m && typea[pa] == typeb[pb]) {
								mm += Math.min(counta[pa], countb[pb]);
								ca = counta[pa];
								cb = countb[pb];
								ca -= Math.min(counta[pa], countb[pb]);
								cb -= Math.min(counta[pa], countb[pb]);
							} else {
								if (pa < n && pb < m) {
									ca = counta[pa];
									cb = countb[pb];
								}
							}
							
							while(pa < n && pb < m) {
								if(typea[pa] == typeb[pb])
									mm += Math.min(ca, cb);
								long min = Math.min(ca, cb);
								ca -= min;
								cb -= min;
								if(ca == 0) {
									++pa;
									if(pa < n)
										ca = counta[pa];
								}
								if(cb == 0) {
									++pb;
									if(pb < m)
										cb = countb[pb];
								}
							}
							
							int ppa = j;
							int ppb = l;
							ca = counta[ppa] - Math.min(counta[ppa], countb[ppb]);
							cb = countb[ppb] - Math.min(counta[ppa], countb[ppb]);
							
							while(ppa >= 0 && ppb >= 0) {
								if(typea[ppa] == typeb[ppb])
									mm += Math.min(ca, cb);
								long min = Math.min(ca, cb);
								ca -= min;
								cb -= min;
								if(ca == 0) {
									--ppa;
									if(ppa >= 0)
										ca = counta[ppa];
								}
								if(cb == 0) {
									--ppb;
									if(ppb >= 0)
										cb = countb[ppb];
								}
							}
							
							if (mm > max)
								max = mm;
						}
					}
				}
				out.write("Case #" + (i + 1) + ": " + max + "\r\n");
			}
			in.close();
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e);
		}
	}
}

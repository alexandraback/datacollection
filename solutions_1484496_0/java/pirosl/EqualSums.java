import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class EqualSums {
	static class Subset implements Comparable {
		public long sum;
		public String subset;
		
		@Override
		public int compareTo(Object o) {
			Subset b = (Subset)o;
			return (int)(sum - b.sum);
		}
		
	}
	
	public static void main(String args[]) {
		try {
			FileInputStream fstream = new FileInputStream("in.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter ofstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(ofstream);
			  
			int t = Integer.parseInt(br.readLine());
			for(int i=0;i<t;++i) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(st.nextToken());
				long[] points = new long[n];
				for(int j=0;j<n;++j) {
					points[j] = Long.parseLong(st.nextToken());
				}
				
				Set set = new TreeSet();
				boolean done = false;
				out.write("Case #" + (i+1) + ":\r\n");
				for(int j=0;j<n && !done;++j) {
					Subset s = new Subset();
					s.sum = points[j];
					s.subset = "" + points[j] + " ";
					
					if(set.contains(s)) {
						done = true;
						Object[] array = set.toArray();
						for(int l=0;l<array.length;++l) {
							if(((Subset)array[l]).sum == s.sum) {
								out.write(((Subset)array[l]).subset);
								out.write("\r\n");	
							}
						}
						out.write(s.subset);
						out.write("\r\n");
					} else {
						Object[] array = set.toArray();
						for(int l=0;l<array.length && !done;++l) {
							Subset s1 = new Subset();
							s1.sum = ((Subset)array[l]).sum + s.sum;
							s1.subset = ((Subset)array[l]).subset + points[j] + " ";
							if(set.contains(s1)) {
								done = true;
								Object[] array1 = set.toArray();
								for(int l1=0;l1<array1.length;++l1) {
									if(((Subset)array1[l1]).sum == s1.sum) {
										out.write(((Subset)array1[l1]).subset);
										out.write("\r\n");	
									}
								}
								out.write(s1.subset);
								out.write("\r\n");
							} 
							else {
								set.add(s1);
							}
						}
						set.add(s);
					}
				}
				if(!done)
					out.write("Impossible\r\n");
			}
			
			
			in.close();
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
}

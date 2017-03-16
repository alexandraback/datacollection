import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;


public class DiamondInheritance {
//	static boolean[][] b= new boolean[10001][1001];
//	static int[] c = new int[1001];
	
	public static void main(String args[]) {
		try {
			FileInputStream fstream = new FileInputStream("in.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter ofstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(ofstream);
	
			int t = Integer.parseInt(br.readLine());
			for(int i=0; i<t;++i) {
				int n = Integer.parseInt(br.readLine());
				//boolean[][] b= new boolean[n][n];
				String[] s = new String[n];
				int[] c = new int[n];
				for(int j=0;j<n;++j) {
					s[j] = br.readLine();
					//StringTokenizer st = new StringTokenizer(br.readLine());
					//c[j] = Integer.parseInt(st.nextToken());
					//while(st.hasMoreTokens()) {
					//	int l = Integer.parseInt(st.nextToken());
					//	b[j][l-1] = true;
					//}
				}
				
				boolean done = false;
				for(int j=0;j<n && !done;++j) {
					Vector v = new Vector();
					boolean[] vis = new boolean[n];
					boolean div = false;
					StringTokenizer st = new StringTokenizer(s[j]);
					int p = Integer.parseInt(st.nextToken());
					if(p > 1) {
						div = true;
					}
					while(st.hasMoreTokens()) {
						int y = Integer.parseInt(st.nextToken()) - 1;
						v.add(new Integer(y));
						vis[y] = true;
					}
					while(!v.isEmpty()) {
						Integer dd = (Integer)v.remove(0);
						StringTokenizer st1 = new StringTokenizer(s[dd.intValue()]);
						int p1 = Integer.parseInt(st1.nextToken());
						if(p1 > 1) {
							div = true;
						}
						while(st1.hasMoreTokens()) {
							int y = Integer.parseInt(st1.nextToken()) - 1;
							if(vis[y] == true && div) 
								done = true;
							else {
								vis[y] = true;
								v.add(new Integer(y));
							}
						}
					}
				}
				out.write("Case #" + (i+1) + ":");
				if(!done)
					out.write(" No\r\n");
				else	
					out.write(" Yes\r\n");
					
			}
			
			in.close();
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e);
		}
	}
}

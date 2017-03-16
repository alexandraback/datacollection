import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.*;

/**
 * @author Seitaro Sakoda
 *
 */
public class TideGoesInTideGoesOut {
	public static void main(String[] args) throws Exception {
		DataReader dr = new DataReader();
		int N = dr.readInt();
		ArrayList<String> ans = new ArrayList<String>();
		for(int n=0;n<N;n++){
			int[] tmp1 = dr.readInts();
			int H = tmp1[0];
			int NN = tmp1[1];
			int MM = tmp1[2];
			int[][] ceil = new int[NN][MM];
			int[][] floor = new int[NN][MM];
			for(int i=0;i<NN;i++) ceil[i] = dr.readInts();
			for(int i=0;i<NN;i++) floor[i] = dr.readInts();
			ans.add("Case #"+(n+1)+": "+doit(H, ceil, floor));
		}
		dr.close();
		DataWriter dw = new DataWriter();
		for(int n=0;n<N;n++) dw.writeLine(ans.get(n));
		dw.close();
	}

	/**
	 * @param c
	 * @param data
	 * @return
	 */
	private static String doit(int H, int[][] c, int[][] f) {
		DecimalFormat df = new DecimalFormat("0.0000000");
		double ret = 0.0;
		double[][] map = new double[c.length][c[0].length];
		int[] dn = new int[]{1,0,-1,0};
		int[] dm = new int[]{0,1,0,-1};
		for(int i=0;i<map.length;i++) Arrays.fill(map[i], 10000000.0);
		Queue<Object> q = new LinkedList<Object>();
		q.add(new Object[]{0.0, (double)H, new int[]{0, 0}}); // time, {N, M}
		while(q.size()>0){
			Object[] o = (Object[])q.poll();
			double t = (Double)o[0];
			double tide = (Double)o[1];
			int[] a = (int[])o[2];
			int x = a[0]; int y = a[1];
			if(map[x][y] <= t) continue;
			map[x][y] = t;
			if(x==c.length && y==c[0].length) continue;
			for(int i=0;i<4;i++){
				int n = x+dn[i];
				int m = y+dm[i];
				if(n<0 || n>=c.length || m<0 || m>=c[0].length) continue;
				if(f[x][y]+50>c[n][m] || c[x][y]-50<f[n][m] || c[n][m]-50<f[n][m]) continue; // wall!! 
				if(tide+50.0<=(double)c[n][m]){ // wait tide draws
					//System.out.println(t+"-"+tide+" GOGO! "+tide+":"+x+","+y+"("+f[x][y]+"-"+c[x][y]+") -> "+n+","+m+"("+f[n][m]+"-"+c[n][m]+")");
					// Go on!
					if(tide == (double)H){
						q.add(new Object[]{0.0, tide, new int[]{n, m}});
					}else{
						q.add(new Object[]{
								t+(tide>=20.0+(double)f[x][y] ? 1.0 : 10.0), 
								tide - (tide>=20.0+(double)f[x][y] ? 1.0 : 10.0)*10.0,
								new int[]{n,m}});
					}
				}else{
					// Wait... and go!
					double dt = (tide - ((double)c[n][m] - 50.0))/10.0;
					if(dt>0){
						//System.out.println(t+"-"+tide+" Wait "+dt+"sec "+tide+":"+x+","+y+"("+f[x][y]+"-"+c[x][y]+") -> "+n+","+m+"("+f[n][m]+"-"+c[n][m]+")");
						double dtt = t+dt+(tide-dt*10.0>=20.0+(double)f[x][y] ? 1.0 : 10.0);
						q.add(new Object[]{
								dtt, 
								tide - (dt+(tide-dt*10.0>=20.0+(double)f[x][y] ? 1.0 : 10.0))*10.0,
								new int[]{n,m}});
					}
				}
			}
		}
		return df.format(map[c.length-1][c[0].length-1]);
	}
	
	static class DataReader {
		public BufferedReader br;
		
		public DataReader(String filename) throws Exception {
			br = new BufferedReader(new FileReader(filename));
		}
		
		public DataReader() throws Exception {
			this("data.in");
		}
		
		private String readLine() throws Exception {
			return br.readLine();
		}
		
		public int readInt() throws Exception {
			return Integer.parseInt(readLine());
		}
		
		public double readDouble() throws Exception {
			return Double.parseDouble(readLine());
		}
		
		public int[] readInts() throws Exception {
			String[] tmp = readLine().split(" ");
			int[] ret = new int[tmp.length];
			for(int i=0;i<tmp.length;i++) ret[i] = Integer.parseInt(tmp[i]);
			return ret;
		}
		
		public double[] readDoubles() throws Exception {
			String[] tmp = readLine().split(" ");
			double[] ret = new double[tmp.length];
			for(int i=0;i<tmp.length;i++) ret[i] = Double.parseDouble(tmp[i]);
			return ret;
		}
		
		public String readString() throws Exception {
			return readLine();
		}
		
		public String[] readStrings() throws Exception {
			return readLine().split(" ");
		}
		
		public void close() throws Exception {
			br.close();
		}	
	}
		
	static class DataWriter {
		public BufferedWriter bw;
		
		public DataWriter(String filename) throws Exception {
			bw = new BufferedWriter(new FileWriter(filename));
		}
		
		public DataWriter() throws Exception {
			this("data.out");
		}
		
		public void writeLine(String line) throws Exception {
			bw.write(line);
			bw.newLine();
		}
		
		public void close() throws Exception {
			bw.flush();
			bw.close();
		}
		
	}

}


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class GC1 {

	
	public static void main(String[] args) throws IOException {
		GC1 trans = new GC1();
		trans.doMe();
	}
	private static final String ID = "practice";
	private static final String SIZE = "small";
	private static final String CODE = "A";
	
	private static final String NAME = "A-small-attempt0";
	
	public void doMe() throws IOException {
		File file = new File(NAME + ".in");
		BufferedWriter out = new BufferedWriter(new FileWriter(NAME+".out"));
		try {
			//use buffering, reading one line at a time
			//FileReader always assumes default encoding is OK!
			BufferedReader input = new BufferedReader(new FileReader(file));
			try {
				String line = input.readLine();
				int count = Integer.parseInt(line);
				
				for (int i=0;i<count;i++) {
				    line = input.readLine();
				    int count2 = Integer.parseInt(line);
				    //System.out.println(line);
				    String[] s = new String[count2];
				    for (int j = 0; j < count2; j++) {
						s[j] = input.readLine().trim();
					}
					String str = this.proccessLine(s);
					out.write("Case #"+(i+1)+": "+str);
					if (i<count-1)
						out.write(System.getProperty("line.separator"));
					System.out.println(str);
				}
			} finally {
				input.close();
				out.flush();
				out.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
	
	int[] toIntArray(String str) {
		StringTokenizer tokens = new StringTokenizer(str);
		int[] a= new int[tokens.countTokens()];
		int i = 0;
		while(tokens.hasMoreElements()) {
			a[i++] = Integer.parseInt(tokens.nextToken());
		}
		return a;
	}
	
	String proccessLine(String line[]) {
		// build graph
		int[][]ns = new int[line.length + 1][];
		for (int i = 0; i < line.length; i++) {
			ns[i+1] = toIntArray(line[i]);
		}
		
		for (int i = 1; i < ns.length; i++) {
			//if (ns[i][0]==0) {
			boolean visited[] = new boolean[ns.length+1];
			java.util.List <Integer>l = new ArrayList<Integer>();
			l.add(i);
			visited[i]=true;
			while(l.size()>0) {
				int u = l.remove(0);
				
				//System.out.println(u);
				for (int j = 1; j < ns[u].length; j++) {
					int t = ns[u][j];
					if (!visited[t]) {
						l.add(t);
						visited[t]=true;
					} else {
						return "Yes";
					}
				}
			}
			
			//}
		}
		return "No";
	}

	

}

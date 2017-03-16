import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.SortedSet;
import java.util.TreeSet;


public class User {

		public static class RankFile {

			public static String doTest(String[] lines) {
				HashMap<Integer, Integer> soldiers = new HashMap<Integer, Integer>();
				for (String line : lines){
					String[] segs = line.split(" ");
					for (String seg: segs){
						Integer soldier = Integer.parseInt(seg);
						Integer count = soldiers.get(soldier);
						if (null == count){
							soldiers.put(soldier, 1);
						} else {
							soldiers.put(soldier,  count + 1);
						}
					}
				}
				
				SortedSet<Integer> missingSoldiers = new TreeSet<Integer>();
				for (Integer soldier : soldiers.keySet()){
					if (soldiers.get(soldier) % 2 != 0){
						missingSoldiers.add(soldier);
					}
				}
				
				StringBuilder result = new StringBuilder();
				int i= 0;
				for (Integer soldier : missingSoldiers){
					if (i>0){
						result.append(" ");
					}
					result.append(soldier);
					i++;
				}
				
				return result.toString();
			}

	}

		private static final String FILENAME = "B-small-attempt0.in";
		private static final String OUTFILENAME = FILENAME.substring(0,FILENAME.lastIndexOf("."))+".out";
		public static String newline = System.getProperty("line.separator");

		private static PrintWriter out;
		private static BufferedReader input;
		
		public static void main(String[] args) throws IOException {
			setupIO();
			
			int T = Integer.parseInt(input.readLine());
			
			for (int t=1; t<=T; t++){
				String line = input.readLine();
				Integer N = Integer.parseInt(line);
				String[] lines = new String[2*N-1];
				for (int i=0; i<2*N-1; i++){
					lines[i] = input.readLine();
				}
				String result = RankFile.doTest(lines);
				out.println("Case #" + t + ": " +result);
				System.out.println("Case #" + t + ": " +result);
			}
			out.close();
		}
		
		private static void setupIO() throws IOException{
			out = new PrintWriter(new FileWriter(OUTFILENAME));
			//	PrintStream out = System.out;
				
				FileReader fr = null;
				try {
					fr = new FileReader(FILENAME);
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
				input = new BufferedReader(fr);
		}
	}

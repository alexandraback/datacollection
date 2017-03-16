import java.io.*;
import java.util.*;

public class A {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = "D:\\cj12\\"+fileName + ".in";
	private static String outputFileName = "D:\\cj12\\"+fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	 
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		//in.nextLine();
		for (int t = 1; t <= tests; t++) {
			HashMap<Integer, List<Integer>> gMap = new HashMap<Integer, List<Integer>>();
			int n = in.nextInt();
			int roots[] = new int[n];
			int r = 0;
			for(int i=1; i <= n; i++) {
				int k = in.nextInt();
				if(k ==0)
				{
					roots[r++] = i;
				}
				while(k>0) {
					int x = in.nextInt();
					if(gMap.get(x) == null)
						gMap.put(x, new ArrayList<Integer>());
					gMap.get(x).add(i);
					k--;
				}
			}
			boolean flag = false;
			String res = "No";
			for(int i=0; i< r; i++) {
				flag = traverse(roots[i], new HashMap<Integer, Integer>(), gMap);
				if(flag) {
					res = "Yes";
					break;
				}
			}
			
			System.out.println("Case #" + t + ": "+res);
			out.println("Case #" + t + ": "+res);
		}
		in.close();
		out.close();
	}
	
	public static boolean traverse(int x, HashMap<Integer, Integer> map, HashMap<Integer, List<Integer>> gMap) {
		List<Integer> list = gMap.get(x);
		if(list == null)
			return false;
		for(int i=0; i < list.size(); i++) {
			int k = list.get(i);
			if(map.containsKey(k))
				return true;
			map.put(k, null);
			boolean flag = traverse(k, map, gMap);
			if(flag)
				return flag;
		}
		return false;
	}
}



package j2012r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class A {
	public static String inputDirectory="src/j2012r1c/";
	public static String inputFile="A.in";
	public static String outputFile="A.out";
	public static PrintWriter output;
	public static boolean[][] inherits;
	public static int N;
	public static Map<Integer, Collection<Integer>> roots;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));

		int cases = s.nextInt();
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			N = s.nextInt();
			s.nextLine();
			inherits = new boolean[N+1][N+1];
			roots = new HashMap<Integer, Collection<Integer>>();
			for(int i=1;i<=N;i++) {
				int M = s.nextInt();
				for(int j =0; j<M; j++) {
					inherits[i][s.nextInt()] = true;
				}
				s.nextLine();
			}
			for(int i=1;i<=N;i++) {
				getRoots(i);
				//out(i+" "+Arrays.toString(getRoots(i).toArray()));
			}
			boolean success = false;
			for(int i=1;i<=N && !success;i++) {
				Collection<Integer> found = new HashSet<Integer>();
				for(int j = 1; j<=N; j++) {
					if (!inherits[i][j]) {
						continue;
					}
					found.add(j);
				}
				for(int j = 1; j<=N; j++) {
					if (!inherits[i][j]) {
						continue;
					}
					Collection<Integer> more = getRoots(j);
					int target = found.size() + more.size();
					found.addAll(more);
					if(found.size() < target) {
						success = true;
						break;
					}
				}
			}

			output.printf("Case #%d: %s\n", Case, success ? "Yes" : "No");
		}
		output.flush();
	}
	
	public static Collection<Integer> getRoots(int i) {
		if (roots.containsKey(i)) {
			return roots.get(i);
		}
		Set<Integer> result = new HashSet<Integer>();
		for(int j =1; j <= N; j ++) {
			if (inherits[i][j]) {
				result.add(j);
				result.addAll(getRoots(j));
			}
		}
		roots.put(i, result);
		return result;
	}
	
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Q1 {
	public static Problem[] probs;

	static class Problem {
		public int N;
		public int[] M;
		public ArrayList<Integer>[] inheritsFrom; 
	}
			
	static class Path {
		public ArrayList<Integer> classes = new ArrayList<Integer>();
		
		public String pathList() {
			StringBuffer buf = new StringBuffer("");
			for (int i=0; i<classes.size(); i++) {
				buf.append(classes.get(i) + ",");
			}
			return buf.toString();
		}
	}
	
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
			
	private static String solveProblem(Problem p) {
		ArrayList<Path> paths = new ArrayList<Path>();
		int pathsNum = 0;
		
		//Initialize
		for (int i=0; i<p.N; i++) {
			for (int j=0; j<p.M[i]; j++) {
				Path pth = new Path();
				pth.classes.add(i+1);
				pth.classes.add(p.inheritsFrom[i].get(j));
				paths.add(pth);
			}
		}
		
		//Iterate
		int startIter = 0;
		while (paths.size()!=pathsNum) {
			startIter = pathsNum;
			pathsNum = paths.size();
		
			for (int i=startIter; i<pathsNum; i++) {
				Path currPath = paths.get(i);
				int lastClass = currPath.classes.get(currPath.classes.size()-1);
				for (int j=0; j<pathsNum; j++) {
					Path testPath = paths.get(j);
					if (testPath.classes.get(0)==lastClass) {
						//append test path
						Path newPath = new Path();
						for(Integer k: currPath.classes) {
							newPath.classes.add(k);
						}
						for(int k=1; k<testPath.classes.size(); k++) {
							newPath.classes.add(testPath.classes.get(k));
						}
						paths.add(newPath);
					}
				}
			}
			
		
			int[][] check = new int[p.N+1][p.N+1];
			int i=0;
			while (i<paths.size()) {
				Path pth = paths.get(i);
				int size = pth.classes.size();
				if (size>1) {
					if (check[pth.classes.get(0)][pth.classes.get(size-1)]!=0) {
						//Check for duplicates
						String p1 = pth.pathList();
						String p2 = paths.get(check[pth.classes.get(0)][pth.classes.get(size-1)]-1).pathList();
						if (p1.equals(p2)) {
							paths.remove(i);
						} else {
						//match
							return "Yes";
						}
					} else {
						check[pth.classes.get(0)][pth.classes.get(size-1)]=i+1;
						i++;
					}
				}
			}
		}
		
		return "No";
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				probs[i].N = Integer.parseInt(pieces[0]);
				probs[i].M = new int[probs[i].N];
				probs[i].inheritsFrom = new ArrayList[probs[i].N];
				for (int j=0; j<probs[i].N; j++) {
					line = br.readLine();
					pieces = line.split(" ");
					probs[i].M[j] = Integer.parseInt(pieces[0]);
					probs[i].inheritsFrom[j] = new ArrayList<Integer>();
					for (int k=0; k<probs[i].M[j]; k++) {
						probs[i].inheritsFrom[j].add(Integer.parseInt(pieces[k+1]));
					}
				}
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

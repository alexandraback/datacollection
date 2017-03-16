import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;


public class Lawnmower {

	public static class Pair {
	    public int i;
	    public int j;
	    public Pair(int i, int j){
	        this.i = i;
	        this.j = j;
	    }
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		String line = null;
		line = br.readLine();

		int T = Integer.parseInt(line);
		
		String[] results = new String[T];
		int[] N = new int[T];
		int[] M = new int[T];
		int[][][] patterns = new int[T][][];
		
		for (int t=0; t<T; t++) {
			String[] size = br.readLine().split(" ");
			N[t] = Integer.parseInt(size[0]);
			M[t] = Integer.parseInt(size[1]);
			
			int n = N[t];
			int m = M[t];
			
			patterns[t] = new int[n][m];
			
			for (int i=0; i<n; i++) {
				String[] row = br.readLine().split(" ");
				for (int j=0; j<m; j++) {
					patterns[t][i][j] = Integer.parseInt(row[j]);
				}
			}
		}
		
		isr.close();
		br.close();
		
		for (int t=0; t<T; t++) {
			int n = N[t];
			int m = M[t];
			
			boolean isPossible = false;
			
			if (n==1 || m==1) {
				isPossible = true;
			}
			
			if (!isPossible) {
				int[][] pattern = patterns[t];
				int[] oneDPattern = twoDToOneDArray(pattern);
				
				int[] indices = new int[oneDPattern.length];
				for (int i=0; i<indices.length; i++) {
					indices[i] = i;
				}
				
				MergeSort(oneDPattern, indices, 0, oneDPattern.length-1);
				
				boolean[][] seen = new boolean[n][m];
				List<Pair> seenPairs = new LinkedList<Pair>();
				
				int prev = oneDPattern[0];
				int max = oneDPattern[oneDPattern.length-1];
				for (int k=0; k<oneDPattern.length; k++) {
					int I = indices[k]/m;
					int J = indices[k]%m;
					int newEl = oneDPattern[k];
					if (newEl == max) {
						isPossible = true;
						break;
					}
					if ( newEl != prev) {
						for (Pair pair:seenPairs) {
							pattern[pair.i][pair.j] = newEl;
						}
						prev = newEl;
					}
					
					isPossible = isSubPatternPossible(pattern, I, J, seen, seenPairs);
					if (!isPossible) {
						break;
					}
				}
			}
			
			results[t] = "Case #" + (t+1) + ": ";
			if (isPossible) {
				results[t] += "YES";
			} else {
				results[t] += "NO";
			}
			System.out.println(results[t]);
		}
		
		resultsToFile("Lawnmower.txt", results);

	}
	
	private static void resultsToFile(String fileName, String[] results) throws IOException {
		File file = new File(fileName);
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        for (int i=0; i< results.length; i++) {
        	output.write(results[i]);
        	if (i < results.length - 1) {
        		output.write("\n");
        	}
        }
        output.close();
	}
	
	private static boolean isSubPatternPossible(int[][] pattern, int I, int J, boolean[][] seen, List<Pair> seenPairs) {
		if (seen[I][J]) {
			return true;
		}
		
		int el = pattern[I][J];
		boolean isPossible = true;
		
		for (int i=0; i<pattern.length; i++) {
			if (pattern[i][J] != el) {
				isPossible = false;
				break;
			}
		}
		
		if (isPossible) {
			for (int i=0; i<pattern.length; i++) {
				seen[i][J] = true;
				seenPairs.add(new Pair(i,J));
			}
		}
		
		if (!isPossible) {
			isPossible = true;
			for (int j=0; j<pattern[0].length; j++) {
				if (pattern[I][j] != el) {
					isPossible = false;
					break;
				} else {
					seen[I][j] = true;
					seenPairs.add(new Pair(I,j));
				}
			}
			
			if(isPossible) {
				for (int j=0; j<pattern[0].length; j++) {
					seen[I][j] = true;
					seenPairs.add(new Pair(I,j));
				}
			}
		}
		
		return isPossible;
	}
	
	private static int[] twoDToOneDArray(int[][] twoD) {
		int rows = twoD.length;
		int cols = twoD[0].length;
		
		int[] oneD = new int[rows*cols]; 
		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols; j++) {
				oneD[(i*cols)+j] = twoD[i][j];
			}
		}
		
		return oneD;
	}

	public static void MergeSort(int[] arr, int[] indices, int start, int end) {
		if(start<end) {
			int mid = (start + end)/2;
			MergeSort(arr,indices,start,mid);
			MergeSort(arr,indices,mid+1,end);
			Merge(arr,indices,start,mid,end);
		}
	}
	
	public static void Merge(int[] arr, int[] indices, int start, int mid, int end){
		int[] indicesCopy = new int[indices.length];
		for (int i=0; i<indicesCopy.length; i++) {
			indicesCopy[i] = indices[i];
		}
		
		int[] left = new int[mid-start+1];
		int[] right = new int[end-mid];
		for(int i=start;i<=mid;i++) {
			left[i-start] = arr[i];
		}
		for(int j=mid+1;j<=end;j++) {
			right[j-mid-1] = arr[j];
		}
		int i = 0;
		int j = 0;
		for(int k=start;k<=end;k++) {
			if(i == left.length ) {
				arr[k] = right[j];
				indices[k] = indicesCopy[j+mid+1];
				j++;
			}
			else if(j == right.length) {
				arr[k] = left[i];
				indices[k] = indicesCopy[i+start];
				i++;
			}
			else if(left[i]<=right[j]) {
				arr[k] = left[i];
				indices[k] = indicesCopy[i+start];
				i++;
			}
			else {
				arr[k] = right[j];
				indices[k] = indicesCopy[j+mid+1];
				j++;
			}
		}
	}

}

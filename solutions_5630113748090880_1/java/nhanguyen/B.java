package gcj;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class B {
	Scanner sc; 
	List<String> listOutput = new ArrayList<>();
	Map<Integer, Integer> map = new HashMap<>();
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	
	private void run() throws Exception{
		sc = new Scanner(new File("B-large.in"));
		int T = sc.nextInt();
		for (int C = 0 ; C < T; C++){
			map.clear();
			handle();
		}
		writeFile("B-large.out", T);
	}
	
	private void handle(){
		int N = sc.nextInt();
		int num = (2*N - 1) * N;
		int[] a = new int[N];
		for (int i = 0; i < num; i++){
			int key = sc.nextInt();
			if (!map.containsKey(key)){
				map.put(key, 1);
			} else {
				int value = map.get(key);
				map.put(key, value + 1);
			}
		}
		
		int i = 0; 
		for (Entry entry: map.entrySet()){
			if ((Integer)entry.getValue() % 2 != 0){
				System.out.println(N);
				a[i] = (int)entry.getKey();
				i++;
			}
		}
		
		Arrays.sort(a);
		listOutput.add(buildOuput(a));
	}
	
	private String buildOuput(int[]a){
		StringBuilder builder = new StringBuilder();
		for ( int i = 0 ; i < a.length; i++){
			if ( i != a.length -1)
				builder.append(a[i] + " ");
			else 
				builder.append(a[i]);
		}
		return builder.toString();
	}
	
	private void writeFile(String outPath, int n) {
		try {
			File fout = new File(outPath);
			if (!fout.exists())
				fout.createNewFile();

			FileOutputStream fos = new FileOutputStream(fout);

			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));

			for (int i = 0; i < n; i++) {
				bw.write("Case #" + (i + 1) + ": " + listOutput.get(i));
				bw.newLine();
			}

			bw.close();
		} catch (Exception ex) {

			ex.printStackTrace();
		}
	}
}

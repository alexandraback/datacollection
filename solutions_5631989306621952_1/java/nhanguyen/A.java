package gcj;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {
	Scanner sc; 
	List<String> listOutput = new ArrayList<>();
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	
	
	private void run() throws Exception{
		sc = new Scanner(new File("A-large.in"));
		int T = sc.nextInt();
		for (int C = 0 ; C < T; C++){
			String res = handle(sc.next());
			System.out.println(res);
			listOutput.add(res);
		}
		writeFile("A-large.out", T);
	}
	
	private String handle(String input){
		if (input.length() == 1)
			return input;
		
		String res= String.valueOf(input.charAt(0));
		for (int i = 1 ; i < input.length() ; i++){
			if (input.charAt(i) >= res.charAt(0)){
				res = String.valueOf(input.charAt(i)) + res;
			} else {
				res = res + String.valueOf(input.charAt(i));
			}
		}
		return res; 
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

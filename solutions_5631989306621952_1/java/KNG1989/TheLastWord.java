package round1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class TheLastWord {
	public static void main(String args[]){

		String path = "round1A/TheLastWord/";
		String filename = path + "A-large.in";
		String out = path + "result_large.txt";
		File file = new File(filename);
		File outfile = new File(out);

		BufferedReader br = null;
		PrintWriter pw = null;

		try {
			br = new BufferedReader(new FileReader(file));
			pw = new PrintWriter(new BufferedWriter(new FileWriter(outfile)));

			int testCase = Integer.parseInt(br.readLine());

			for(int t=1;t<=testCase;t++){
				System.out.println("test "+ t);
				String str = br.readLine();

				String result = String.valueOf(str.charAt(0));

				for(int i=1;i<str.length();i++){
					String tmp_first = str.charAt(i) + result;
					String tmp_last = result + str.charAt(i);

					if(tmp_first.compareTo(tmp_last) < 0){
						result = tmp_last;
					}else{
						result = tmp_first;
					}

				}

				/*

				List<String> list = new ArrayList<String>();

				String first = String.valueOf(str.charAt(0));
				list.add(first);

				for(int i=1;i<str.length();i++){
					List<String> list_tmp = new ArrayList<String>();

					for(String tmp : list){
						list_tmp.add(tmp + str.charAt(i));
						list_tmp.add(str.charAt(i) + tmp);
					}

					list.clear();
					list = list_tmp;
				}

				Collections.sort(list);
				String result = list.get(list.size()-1);
*/
				pw.println("Case #"+ t + ": " + result);
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			if(br != null){
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
					System.exit(1);
				}
			}
			if(pw != null){
				pw.close();
			}
		}
	}
}

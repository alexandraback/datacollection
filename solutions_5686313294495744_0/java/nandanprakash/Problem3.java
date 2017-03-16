package round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class Problem3 {

	public static final String fileName="./round1b/"+"C-small-attempt0 (1).in";
	
	public static void main(String[] args) {
		ArrayList<String> values = new ArrayList<String>();;
		try {
		FileInputStream fis = new FileInputStream(fileName);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		long count = Long.parseLong(br.readLine());
		String line=null;
		while((line=br.readLine())!=null)
			values.add(line);
		br.close();
		FileWriter fw = new FileWriter("./round1b/"+"prob3result.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		int num=1;
		for(int i=1;i<=values.size();) {
			ArrayList<String> inputs = new ArrayList<String>();
			int inputCount = Integer.parseInt(values.get(i-1));
			for(int j=0;j<inputCount;j++) {
				inputs.add(values.get(i++));
			}
			i++;
			bw.write("Case #"+(num++)+": "+getDuplicates(inputs)+"\n");
			bw.flush();
		}
		bw.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static String getDuplicates(ArrayList<String> inputs) {
		HashMap<String,ArrayList<String>> first = new HashMap<String,ArrayList<String>>();
		HashMap<String,ArrayList<String>> second = new HashMap<String,ArrayList<String>>();
		for(String i:inputs){
			String fw = i.split(" ")[0],sw = i.split(" ")[1];
			if(first.containsKey(fw))
				first.get(fw).add(i);
			else
				first.put(fw,new ArrayList<String>(Arrays.asList(i)));
			if(second.containsKey(sw))
				second.get(sw).add(i);
			else
				second.put(sw,new ArrayList<String>(Arrays.asList(i)));
		}
		HashSet<String> fakes = new HashSet<String>();
		for (String i : inputs) {
			if (!fakes.contains(i)) {
				String fw = i.split(" ")[0], sw = i.split(" ")[1];
				ArrayList<String> fwords = first.get(fw);
				for (String s : fwords) {
					if (!fakes.contains(s))
						for (String p : second.get(sw)) {
							if (!s.equals(p) && first.get(p.split(" ")[0]).size()>1)
								fakes.add(p);
						}
				}
			}
		}
		return fakes.size()+"";
	}
}

package glycine.gcj2012.qr;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class ProblemA {
	private static List<String> srcList = new ArrayList<String>(3);
	private static List<String> destList = new ArrayList<String>(3);
	private static Map<String, String> map = new HashMap<String, String>();

	private static void init() {
		srcList.add("ejp mysljylc kd kxveddknmc re jsicpdrysi");
		srcList.add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		srcList.add("de kr kd eoya kw aej tysr re ujdr lkgc jv");
		destList.add("our language is impossible to understand");
		destList.add("there are twenty six factorial possibilities");
		destList.add("so it is okay if you want to just give up");
	}

	private static void learn() {
		for (int i = 0; i < srcList.size(); ++i) {
			String src = srcList.get(i);
			String dest = destList.get(i);
			for (int j = 0; j < src.length(); ++j) {
				map.put(String.valueOf(src.charAt(j)),
						String.valueOf(dest.charAt(j)));
			}
		}
		map.put(new String("z"), new String("q"));
		map.put(new String("q"), new String("z"));
	}

	private static void checkMap() {
		Set<String> keySet = map.keySet();
		List<String> keyList = new ArrayList<String>(keySet);
		Collections.sort(keyList);

		for (String key : keyList) {
			System.out.println(key + ": " + map.get(key));
		}
	}

	private static String solve( String inputStr){
		char[] input = inputStr.toCharArray();
		char[] result = new char[inputStr.length()];

		for( int i = 0; i < inputStr.length(); ++i ){
			result[i] = map.get(String.valueOf(input[i])).charAt(0);
		}
		return String.valueOf(result);
	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}

		init();
		learn();
//		checkMap();
//		System.out.println(map.size());

		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);

		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			String output = solve(line);
			System.out.println("Case #" + (i+1) + ": " + output);

		}

	}

}

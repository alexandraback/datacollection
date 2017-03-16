import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.base.Joiner;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.HashMultiset;
import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Multimap;
import com.google.common.collect.Multiset;
import com.google.common.collect.Multiset.Entry;
import com.google.common.collect.Sets;
import com.google.common.io.Files;

/*
 * using Google Guava (http://code.google.com/p/guava-libraries/)
 */

public class GCJ2013R1CB {
	public static void main(String[] args) throws IOException {
		String content = Files.toString(new File(args[0]), Charsets.UTF_8);
		Scanner scanner = new Scanner(content);
		
		StringBuilder output = new StringBuilder();
		int testCases = scanner.nextInt();
		for(int i=1; i<=testCases; i++) {
			String solution = "Case #"+i+": "+solve(scanner)+"\n";
			System.err.print(solution);
			output.append(solution);
		}
		Files.write(output.toString(), new File("out.out"), Charsets.UTF_8);
	}

	private static String solve(Scanner scanner) {
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		StringBuilder result = new StringBuilder();
		if (x>0) {
			for (int i=0; i<x; i++) result.append("WE");
		} else {
			for (int i=0; i>x; i--) result.append("EW");
		}
		if (y>0) {
			for (int i=0; i<y; i++) result.append("SN");
		} else {
			for (int i=0; i>y; i--) result.append("NS");
		}
		return result.toString();
	}
}

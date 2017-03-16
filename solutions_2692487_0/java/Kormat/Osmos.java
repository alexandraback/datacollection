import java.io.File;
import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

import com.google.common.base.Charsets;
import com.google.common.collect.Lists;
import com.google.common.io.Files;

/*
 * using Google Guava (http://code.google.com/p/guava-libraries/)
 */

public class Osmos {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File(args[0]));
		
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
		long size = scanner.nextLong();
		int motesNum = scanner.nextInt();
		List<Long> motes = Lists.newLinkedList();
		for (int i=0; i<motesNum; i++) {
			motes.add(scanner.nextLong());
		}
		Collections.sort(motes);
		
		if (size == 1) return ""+motes.size();
		
		long moves = Math.min(solveState(size, motes), motesNum);
		
		return ""+moves;
	}
	
	private static long solveState(long size, List<Long> motes) {
		if (motes.size() == 0) return 0;
		
		if(motes.get(0) < size) {
			size+=motes.get(0);
			motes.remove(0);
			return solveState(size, motes);
		}
		if (motes.get(0) < (2*size-1)) {
			size+=size-1;
			return 1 + solveState(size, motes);
		} else {
			List<Long> newMotes = Lists.newLinkedList(motes);
			newMotes.remove(0);
			return 1 + Math.min(solveState(2*size-1, motes), solveState(size, newMotes));
		}
	}
}

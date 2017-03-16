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
		
		long moves = Math.min(solveState(size, motes, motesNum, 0), motesNum);
		
		return ""+moves;
	}
	
	private static long solveState(long size, List<Long> motes, long motesNum, long moves) {
		if (moves > motesNum) return motesNum;
		if (motes.size() == 0) return moves;
		
		if(motes.get(0) < size) {
			size+=motes.get(0);
			motes.remove(0);
			return solveState(size, motes, motesNum, moves);
		}
		if (motes.get(0) < (2*size-1)) {
			size+=size-1;
			return solveState(size, motes, motesNum, moves+1);
		} else {
			long bigMote = motes.get(0);
			int added =0;
			long newsize = size;
			while(newsize < bigMote) {
				newsize += newsize-1;
				added++;
			}
			List<Long> newMotes = Lists.newLinkedList(motes);
			newMotes.remove(0);
			return Math.min(solveState(newsize, motes, motesNum, moves+added), solveState(size, newMotes, motesNum, moves+1));
		}
	}
}

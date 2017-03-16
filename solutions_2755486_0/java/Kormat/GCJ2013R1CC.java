import java.io.File;
import java.io.IOException;
import java.util.Collections;
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

public class GCJ2013R1CC {
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
		int tribes = scanner.nextInt();
		List<Integer> attDay   = Lists.newArrayList();
		int[] west     = new int[tribes];
		int[] east     = new int[tribes];
		int[] strength = new int[tribes];
		int[] deltaDay = new int[tribes];
		int[] deltaPos = new int[tribes];		
		int[] deltaStr = new int[tribes];
		int[] attLeft  = new int[tribes];
		int[] wall = new int[676060*2];
		int totalAttacks = 0;
		
		for (int i=0; i<tribes; i++) {
			attDay.add(scanner.nextInt());
			attLeft[i]  = (scanner.nextInt());
			west    [i] = (scanner.nextInt()+676060);
			east    [i] = (scanner.nextInt()+676060);
			strength[i] = (scanner.nextInt());
			deltaDay[i] = (scanner.nextInt());
			deltaPos[i] = (scanner.nextInt());
			deltaStr[i] = (scanner.nextInt());
			totalAttacks += attLeft[i];
		}
		
		List<Integer> attackingTribes = Lists.newArrayList();
		int successfulAttacks = 0;
		while(totalAttacks > 0) {
			int day = Collections.min(attDay);
			attackingTribes.clear();
			for(int i = 0; i< tribes; i++) {
				if (attDay.get(i) == day) {
					attackingTribes.add(i);
				}
			}
			// attack successful?
			for (int t:attackingTribes) {
				for(int x = west[t]; x<east[t]; x++) {
					if (wall[x] < strength[t]) {
						successfulAttacks++;
						break;
					}
				}
			}
			
			
			// repair wall
			for (int t:attackingTribes) {
				for(int x = west[t]; x<east[t]; x++) {
					if (wall[x] < strength[t]) {
						wall[x] = strength[t];
					}
				}
			}
			
			// update tribes & total attacks
			for (int t:attackingTribes) {
				attLeft[t]--;
				if (attLeft[t] > 0) {
					attDay.set(t, attDay.get(t)+deltaDay[t]);
				} else {
					attDay.set(t, 6760600);
				}
				west[t]     += deltaPos[t];
				east[t]     += deltaPos[t];
				strength[t] += deltaStr[t];
			}
			totalAttacks-=attackingTribes.size();
		}
		
		return ""+ successfulAttacks;
	}
}

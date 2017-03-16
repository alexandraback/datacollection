package com.github.eddiecurtis.codejam2015.round1c;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Iterator;
import java.util.stream.Stream;

public class Brattleships {
	
	public static void main(String[] args) throws Exception {
		Stream<String> lines = Files.lines(Paths.get("data/input.txt"));
		Iterator<String> iterator = lines.iterator();
		iterator.next(); // Ignore first line
		for (int testCase = 1; iterator.hasNext(); testCase++) {
			String[] line = iterator.next().split(" ");
			int rows = Integer.parseInt(line[0]);
			int cols = Integer.parseInt(line[1]);
			int shipSize = Integer.parseInt(line[2]);
			
			int turnsBeforeHit = (cols / shipSize) * rows;
			
			int mod = cols % shipSize;
			
			if (mod > 0) {
				turnsBeforeHit = turnsBeforeHit + shipSize;
			} else {
				turnsBeforeHit = turnsBeforeHit + shipSize - 1;
			}
			
			
			System.out.println("Case #" + testCase + ": " + turnsBeforeHit);
		}
	}
	
}

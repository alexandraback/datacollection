package nl.bertje.googlecodejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class ProblemA extends Problem {

  public ProblemA(String problemFile) {
	super(problemFile);
  }

  @Override
  public String solveNextCase(BufferedReader br) throws IOException {
	final String input = br.readLine();
	String remaining = input;
	final List<Integer> found = new ArrayList<>();
	Integer timesTried = 0;
	while (!remaining.isEmpty() && timesTried < 100) {
	  remaining = input;
	  String previous = "";
	  found.clear();
	  while (!remaining.isEmpty() && !previous.equals(remaining)) {
		previous = remaining;
		final List<Number> numbers = Arrays.asList(Number.values());
		Collections.shuffle(numbers);
		for (final Number number : numbers) {
		  if (number.contained(remaining)) {
			remaining = number.getNext(remaining);
			found.add(number.ordinal());
		  }
		}
	  }
	  timesTried++;
	}
	if (!remaining.isEmpty()) {
	  System.out.println("Error with " + input);
	}
	Collections.sort(found);
	String output = "";
	for (final Integer number : found) {
	  output += number;
	}

	return output;
  }

  enum Number {
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE;

	private boolean contained(String original) {
	  final List<String> chars = name().chars().mapToObj(e -> "" + (char) e).collect(Collectors.toList());
	  boolean contained = true;
	  String remaining = original;
	  for (final String character : chars) {
		if (remaining.contains(character)) {
		  remaining = remaining.replaceFirst(character, "");
		} else {
		  contained = false;
		}
	  }
	  return contained;
	}

	private String getNext(String original) {
	  final List<String> chars = name().chars().mapToObj(e -> "" + (char) e).collect(Collectors.toList());
	  boolean contained = true;
	  String remaining = original;
	  for (final String character : chars) {
		if (remaining.contains(character)) {
		  remaining = remaining.replaceFirst(character, "");
		} else {
		  contained = true;
		}
	  }
	  return contained ? remaining : original;
	}

  }

}

package nl.bertje.googlecodejam;

import java.io.BufferedReader;
import java.io.IOException;

public class ProblemB extends Problem {

  private static final char REPLACE = '?';
  private static final String REPLACE_STRING = "?";
  private static final String REPLACE_REGEX = "\\?";

  public ProblemB(String problemFile) {
	super(problemFile);
  }

  @Override
  public String solveNextCase(BufferedReader br) throws IOException {
	final String scores = br.readLine();
	final String[] splitScores = scores.split(" ");
	final String scoreOne = splitScores[0];
	final String scoreTwo = splitScores[1];

	String parsedOne = solveNext(scoreOne, scoreTwo, 0);
	String parsedTwo = solveNext(scoreTwo, scoreOne, 0);

	if (parsedOne.startsWith(REPLACE_STRING)) {
	  parsedOne = parsedOne.replaceFirst(REPLACE_REGEX, "0");
	  parsedTwo = parsedTwo.replaceFirst(REPLACE_REGEX, "0");
	}

	while (parsedOne.contains(REPLACE_STRING)) {
	  final int indexOf = parsedOne.indexOf(REPLACE_STRING);
	  String replaceOneWith = "0";
	  String replaceTwoWith = "0";
	  final int upToOne = Integer.parseInt(parsedOne.substring(0, indexOf));
	  final int upToTwo = Integer.parseInt(parsedTwo.substring(0, indexOf));
	  if (upToOne < upToTwo) {
		replaceOneWith = "9";
	  } else if (upToOne > upToTwo) {
		replaceTwoWith = "9";
	  }
	  parsedOne = parsedOne.replaceFirst(REPLACE_REGEX, replaceOneWith);
	  parsedTwo = parsedTwo.replaceFirst(REPLACE_REGEX, replaceTwoWith);
	}

	return parsedOne + " " + parsedTwo;
  }

  private String solveNext(String current, String from, int startingAt) {
	final int replaceAt = current.indexOf(REPLACE, startingAt);
	String replaced = "";
	if (replaceAt != -1 && from.charAt(replaceAt) != REPLACE) {
	  replaced += current.substring(0, replaceAt) + from.charAt(replaceAt);
	  if (replaceAt < current.length()) {
		replaced += current.substring(replaceAt + 1);
	  }
	} else {
	  replaced = current;
	}
	return replaceAt == -1 ? current : solveNext(replaced, from, replaceAt + 1);
  }

}

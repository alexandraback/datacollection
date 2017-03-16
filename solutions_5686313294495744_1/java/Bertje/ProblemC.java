package nl.bertje.googlecodejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ProblemC extends Problem {

  public ProblemC(String problemFile) {
	super(problemFile);
  }

  @Override
  public String solveNextCase(BufferedReader br) throws IOException {
	final int nrOfTitles = Integer.parseInt(br.readLine());
	final List<String> titles = new ArrayList<>();
	int fakes = 0;
	for (int i = 0; i < nrOfTitles; i++) {
	  final String topic = br.readLine();
	  titles.add(topic);
	}
	for (int i = 0; i < 50000; i++) {
	  final List<String> shuffledList = new ArrayList<>(titles);
	  Collections.shuffle(shuffledList);
	  final Set<String> firstFound = new HashSet<>();
	  final Set<String> secondFound = new HashSet<>();
	  int currentFakes = 0;
	  for (final String topic : shuffledList) {
		final String[] topicSplit = topic.split(" ");
		final String first = topicSplit[0];
		final String second = topicSplit[1];
		if (firstFound.contains(first) && secondFound.contains(second)) {
		  currentFakes++;
		} else {
		  firstFound.add(first);
		  secondFound.add(second);
		}
	  }
	  fakes = Math.max(currentFakes, fakes);
	}

	return String.valueOf(fakes);
  }

}

package nl.bertje.googlecodejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public abstract class Problem {

  private static final String PROBLEM_FILE_EXTENSION = ".in";
  private static final String SOLUTION_FILE_EXTENSION = ".out";

  private final String problemFile;

  public Problem(String problemFile) {
    this.problemFile = problemFile;
  }

  public void solve() throws IOException {
    final Path path = Paths.get(problemFile + PROBLEM_FILE_EXTENSION);
    try (BufferedReader br = Files.newBufferedReader(path)) {
      final int nrOfCases = Integer.parseInt(br.readLine());
      solveCases(nrOfCases, br);
    }
  }

  public void solveCases(final int nrOfCases, BufferedReader br) throws IOException {
    final List<String> solutions = new ArrayList<>();
    for (int currentCase = 1; currentCase <= nrOfCases; currentCase++) {
      final String solved = "Case #" + currentCase + ": " + solveNextCase(br);
      System.out.println(solved);
      solutions.add(solved);
    }
    Files.write(Paths.get(problemFile + SOLUTION_FILE_EXTENSION), solutions);
  }

  public abstract String solveNextCase(BufferedReader br) throws IOException;

}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class DancingWithTheGoolers {
  int[][] judgeScoresCache = new int[31][];

  public DancingWithTheGoolers() {
  }

  public int solveFromString(String input) {
    String[] tokens = input.split(" ");
    int playerNum = Integer.parseInt(tokens[0]);
    int surprisingTriplets = Integer.parseInt(tokens[1]);
    int p = Integer.parseInt(tokens[2]);
    int[] totalScores = new int[playerNum];
    for (int i = 0; i < playerNum; ++i) {
      totalScores[i] = Integer.parseInt(tokens[i + 3]);
    }
    return solve(surprisingTriplets, p, totalScores);
  }

  public int solve(int surprisingTriplets, int p, int[] totalScores) {
    Arrays.sort(totalScores);
    int qualifiedPlayerCnt = 0;
    int[] judgeScores;
    for (int i = totalScores.length - 1; i >= 0; --i) {
      judgeScores = getJudgeScores(totalScores[i]);
      if (judgeScores[2] >= p) {
        qualifiedPlayerCnt++;
        continue;
      }
      if (surprisingTriplets > 0) {
        if (canBeSurprised(totalScores[i])) {
          // check if max score can be better than b with surprising triplets
          int maxScore = maxScoreOfSurprisingTriplets(judgeScores);
          if (maxScore >= p) {
            qualifiedPlayerCnt++;
            surprisingTriplets--;
          }
        }
      }
    }

    return qualifiedPlayerCnt;
  }

  // return not surprised judge scores
  public int[] getJudgeScores(int totalScore) {
    if (judgeScoresCache[totalScore] != null) {
      return judgeScoresCache[totalScore];
    }
    int[] scores = new int[3];
    scores[0] = totalScore / 3;
    scores[1] = (totalScore - scores[0]) / 2;
    scores[2] = totalScore - scores[0] - scores[1];
    Arrays.sort(scores);
    judgeScoresCache[totalScore] = scores;
    return scores;
  }

  public int maxScoreOfSurprisingTriplets(int[] scores) {
    if (scores[2] == scores[1]) {
      return scores[2] + 1;
    }
    return scores[2];
  }

  public boolean canBeSurprised(int totalScore) {
    if (totalScore < 2 || totalScore > 28)
      return false;
    return true;
  }

  public static void main(String[] args) throws IOException {
    DancingWithTheGoolers solver = new DancingWithTheGoolers();
    // System.out.println(solver.solveFromString("6 2 8 29 20 8 18 18 21"));
    File folder = new File(".");
    for (File f : folder.listFiles()) {
      if (!f.getName().endsWith("in") || !f.isFile()) {
        continue;
      }
      System.out.println(f.getName());
      String outFileName = f.getName().replace("in", "out");

      BufferedReader reader = new BufferedReader(new FileReader(f));
      String str;
      int lineNum = 0, caseNum = 1;
      BufferedWriter writer = new BufferedWriter(new FileWriter(outFileName));
      lineNum = Integer.valueOf(reader.readLine());
      while ((str = reader.readLine()) != null) {
        writer.write(String.format("Case #%d: %s\n", caseNum++,
            solver.solveFromString(str)));
      }
      if (lineNum != caseNum - 1) {
        System.err.println("Case Number is not matched to input file.");
      }
      writer.flush();
      writer.close();
    }
  }

}

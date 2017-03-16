package codejam.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

public class ChinaWall {

  SortedSet<Integer> attackDays = new TreeSet<Integer>();
  HashMap<Integer, List<Attack> > attacks = new HashMap<Integer, List<Attack>>();
  HashMap<Integer, Integer> wall = new HashMap<Integer, Integer>();
  
  public static void main(String[] args) {
    ChinaWall cw = new ChinaWall();
    cw.readAndSolve(args[0], args[1]);
  }
  
  private void readAndSolve(String filePath, String outFilePath) {
    try {
      BufferedReader reader = new BufferedReader(new FileReader(filePath));
      BufferedWriter writer = new BufferedWriter(new FileWriter(outFilePath));
      String line = reader.readLine();
      int numberOfTestCases = Integer.valueOf(line);
      for (int caseNum = 0; caseNum < numberOfTestCases; ++caseNum) {
        line = reader.readLine();
        String[] splittedLine = line.split(" ");
        int numberOfTribes = Integer.valueOf(splittedLine[0]);
        Tribe[] tribes = new Tribe[numberOfTribes];
        for (int i = 0; i < numberOfTribes; ++i) {
          line = reader.readLine();
          splittedLine = line.split(" ");
          int d = Integer.valueOf(splittedLine[0]);
          int n = Integer.valueOf(splittedLine[1]);
          int w = Integer.valueOf(splittedLine[2]);
          int e = Integer.valueOf(splittedLine[3]);
          int s = Integer.valueOf(splittedLine[4]);
          int delta_d = Integer.valueOf(splittedLine[5]);
          int delta_p = Integer.valueOf(splittedLine[6]);
          int delta_s = Integer.valueOf(splittedLine[7]);
          tribes[i] = new Tribe(d, n, w, e, s, delta_d, delta_p, delta_s);
        }
        // System.err.println("Case #" + (caseNum + 1) + ": " + solve(tribes));
        writer.write("Case #" + (caseNum + 1) + ": " + solve(tribes) + "\n");
      }
      //System.err.println(solve(7, 4, 0));
      reader.close();
      writer.close();
    } catch (IOException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
  }
  
  int solve(Tribe[] tribes) {
    wall = new HashMap<Integer, Integer>();
    attackDays = new TreeSet<Integer>();
    attacks = new HashMap<Integer, List<Attack>>();
    int successfullAttacks = 0;
    createDates(tribes);
    createAttacks(tribes);
    for (Integer day : attackDays) {
      successfullAttacks += playDay(day);
    }
    return successfullAttacks;
  }
  
  private int playDay(Integer day) {
    int result = 0;
    HashMap<Integer, Integer> nextWall = new HashMap<Integer, Integer>(wall);
    for (Attack attack : attacks.get(day)) {
      boolean successfull = false;
      for (int i = attack.w; i < attack.e; ++i) {
        if (!wall.containsKey(i)) {
          wall.put(i, 0);
          nextWall.put(i, 0);
        }
        if (wall.get(i) < attack.s) {
          successfull = true;
          if (nextWall.get(i) < attack.s) {
            nextWall.put(i, attack.s);
          }
        }
      }
      if (successfull) {
        ++result;
      }
    }
    wall = nextWall;
    return result;
  }

  private void createAttacks(Tribe[] tribes) {
    for (Tribe tribe : tribes) {
      for (int i = 0; i < tribe.n; ++i) {
        Attack attack = new Attack(tribe.w + i * tribe.delta_p,
                                   tribe.e + i * tribe.delta_p,
                                   tribe.s + i * tribe.delta_s);
        attacks.get(tribe.d + i * tribe.delta_d).add(attack);
      }
    }
  }

  private void createDates(Tribe[] tribes) {
    for (Tribe tribe : tribes) {
      for (int i = 0; i < tribe.n; ++i) {
        attackDays.add(tribe.d + i * tribe.delta_d);
      }
    }
    for (Integer day : attackDays) {
      attacks.put(day, new ArrayList<Attack>());
    }
  }

  class Tribe {
    public int d;
    public int n;
    public int w;
    public int e;
    public int s;
    public int delta_d;
    public int delta_p;
    public int delta_s;

    public Tribe(int d2, int n2, int w2, int e2, int s2, int delta_d2, int delta_p2,
        int delta_s2) {
      d = d2;
      n = n2;
      w = w2;
      e = e2;
      s = s2;
      delta_d = delta_d2;
      delta_p = delta_p2;
      delta_s = delta_s2;
    }

  }
  
  class Attack {
    public int w;
    public int e;
    public int s;
    
    Attack(int w, int e, int s) {
      this.w = w;
      this.e = e;
      this.s = s;
    }
  }
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

public class C {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java C <input> <output>");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    new File(args[1]).getParentFile().mkdirs();
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line;
    line = br.readLine();
    int num = 1, parsedTribe = 1, maxTribes = 0;
    SortedMap<Integer, List<int[]>> attacks =
        new TreeMap<Integer, List<int[]>>();
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        continue;
      }
      String[] parts = line.split(" ");
      if (parts.length == 1) {
        maxTribes = Integer.parseInt(parts[0]);
      } else {
        int dayOfNextAttack = Integer.parseInt(parts[0]);
        int numberOfAttacks = Integer.parseInt(parts[1]);
        int westmostPoint = Integer.parseInt(parts[2]);
        int eastmostPoint = Integer.parseInt(parts[3]);
        int nextStrengthOfAttack = Integer.parseInt(parts[4]);
        int deltaDays = Integer.parseInt(parts[5]);
        int deltaTravel = Integer.parseInt(parts[6]);
        int deltaStrength = Integer.parseInt(parts[7]);
        for (int i = 0; i < numberOfAttacks; i++) {
          if (!attacks.containsKey(dayOfNextAttack)) {
            attacks.put(dayOfNextAttack, new ArrayList<int[]>());
          }
          int[] attack = new int[5];
          attack[0] = parsedTribe;
          attack[1] = dayOfNextAttack;
          attack[2] = westmostPoint;
          attack[3] = eastmostPoint;
          attack[4] = nextStrengthOfAttack;
          attacks.get(dayOfNextAttack).add(attack);
          dayOfNextAttack += deltaDays;
          westmostPoint += deltaTravel;
          eastmostPoint += deltaTravel;
          nextStrengthOfAttack += deltaStrength;
        }
        if (parsedTribe++ == maxTribes) {
          int successes = 0;
          SortedMap<Integer, Integer>
              wall = new TreeMap<Integer, Integer>();
          for (Map.Entry<Integer, List<int[]>> e : attacks.entrySet()) {
            SortedMap<Integer, Integer> newWall =
                new TreeMap<Integer, Integer>(wall);
            int day = e.getKey();
            for (int[] attack : e.getValue()) {
              int tribe = attack[1];
              int west = attack[2];
              int east = attack[3];
              int height = attack[4];
              boolean success = false;
              for (int pos = west; pos < east; pos++) {
                if (!wall.containsKey(pos) || wall.get(pos) < height) {
                  success = true;
                }
                int newHeight = height;
                if (newWall.containsKey(pos)) {
                  newHeight = Math.max(newHeight, newWall.get(pos));
                }
                newWall.put(pos, newHeight);
              }
              /*System.out.println("Attack: day=" + day + " tribe=" + tribe
                  + " west=" + west + " east=" + east + " height="
                  + height + " success=" + (success ? "yes" : "no"));*/
              if (success) {
                successes++;
              }
            }
            /*System.out.print("New wall: ");
            for (Map.Entry<Integer, Integer> f : newWall.entrySet()) {
              System.out.print(" " + f.getKey() + "=" + f.getValue());
            }
            System.out.println();*/
            wall = newWall;
          }
          bw.write("Case #" + num++ + ": " + successes + "\n");
          parsedTribe = 1;
          maxTribes = 0;
          attacks.clear();
        }
      }
      
    }
    br.close();
    bw.close();
  }
}


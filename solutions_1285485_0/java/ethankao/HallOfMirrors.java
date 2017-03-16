import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class HallOfMirrors {
  private int[][] map;
  private int meH, meW;
  private double d;

  enum TravelType {BackFromStart, ReflectedVertical, ReflectedHorizontal, PassThrough, Destroy,  }

  public HallOfMirrors(int[][] map, int meH, int meW, double d) {
    this.map = map;
    this.meH = meH;
    this.meW = meW;
    this.d = d;
  }

  public int lightTravel(int fromH, int fromW, int toH, int toW, int hitMeCount, double travelDis, int multiplier) {
    if (toH == -1 || toW == -1)
      return hitMeCount;

    int passMeCnt = 0;
    TravelType t = getTravelType(fromH, fromW, toH, toW);
    int[] nextLoc = findNextObstacle(fromH, fromW, toH, toW);

    if (t == TravelType.BackFromStart) {
      int[] loc1 = nextLoc;
      double dis1 = calcDist(fromH, fromW, toH, toW) * 2;
      nextLoc = findNextObstacle(toH, toW, fromH, fromW);
      t = getTravelType(fromH, fromW, nextLoc[0], nextLoc[1]);
      double dis2 = calcDist(fromH, fromW, nextLoc[0], nextLoc[1]) * 2;

      travelDis += dis1;
      System.out.println("travel round trip from (" + fromH + ", " + fromW + ") to (" + toH  + ", " + toW + ")");
      System.out.println("Dist: " + travelDis);
      if (loc1[2] != -1) {
        multiplier *= 3;
      }
      if (map[fromH][fromW] == 2 && (d - travelDis) >= 0) {
        hitMeCount += multiplier;
        passMeCnt++;
      }

      if (loc1[2] == -1) {
        return hitMeCount;
      } else if (t != TravelType.BackFromStart) {
        hitMeCount = lightTravel(fromH, fromW, nextLoc[0], nextLoc[1], hitMeCount, travelDis, multiplier);
      } else {
        while ((d - travelDis) >= 0) {
          travelDis += dis2;
          System.out.println("travel round trip from (" + fromH + ", " + fromW + ") to (" + nextLoc[0]  + ", " + nextLoc[1] + ")");
          System.out.println("Dist: " + travelDis);
          if (loc1[2] != -1) {
            multiplier *= 3;
          }
          if (map[fromH][fromW] == 2 && (d - travelDis) >= 0) {
            hitMeCount += multiplier;
            passMeCnt++;
          }
          travelDis += dis1;
          System.out.println("travel round trip from (" + fromH + ", " + fromW + ") to (" + toH  + ", " + toW + ")");
          System.out.println("Dist: " + travelDis);
          if (loc1[2] != -1) {
            multiplier *= 3;
          }
          if (map[fromH][fromW] == 2 && (d - travelDis) >= 0) {
            hitMeCount += multiplier;
            passMeCnt++;
          }
        }
        hitMeCount -= Math.pow(3, passMeCnt - 1);
      } 
      return hitMeCount;
    } else {
      travelDis += calcDist(fromH, fromW, toH, toW);
      System.out.println("travel from (" + fromH + ", " + fromW + ") to (" + toH  + ", " + toW + ")");
      System.out.println("Dist: " + travelDis);
      if (d - travelDis < 0)
        return hitMeCount;

      if (map[toH][toW] == 2) {
        hitMeCount += multiplier;
        passMeCnt++;
        if (Math.abs(fromH - toH) == Math.abs(fromW - toW))
          return hitMeCount;
      }
      return lightTravel(toH, toW, nextLoc[0], nextLoc[1], hitMeCount, travelDis, multiplier);
    }
  }
  
  public int solve() {
    int images = 0;
    // map format: 0 empty, 1 mirror, 2 me
    for (int h = 0; h < map.length; ++h) {
      for (int w = 0; w < map[0].length; ++w) {
        if (map[h][w] == 1 && canTravel(h, w)) {
//          System.out.println("Start to: (" + h + ", " + w + ")");
          images += lightTravel2(meH, meW, h, w, 0, 0, 1);
        }
      }
    }
    return images;
  }

  public double calcDist(int fromH, int fromW, int toH, int toW) {
    boolean containMe = ((map[fromH][fromW] == 2) || (map[toH][toW] == 2));
    double x = Math.abs(toW - fromW);
    double y = Math.abs(toH - fromH);
    double delta = containMe ? 0.5 : 1;
    if (x != 0 && y == 0) {
      x -= delta;
    } else if (y != 0 && x == 0) {
      y -= delta;
    } else {
      x -= 0.5;
      y -= 0.5;
    }
    
    return Math.sqrt((x * x) + (y * y));
  }

  public int[] findNextObstacle(int fromH, int fromW, int toH, int toW) {
    TravelType t = getTravelType(fromH, fromW, toH, toW);
    // if the third number is not -1, it means not right angle (45 or 0)
    int[] mirrorLoc = {-1, -1, -1};
    boolean isMirror = map[toH][toW] == 1;
    if (t == TravelType.Destroy)
      return mirrorLoc;
    // from to to find next obstacle
    if (fromH == toH) {
      int unitW = (fromW > toW) ? 1 : -1;
      if (!isMirror) {
        return mirrorLoc;
      }
      int posW = toW + unitW;
      while (posW >= 0 && posW < map[0].length) {
        //System.out.println("Go : " + meH + " "+ posW);
        if (map[fromH][posW] != 0) {
          mirrorLoc[0] = fromH;
          mirrorLoc[1] = posW;
          return mirrorLoc;
        }
        posW += unitW;
      }
    } else if (fromW == toW) {
      int unitH = (fromH > toH) ? 1 : -1;
      if (!isMirror) {
        return mirrorLoc;
      }
      int posH = toH + unitH;
      while (posH >= 0 && posH < map.length) {
        //System.out.println("Go : " + posH + " "+ meW);
        if (map[posH][fromW] != 0) {
          mirrorLoc[0] = posH;
          mirrorLoc[1] = fromW;
          return mirrorLoc;
        }
        posH += unitH;
      } 
    } else {
      // other angle
      int hUnit = (fromH > toH) ? 1 : -1;
      int wUnit = (fromW > toW) ? 1 : -1;
      double deltaH = fromH - toH;
      double deltaW = fromW - toW;
      if (Math.abs(deltaH) != Math.abs(deltaW))
        mirrorLoc[2] = 0;
      if (t == TravelType.ReflectedVertical) {
        deltaH *= -1;
        hUnit *= -1;
      } else if (t == TravelType.ReflectedHorizontal) {
        deltaW *= -1;
        wUnit *= -1;
      }

      if (!isMirror) {
        hUnit *= -1;
        wUnit *= -1;
        deltaH *= -1;
        deltaW *= -1;
      }
      double dis = calcDist(fromH, fromW, toH, toW) * 2;
      deltaH /= dis;
      deltaW /= dis;
      double posHd = toH + deltaH;
      double posWd = toW + deltaW;
      int posH = (int) Math.ceil(posHd * hUnit) * hUnit;
      int posW = (int) Math.ceil(posWd * wUnit) * wUnit;
      while (posH >= 0 && posW >= 0 && posH < map.length && posW < map[0].length) {
        //System.out.println("Go: " + posH + " " + posW);
        if (map[posH][posW] != 0 && posH != toH && posW != toW) {
          mirrorLoc[0] = posH;
          mirrorLoc[1] = posW;
          return mirrorLoc;
        }
        posHd += deltaH;
        posWd += deltaW;
        posH = (int) Math.ceil(posHd * hUnit) * hUnit;
        posW = (int) Math.ceil(posWd * wUnit) * wUnit;
      }
    }
    return mirrorLoc;
  }

  public TravelType getTravelType(int mirrorH, int mirrorW) {
    return getTravelType(meH, meW, mirrorH, mirrorW);
  }

  public TravelType getTravelType(int fromH, int fromW, int toH, int toW) {
    if (fromH == -1 || fromW == -1 || toH == -1 || toW == -1)
      return TravelType.Destroy;
    if (map[toH][toW] == 2)
      return TravelType.PassThrough;
    else if (fromH == toH || fromW == toW) {
      return TravelType.BackFromStart;
    } else {
      int hUnit = (fromH > toH) ? -1 : 1;
      int wUnit = (fromW > toW) ? -1 : 1;
      if (map[toH - hUnit][toW] == 1 && map[toH][toW - wUnit] == 1) {
        return TravelType.BackFromStart;
      } else if (map[toH - hUnit][toW] == 0 && map[toH][toW - wUnit] == 0) {
        return TravelType.Destroy;
      } else if (map[toH - hUnit][toW] == 1) {
        return TravelType.ReflectedVertical;
      } else {
        return TravelType.ReflectedHorizontal;
      }
    }
  }

  public boolean canTravel(int mirrorH, int mirrorW) {
    return canTravel(meH, meW, mirrorH, mirrorW);
  }
  
  public boolean canTravel(int fromH, int fromW, int mirrorH, int mirrorW) {
    // check angles and obstacle in two points
    if (fromH == mirrorH) {
      // horizontal
      int start = (fromW > mirrorW) ? mirrorW : fromW;
      int end = (fromW > mirrorW) ? fromW : mirrorW;
      for (int i = start + 1; i < end; ++i) {
        //System.out.println("test: " + fromH + " " + i);
        if (map[fromH][i] != 0) {
          return false;
        }
      }
      return true;
    } else if (fromW == mirrorW) {
      // vertical
      int start = (fromH > mirrorH) ? mirrorH : fromH;
      int end = (fromH > mirrorH) ? fromH : mirrorH;
      for (int i = start + 1; i < end; ++i) {
        //System.out.println("test: " + i + " " + meW);
        if (map[i][fromW] != 0) {
          return false;
        }
      }
      return true;
    } else {
      // other angles, need to meet case three
      // check if we have any obstacle from me to mirror
      int hUnit = (fromH > mirrorH) ? 1 : -1;
      int wUnit = (fromW > mirrorW) ? 1 : -1;
      double startH = fromH, startW = fromW;
      double toH = mirrorH + 1, toW = mirrorW + 1;
      if (map[fromH][fromW] == 2) {
        startH += 0.5;
        startW += 0.5;
      }
      double deltaH = toH - startH;
      double deltaW = toW - startW;
      double dis = calcDist(fromH, fromW, mirrorH, mirrorW) * 2;
      deltaH /= dis;
      deltaW /= dis;
      double posHd = startH + deltaH;
      double posWd = startW + deltaW;
      int posH = (int) Math.floor(posHd);
      int posW = (int) Math.floor(posWd);
      boolean cond = true;
      if (hUnit == 1) {
        cond = posH > mirrorH;
      } else {
        cond = posH < mirrorH;
      }
      if (wUnit == 1) {
        cond = cond && posW > mirrorW;
      } else {
        cond = cond && posW < mirrorW;
      }
      while (cond) {
        //System.out.println("test: " + posH + " " + posW);
        if (map[posH][posW] == 1) {
          return false;
        }
        posHd += deltaH;
        posWd += deltaW;
        posH = (int) Math.floor(posHd);
        posW = (int) Math.floor(posWd);
        if (hUnit == 1) {
          cond = posH > mirrorH;
        } else {
          cond = posH < mirrorH;
        }
        if (wUnit == 1) {
          cond = cond && posW > mirrorW;
        } else {
          cond = cond && posW < mirrorW;
        }
      }
      return true;
    }
  }

  public static HallOfMirrors getHallOfMirrors(String[] inputs) {
    String[] tokens = inputs[0].split(" ");
    int h = Integer.valueOf(tokens[0]);
    int w = Integer.valueOf(tokens[1]);
    double d = Double.valueOf(tokens[2]);
    int meH = 0, meW = 0;
    int[][] map = new int[h][w];
    for (int i = 0; i < h; ++i) {
      char[] cs = inputs[i + 1].toCharArray();
      for (int j = 0; j < w; ++j) {
        if (cs[j] == '#') {
          map[i][j] = 1;
        } else if (cs[j] == 'X') {
          map[i][j] = 2;
          meH = i;
          meW = j;
        }
      }
    }
    System.out.println(meH + " " + meW + " " + d);
    for (int i = 0; i < map.length; ++i) {
      System.out.println(Arrays.toString(map[i]));
    }
    return new HallOfMirrors(map, meH, meW, d);
  }

  public int lightTravel2(int fromH, int fromW, int toH, int toW, int hitMeCount, double travelDis, int multiplier) {
    if (toH == -1 || toW == -1)
      return hitMeCount;

    int passMeCnt = 0;
    TravelType t = getTravelType(fromH, fromW, toH, toW);
    int[] nextLoc = findNextObstacle(fromH, fromW, toH, toW);

    if (t == TravelType.BackFromStart) {
      int[] loc1 = nextLoc;
      double dis1 = calcDist(fromH, fromW, toH, toW) * 2;
      nextLoc = findNextObstacle(toH, toW, fromH, fromW);
      t = getTravelType(fromH, fromW, nextLoc[0], nextLoc[1]);
      double dis2 = calcDist(fromH, fromW, nextLoc[0], nextLoc[1]) * 2;

      travelDis += dis1;
      System.out.println("travel round trip from (" + fromH + ", " + fromW + ") to (" + toH  + ", " + toW + ")");
      System.out.println("Dist: " + travelDis);
      if (loc1[2] != -1) {
        multiplier *= 3;
      }

      if (map[fromH][fromW] == 2 && (d - travelDis) >= 0) {
        hitMeCount += multiplier;
        passMeCnt++;
      }

      if (loc1[2] == -1) {
        return hitMeCount;
      } else {
        while ((d - travelDis) >= 0 && t != TravelType.Destroy) {
          travelDis += dis2;
          System.out.println("travel round trip from (" + fromH + ", " + fromW + ") to (" + nextLoc[0]  + ", " + nextLoc[1] + ")");
          System.out.println("Dist: " + travelDis);
          if (loc1[2] != -1) {
            multiplier *= 3;
          }
          if (map[fromH][fromW] == 2 && (d - travelDis) >= 0) {
            hitMeCount += multiplier;
            passMeCnt++;
          }
          travelDis += dis1;
          System.out.println("travel round trip from (" + fromH + ", " + fromW + ") to (" + toH  + ", " + toW + ")");
          System.out.println("Dist: " + travelDis);
          if (loc1[2] != -1) {
            multiplier *= 3;
          }
          if (map[fromH][fromW] == 2 && (d - travelDis) >= 0) {
            hitMeCount += multiplier;
            passMeCnt++;
          }
        }
      }
      int result = 0, p = 0;
      for (int i = 0; i < passMeCnt; ++i) {
        if ( i != 0)
          p = (int) Math.pow(3, i);
        result += Math.pow(3, i + 1);
      }
      result -= p;
      return result;
    } else {
      travelDis += calcDist(fromH, fromW, toH, toW);
      System.out.println("travel from (" + fromH + ", " + fromW + ") to (" + toH  + ", " + toW + ")");
      System.out.println("Dist: " + travelDis);
      if (d - travelDis < 0)
        return hitMeCount;

      if (map[toH][toW] == 2) {
        hitMeCount += multiplier;
        passMeCnt++;
        if (Math.abs(fromH - toH) == Math.abs(fromW - toW))
          return hitMeCount;
      }
      return lightTravel(toH, toW, nextLoc[0], nextLoc[1], hitMeCount, travelDis, multiplier);
    }
  }

  public static void main(String[] args) throws IOException {
    String[] testInput = 
      { "3 3 1", 
        "###", 
        "#X#", 
        "###" };
    String[] testInput2 = {
        "5 6 10",
        "######",
        "#..X.#",
        "#.#..#",
        "#...##",
        "######"};
    String[] testInput3 = { 
        "4 3 8", 
        "###", 
        "#X#", 
        "#.#", 
        "###" };
    HallOfMirrors solver2 = HallOfMirrors.getHallOfMirrors(testInput3);
    //System.out.println(Arrays.toString(solver2.findNextObstacle(1, 3, 2, 5)));
    //System.out.println(solver2.lightTravel2(1, 1, 3, 0, 0, 0, 1));
    System.out.println(solver2.solve());

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
      boolean firstLine = true;
      String[] inputs = null;
      int ind = 1;
      while ((str = reader.readLine()) != null) {
        str = str.trim();
        if (firstLine) {
          String[] tokens = str.split(" ");
          int h = Integer.valueOf(tokens[0]);
          inputs = new String[h + 1];
          inputs[0] = str;
          ind = 1;
          firstLine = false;
        } else {
          inputs[ind++] = str;
          if (ind == inputs.length) {
            HallOfMirrors solver = HallOfMirrors.getHallOfMirrors(inputs);
            writer.write(String.format("Case #%d: %d\n", caseNum++,
                solver.solve()));
            firstLine = true;
          }
        }
      }
      if (lineNum != caseNum - 1) {
        System.err.println("Case Number is not matched to input file.");
      }
      writer.flush();
      writer.close();
    }
  }

}

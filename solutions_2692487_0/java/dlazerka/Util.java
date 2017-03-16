package util;

import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigInteger;

public class Util {
  public static long readLong(BufferedReader reader) throws IOException {
    String s = reader.readLine().trim();
    return Long.parseLong(s);
  }

  public static int readInt(BufferedReader reader) throws IOException {
    return (int) readLong(reader);
  }

  public static int[] readInts(BufferedReader reader) throws IOException {
    String s = reader.readLine().trim();
    String[] split = s.split(" ");
    int[] result = new int[split.length];
    for (int i = 0; i < split.length; i++) {
      result[i] = Integer.parseInt(split[i]);
    }
    return result;
  }

  public static long[] readLongs(BufferedReader reader) throws IOException {
    String s = reader.readLine().trim();
    String[] split = s.split(" ");
    long[] result = new long[split.length];
    for (int i = 0; i < split.length; i++) {
      result[i] = Long.parseLong(split[i]);
    }
    return result;
  }

  public static BigInteger[] readBigIntegers(BufferedReader reader) throws IOException {
      String s = reader.readLine().trim();
      String[] split = s.split(" ");
      BigInteger[] result = new BigInteger[split.length];
      for (int i = 0; i < split.length; i++) {
        result[i] = new BigInteger(split[i]);
      }
      return result;
    }

  public static String readLine(BufferedReader reader) throws IOException {
    return reader.readLine().trim();
  }

  public static void printMap(char[][] map) {
    for (int h = 0; h < map.length; h++) {
      for (int w = 0; w < map[h].length; w++) {
        System.out.print(map[h][w]);
      }
      System.out.println();
    }
  }
}

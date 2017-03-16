package lt.kasrud.gcj.common;


import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class IO {
  public static Data readFile(String filename) throws IOException {
    Data results = new Data();

    BufferedReader reader = new BufferedReader(new FileReader(filename));
    String line = null;
    while ((line = reader.readLine()) != null) {
      results.add(new Record(line));
    }

    reader.close();
    return results;
  }

  private static String formatCase(int caseNr, String output) {
    return String.format("Case #%d: %s", caseNr, output);
  }

  public static void writeFile(String filename, List data) throws IOException {
    BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
    for (int i = 0; i < data.size(); i++) {
      String output = formatCase(i + 1, data.get(i).toString());
      writer.write(output + "\n");
    }
    writer.close();
  }

  public static class Data {
    List<Record> records = new ArrayList<Record>();

    public void add(Record record) {
      records.add(record);
    }

    public String getString(int recNr, int i) {
      Record record = getRecord(recNr);
      return record.getString(i);
    }

    public Integer getInt(int recNr, int i) {
      Record record = getRecord(recNr);
      return record.getInt(i);
    }

    public Double getDouble(int recNr, int i) {
      Record record = getRecord(recNr);
      return record.getDouble(i);
    }

    public Record getRecord(int recNr) {
      return records.get(recNr);
    }

    public List<Record> getRecords(int from) {
      return getRecords(from, records.size());
    }

    public List<Record> getRecords(int from, int to) {
      return records.subList(from, to);
    }

    public int size() {
      return records.size();
    }
  }

  public static class Record {
    String raw;
    String[] tokens;

    Record(String raw) {
      this(raw, " ");
    }

    Record(String raw, String separator) {
      this.raw = raw;
      tokens = raw.trim().split(separator);
    }

    public String getRaw() {
      return raw;
    }

    public String getString(int i) {
      return tokens[i];
    }

    public int getInt(int i) {
      return Integer.valueOf(getString(i));
    }

    public List<String> getStringList(int from) {
      return getStringList(from, tokens.length);
    }

    public List<String> getStringList(int from, int to) {
      return Arrays.asList(tokens).subList(from, to);
    }

    public List<Integer> getIntList(int from) {
      return getIntList(from, tokens.length);
    }

    public List<Integer> getIntList(int from, int to) {
      List<String> strings = Arrays.asList(tokens).subList(from, to);
      List<Integer> ints = new ArrayList<Integer>(strings.size());
      for (String s : strings) {
        ints.add(Integer.valueOf(s));
      }
      return ints;
    }

    public Double getDouble(int i) {
      return Double.valueOf(getString(i));
    }

    public List<Double> getDoubleList(int from) {
      return getDoubleList(from, tokens.length);
    }

    public List<Double> getDoubleList(int from, int to) {
      List<String> strings = Arrays.asList(tokens).subList(from, to);
      List<Double> doubles = new ArrayList<Double>(strings.size());
      for (String s : strings) {
        doubles.add(Double.valueOf(s));
      }
      return doubles;
    }
  }
}

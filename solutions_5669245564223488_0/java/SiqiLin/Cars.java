package cars;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class Cars {
    public static void main(String[] args) {
        try {
            BufferedReader reader = Files.newBufferedReader(Paths.get("./cars-in.txt"), Charset.forName("US-ASCII"));
            BufferedWriter writer = Files.newBufferedWriter(Paths.get("./cars-out.txt"), Charset.forName("US-ASCII"));
            int T = Integer.parseInt(reader.readLine());
            outer: for (int t = 1; t <= T; t++) {
                reader.readLine();
                boolean skip = false;
                String line = reader.readLine();
                String[] splitted = line.split(" ");
                List<String> trainsStartingWith = new ArrayList<String>();
                List<String> trainsEndingWith = new ArrayList<String>();
                List<String> binaryTrains = new ArrayList<String>();
                Map<String, Integer> unaryTrains = new TreeMap<String, Integer>();

                for (String train : splitted) {
                    if (!isValidTrain(train)) {
                        skip = true;
                        break;
                    }
                    if ((train.length() == 1) || (train.charAt(0) == train.charAt(train.length() - 1))) {
                        String key = "" + train.charAt(0);
                        if (unaryTrains.containsKey(key)) {
                            unaryTrains.put(key, unaryTrains.get(key) + 1);
                        } else {
                            unaryTrains.put(key, 1);
                        }
                    } else {
                        String starting = "" + train.charAt(0);
                        String ending = "" + train.charAt(train.length() - 1);

                        if (trainsStartingWith.contains(starting)) {
                            skip = true;
                        } else {
                            trainsStartingWith.add(starting);
                        }
                        if (trainsEndingWith.contains(ending)) {
                            skip = true;
                        } else {
                            trainsEndingWith.add(ending);
                        }

                        binaryTrains.add(starting + ending);
                    }
                }
                if (!skip) {
                    while (true) {
                        boolean repeat = false;
                        for (int i = 0; i < binaryTrains.size(); i++) {
                            if (!repeat) {
                                for (int j = i + 1; j < binaryTrains.size(); j++) {
                                    if (!repeat) {
                                        String train1 = binaryTrains.get(i);
                                        String train2 = binaryTrains.get(j);
                                        if (train1.charAt(1) == train2.charAt(0)) {
                                            binaryTrains.remove(j);
                                            binaryTrains.remove(i);
                                            binaryTrains.add("" + train1.charAt(0) + train2.charAt(1));
                                            repeat = true;
                                        } else if (train2.charAt(1) == train1.charAt(0)) {
                                            binaryTrains.remove(j);
                                            binaryTrains.remove(i);
                                            binaryTrains.add("" + train2.charAt(0) + train1.charAt(1));
                                            repeat = true;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            } else {
                                break;
                            }
                        }
                        if (!repeat) {
                            break;
                        }
                    }
                    BigInteger count = BigInteger.ONE;
                    Map<String, BigInteger> newUnaryTrains = new TreeMap<String, BigInteger>();
                    for (Map.Entry<String, Integer> entry : unaryTrains.entrySet()) {
                        String key = entry.getKey();
                        newUnaryTrains.put(key, factorial(entry.getValue()));
                    }
                    for (BigInteger value : newUnaryTrains.values()) {
                        count = count.multiply(value);
                    }
                    int uniqueUnaries = 0;
                    for (String train : newUnaryTrains.keySet()) {
                        if (trainsStartingWith.contains(train) || trainsEndingWith.contains(train)) {
                            continue;
                        } else {
                            uniqueUnaries++;
                        }
                    }
                    count = count.multiply(factorial(binaryTrains.size() + uniqueUnaries));
                    writer.write(String.format("Case #%s: %s", t, count.mod(BigInteger.valueOf(1000000007L))));
                } else {
                    writer.write(String.format("Case #%s: 0", t));
                }
                writer.newLine();
            }
            writer.close();
            reader.close();
        } catch (IOException e) {

        }
    }

    public static BigInteger factorial(int n) {
        BigInteger result = BigInteger.valueOf(1);

        for (int i = 1; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }

        return result;
    }

    public static boolean isValidTrain(String train) {
        ArrayList<Character> seen = new ArrayList<>();

        char startChar = train.charAt(0);
        char endChar = train.charAt(train.length() - 1);
        char diff = startChar;

        if ((train.length() == 1) || (train.length() == 2)) {
            return true;
        }

        for (int i = 0; i < train.length(); i++) {
            if (train.charAt(i) != diff) {
                if (seen.contains(train.charAt(i))) {
                    return false;
                } else {
                    seen.add(train.charAt(i));
                    diff = train.charAt(i);
                }
            }
        }

        return true;
    }
}
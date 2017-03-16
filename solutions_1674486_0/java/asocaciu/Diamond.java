package ch.socaciu.andrei.codejam;

import java.io.*;
import java.util.*;

/**
 * @author Andrei Socaciu
 */
public class Diamond {

    public static void main(String[] args) throws Exception {
        String inFile = "data/Diamond-small-attempt3.in.txt";
        String outFile = "data/Diamond-small-attempt3.out.txt";
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(inFile), "ISO-8859-1"));
        String line1;
        LinkedList<String> result = new LinkedList<String>();
        while ((line1 = reader.readLine()) != null) {
            result.add(line1);
        }
        reader.close();
        List<String> lines = result;
        List<String> results = new LinkedList<String>();

        int testCaseCount = Integer.parseInt(lines.remove(0));
        int lineNr = 0;
        for (int i = 0; i < testCaseCount; i++) {
            Map<Integer, List<Integer>> subClasses = new HashMap<Integer, List<Integer>>();
            String line = lines.get(lineNr++);
            int n = Integer.parseInt(line);
            for (int j = 0; j < n; j++) {
                line = lines.get(lineNr++);
                String[] parts = line.split(" ");
                int m = Integer.parseInt(parts[0]);
                for (int k = 0; k < m; k++) {
                    int parent = Integer.parseInt(parts[k + 1]);
                    List<Integer> scs = subClasses.get(parent);
                    if (scs == null) {
                        scs = new ArrayList<Integer>();
                        subClasses.put(parent, scs);
                    }
                    scs.add(j+1);
                }
            }

            boolean diamond = solve2(subClasses);
            results.add("Case #" + (i + 1) + ": " + (diamond ? "Yes" : "No"));
        }


        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outFile), "ISO-8859-1"));
        for (String resultLine : results) {
            writer.write(resultLine);
            writer.write("\r\n");
        }
        writer.close();
    }

    private static boolean solve2(Map<Integer, List<Integer>> subClasses) {
        try {
            for (Integer aClass : subClasses.keySet()) {
                getSubclasses(aClass, subClasses);
            }
        } catch (IllegalArgumentException iae) {
            return true;
        }
        return false;
    }

    private static void getSubclasses(Integer aClass, Map<Integer, List<Integer>> subClasses) {
        Set<Integer> scs = new HashSet<Integer>();
        List<Integer> queue = new ArrayList<Integer>();
        queue.add(aClass);
        while (!queue.isEmpty()) {
            Integer cls = queue.remove(0);
            List<Integer> subcl = subClasses.get(cls);
            if (subcl != null) {
                for (Integer sc : subcl) {
                    queue.add(sc);
                    if (!scs.add(sc)) {
                        throw new IllegalArgumentException();
                    }
                }
            }
        }
    }

}

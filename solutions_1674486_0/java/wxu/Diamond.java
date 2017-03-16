package codejam.round1a;

import java.io.*;
import java.util.*;

public class Diamond {
    private static boolean found = false;

    public static void main(String[] args) throws IOException {
        InputStream is;
        OutputStream os;
        if (args.length > 0) {
            is = new FileInputStream(args[0]);
        } else {
            is = System.in;
        }

        if (args.length > 1) {
            os = new FileOutputStream(args[1]);
        } else {
            os = System.out;
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(os));
        BufferedReader inputReader = new BufferedReader(new InputStreamReader(is));
        String firstLine = inputReader.readLine();
        int count_of_cases = Integer.parseInt(firstLine);

        for (int idx_of_case = 1; idx_of_case <= count_of_cases; idx_of_case++) {
            found = false;
            String caseLine = inputReader.readLine();

            int count = Integer.parseInt(caseLine);

            HashMap<Integer, HashSet<Integer>> numbersList = new HashMap<Integer, HashSet<Integer>>(count);
            for (int i = 1; i <= count; i++) {
                String classLine = inputReader.readLine();
                String[] deps = classLine.split(" ");
                HashSet<Integer> d = new HashSet<Integer>();
                for (int j = 1; j < deps.length; j++) {
                    d.add(Integer.parseInt(deps[j]));
                }
                numbersList.put(i, d);
            }

            boolean has = has_dia(numbersList);

            writer.write(String.format("Case #%d: %s", idx_of_case, has ? "Yes" : "No"));
            writer.newLine();

        }

        writer.close();
        inputReader.close();
    }

    private static boolean has_dia(HashMap<Integer, HashSet<Integer>> numbersList) {
        for (int i = 1; i <= numbersList.size(); i++) {
            if (numbersList.get(i).isEmpty()) {
                find_by_deps(numbersList, i);

                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    private static HashSet<Integer> find_by_deps(HashMap<Integer, HashSet<Integer>> numbersList, int idx) {
        HashSet<Integer> children = new HashSet<Integer>();

        for (int i = 1; i <= numbersList.size(); i++) {
            if (i == idx) {
                continue;
            }

            if (numbersList.get(i).contains(idx)) {
                if (children.contains(i)) {
                    found = true;
                    System.out.println("--------22222222222222222222222");
                    System.out.println(children);
                    System.out.println("--------");
                    break;

                }
                children.add(i);
                HashSet<Integer> sub_deps = find_by_deps(numbersList, i);

                for (Integer sub_dep : sub_deps) {
                    if (children.contains(sub_dep)) {
                        found = true;
                        System.out.println("--------");
                        System.out.println(children);
                        System.out.println(sub_deps);
                        System.out.println("--------");
                        break;
                    }
                }

                if (found) {
                    break;
                }
                children.addAll(sub_deps);
            }
        }
        return children;
    }

}

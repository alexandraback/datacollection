package jam.jam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 *
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 29.04.12
 * Time: 22:15
 */
public class Round1CA {

    public static void main(String[] args) throws Exception {
        new Round1CA().run();
    }

    private void run() throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("input/A-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output/A-large.out"));
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for (int i = 0; i < cases; i++) {
            line = br.readLine();
            int n = Integer.parseInt(line);
            Clazz[] classes = new Clazz[n];
            for (int j = 0; j < n; j++) {
                line = br.readLine();
                String[] parts1 = line.split(" ");
                int m = Integer.parseInt(parts1[0]);
                classes[j] = new Clazz();
                classes[j].parents = new int[m];
                for (int k = 1; k < parts1.length; k++) {
                    String s = parts1[k];
                    classes[j].parents[k - 1] = Integer.parseInt(s);
                }
            }
            String result = calculate(classes);
            System.out.println("Case #" + (i + 1) + ": " + result);
            bw.write("Case #" + (i + 1) + ": " + result);
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private String calculate(Clazz[] classes) {
        for (int i = 0; i < classes.length; i++) {
            Clazz aClass = classes[i];
            aClass.parentsC = new Clazz[aClass.parents.length];
            for (int j = 0; j < aClass.parents.length; j++) {
                int parent = aClass.parents[j] - 1;
                aClass.parentsC[j] = classes[parent];
            }
        }
        for (int i = 0; i < classes.length; i++) {
            Clazz aClass = classes[i];
            List<Clazz> toGo = new ArrayList<Clazz>();
            toGo.add(aClass);
            List<Clazz> ntoGo = new ArrayList<Clazz>();
            while(toGo.size() > 0) {
                for (Clazz clazz : toGo) {
                    for (Clazz parent : clazz.parentsC) {
                        if(parent.have(i)) {
                            return "Yes";
                        } else {
                            parent.accessibleFrom.add(i);
                            ntoGo.add(parent);
                        }
                    }
                }
                toGo.clear();
                toGo.addAll(ntoGo);
                ntoGo.clear();
            }
        }
        return "No";
    }

    private void traverse(Clazz aClass, int i) {

    }

    private class Clazz {
        private int[] parents;
        private Clazz[] parentsC;
        private Set<Integer> accessibleFrom = new HashSet<Integer>();

        public boolean have(int i) {
            return accessibleFrom.contains(i);
        }
    }
}

package codejam1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CodeJamQualfication {

    public static void main(String[] args) {
        File file = new File("C:\\codejam\\data.txt");
        File result = new File("C:\\codejam\\result.txt");


        try {
            BufferedReader input = new BufferedReader(new FileReader(file));
            FileWriter writer = new FileWriter(result);



            int testCases = Integer.valueOf(input.readLine()).intValue();

            for (int i = 0; i < testCases; i++) {
                List<Node> nodes = new ArrayList<Node>();
                short noClasses = Short.valueOf(input.readLine()).shortValue();
                for (short j = 1; j <= noClasses; j++) {
                    writeDirectInheritances(input.readLine(), nodes, j);
                }
                if (checkForDiamonds(nodes)) {
                    writer.append("Case #" + (i + 1) + ": Yes\n");
                } else {
                    writer.append("Case #" + (i + 1) + ": No\n");
                }                
            }

            input.close();
            writer.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean checkForDiamonds(List<Node> nodes) {
        for (Node n : nodes) {
            try {                
                addSuperClasses(nodes, n.name);
                Collections.sort(n.allInheritsFrom);                
            } catch (AlreadyHasException ex) {
                return true;
            }
        }
        return false;
    }

    private static List<Short> addSuperClasses(List<Node> nodes, short name) throws AlreadyHasException {

        List<Short> result = new ArrayList<Short>();

        Node n = nodes.get(name - 1);
        if (!n.counted) {
            n.counted = true;
            addAndThrowExWhenRepeated(n.allInheritsFrom, n.directInheritsFrom);
            //n.allInheritsFrom.addAll(n.directInheritsFrom);
            result.addAll(n.directInheritsFrom);

            for (short p : n.directInheritsFrom) {
                List<Short> toAdd = addSuperClasses(nodes, p);
                addAndThrowExWhenRepeated(n.allInheritsFrom, toAdd);
                result.addAll(toAdd);
            }
        }     
        else{
            result.addAll(n.allInheritsFrom);
        }
        return result;
    }

    private static void addAndThrowExWhenRepeated(List<Short> list, List<Short> toAdd) throws AlreadyHasException {
        for (short s : toAdd) {
            if (list.contains(s)) {
                throw new AlreadyHasException();
            } else {
                list.add(s);
            }
        }

    }

    private static void writeDirectInheritances(String line, List<Node> nodes, short className) {
        String[] arr = line.split(" ");
        Node n = new Node();
        n.name = className;
        boolean first = true;
        for (String s : arr) {
            if (first) {
                first = false;
            } else {
                n.directInheritsFrom.add(Short.valueOf(s).shortValue());
            }
        }
        nodes.add(n);
    }

    //writes result to output
    private static void processLine(String line, int i) {
        StringBuilder sb = new StringBuilder("Case #");
        sb.append(i);
        sb.append(": ");
        for (char c : line.toCharArray()) {
            //sb.append(codeMap.get(c));
        }
        System.err.println(sb.toString());
    }
}

class AlreadyHasException extends Exception {
}

class Node {

    short name;
    List<Short> directInheritsFrom = new ArrayList<Short>();
    List<Short> allInheritsFrom = new ArrayList<Short>();
    boolean counted = false;
}
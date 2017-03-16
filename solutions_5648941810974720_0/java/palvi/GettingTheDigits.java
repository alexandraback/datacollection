/**
 * Created by pallavi on 30/4/16.
 */

import java.io.*;
import java.util.*;

public class GettingTheDigits {
    public static void f(Map<Character, Integer> map, char c, int cc) {
        if (map.containsKey(c)) map.put(c, map.get(c)-cc);
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader("in.txt")));
        PrintWriter writer = new PrintWriter("out.txt");
        int t = scanner.nextInt();
        for (int i = 1; i <= t; i++) {
            char[] ch = scanner.next().toCharArray();
            Map<Character, Integer> map = new HashMap<>();
            TreeMap<Integer, Integer> treeMap = new TreeMap<>();
            for (int j = 0; j < ch.length; j++) {
                if (!map.containsKey(ch[j])) map.put(ch[j], 0);
                map.put(ch[j], map.get(ch[j])+1);
            }
            int c = 0;
            if (map.containsKey('Z')) c = map.get('Z');
            f(map, 'Z', c);
            f(map, 'E', c);
            f(map, 'R', c);
            f(map, 'O', c);
            treeMap.put(0, c);
            c = 0;
            if (map.containsKey('W')) c = map.get('W');
            f(map, 'T', c);
            f(map, 'W', c);
            f(map, 'O', c);
            treeMap.put(2, c);
            c = 0;
            if (map.containsKey('X')) c = map.get('X');
            f(map, 'S', c);
            f(map, 'I', c);
            f(map, 'X', c);
            treeMap.put(6, c);
            c = 0;
            if (map.containsKey('U')) c = map.get('U');
            f(map, 'F', c);
            f(map, 'O', c);
            f(map, 'U', c);
            f(map, 'R', c);
            treeMap.put(4, c);
            c = 0;
            if (map.containsKey('F')) c = map.get('F');
            f(map, 'F', c);
            f(map, 'I', c);
            f(map, 'V', c);
            f(map, 'E', c);
            treeMap.put(5, c);
            c = 0;
            if (map.containsKey('S')) c = map.get('S');
            f(map, 'S', c);
            f(map, 'E', 2*c);
            f(map, 'V', c);
            f(map, 'N', c);
            treeMap.put(7, c);
            c = 0;
            if (map.containsKey('R')) c = map.get('R');
            f(map, 'T', c);
            f(map, 'H', c);
            f(map, 'R', c);
            f(map, 'E', 2 * c);
            treeMap.put(3, c);
            c = 0;
            if (map.containsKey('O')) c = map.get('O');
            f(map, 'O', c);
            f(map, 'N', c);
            f(map, 'E', c);
            treeMap.put(1, c);
            c = 0;
            if (map.containsKey('T')) c = map.get('T');
            f(map, 'E', c);
            f(map, 'I', c);
            f(map, 'G', c);
            f(map, 'H', c);
            f(map, 'T', c);
            treeMap.put(8, c);
            c = 0;
            if (map.containsKey('E')) c = map.get('E');
            f(map, 'N', c);
            f(map, 'I', c);
            f(map, 'N', c);
            f(map, 'E', c);
            treeMap.put(9, c);
            writer.print("Case #" + i + ": ");
            for (int j: treeMap.keySet()) {
                c = treeMap.get(j);
                for (int k = 0; k < c; k++) {
                    writer.print(j);
                }
            }
            writer.println();
        }
        writer.close();
        scanner.close();
    }
}

package GoogleR1A;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created by Jason on 4/15/2016.
 */
public class C {

    public static void main(String args[]) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        for (int i = 0; i < T; i++) {
            int length = reader.nextInt();
            int[] array = new int[length+1];
            for (int j = 1; j < array.length; j++) {
                array[j] = reader.nextInt();
            }
            int answer = 2;
            for (int j = 1; j < array.length; j++) {
                LinkedList<LinkedList<Integer>> list = new LinkedList<>();
                LinkedList<Integer> b = new LinkedList<>();
                b.add(j);
                list.add(b);
                boolean changed;
                LinkedList<LinkedList<Integer>> buffer = new LinkedList<>();
                LinkedList<LinkedList<Integer>> allposible = new LinkedList<>();
                do {
                    changed = false;
                    for (LinkedList<Integer> l : list) {
                        int head = l.getFirst();
                        int tail = l.getLast();
                        for (int k = 1; k < array.length; k++){
                            if (l.contains(k)) {
                                continue;
                            }
                            if (array[k] == head && (l.size() == 1 || array[head] == l.get(1))) {
                                LinkedList<Integer> n = new LinkedList<>(l);
                                n.addFirst(k);
                                buffer.add(n);
                                changed = true;
                            }
                            if (k == array[head]) {
                                LinkedList<Integer> n = new LinkedList<>(l);
                                n.addFirst(k);
                                buffer.add(n);
                                changed = true;
                            }
                            if (array[k] == tail && (l.size() == 1 || array[tail] == l.get(l.size() - 2))) {
                                LinkedList<Integer> n = new LinkedList<>(l);
                                n.add(k);
                                buffer.add(n);
                                changed = true;
                            }
                            if (k == array[tail]) {
                                LinkedList<Integer> n = new LinkedList<>(l);
                                n.add(k);
                                buffer.add(n);
                                changed = true;
                            }
                        }
                    }
                    if (changed) {
                        list.clear();
                        list.addAll(buffer);
                        allposible.addAll(buffer);
                        buffer.clear();
                    }
                } while(changed);
                for (LinkedList<Integer> l : allposible) {
//                    System.out.println(l);
//                    System.out.println("check");
//                    if (check(l, array)) {
//                        System.out.println(l);
//                    }
                    if (l.size() > answer && check(l, array)) {
                        answer = l.size();
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + answer);
        }
    }

    private static boolean check(LinkedList<Integer> list, int[] array) {
        if (list.size() < 2) {
            return false;
        }
        if (list.get(1) != array[list.get(0)] && list.getLast() != array[list.get(0)]) {
            return false;
        }
        if (!(list.get(list.size()-2) == array[list.getLast()] || list.getFirst() == array[list.getLast()])) {
            return false;
        }
        for (int i = 1; i < list.size()-1; i++) {
            if (array[list.get(i)] != list.get(i+1) && array[list.get(i)] != list.get(i-1)) {
                return false;
            }
        }
        return true;
    }
}

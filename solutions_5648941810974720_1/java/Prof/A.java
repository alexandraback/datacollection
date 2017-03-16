package ee.prof;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        Scanner sc = new Scanner(new File("A-large.in"));
//        Scanner sc = new Scanner(System.in);
//        PrintStream out = System.out;
//        PrintStream out = new PrintStream(new FileOutputStream("A-small.out"));
        PrintStream out = new PrintStream(new FileOutputStream("A-large.out"));
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String str = sc.next();
            char[] chars = str.toCharArray();
            List<Integer> result = new ArrayList<>();
            List<Character> list = new ArrayList<>();
            for (char aChar : chars) {
                list.add(aChar);
            }
            while (!list.isEmpty()) {
                int z = list.indexOf('Z');
                if(z>=0){
                    result.add(0);
                    list.remove(new Character('Z'));
                    list.remove(new Character('E'));
                    list.remove(new Character('R'));
                    list.remove(new Character('O'));
                    continue;
                }
                int x = list.indexOf('X');
                if(x>=0){
                    result.add(6);
                    list.remove(new Character('S'));
                    list.remove(new Character('I'));
                    list.remove(new Character('X'));
                    continue;
                }
                int w = list.indexOf('W');
                if(w>=0){
                    result.add(2);
                    list.remove(new Character('T'));
                    list.remove(new Character('W'));
                    list.remove(new Character('O'));
                    continue;
                }
                int g = list.indexOf('G');
                if(g>=0){
                    result.add(8);
                    list.remove(new Character('E'));
                    list.remove(new Character('I'));
                    list.remove(new Character('G'));
                    list.remove(new Character('H'));
                    list.remove(new Character('T'));
                    continue;
                }
                int u = list.indexOf('U');
                if(u>=0){
                    result.add(4);
                    list.remove(new Character('F'));
                    list.remove(new Character('O'));
                    list.remove(new Character('U'));
                    list.remove(new Character('R'));
                    continue;
                }
                //----------
                int s = list.indexOf('S');
                if(s>=0){
                    result.add(7);
                    list.remove(new Character('S'));
                    list.remove(new Character('E'));
                    list.remove(new Character('V'));
                    list.remove(new Character('E'));
                    list.remove(new Character('N'));
                    continue;
                }
                int f = list.indexOf('F');
                if(f>=0){
                    result.add(5);
                    list.remove(new Character('F'));
                    list.remove(new Character('I'));
                    list.remove(new Character('V'));
                    list.remove(new Character('E'));
                    continue;
                }
                int h = list.indexOf('H');
                if(h>=0){
                    result.add(3);
                    list.remove(new Character('T'));
                    list.remove(new Character('H'));
                    list.remove(new Character('R'));
                    list.remove(new Character('E'));
                    list.remove(new Character('E'));
                    continue;
                }
                int o = list.indexOf('O');
                if(o>=0){
                    result.add(1);
                    list.remove(new Character('O'));
                    list.remove(new Character('N'));
                    list.remove(new Character('E'));
                    continue;
                }
                result.add(9);
                list.remove(new Character('N'));
                list.remove(new Character('I'));
                list.remove(new Character('N'));
                list.remove(new Character('E'));
            }

            Collections.sort(result);
            out.print("Case #" + (i + 1) + ": ");
            for (Integer integer : result) {
                out.print(integer);
            }
            out.println();
        }

    }
}

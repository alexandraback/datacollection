
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import sun.security.util.Length;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Erico
 */
public class Osmos {

    public static void printTab(int[] tab, boolean withCharacter) {
        System.out.print("[");
        for (int i = 0; i < tab.length - 1; i++) {
            System.out.print((withCharacter ? ((char) (i + 'a')) + ":" : "") + tab[i] + ", ");
        }
        if (tab.length > 0) {
            System.out.print((withCharacter ? ((char) (tab.length - 1 + 'a')) + ":" : "") + tab[tab.length - 1]);
        }
        System.out.print("]\n");
    }

    public static int min(int[] nb, int os, int p){
        if (p == nb.length - 1)
            return os > nb[p] ? 0 : 1;
        int v = nb[p];
        if (os > v)
            return min(nb, os + v, p + 1);
        int v1 = 1 + min(nb, os, p + 1);
        int v2 = min(nb, evalNextOs(os, v), p + 1) + evalNbAdd(os, v);
        return v1 < v2 ? v1 : v2;
    }

    public static int evalNextOs(int os, int dest) {
        while (os <= dest) {
            os += os - 1;
        }
        return os + dest;
    }

    public static int evalNbAdd(int os, int dest) {
        int nb = 0;
        while (os <= dest) {
            os += os - 1;
            nb++;
        }
        return nb;
    }

    public static int computeScore(String str, int os, int nbos) {
        if (nbos == 0) {
            return 0;
        }
        int val = 0;
        String[] parts = str.split(" ");
        if (os == 0) {
            return parts.length;
        }
        int[] v = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            v[i] = Integer.parseInt(parts[i]);
        }
        Arrays.sort(v);
        if (os == 1) {
            val = parts.length;
            for (int i = 0; i < parts.length && v[i] < 1; i++) {
                val--;
            }
            return val;
        }
        return min(v, os, 0);
    }
    public static int nbAdd;

    public static void main(String[] args) throws FileNotFoundException {
        String inputFileName = args.length > 0 ? args[0] : "in.txt";
        String outPutFileName = args.length > 1 ? args[1] : "out.txt";
        Scanner sc = new Scanner(new File(inputFileName));
        PrintWriter pw = new PrintWriter(outPutFileName);
        String str = sc.nextLine(), part[];
        int nb = Integer.parseInt(str), score;
        int os, nbos;
        for (int i = 0; i < nb; i++) {
            str = sc.nextLine();
            os = Integer.parseInt((part = str.split(" "))[0]);
            nbos = Integer.parseInt(part[1]);
            str = sc.nextLine();
            score = computeScore(str, os, nbos);
            pw.println(str = "Case #" + (i + 1) + ": " + score);
            System.out.println(str);
        }
        pw.flush();
        pw.close();
    }
}

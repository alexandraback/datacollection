import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Chathura
 */
public class Solution {

    public static void main(String[] args) throws FileNotFoundException, IOException {

        Scanner scnr = new Scanner(new File("in.in"));
        int T = scnr.nextInt();
        ArrayList<String> answeres = new ArrayList<>();
        for (int i = 0; i < T; i++) {
            int L = scnr.nextInt();
            int X = scnr.nextInt();
            scnr.nextLine();
            String read = scnr.nextLine();
            ArrayList<Element> elements = new ArrayList<>();
            for (int j = 0; j < read.length(); j++) {
                Element e = new Element(read.charAt(j), 1);
                elements.add(e);

            }
            if (elements.size() == 1 || L * X < 3) {
                answeres.add("NO");
                continue;
            }

            ArrayList<Element> eleCOpy = new ArrayList<>(elements);
            for (int j = 0; j < X - 1; j++) {
                elements.addAll(eleCOpy);
            }
            //System.out.println(elements.toString());
            Element mul = new Element('1', 1);
            for (int j = 0; j < elements.size(); j++) {
                mul = mul.mul(elements.get(j));                
            }
            if(!mul.toString().equals("-1")){
                answeres.add("NO");
                continue;
            }

            boolean find = findI(elements);
            if (find) {
                answeres.add("YES");
            } else {
                answeres.add("NO");
            }

            //System.out.println("done " + (i + 1));

        }

        String out = "";
        for (int i = 0; i < T; i++) {
            out += "Case #" + (i + 1) + ": ";
            out += answeres.get(i);
            if (i != T - 1) {
                out += "\r\n";
            }
        }
        System.out.println(out);
        File outF = new File("out.out");
        FileWriter fw = new FileWriter(outF);
        fw.write(out);
        fw.flush();//*/

    }

    public static boolean findI(ArrayList<Element> elements) {
        boolean foundIJK = false;
        Element prod = new Element('1', 1);
        for (int i = 0; i < elements.size(); i++) {
            prod = prod.mul(elements.get(i));
            // System.out.println(prod);
            if (prod.toString().equals("i")) {
                //System.out.println("found i");
                boolean comp = findJ(elements, i);
                if (comp) {
                    foundIJK = true;
                    break;
                }
            }

        }
        return foundIJK;
    }

    public static boolean findJ(ArrayList<Element> elements, int start) {
        boolean foundK = false;
        Element prod = new Element('1', 1);
        for (int i = start + 1; i < elements.size(); i++) {
            prod = prod.mul(elements.get(i));
            //System.out.println("prod in j "+prod);
            if (prod.toString().equals("j")) {
                //System.out.println("found j");
                boolean comp = isK(elements, i);
                if (comp) {
                    foundK = true;
                    //System.out.println("found k");
                    break;
                }
            }

        }
        return foundK;
    }

    public static boolean isK(ArrayList<Element> elements, int start) {
        Element prod = new Element('1', 1);
        for (int i = start + 1; i < elements.size(); i++) {
            prod = prod.mul(elements.get(i));
        }
        return prod.toString().equals("k");
    }

    static class Element {

        private Character ltr;
        private int sign;

        public Element(char ltr, int sign) {
            this.ltr = ltr;
            this.sign = sign;
        }

        public Element mul(Element ele) {
            int mulSign = ltr.compareTo(ele.ltr) <= 0 ? 1 : -1;
            if (ltr.equals('i') && ele.ltr.equals('k')) {
                mulSign = -1;
            } else if (ltr.equals('k') && ele.ltr.equals('i')) {
                mulSign = 1;
            }

            if (ele.ltr == '1') {
                return new Element(ltr, sign * ele.sign);
            } else if (ltr.equals('1')) {
                return new Element(ele.ltr, sign * ele.sign);
            } else if (ele.ltr.equals(this.ltr)) {
                return new Element('1', -1 * mulSign * sign * ele.sign);
            } else if (ele.ltr.equals('i')) {
                if (this.ltr.equals('j')) {
                    return new Element('k', mulSign * sign * ele.sign);
                } else {
                    return new Element('j', mulSign * sign * ele.sign);
                }
            } else if (ele.ltr.equals('j')) {
                if (this.ltr.equals('k')) {
                    return new Element('i', mulSign * sign * ele.sign);
                } else {
                    return new Element('k', mulSign * sign * ele.sign);
                }
            } else {
                if (this.ltr.equals('j')) {
                    return new Element('i', mulSign * sign * ele.sign);
                } else {
                    return new Element('j', mulSign * sign * ele.sign);
                }
            }
        }

        @Override
        public String toString() {
            return sign > 0 ? ltr.toString() : "-" + ltr;
        }

    }

}

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author khelman
 */
public class Train {

    public static final long MOD = 1000000007L;

    public static void main(String... args) throws IOException {
        FileReader fr = new FileReader("d:\\train.in");
        BufferedReader br = new BufferedReader(fr);
        String s = br.readLine();

        FileWriter f0 = new FileWriter("d:\\train.out");

        int t = Integer.parseInt(s.trim());

        for (int i = 1; i <= t; i++) {
            s = br.readLine();
            int n = Integer.parseInt(s);

            s = br.readLine();
            String[] elems = s.split(" ");

            for (int j = 0; j < n; j++) {
                elems[j] = compact(elems[j]);
            }

            boolean isOk = true;

            int[] endings = new int[255];
            int[] trapped = new int[255];


            //check elements
            for (String elem : elems) {

                if (elem.length() > 1 && isOk) {
                    endings[elem.charAt(0)]++;
                    if (endings[elem.charAt(0)] == 2) {
                        isOk = false;
                        break;
                    }

                    for (int j = 1; j < elem.length() - 1; j++) {
                        trapped[elem.charAt(j)]++;
                        if (trapped[elem.charAt(j)] == 2) {
                            isOk = false;
                            break;
                        }
                    }

                    if (elem.length() > 2 && elem.charAt(0) == elem.charAt(elem.length() - 1)) {
                        isOk = false;
                        break;
                    }
                }
            }

            for (String elem : elems) {
                if (isOk) {
                    if (trapped[elem.charAt(0)] > 0) {
                        isOk = false;
                        break;
                    }

                    if (trapped[elem.charAt(elem.length() - 1)] > 0) {
                        isOk = false;
                        break;
                    }
                }
            }

            char[] isAfter = new char[255];

            for (String elem : elems) {
                if (elem.length() > 1) {
                    char c = elem.charAt(elem.length() - 1);
                    isAfter[c] = elem.charAt(0);
                    while (isAfter[isAfter[c]] != 0 && isAfter[c] != c) {
                        isAfter[c] = isAfter[isAfter[c]];
                    }

                    if (isAfter[c] == c) {
                        isOk = false;
                        break;
                    }
                }
            }


            if (!isOk) {
                System.out.println("Case #" + i + ": " + 0);
                f0.write("Case #" + i + ": " + 0 + "\r\n");
                continue;
            }

            MixingBag[] bags = new MixingBag[255];
            //separate singleCharacters from rest
            for (String elem : elems) {
                if (elem.length() == 1) {
                    char c = elem.charAt(0);
                    if (bags[c] == null) {
                        bags[c] = new MixingBag(c);
                    } else {
                        bags[c].increment();
                    }
                }
            }

            List<Element> e = new ArrayList<Element>(n);
            for (MixingBag bag : bags) {
                if (bag != null) {
                    e.add(bag);
                }
            }

            //create single elements
            for (String elem : elems) {
                if (elem.length() > 1) {
                    e.add(new SingleElem(elem.charAt(0), elem.charAt(elem.length() - 1)));
                }
            }

            //compact everything
            boolean changed;
            do {
                changed = false;
                bigger:
                for (Element firstElem : e) {
                    for (Element secondElem : e) {
                        if (firstElem != secondElem && firstElem.getLastChar() == secondElem.getFirstChar()) {
                            e.remove(firstElem);
                            e.remove(secondElem);
                            e.add(new OrderedPair(firstElem, secondElem));
                            changed = true;
                            break bigger;
                        }
                    }
                }
            } while (changed);

            long ret = 1;
            long count = 1;

            for (Element element : e) {
                ret = (ret * element.getResult() * count) % MOD;
                count++;
            }


            System.out.println("Case #" + i + ": " + ret);
            f0.write("Case #" + i + ": " + ret + "\r\n");
        }

        fr.close();
        f0.close();
    }

    private static class MixingBag extends Element {

        private int count = 1;

        private MixingBag(char ch) {
            super(ch, ch);
        }

        public void increment() {
            count++;
        }

        @Override
        long getResult() {
            long ret = 1;

            for (long i = 1; i <= count; i++) {
                ret = (ret * i) % MOD;
            }

            return ret;
        }

        @Override
        public String toString() {
            return "Mix{" + getFirstChar() + "," + count + "!}";
        }
    }

    private static class OrderedPair extends Element {

        Element left;
        Element right;

        private OrderedPair(Element left, Element right) {
            super(left.firstChar, right.lastChar);
            this.left = left;
            this.right = right;
        }

        @Override
        long getResult() {
            return (left.getResult() * right.getResult()) % MOD;
        }

        @Override
        public String toString() {
            return "Pair{" + left.toString() + "," + right.toString() + "}";
        }
    }

    private static class SingleElem extends Element {

        private SingleElem(char firstChar, char lastChar) {
            super(firstChar, lastChar);
        }

        @Override
        long getResult() {
            return 1L;
        }

        @Override
        public String toString() {
            return "Sin{" + getFirstChar() + getLastChar() + "}";
        }
    }

    private static abstract class Element {

        private char firstChar;
        private char lastChar;

        private Element(char firstChar, char lastChar) {
            this.firstChar = firstChar;
            this.lastChar = lastChar;
        }

        public char getFirstChar() {
            return firstChar;
        }

        char getLastChar() {
            return lastChar;
        }

        abstract long getResult();
    }


    public static String compact(String input) {

        StringBuilder sb = new StringBuilder();

        char lastChar = input.charAt(0);
        sb.append(lastChar);

        for (int i = 1; i < input.length(); i++) {

            char curChar = input.charAt(i);
            if (curChar != lastChar) {
                sb.append(curChar);
                lastChar = curChar;
            }

        }

        return sb.toString();

    }

}

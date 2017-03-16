package twentythirteen.contest;

import java.io.*;
import java.util.HashSet;
import java.util.Set;

/**
 * User: Grant
 * Date: 13/04/13
 * Time: 15:05
 */
public class A2 {

    public static void main(String[] args) throws IOException {
        // Prepare output file
        File outputFile = new File("E:\\Programming\\Java\\CodeJam\\resources\\twentythirteen\\contest\\A-small-attempt.out");
        if(outputFile.exists()) {
            outputFile.delete();
        }
        // a == 97
        // e == 101
        // i == 105
        // o == 111
        // u == 117

        FileWriter fileWriter = new FileWriter(outputFile);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        // Read input file
        File inputFile = new File("E:\\Programming\\Java\\CodeJam\\resources\\twentythirteen\\contest\\A-small-attempt.in");
        FileReader fileReader = new FileReader(inputFile);
        BufferedReader bufferedReader = new BufferedReader(fileReader);

        Integer testCases = Integer.parseInt(bufferedReader.readLine().trim());
        for(int t = 0; t < testCases; t++) {
            StringBuilder output = new StringBuilder();
            String[] nextLine = bufferedReader.readLine().split(" ");
            String name = nextLine[0];
            int minLength = Integer.parseInt(nextLine[1]);

            int consecutive = 0;
            Set<MyString> mySubs = new HashSet<MyString>();
            for(int i = 0; i < name.length(); i++) {
                final char n = name.charAt(i);
                if(n != 'a'
                    && n != 'e'
                    && n != 'i'
                    && n != 'o'
                    && n != 'u'
                ) {
                    consecutive++;

                    if(consecutive >= minLength) {
                        mySubs.addAll(substringThisFecker(name, i + 1 - minLength, i + 1));
                    }

                }
                else {
                    consecutive = 0;
                }
            }

            output.append("Case #").append(t+1).append(": ").append(mySubs.size()).append("\n");

            bufferedWriter.write(output.toString());
        }
        bufferedReader.close();
        fileReader.close();

        // Write output file
        bufferedWriter.flush();
        fileWriter.flush();
        bufferedWriter.close();
        fileWriter.close();
    }
    private static Set<MyString> substringThisFecker(String name, int start, int end) {
        Set<MyString> theSubs = new HashSet<MyString>();
        for(int i = 0; i <= start; i++) {
            theSubs.add(new MyString(name.substring(i, name.length()), i));
        }
        for(int i = name.length(); i >= end; i--) {
            theSubs.add(new MyString(name.substring(start, i), start));
        }
        for(int s = 0; s <= start; s++) {
            for(int e = name.length(); e >= end; e--) {
                theSubs.add(new MyString(name.substring(s, e), s));
            }
        }

        return theSubs;
    }

    private static class MyString {
        String string;
        int start;

        private MyString(String string, int start) {
            this.string = string;
            this.start = start;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            MyString myString = (MyString) o;

            if (start != myString.start) return false;
            if (!string.equals(myString.string)) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = string.hashCode();
            result = 31 * result + start;
            return result;
        }

        @Override
        public String toString() {
            return "MyString{" +
                    "string='" + string + '\'' +
                    ", start=" + start +
                    '}';
        }
    }
}

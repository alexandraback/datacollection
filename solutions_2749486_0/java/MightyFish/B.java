package twentythirteen.contest;

import java.io.*;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

/**
 * User: Grant
 * Date: 13/04/13
 * Time: 15:05
 */
public class B {

    public static void main(String[] args) throws IOException {
        // Prepare output file
        File outputFile = new File("E:\\Programming\\Java\\CodeJam\\resources\\twentythirteen\\contest\\B-small-attempt.out");
        if(outputFile.exists()) {
            outputFile.delete();
        }

        int[] movements = {1, -1};
        boolean[] verticalHorizontal = {true, false};

        FileWriter fileWriter = new FileWriter(outputFile);
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        // Read input file
        File inputFile = new File("E:\\Programming\\Java\\CodeJam\\resources\\twentythirteen\\contest\\B-small-attempt.in");
        FileReader fileReader = new FileReader(inputFile);
        BufferedReader bufferedReader = new BufferedReader(fileReader);

        Integer testCases = Integer.parseInt(bufferedReader.readLine().trim());
        for(int t = 0; t < testCases; t++) {
            StringBuilder output = new StringBuilder();
            output.append("Case #").append(t+1).append(": ");

            String[] nextLine = bufferedReader.readLine().split(" ");
            int ex = Integer.parseInt(nextLine[0]);
            int ey = Integer.parseInt(nextLine[1]);

            int myx = 0;
            int myy = 0;

            boolean madeIt = false;
            StringBuilder path = new StringBuilder();
            int stepSize = 1;
            Random random = new Random();
            while(!madeIt) {
                int movement = movements[random.nextInt(2)];
                boolean vertical = verticalHorizontal[random.nextInt(2)];
                if(vertical) {
                    myy += (movement * stepSize);
                }
                else {
                    myx += (movement * stepSize);
                }
                stepSize++;
                path.append(getPath(movement, vertical));
                if(myx == ex && myy == ey) {
                    output.append(path);
                    madeIt = true;
                }
                else if(stepSize > 500) {
                    myx = myy = 0;
                    stepSize = 1;
                    path = new StringBuilder();
                }
            }

            output.append("\n");

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
    private static String getPath(int movement, boolean vertical) {
        if(movement == -1 && vertical) {
            return "S";
        }
        if(movement == 1 && vertical) {
            return "N";
        }
        if(movement == 1 && !vertical) {
            return "E";
        }
        if(movement == -1 && !vertical) {
            return "W";
        }
        return "LALALALA";
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

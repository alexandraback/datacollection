package org.active.nerd.code.jam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collection;

import org.active.nerd.code.jam.InOutProcessor.LineReader;
import org.active.nerd.code.jam.InOutProcessor.Result;

public class InOutProcessor<R extends LineReader<T>, T extends Result> {

    private static final String NEWLINE = System.getProperty("line.separator");

    private static final String RESC_PATH_IN = "./src/resc/in/";
    private static final String RESC_PATH_OUT = "./src/resc/out/";

    private String infile;
    private String outfile;
    private R reader;

    public InOutProcessor(String filename, R reader) {
        this.infile = RESC_PATH_IN + filename;
        this.outfile = RESC_PATH_OUT + filename.replace("in", "out");
        this.reader = reader;
    }

    public Collection<Result> processFile() throws NumberFormatException,
            IOException {
        BufferedReader br = new BufferedReader(new FileReader(infile));
        Collection<Result> output = reader.parse(br);
        writeFile(outfile, output);
        return output;
    }

    public static void writeFile(String fileName, Collection<Result> results)
            throws IOException {
        StringBuilder sb = new StringBuilder();
        try {
            FileWriter fw = new FileWriter(new File(fileName));

            int count = 1;
            for (Result r : results) {
                String s = "Case #" + count++ + ": " + r.getResult() + NEWLINE;
                fw.append(s);
                sb.append(s);
            }

            fw.flush();
        } finally {
            System.out.println(sb.toString());
        }
    }

    public static String getOutputContents(Collection<Result> results) {

        StringBuilder outputString = new StringBuilder();

        return outputString.toString();
    }

    public static abstract class LineReader<T extends Result> {

        public abstract Collection<Result> parse(BufferedReader reader)
                throws NumberFormatException, IOException;

    }

    public interface Result {

        String getResult();
    }

    public static class Utility {

        public static double[] toDoubleArray(String spaceDelim, String split) {
            String[] strings = spaceDelim.split(split);
            double[] retArray = new double[strings.length];
            for (int i = 0; i < strings.length; i++) {
                retArray[i] = Double.parseDouble(strings[i]);
            }

            return retArray;
        }

        public static int[] toIntArray(String spaceDelim, String split) {
            String[] strings = spaceDelim.split(split);
            int[] retArray = new int[strings.length];
            for (int i = 0; i < strings.length; i++) {
                retArray[i] = Integer.parseInt(strings[i]);
            }

            return retArray;
        }

        public static Integer[] toIntgerArray(String ints, String split) {
            String[] strings = ints.split(split);
            Integer[] retArray = new Integer[strings.length];
            for (int i = 0; i < strings.length; i++) {
                retArray[i] = Integer.parseInt(strings[i]);
            }

            return retArray;
        }

    }
}

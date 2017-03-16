import java.awt.List;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileFilter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * 
 */

/**
 * @author leonid
 *
 */
public class Solution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
        File[]  inputFiles = FilesManager.locateInputFiles();
        for(File inputFile : inputFiles) {
            FilesManager filesManager = new FilesManager(inputFile);

            int numberOfCases = Integer.parseInt(filesManager.readInputLine());
            for(int i=0; i<numberOfCases; i++) {
                //solution implementation
                TypeCastStringTokenizer stringTokenizer = new TypeCastStringTokenizer(filesManager.readInputLine());

                int N = stringTokenizer.getInt();
                int[] grades = new int[N];
                double[] results = new double[N];
                int sum = 0;
                for(int j=0; j<N; j++) {
                	grades[j] = stringTokenizer.getInt();
                	sum += grades[j];
                }
                
                StringBuilder sb = new StringBuilder(100);
                
                boolean recalc = false;
                int recalcSum = 0;
                ArrayList<Integer> reGrades = new ArrayList<Integer>();
                for(int k=0; k<N; k++) {
                 double result = (((((double)sum)/N)*2-grades[k])/sum)*100;
                 if(result<0) {
                	 recalc = true;
                	 results[k] = 0;
                 } else {
                	 reGrades.add(0, grades[k]);
                	 recalcSum +=grades[k];
                	 results[k] = result;
                 }
                 sb.append(result).append(" ");
                }
                if(recalc) {
                	sb = new StringBuilder(100);
                	for(int k=0; k<N; k++) {
                		double result;
                		if(results[k]==0) {
                			result = 0;
                		} else {
                			result = ( ( ( ( (double)recalcSum )/reGrades.size() ) +(double)sum/reGrades.size() - grades[k] )/sum )*100;
                		}
                		sb.append(result).append(" ");
                	}
                }

                


                String caseNumber = "Case #" + (i+1) + ": ";
                String output = caseNumber + sb.toString();
                filesManager.writeOutputLine(output);
            }

            filesManager.closeStreams();
        }
    }





    private static class FilesManager {
        private File inputFile;
        private File outputFile;

        private BufferedReader inputReader;
        private BufferedWriter outputWriter;

        public FilesManager(File inputFile) {
            this.inputFile = inputFile;
            outputFile = createCorrespondingOutputFile(inputFile);
        }

        public String readInputLine() {
            if(inputReader==null) {
                try {
                    FileReader fr = new FileReader(inputFile);
                    inputReader = new BufferedReader(fr);
                    System.out.println("Input reader created successfully");
                } catch (FileNotFoundException e) {
                    System.err.println("Failed to create input reader");
                    e.printStackTrace();
                }
            }

            try {
                return inputReader.readLine();
            } catch (IOException e) {
                System.err.println("Failed to read an input line");
                e.printStackTrace();
            }
            return null;
        }

        public boolean writeOutputLine(String line) {
            if(outputWriter==null) {
                try {
                    FileWriter fw = new FileWriter(outputFile);
                    outputWriter = new BufferedWriter(fw);
                    System.out.println("Output writer created successfully");
                } catch (IOException e) {
                    System.err.println("Failed to create output writer");
                    e.printStackTrace();
                }
            }

            try {
                outputWriter.write(line);
                outputWriter.newLine();
                return true;
            } catch (IOException e) {
                System.err.println("Failed to write output line: " + line);
                e.printStackTrace();
            }
            return false;
        }

        public void closeStreams() {
            try {
                inputReader.close();
            } catch (IOException e) {
                System.err.println("Failed to close input reader");
                e.printStackTrace();
            }
            try {
                if (outputWriter != null) {
                    outputWriter.flush();
                    outputWriter.close();
                }
            } catch (IOException ex) {
                System.err.println("Failed to close output writer");
                ex.printStackTrace();
            }
        }


        public static File[] locateInputFiles() {
            File currentDir = new File(".");
            return currentDir.listFiles(new FileFilter() {
                @Override
                public boolean accept(File file) {
                    if(file.isDirectory()) {
                        return false;
                    }
                    String[] splitFileName = file.getName().split("\\.");
                    return splitFileName[1].equalsIgnoreCase("in");
                }
            });
        }

        private static File createCorrespondingOutputFile(File inputFile) {
            if(!inputFile.exists()) {
                System.err.println("Input file " + inputFile.getAbsolutePath() + " doesn't exist");
                return null;
            }

            String inputFileName = inputFile.getName();
            String[] splitFileName = inputFileName.split("\\.");
            String outputFileName = splitFileName[0] + "-output.txt";

            File outputFile = new File(outputFileName);
            try {
                if(outputFile.createNewFile()) {
                    System.out.println("Output file created successfully at: " + outputFile.getAbsolutePath());
                    return outputFile;
                }
            } catch (IOException e) {
                System.err.println("Failed to create output file at: " + outputFile.getAbsolutePath());
                e.printStackTrace();
            }

            return null;
        }
    }

    private static class TypeCastStringTokenizer extends StringTokenizer {
        public TypeCastStringTokenizer(String str) {
            super(str, " ");
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        public float getFloat() {
            return Float.parseFloat(nextToken());
        }

        public String getString() {
            return nextToken();
        }
    }

}

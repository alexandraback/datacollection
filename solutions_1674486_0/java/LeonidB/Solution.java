import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileFilter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

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
            for(int caseNum=0; caseNum<numberOfCases; caseNum++) {
                //solution implementation
                StringBuilder sb = new StringBuilder(100);

                TypeCastStringTokenizer stringTokenizer = new TypeCastStringTokenizer(filesManager.readInputLine());

                int numOfClasses = stringTokenizer.getInt();

                ArrayList<ClassNode> classes = new ArrayList<ClassNode>(numOfClasses+1);
                classes.add(new ClassNode()); //dummy

                for(int classIt=0; classIt<numOfClasses; classIt++) {
                    ClassNode classNode = new ClassNode();
                    stringTokenizer = new TypeCastStringTokenizer(filesManager.readInputLine());
                    int numOfInherited = stringTokenizer.getInt();
                    for(int inheritedIt=0; inheritedIt<numOfInherited; inheritedIt++) {
                        int inheritedClass = stringTokenizer.getInt();
                        classNode.addInherited(inheritedClass);
                    }
                    classes.add(classNode);
                }

                boolean noLoop = true;
                for(int classIt=1; classIt<=numOfClasses; classIt++) {
                    ClassNode current  = classes.get(classIt);
                    for(Integer inherited : current.getInheritedClasses()) {
                        noLoop &= updateAncestor(classes, inherited, classIt);
                        if(!noLoop) {
                            break;
                        }
                    }
                }


                sb.append(noLoop ? "No" : "Yes");


                String caseNumber = "Case #" + (caseNum+1) + ": ";
                String output = caseNumber + sb.toString();
                filesManager.writeOutputLine(output);
            }

            filesManager.closeStreams();
        }
    }

    static boolean updateAncestor(ArrayList<ClassNode> classes, int classIt, int currAncestor) {
        ClassNode current  = classes.get(classIt);

        if(!current.addAncestor(currAncestor)) return false;

        for(Integer inherited : current.getInheritedClasses()) {
            if(!updateAncestor(classes, inherited, currAncestor)) return false;
        }

        return true;
    }



    private static class ClassNode {
        Set<Integer> inheritedClasses = new HashSet<Integer>();
        TreeSet<Integer> ancestors = new TreeSet<Integer>();
        boolean checked = false;

        public Set<Integer> getInheritedClasses() {
            return inheritedClasses;
        }

        public TreeSet<Integer> getAncestors() {
            return ancestors;
        }

        void addInherited(int inherited) {
            inheritedClasses.add(inherited);
        }

        //if return false - was already there
        boolean addAncestor(int ancestor) {
            return ancestors.add(ancestor);
        }

        public void setChecked(boolean checked) {
            this.checked = checked;
        }

        public boolean isChecked() {
            return checked;
        }

        //        boolean addAncestors(TreeSet<Integer> ancestors) {
//            retunr ancestors.addAll(ancestors);
//        }
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

package round1c.diamond;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

import round1c.diamond.MainDefault2.DiamondClass;

public class MainDefault2 {

    //private static String inputFileName = "sample.in";
    private static String inputFileName = "A-small-attempt1.in";
    //private static String inputFileName = "large.in";
    //private static String outputFileName = "sample.out";
    private static String outputFileName = "small-attempt1.out";
    //private static String outputFileName = "large.out";
    
    private static int nbrOfTests;
    private static String inputFolder = "input/";
    private static String outputFolder = "output/";

    /**
     * @param args
     */
    public static void main(String[] args) {
        
        MainDefault2 mainDefault = new MainDefault2();
        
        MyTestCase[] input = mainDefault.readInputCodeJam(inputFileName);
        StringBuffer output = mainDefault.createOutput(input);
        printToFile(output, outputFileName);
    }
    
    public MainDefault2() {
        //TODO if anything should be prepared for all testcases
    }
    
    public MyTestCase[] readInputCodeJam(String fileName) {
        MyTestCase[] testCases = null;
        File file = new File(inputFolder + fileName);
        try {
            Scanner scanner = new Scanner(file);
            
            nbrOfTests = Integer.valueOf(scanner.nextLine());
            testCases = new MyTestCase[nbrOfTests];
            
            for(int i=0; i<nbrOfTests; i++) {
                String tmp = scanner.nextLine();
                int nbrOfClasses = Integer.valueOf(tmp);
                String[] inheritance = new String[nbrOfClasses];
                for(int j=0; j<nbrOfClasses; j++) {
                    String tmp2 = scanner.nextLine();
                    inheritance[j] = tmp2;
                }
                //String[] testCaseInput = tmp.split(" "); //TODO String[] valid?
                MyTestCase obj = new MyTestCase(nbrOfClasses, inheritance); //TODO valid input
                
                testCases[i] = obj;
            }
            
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return testCases;
    }
    
    public StringBuffer createOutput(MyTestCase[] myTestCases) {
        StringBuffer buffer = new StringBuffer();
        int count = 1;
        for(int i=0; i<nbrOfTests; i++) {
            buffer.append("Case #" + count++ + ": ");
            
            MyTestCase myTestCase = myTestCases[i];
            buffer.append(myTestCase.getAnswer());
            
            buffer.append("\n");
        }
        return buffer;
    }
    
    public static void printToFile(StringBuffer output, String fileName) {
        try {
            FileWriter fstream = new FileWriter(outputFolder + fileName);
            BufferedWriter out = new BufferedWriter(fstream);
            out.write(output.toString());
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class MyTestCase {
        private String answer;
        private int nbrOfClasses;
        
        public MyTestCase(int nbrOfClasses, String[] input) {
            this.nbrOfClasses = nbrOfClasses;
            //System.out.println(nbrOfClasses);
            //DiamondClass[] classes = new DiamondClass[nbrOfClasses];
            HashMap<Integer, DiamondClass> classes = new HashMap<Integer, DiamondClass>();
            int nbr = 1;
            for(int i=0; i<nbrOfClasses; i++) {
                String inheritance = input[i];
                String[] info = inheritance.split(" ");
                //int nbrOfInheritance = Integer.valueOf(info[0]);
                classes.put(nbr, new DiamondClass(nbr, info));
                nbr++;
            }
            solve(classes);
        }
        
        private void addChildren(HashMap<Integer, DiamondClass> classes, DiamondClass tmp, int value) {
            ArrayList<Integer> inheritance = tmp.myValues;
            for(int inherit : inheritance) {
                DiamondClass tmp2 = classes.get(inherit);
                addChildren(classes, tmp2, value);
            }
            tmp.addChild(value);
        }
        
        private void solve(HashMap<Integer, DiamondClass> classes) {
            Iterator<Integer> itr = classes.keySet().iterator();
            while(itr.hasNext()) {
                int process = itr.next();
                DiamondClass tmp = classes.get(process);
                addChildren(classes, tmp, process);
            }
            
            String ans = "No";
            Iterator<Integer> itr2 = classes.keySet().iterator();
            while(itr2.hasNext()) {
                DiamondClass processClass = classes.get(itr2.next());
                if(processClass.hasSameChild()) {
                    ans = "Yes";
                }
            }
            
            answer = ans;
        }
        
        public String getAnswer() {
            return answer;
        }
    }
    
    class DiamondClass {
        
        private int nbrOfInheritance;
        private ArrayList<Integer> myValues;
        private ArrayList<Integer> children;
        private int nbr;

        public DiamondClass(int nbr, String[] info) {
            this.nbr = nbr;
            nbrOfInheritance = Integer.valueOf(info[0]);
            //System.out.print(nbrOfInheritance);
            myValues = new ArrayList<Integer>();
            for(int i=0; i<nbrOfInheritance; i++) {
                int tmp = Integer.valueOf(info[i+1]);
                //System.out.print(" " + tmp);
                myValues.add(tmp);
            }
            //System.out.println();
            children = new ArrayList<Integer>();
        }
        
        public void addChild(int value) {
            children.add(value);
        }
        
        public boolean hasSameChild() {
            HashSet<Integer> tmpChildren = new HashSet<Integer>(children);
            return tmpChildren.size() < children.size();
        }
    }
}

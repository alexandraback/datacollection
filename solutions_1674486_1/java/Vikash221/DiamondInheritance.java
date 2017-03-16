import java.io.*;
import java.util.*;

class DiamondInheritance {

    private class ProbClass {
        private int classId_;
        private ProbClass[] inheritsClasses_;
        private Set<Integer> allInheritances_;

        ProbClass(int classId) {
            classId_ = classId;
        }

        int getClassId() {
            return classId_;
        }

        void setDirectInheritance(ProbClass[] inheritances) {
            inheritsClasses_ = inheritances;
        }

        ProbClass[] getDirectInheritances() {
            return inheritsClasses_;
        }

        Set<Integer> getAllInheritances() {
            if (allInheritances_ == null) {
                allInheritances_ = new HashSet<Integer>();
                allInheritances_.add(classId_);
                for (ProbClass probClass : inheritsClasses_) {
                    allInheritances_.add(probClass.getClassId());
                    allInheritances_.addAll(probClass.getAllInheritances());
                }
            }
            return allInheritances_;
        }
    }

    DiamondInheritance() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("/Users/vikash/DiamondInheritanceIn.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("/Users/vikash/DiamondInheritanceOut.txt"));
        int testCases = Integer.parseInt(br.readLine());
        int currentTest = 1;
        while (currentTest <= testCases) {
            int totalProbClasses = Integer.parseInt(br.readLine());
            Map<Integer, ProbClass> probClassMap = new HashMap<Integer, ProbClass>();
            for (int i = 1; i <= totalProbClasses; i++) {
                probClassMap.put(i, new ProbClass(i));
            }
            for (int i = 1; i <= totalProbClasses; i++) {
                String[] numbers = br.readLine().split(" ");
                int totalInheritClasses = Integer.parseInt(numbers[0]);
                ProbClass[] inheritClasses = new ProbClass[totalInheritClasses];
                for (int j = 0; j < inheritClasses.length; j++) {
                    inheritClasses[j] = probClassMap.get(Integer.parseInt(numbers[1 + j]));
                }
                probClassMap.get(i).setDirectInheritance(inheritClasses);
            }
            //Now i finished reading specific test case, turn to determine if there exists inheritance.
            boolean foundDiamondInheritance = false;
            for (int i = 1; i <= totalProbClasses; i++) {
                ProbClass probClass = probClassMap.get(i);
                ProbClass[] directInheritances = probClass.getDirectInheritances();
                if (directInheritances.length > 1) {
                    //This is a candidate, should evaluate.
                    List<Set<Integer>> allIndirectInheritances = new ArrayList<Set<Integer>>();
                    for (ProbClass directInheritance : directInheritances) {
                        allIndirectInheritances.add(directInheritance.getAllInheritances());
                    }
                    for (int j = 0; j < allIndirectInheritances.size(); j++) {
                        Set<Integer> jSet = allIndirectInheritances.get(j);
                        for (int k = j + 1; k < allIndirectInheritances.size(); k++) {
                            Set<Integer> kSet = new HashSet<Integer>(allIndirectInheritances.get(k));
                            kSet.retainAll(jSet);
                            if (!kSet.isEmpty()) {
                                foundDiamondInheritance = true;
                                break;
                            }
                        }
                    }
                    if (foundDiamondInheritance) {
                        break;
                    }
                }
            }
            bw.write("Case #" + currentTest + ": " + (foundDiamondInheritance ? "Yes" : "No"));
            bw.newLine();
            currentTest++;
        }
        bw.close();
        br.close();
    }

    public static void main(String[] args) throws IOException {
        new DiamondInheritance();
    }
}

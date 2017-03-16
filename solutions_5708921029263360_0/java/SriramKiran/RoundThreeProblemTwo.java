package Round1C2016;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class RoundThreeProblemTwo {
    
    static String[] alpha = new String[4];

    public static void main(String[] args) {

        String inPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/small.in";
        String outPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/small.out";
        
//        String inPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/large.in";
//        String outPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/large.out";
        
        alpha[0] = "J";
        alpha[1] = "P";
        alpha[2] = "S";
        alpha[3] = "K";
        
        try {

            BufferedReader bufferedReader = new BufferedReader(new FileReader(inPutFile));
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(outPutFile));

            // Total number of test cases
            int noOfTestCases = Integer.valueOf(bufferedReader.readLine());
            
            
            
            for (int testCase = 0; testCase < noOfTestCases; testCase++){
                
                String[] combination=bufferedReader.readLine().split(" ");
                
                Map<Integer,ArrayList<Integer>> combMap = new HashMap<>();
                int comb=1;
                int jackets=Integer.valueOf(combination[0]), pants=Integer.valueOf(combination[1]), shirts=Integer.valueOf(combination[2]), combinations=Integer.valueOf(combination[3]);
                
                
                
                List<Integer> currCombination = new ArrayList<>();
                List<Integer> prevCombination = new ArrayList<>();
                List<Integer> currMatching = new ArrayList<>();
                List<Integer> prevMatching = new ArrayList<>();
                List<Integer> possibleCombinations = new ArrayList<>();
                
                for(int j=jackets; j>0; j--) {
                    for(int p=pants;p>0; p-- ) {
                        for(int s = shirts;s >0; s--) {
                            combMap.put(comb++, new ArrayList<Integer>(Arrays.asList(j,p,s)));
                        }
                    }
                }
                
                for (Map.Entry<Integer,ArrayList<Integer>> entry : combMap.entrySet()) {
                    currCombination=entry.getValue();
                    if(prevCombination.size()==0) {
                        prevCombination=entry.getValue();
                        possibleCombinations.add(entry.getKey());
                    } else {
                        currMatching = new ArrayList<Integer>(prevCombination);
                        currMatching.retainAll(currCombination);
                        if(currMatching.size() > 1 && !currMatching.equals(prevMatching)) {
                            combinations--;
                            possibleCombinations.add(entry.getKey());
                            prevMatching=new ArrayList<Integer>(currMatching);
                        }
                    }
                    
                    if(combinations<0) {
                        break;
                    }
                }
                
              bufferedWriter.write("Case #" + (testCase + 1) + ": " + possibleCombinations.size());
              bufferedWriter.write("\n");
              System.out.println("Case #" + (testCase + 1) + ": " + possibleCombinations.size());

                for(Integer index: possibleCombinations) {
                   List<Integer> currList = combMap.get(index);
                   String outputString ="";
                   for(Integer value: currList) {
                       outputString=outputString.concat(value.toString()).concat(" ");
                   }
                   bufferedWriter.write(outputString.trim());
                   bufferedWriter.write("\n");
                   System.out.println(outputString.trim());
                }
                
//                bufferedWriter.write("Case #" + (testCase + 1) + ": " + resultSet.toString().replace("[", "").replace("]", "").replaceAll(", "," "));
//                System.out.print("Case #" + (testCase + 1) + ": " + resultSet.toString().replace("[", "").replace("]", "").replaceAll(", "," "));
                

                

            }
                
            bufferedReader.close();
            bufferedWriter.close();

        } catch (FileNotFoundException fileNotFoundException) {

            System.out.println("Some Exception: " + fileNotFoundException.getMessage());
            fileNotFoundException.printStackTrace();

        } catch (IOException ioException) {

            System.out.println("Some Exception: " + ioException.getMessage());
            ioException.printStackTrace();

        } catch (Exception exception) {
            
            System.out.println("Some Exception: " + exception.getMessage());
            exception.printStackTrace();
        }

    }

    public static int sum(ArrayList<Integer> list) {
        int sum = list.stream().mapToInt(Integer::intValue).sum();
        return sum;
    }

}

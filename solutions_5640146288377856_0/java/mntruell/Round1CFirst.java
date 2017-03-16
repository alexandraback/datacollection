import java.util.ArrayList;
/**
 * Write a description of class Round1CFirst here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Round1CFirst
{
    static String filename = "A-small-attempt1 (5).in";
    //static String filename = "tester.txt";
    static String outfilename = "CFirst.txt";

    public static void main(String [] args) {
        System.out.print("a\f");
        Problem prob = HelperFunctions.getContentsOfFile(filename, 1, 1, 0);
        ArrayList<String> outputList = new ArrayList<String>(0);
        for(int a = 0; a < prob.cases.size(); a++) {
            System.out.println("Case: " + a);
            String[] splitArray = prob.cases.get(a).get(0).split(" ");

            int rows = Integer.parseInt(splitArray[0]);
            int colums = Integer.parseInt(splitArray[1]);
            int widthOfShip = Integer.parseInt(splitArray[2]);
            ArrayList<Integer> possiblePositions = new ArrayList<Integer>();
            ArrayList<Integer> hitTiles = new ArrayList<Integer>();
            for(int b = 0; b < colums-(widthOfShip-1); b++) {
                possiblePositions.add(b);
            }
  
            int turns = 0;
            ArrayList<Integer> hitPositions = null;
            while(possiblePositions.size() > 1) {
                ArrayList< ArrayList<Integer>> list = spotContainingMostPositions(possiblePositions, widthOfShip, colums);
                hitPositions = list.get(1);
                System.out.println("Turns " + turns);
                hitTiles.add(list.get(0).get(0));
                for(int b = 0; b < hitPositions.size(); b++) {
                    System.out.println("Hit " + hitPositions.get(b));
                    possiblePositions.remove(new Integer(hitPositions.get(b)));
                    
                }
                turns++;
            }
            
            if(possiblePositions.size() == 1) {
                turns += widthOfShip;
            } else {
                int start = hitPositions.get(0);
                int end = hitPositions.get(hitPositions.size()-1)+(widthOfShip-1);
                for(int b = start; b < end+1; b++) {
                    boolean shouldContinue = false;
                    for(int c = 0; c < hitTiles.size(); c++) {
                        if(hitTiles.get(c) == b) {
                            shouldContinue = true;
                        }
                    }
                    if(shouldContinue) continue;
                    turns++;
                }
            }
                
            outputList.add(turns+"");
        }

        HelperFunctions.writeCasesToFile(outfilename, outputList);
    }

    public static  ArrayList< ArrayList<Integer>> spotContainingMostPositions(ArrayList<Integer> positionStarts, int posisitionLength, int widthOfBoard) {
        if(positionStarts.size() < 1)return null;
        
        int greatestSpot = 0;
        int greatestNumberOfPosisitons = 0;
        ArrayList<Integer> greatestPositionsArray = null;
        for(int a = 0; a < widthOfBoard; a++) {
            int numberOfPositions = 0;
            ArrayList<Integer> positionsArray = new ArrayList<Integer>(0);
            System.out.println(a + " ship " + posisitionLength);
            for(int b = 0; b < positionStarts.size(); b++) {
                int position = positionStarts.get(b);
                
                if(a >=  position && a < position + posisitionLength) {
                    System.out.println("Hit  " + position);
                    numberOfPositions++;
                    positionsArray.add(position);
                }
            }
            if(numberOfPositions >greatestNumberOfPosisitons  && numberOfPositions != positionStarts.size()) {
                greatestNumberOfPosisitons = numberOfPositions;
                greatestSpot = a;
                greatestPositionsArray = positionsArray;
            }
        }
        ArrayList<Integer> firstArray = new ArrayList<Integer>();
        firstArray.add(greatestSpot);

        ArrayList< ArrayList<Integer>> returnArray = new ArrayList< ArrayList<Integer>>(0);
        returnArray.add(firstArray);
        returnArray.add(greatestPositionsArray);
        return returnArray;
    }
    public static  ArrayList< ArrayList<Integer>> spotContainingMostPositionsWithout(ArrayList<Integer> positionStarts, int posisitionLength, int widthOfBoard, ArrayList<Integer> notAllowed) {
        if(positionStarts.size() < 1)return null;
        
        int greatestSpot = 0;
        int greatestNumberOfPosisitons = 0;
        ArrayList<Integer> greatestPositionsArray = null;
        for(int a = 0; a < widthOfBoard; a++) {
            boolean shouldContinue = false;
            for(int b = 0; b < notAllowed.size(); b++) {
                if(notAllowed.get(b) == a) {
                    shouldContinue = true;
                }
            }
            if(shouldContinue) continue;
            
            int numberOfPositions = 0;
            ArrayList<Integer> positionsArray = new ArrayList<Integer>(0);
            System.out.println(a + " ship " + posisitionLength);
            for(int b = 0; b < positionStarts.size(); b++) {
                int position = positionStarts.get(b);
                
                if(a >=  position && a < position + posisitionLength) {
                    System.out.println("Hit  " + position);
                    numberOfPositions++;
                    positionsArray.add(position);
                }
            }
            if(numberOfPositions >greatestNumberOfPosisitons && numberOfPositions != positionStarts.size()) {
                greatestNumberOfPosisitons = numberOfPositions;
                greatestSpot = a;
                greatestPositionsArray = positionsArray;
            }
        }
        ArrayList<Integer> firstArray = new ArrayList<Integer>();
        firstArray.add(greatestSpot);

        ArrayList< ArrayList<Integer>> returnArray = new ArrayList< ArrayList<Integer>>(0);
        returnArray.add(firstArray);
        returnArray.add(greatestPositionsArray);
        return returnArray;
    }
}

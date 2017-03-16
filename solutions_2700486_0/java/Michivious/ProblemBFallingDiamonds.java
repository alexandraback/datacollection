import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;


public class ProblemBFallingDiamonds {    
    public static void main(String[] args) {
        try {
            FileReader input = new FileReader(args[0]);
            BufferedReader in = new BufferedReader(input);
            FileWriter output = new FileWriter("FallingDiamonds.out");
            BufferedWriter out = new BufferedWriter(output);
            
            int count = 1;            
            int cases = Integer.parseInt(in.readLine());
            
            while (count <= cases) {
                if (count != 1) {
                    out.write("\n");
                }
                
                String[] nums = in.readLine().split("\\s+");
                
                int nVal = Integer.parseInt(nums[0]),
                    xVal = Integer.parseInt(nums[1]),
                    yVal = Integer.parseInt(nums[2]);
                
                String outStr = "Case #" + count + ": " + probOfDiamond(nVal, xVal, yVal);
                System.out.println(nVal + " -> " + xVal + ", " + yVal);
                System.out.println(outStr);
                out.write(outStr);
                
                count++;
            }
            
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String probOfDiamond(int nVal, int xVal, int yVal) {
        HashSet<Point> dmnMap = new HashSet<Point>();
        
        double prob;
        
        Point p = new Point(0, 0);
        dmnMap.add(p);
        
        if (0 == xVal && 0 == yVal) {
            prob = 1;
        } else if (nVal == 1) {
            prob = 0;
        } else {
            prob = prob(nVal - 1, xVal, yVal, dmnMap, p);            
        }
        
        return Double.toString(prob);
    }

    private static double prob(int nVal, int xVal, int yVal, HashSet<Point> dmnMap, Point highestMid) {
        // Check if no branches
        if (dmnMap.contains(new Point(highestMid.x - 1, highestMid.y + 1)) &&
                dmnMap.contains(new Point(highestMid.x + 1, highestMid.y + 1))) {
            Point newMid = new Point(highestMid);
            newMid.y += 2;
            
            if (newMid.x == xVal && newMid.y == yVal) {
                return 1;
            } else if (nVal == 1) {
                return 0;
            } else {
                HashSet<Point> newMap = new HashSet<Point>(dmnMap);
                newMap.add(newMid);
                return prob(nVal - 1, xVal, yVal, newMap, newMid);
            }
        }
        
        // Left branch
        Point left = new Point(highestMid);
        double leftProb = -1;
        
        left.y += 2;
        while (left.y > 0) {
            if (dmnMap.contains(new Point(left.x - 1, left.y - 1))) {
                break;
            }
            
            left.x -= 1;
            left.y -= 1;
        }
        
        if (left.x != highestMid.x) {
            if (left.x == xVal && left.y == yVal) {
                leftProb = 1;
            } else if (nVal == 1) {
                leftProb = 0;
            } else {
                HashSet<Point> newMap = new HashSet<Point>(dmnMap);
                newMap.add(left);
                leftProb = prob(nVal - 1, xVal, yVal, newMap, highestMid);
            }
        }
        
        // Right branch
        Point right = new Point(highestMid);
        double rightProb = -1;
        
        right.y += 2;
        while (right.y > 0) {
            if (dmnMap.contains(new Point(right.x + 1, right.y - 1))) {
                break;
            }
            
            right.x += 1;
            right.y -= 1;
        }
        
        if (right.x != highestMid.x) {
            if (right.x == xVal && right.y == yVal) {
                rightProb = 1;
            } else if (nVal == 1) {
                rightProb = 0;
            } else {
                HashSet<Point> newMap = new HashSet<Point>(dmnMap);
                newMap.add(right);
                rightProb = prob(nVal - 1, xVal, yVal, newMap, highestMid);
            }
        }
        
        if (leftProb == -1) {
            return rightProb;
        } else if (rightProb == -1) {
            return leftProb;
        }
        
        return 0.5 * leftProb + 0.5 * rightProb;
    }
}

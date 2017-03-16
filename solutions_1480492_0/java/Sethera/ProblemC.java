import java.io.*;
import java.util.*;

/**
 *
 * @author Sethera
 */
public class ProblemC {
    
    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {

            String filename = "C-small-attempt0";

            br = new BufferedReader(new FileReader("E:\\Downloads\\" + filename + ".in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\" + filename + ".out"));
            //bw = new BufferedWriter(new OutputStreamWriter(System.out));

            ProblemC prob = new ProblemC();
            prob.solveFile();

        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }
    

    public void solveFile() throws Exception {
        int caseCount = Integer.parseInt(br.readLine());

        for (int caseNumber = 0; caseNumber < caseCount; caseNumber++) {
            int cars = Integer.parseInt(br.readLine());
            
            ArrayList<Car> carObjs = new ArrayList<Car>();
            for(int i = 0; i<cars; i++){
                String[] lineParts = br.readLine().split(" ");
                Car c = new Car();
                c.LeftLane = lineParts[0] == "L";
                c.speed = Integer.parseInt(lineParts[1]);
                c.pos = Integer.parseInt(lineParts[2]); 
                carObjs.add(c);
            }
            
            solveCase(caseNumber + 1, carObjs);
        }
    }

    public void solveCase(int caseNumber, ArrayList<Car> carObjs) throws Exception {
        int answer = 0;
        
        int cars = carObjs.size();
        
        ArrayList<Car> bySpeed = new ArrayList<Car>(carObjs);        
        ArrayList<Car> byPos = new ArrayList<Car>(carObjs);
        
        Collections.sort(byPos, new PositionComparor());
        Collections.sort(bySpeed, new PositionComparor());
        
        //TODO: move all cars to left lane if possible;
        //TODO: iterate over seconds incrementing by the difference between when the next colision will happen
        //TODO: change lanes if possible and move them back left as soon as they pass
        //TODO: keep sorting by pos and speed if the lists match they can drive forever /pass the case
        //TODO: come back for Round 1B...
        
        bw.write("Case #" + caseNumber + ": " + answer + "\r\n");
        bw.flush();
    } 
    
    public class Car {
        boolean LeftLane = false;
        int speed = 0;
        int pos = 0;
    }
    
    
    
    
    
    public class SpeedComparor implements Comparator{
        public int compare(Object o1, Object o2){
            Car c1 = (Car)o1;            
            Car c2 = (Car)o2;
            
            return Integer.compare(c1.speed, c2.speed);
        }
    }
    public class PositionComparor implements Comparator{
        public int compare(Object o1, Object o2){
            Car c1 = (Car)o1;            
            Car c2 = (Car)o2;
            
            return Integer.compare(c1.pos, c2.pos);
        }
    }
    
}

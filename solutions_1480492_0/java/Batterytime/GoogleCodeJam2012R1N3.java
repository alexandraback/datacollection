/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2012;

import java.io.*;
import java.util.*;
import java.util.Collections;

/**
 *
 * @author Stephen
 */
class Car {

    public Car(int vel, int pos) {
        velocity = vel;
        position = pos;
    }

    @Override
    public String toString() {
        return "Vel: " + velocity + " Pos: " + position;
    }
    public int velocity;
    public double position;
}

class CarComparator implements Comparator<Car> {

    @Override
    public int compare(Car car1, Car car2) {
        return new Double(car1.position).compareTo(car2.position);
    }
}

public class GoogleCodeJam2012R1N3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            FileInputStream fs = new FileInputStream("input.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            FileWriter fws = new FileWriter("output.txt");
            BufferedWriter out = new BufferedWriter(fws);
            String numLine = br.readLine();
            System.out.println(numLine);
            int numCases = Integer.parseInt(numLine);
            String caseLine;
            for (int i = 1; i <= numCases; i++) {
                caseLine = br.readLine();
                System.out.println("Case #" + i);
                int N = Integer.parseInt(caseLine);
                ArrayList<Car> leftLane = new ArrayList<Car>();
                ArrayList<Car> rightLane = new ArrayList<Car>();
                for (int j = 0; j < N; j++) {
                    caseLine = br.readLine();
                    String[] splitted = caseLine.split(" ");
                    if (splitted[0].equals("L")) {
                        leftLane.add(new Car(Integer.parseInt(splitted[1]), Integer.parseInt(splitted[2])));
                    } else {
                        rightLane.add(new Car(Integer.parseInt(splitted[1]), Integer.parseInt(splitted[2])));
                    }
                }
                CarComparator compare = new CarComparator();

                Collections.sort(leftLane, compare);
                Collections.sort(rightLane, compare);

                System.out.println("Left Lane: " + leftLane);
                System.out.println("RightLane: " + rightLane);

                boolean willCollide = true;
                double nextCollision = 100000000000.0;
                boolean leftLaneCollide = false;
                int guiltyCar = 0;
                boolean impossible = false;
                double timeElapsed = 0;
                double lastCollideTime = 1000;
                
                while (willCollide && !impossible) {
                    willCollide = false;
                    nextCollision = 100000000000.0;
                    leftLaneCollide = false;
                    guiltyCar = 0;
                    if (leftLane.size() > 1) {
                        for (int j = 0; j < leftLane.size() - 1; j++) { //Process left lane
                            Car c1 = leftLane.get(j);
                            Car c2 = leftLane.get(j + 1);
                            if (c2.velocity >= c1.velocity) {
                                continue;
                            }
                            double collideTime = (double) (c2.position - c1.position - 5) / (double) (c1.velocity - c2.velocity);
                            willCollide = true;
                            if (collideTime < nextCollision) {
                                leftLaneCollide = true;
                                guiltyCar = j;
                                nextCollision = collideTime;
                            }
                        }
                    }
                    //System.out.println(rightLane.size());
                    if (rightLane.size() > 1) {
                        for (int j = 0; j < rightLane.size() - 1; j++) { //Process right lane
                            Car c1 = rightLane.get(j);
                            Car c2 = rightLane.get(j + 1);
                            if (c2.velocity >= c1.velocity) {
                                continue;
                            }
                            double collideTime = (double) (c2.position - c1.position - 5) / (double) (c1.velocity - c2.velocity);
                            willCollide = true;
                            if (collideTime < nextCollision) {
                                leftLaneCollide = false;
                                guiltyCar = j;
                                nextCollision = collideTime;
                            }
                        }
                    }
                    
                    //if(nextCollision < 0.000001) {
                     //   System.out.println("Something's wrong");
                     //   timeElapsed+=nextCollision;
                     //   impossible = true;
                    //}
                    
                    System.out.println("Colliding? " + willCollide + " Next Collide: " + nextCollision + " Left lane? " + leftLaneCollide + " Car: " + guiltyCar);

                    if (willCollide) {
                        timeElapsed+=nextCollision;
                        nextCollision*=0.99999;
                        for(int j = 0; j < leftLane.size(); j++) { // Move left lane
                            Car car = leftLane.get(j);
                            car.position += (double)car.velocity*nextCollision;
                        }
                        for(int j = 0; j < rightLane.size(); j++) { // Move right lane
                            Car car = rightLane.get(j);
                            car.position += (double)car.velocity*nextCollision;
                        }
                        if(leftLaneCollide) {
                            Car offender = leftLane.get(guiltyCar);
                            for(int j = 0; j < rightLane.size(); j++) { // Try to move car.
                                Car car = rightLane.get(j);
                                if(Math.abs(offender.position-car.position)<5) { // Can't move, we're screwed
                                    impossible = true;
                                    break;
                                }
                            }
                            if(impossible) {
                                boolean secondCarImpossible = false;
                                offender = leftLane.get(guiltyCar+1);
                                for(int j = 0; j < rightLane.size(); j++) { // Try to move car.
                                    Car car = rightLane.get(j);
                                    if(Math.abs(offender.position-car.position)<5) { // Can't move, we're screwed
                                       secondCarImpossible = true;
                                       break;
                                    }
                                }
                                if(!secondCarImpossible) {
                                    System.out.println("Second car could");
                                    impossible = false;
                                    guiltyCar++;
                                }
                            }
                            if(!impossible) {
                                leftLane.remove(guiltyCar);
                                rightLane.add(offender);
                                Collections.sort(rightLane, compare);
                            }
                        } else {
                            Car offender = rightLane.get(guiltyCar);
                            for(int j = 0; j < leftLane.size(); j++) { // Try to move car.
                                Car car = leftLane.get(j);
                                if(Math.abs(offender.position-car.position)<5) { // Can't move, we're screwed
                                    impossible = true;
                                    break;
                                }
                            }
                            if(impossible) {
                                boolean secondCarImpossible = false;
                                offender = rightLane.get(guiltyCar+1);
                                for(int j = 0; j < leftLane.size(); j++) { // Try to move car.
                                    Car car = leftLane.get(j);
                                    if(Math.abs(offender.position-car.position)<5) { // Can't move, we're screwed
                                       secondCarImpossible = true;
                                       break;
                                    }
                                }
                                if(!secondCarImpossible) {
                                    System.out.println("Second car could");
                                    impossible = false;
                                    guiltyCar++;
                                }
                            }
                            if(!impossible) {
                                rightLane.remove(guiltyCar);
                                leftLane.add(offender);
                                Collections.sort(leftLane, compare);
                            }
                        }
                    }
                    if(nextCollision == 0 && nextCollision == lastCollideTime) {
                        impossible = true;
                        System.out.println("IMPOSSIBLCASED");
                    }
                    lastCollideTime = nextCollision;
                    System.out.println("Left Lane: " + leftLane);
                    System.out.println("RightLane: " + rightLane);
                }

                if(impossible) {
                    out.write("Case #" + i + ": " + timeElapsed + "\r\n");
                    System.out.print("Case #" + i + ": " + timeElapsed + "\r\n");
                }
                else {
                    out.write("Case #" + i + ": Possible\r\n");
                    System.out.print("Case #" + i + ": Possible\r\n");
                }
            }
            in.close();
            out.close();

            displayOutput();
        } catch (Exception e) {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
    }

    public static void displayOutput() {
        System.out.println("START OUTPUT\n-------------------");
        try {
            FileInputStream fs = new FileInputStream("output.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String readLine;
            while ((readLine = br.readLine()) != null) {
                System.out.println(readLine);
            }
        } catch (Exception e) {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
        System.out.println("---------------------\nEND OUTPUT");
    }
}

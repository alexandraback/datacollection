import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Ari
 */
public class ProblemC {
    static String in = "src/c.in";
    static String out = "src/c.out";
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        int numCars;
        String laneChar;
        boolean leftLane;
        Car[] cars;
        double distance;
        double maxDistance;
        double temp;
        double temp2;
        for(int x = 0; x < numlines; x++) {
            double maxTime = Double.MAX_VALUE;
            numCars = scan.nextInt();
            cars = new Car[numCars];
            for(int y = 0; y < numCars; y++) {
                laneChar = scan.next();
                leftLane = laneChar.equals("L");
                cars[y] = new Car(leftLane,scan.nextInt(),scan.nextInt());
            }
            
            for(int a = 0; a < numCars - 1; a++) {
                for(int b = a + 1; b < numCars; b++) {
                    if(cars[a].speed == cars[b].speed) {
                        if(Math.abs(cars[a].initial - cars[b].initial) < 5) {
                            cars[a].locked = cars[b];
                            cars[b].locked = cars[a];
                        }
                    }
                }
            }
            
            for(int a = 0; a < numCars - 1; a++) {
                for(int b = a + 1; b < numCars; b++) {
                    if(cars[a].speed > cars[b].speed) {
                        if(cars[a].initial < cars[b].initial + 5) {
                            distance = cars[b].initial - cars[a].initial - 5;
                            maxDistance = distance + 5;
                            if(distance < 0) {
                                distance = 0;
                            }
                            temp = distance / (cars[a].speed - cars[b].speed);
                            
                            if(cars[a].locked != null && cars[b].locked != null) {
                                if(cars[a].left == cars[b].left) {
                                    if(temp < maxTime) {
                                        maxTime = temp;
                                    }
                                }
                            }
                            else if(cars[a].locked != null) {
                                if(cars[a].initial <= cars[a].locked.initial) {
                                    if(temp < maxTime) {
                                        maxTime = temp;
                                    }
                                }
                            }
                            else if(cars[b].locked != null) {
                                if(cars[b].initial >= cars[b].locked.initial) {
                                    if(temp < maxTime) {
                                        maxTime = temp;
                                    }
                                }
                            }
                            else {
                                temp2 = maxDistance / (cars[a].speed - cars[b].speed);
                                Range r1 = new Range(temp,temp2);
                                Range r2 = new Range(temp,temp2);
                                for(int c = 0; c < cars[a].cols.size(); c++) {
                                    double overlap = cars[a].cols.get(c).overlap(r1);
                                    if(overlap > 0) {
                                        if(overlap < maxTime) {
                                            maxTime = overlap;
                                        }
                                    }
                                }
                                for(int c = 0; c < cars[b].cols.size(); c++) {
                                    double overlap = cars[b].cols.get(c).overlap(r2);
                                    if(overlap > 0) {
                                        if(overlap < maxTime) {
                                            maxTime = overlap;
                                        }
                                    }
                                }
                                cars[a].cols.add(r1);
                                cars[b].cols.add(r2);
                            }
                        }
                    }
                    else if(cars[a].speed < cars[b].speed) {
                        if(cars[b].initial < cars[a].initial + 5) {
                            distance = cars[a].initial - cars[b].initial - 5;
                            maxDistance = distance + 5;
                            if(distance < 0) {
                                distance = 0;
                            }
                            temp = distance / (cars[b].speed - cars[a].speed);
                            
                            if(cars[a].locked != null && cars[b].locked != null) {
                                if(cars[a].left == cars[b].left) {
                                    if(temp < maxTime) {
                                        maxTime = temp;
                                    }
                                }
                            }
                            else if(cars[a].locked != null) {
                                if(cars[a].initial >= cars[a].locked.initial) {
                                    if(temp < maxTime) {
                                        maxTime = temp;
                                    }
                                }
                            }
                            else if(cars[b].locked != null) {
                                if(cars[b].initial <= cars[b].locked.initial) {
                                    if(temp < maxTime) {
                                        maxTime = temp;
                                    }
                                }
                            }
                            else {
                                temp2 = maxDistance / (cars[b].speed - cars[a].speed);
                                Range r1 = new Range(temp,temp2);
                                Range r2 = new Range(temp,temp2);
                                for(int c = 0; c < cars[a].cols.size(); c++) {
                                    double overlap = cars[a].cols.get(c).overlap(r1);
                                    if(overlap > 0) {
                                        if(overlap < maxTime) {
                                            maxTime = overlap;
                                        }
                                    }
                                }
                                for(int c = 0; c < cars[b].cols.size(); c++) {
                                    double overlap = cars[b].cols.get(c).overlap(r2);
                                    if(overlap > 0) {
                                        if(overlap < maxTime) {
                                            maxTime = overlap;
                                        }
                                    }
                                }
                                cars[a].cols.add(r1);
                                cars[b].cols.add(r2);
                            }
                        }
                    }
                }
            }
            
            write.write("Case #" + (x+1) + ": ");
            if(maxTime == Double.MAX_VALUE) {
                write.write("Possible\n");
            }
            else {
                write.write(maxTime + "\n");
            }
        }
        scan.close();
        write.close();
    }
    
    public static class Range {
        public double start;
        public double end;
        
        public Range(double s, double e) {
            start = s;
            end = e;
        }

        public double overlap(Range r2) {
            if(r2.start >= end)
                return -1;
            if(start >= r2.end)
                return -1;
            
            if(r2.start > start) {
                return r2.start;
            }
            else {
                return start;
            }
        }
    }
    
    static class Car {
        public int speed;
        public int initial;
        public boolean left;
        
        public ArrayList<Range> cols = new ArrayList<Range>();
        
        public Car locked = null;
        
        public Car(boolean l, int s, int p) {
            left = l;
            speed = s;
            initial = p;
        }
    }
}

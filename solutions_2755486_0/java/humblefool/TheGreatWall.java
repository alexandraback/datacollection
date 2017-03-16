import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class TheGreatWall {
    static Scanner sc;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        //sc = new Scanner(System.in);
        //out = new PrintWriter(System.out);

        sc = new Scanner(new BufferedReader(new FileReader("C-small-attempt0.in")));
        out = new PrintWriter(new FileWriter("C-small-attempt0.out"));

        int testCases = sc.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println(String.format("Case #%s: %s", testCase, solveCase()));
            out.flush();
        }
        out.close();
    }

    public static int solveCase() {
        int n = sc.nextInt();
        Tribe[] tribes = new Tribe[n];
        for(int index = 0; index < n; index++) {
            tribes[index] = new Tribe();
        }
        
        SortedSet<Segment> segments = new TreeSet<Segment>();
        segments.add(new Segment());
        
        int breaches = 0;
        while(true) {
            int today = Integer.MAX_VALUE;
            for(Tribe tribe: tribes) {
                if(tribe.attacksRemaining > 0)
                    today = Math.min(today, tribe.nextAttackDay);
            }
            if (today == Integer.MAX_VALUE)
                break;
            
            for(Tribe tribe: tribes) {
                if(tribe.attacksRemaining > 0 && tribe.nextAttackDay == today) {
                    for(Segment segment: segments) {
                        if (segment.isBreached(tribe)) {
                            //System.out.println(tribe);
                            //System.out.println(segment);
                            breaches++;
                            break;
                        }
                    }
                }
            }
            
            for(Tribe tribe: tribes) {
                if(tribe.attacksRemaining > 0 && tribe.nextAttackDay == today) {
                    Segment[] tempSegments = segments.toArray(new Segment[0]);
                    for(Segment segment: tempSegments) {
                        if (segment.isBreached(tribe)) {
                            Segment[] upgraded = segment.split(tribe);
                            segments.remove(segment);
                            for(Segment upgradedSegment: upgraded) {
                                segments.add(upgradedSegment);
                            }
                        }
                    }
                    
                    tribe.attacksRemaining--;
                    tribe.nextAttackDay += tribe.attackDayIncrement;
                    tribe.start += tribe.segmentIncrement;
                    tribe.end += tribe.segmentIncrement;
                    tribe.strength += tribe.strengthIncrement;
                }
            }
        }
        return breaches;
        
    }
    
    static class Segment implements Comparable<Segment> {
        int start = Integer.MIN_VALUE, end = Integer.MAX_VALUE;
        int height = 0;
        public Segment() {
        }
        public Segment(int start, int end, int height) {
            this.start = start;
            this.end = end;
            this.height = height;
        }
        
        public boolean isBreached(Tribe tribe) {
            int commonStart = Math.max(start, tribe.start);
            int commonEnd = Math.min(end, tribe.end);
            return commonStart < commonEnd && tribe.strength > height;
        }
        
        public Segment[] split(Tribe tribe) {
            List<Segment> segments = new ArrayList<Segment>();
            if (start < tribe.start) {
                segments.add(new Segment(start, tribe.start, height));
            }
            if (tribe.end < end) {
                segments.add(new Segment(tribe.end, end, height));
            }
            segments.add(new Segment(Math.max(start, tribe.start), Math.min(end, tribe.end), tribe.strength));
            return segments.toArray(new Segment[0]);
        }

        @Override
        public int compareTo(Segment other) {
            return start == other.start ? 0 : start < other.start ? -1 : +1;
        }
        
        public String toString() {
            return String.format("%s %s to %s", height, start, end);
        }
    }
    
    static class Tribe {
        int nextAttackDay;
        int attackDayIncrement;
        
        int start, end;
        int segmentIncrement;
        
        int attacksRemaining;
        
        int strength, strengthIncrement;
        
        public Tribe() {
            nextAttackDay = sc.nextInt();
            attacksRemaining = sc.nextInt();
            
            start = sc.nextInt();
            end = sc.nextInt();
            
            strength = sc.nextInt();
            
            attackDayIncrement = sc.nextInt();
            segmentIncrement = sc.nextInt();
            strengthIncrement = sc.nextInt();
        }
        public String toString() {
            return String.format("%s %s %s %s", nextAttackDay, start, end, strength);
        }
    }
}

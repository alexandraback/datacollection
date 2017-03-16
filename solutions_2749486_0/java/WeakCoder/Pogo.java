package Round_1_C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Pogo {

    /**
     * @param args
     */
    public static void main(String[] args) {
        /*Set<Point> test = new HashSet<Point>();
        test.add(new Point(0, 0, ' ', null));
        test.add(new Point(0, 0, ' ', null));
        System.out.println(test.size());*/
        
        Scanner in = null;
        PrintWriter out = null;
        try {
            in = new Scanner(new File("B-small-attempt1.in"));
            out = new PrintWriter(new File("b_small.out"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int T = in.nextInt();
        for (int cs=1; cs<=T; cs++) {
            long X = in.nextLong();
            long Y = in.nextLong();
            Set<Point> queue = new HashSet<Point>();
            Set<Point> tmp = new HashSet<Point>();
            queue.add(new Point(0, 0, ' ', null));
            Point target = null;
            LOOP: for (long add=1; ; add++) {
                tmp.clear();
                tmp.addAll(queue);
                queue.clear();
                Iterator<Point> ite = tmp.iterator();
                while (ite.hasNext()) {
                    Point current = ite.next();
                    
                   //if (cs == 3)
                        //System.out.println(current.toString());
                    
                    Point N = new Point(current.getX(), current.getY()+add, 'N', current);
                    if (N.getX()==X && N.getY()==Y) {
                        target = N;
                        break LOOP;
                    }
                    else if (Math.abs(N.getX()-X)<=500 && Math.abs(N.getY()-Y)<=500){
                        queue.add(N);
                        /*if (add<10) {
                            System.out.println("N" + N.toString());
                        }*/
                    }
                    Point S = new Point(current.getX(), current.getY()-add, 'S', current);
                    if (S.getX()==X && S.getY()==Y) {
                        target = S;
                        break LOOP;
                    }
                    else if (Math.abs(S.getX()-X)<=500 && Math.abs(S.getY()-Y)<=500){
                        /*if (add<10) {
                            System.out.println("S" + S.toString());
                        }*/
                        queue.add(S);
                    }
                    Point E = new Point(current.getX()+add, current.getY(), 'E', current);
                    if (E.getX()==X && E.getY()==Y) {
                        target = E;
                        break LOOP;
                    }
                    else if (Math.abs(E.getX()-X)<=500 && Math.abs(E.getY()-Y)<=500){
                        /*if (add<10) {
                            System.out.println("E" + E.toString());
                        }*/
                        queue.add(E);
                    }
                    Point W = new Point(current.getX()-add, current.getY(), 'W', current);
                    if (W.getX()==X && W.getY()==Y) {
                        target = W;
                        break LOOP;
                    }
                    else if (Math.abs(W.getX()-X)<=500 && Math.abs(W.getY()-Y)<=500){
                        /*if (add<10) {
                            System.out.println("W" + W.toString());
                        }*/
                        queue.add(W);
                    }
                }
            }
            StringBuilder result = new StringBuilder();
            while (target.getLp() != null) {
                result.append(target.getLast());
                target = target.getLp();
            }
            String value = result.reverse().toString();
            System.out.println("Case #"+cs+": " + value);
            out.println("Case #"+cs+": " + value);
            out.flush();
            Object obj = null;
        }
    }

}

class Point {
    private long x;
    private long y;
    private char last;
    private Point lp;
    
    public Point(long xx, long yy, char la, Point lpp) {
        x = xx;
        y = yy;
        last = la;
        lp = lpp;
    }
    
    public long getX() {
        return x;
    }
    
    public long getY() {
        return y;
    }
    
    public char getLast() {
        return last;
    }
    
    public Point getLp() {
        return lp;
    }
    
    public String toString() {
        return x + "_" + y;
    }
    
    @Override
    public int hashCode() {
        return toString().hashCode();
    }
    
    @Override
    public boolean equals(Object obj) {
        Point p = (Point) obj;
        if (p.getX() == this.getX() && p.getY() == this.getY())
            return true;
        else
            return false;
    }
}
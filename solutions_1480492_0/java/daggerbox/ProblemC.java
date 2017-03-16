package com.forthgo.google.g2012r1a;

import java.awt.geom.Point2D;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Xan Gregg.
 * Date: 4/27/12
 */
public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                int n = in.nextInt();
                double s = solve(in, n);
                if (s == 0)
                    out.printf("Case #%d: %s%n", i + 1, "Possible");
                else
                    out.printf("Case #%d: %f%n", i + 1, s);
                out.flush();
            }

        } catch (IOException e) {
            throw new RuntimeException();
        }
    }

    private static double solve(Scanner in, int n) {
        double[] pos = new double[n];
        double[] speed = new double[n];
        char[] side = new char[n];
        for (int i = 0; i < n; i++) {
            side[i] = in.next().charAt(0);
            speed[i] = in.nextDouble();
            pos[i] = in.nextDouble();
        }
        List<Zone> zones = new ArrayList<Zone>(n * n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                addZones(zones, i, j, pos, speed);
            }
        }
        Collections.sort(zones);
        double min = 0;
        for (int k = 0; k < zones.size(); k++) {
            Zone z = zones.get(k);
            for (int m = k + 1; m < zones.size(); m++) {
                Zone mz = zones.get(m);
                //if (mz.p[0].getX() >= z.p[2].getX())
                //    break;
                double x = z.getIntersection(mz);
                if (x < min || min == 0) {
                    min = x;
                }
            }
        }
        return min;
    }

    private static void addZones(List<Zone> zones, int i, int j, double[] pos, double[] speed) {
        if (speed[i] == speed[j])
            return;
        if (pos[i] > pos[j]) {
            int k = i;
            i = j;
            j = k;
        }
        Point2D.Double pfi = new Point2D.Double(0, pos[i] + 5);
        Point2D.Double pbi = new Point2D.Double(0, pos[i]);
        Point2D.Double pfj = new Point2D.Double(0, pos[j] + 5);
        Point2D.Double pbj = new Point2D.Double(0, pos[j]);
        Point2D.Double qbb = lineIntersection(pfi, speed[i], pbj, speed[j]);
        if (qbb.getX() < 0)
            return;
        zones.add(new Zone(qbb,
                lineIntersection(pbi, speed[i], pbj, speed[j]),
                lineIntersection(pbi, speed[i], pfj, speed[j]),
                lineIntersection(pfi, speed[i], pfj, speed[j])));
    }

    public static boolean approx(double a, double b) {
        if (a == b)
            return true;
        return Math.abs(a-b) / Math.max(a, b) < 1e-6;
    }
    public static Point2D.Double lineSegIntersection(Point2D.Double p0, Point2D.Double p1,
                                                  Point2D.Double p2, Point2D.Double p3) {
        if (p0.getX() > p1.getX()) {
            Point2D.Double r = p0;
            p0 = p1;
            p1 = r;
        }
        if (p2.getX() > p3.getX()) {
            Point2D.Double r = p2;
            p2 = p3;
            p3 = r;
        }
        double m1 = (p1.getY() - p0.getY()) / (p1.getX() - p0.getX());
        double m2 = (p3.getY() - p2.getY()) / (p3.getX() - p2.getX());
        if (approx(m1, m2)) {
            double b1 = p0.getY() - p0.getX() * m1;
            double b2 = p2.getY() - p2.getX() * m2;
            if (approx(b1, b2)) {
                if (p2.getX() >= p0.getX() && p2.getX() < p1.getX())
                    return p2;
                if (p0.getX() >= p2.getX() && p0.getX() < p3.getX())
                    return p0;
            }
            return null;
        }
        Point2D.Double q = lineIntersection(p0, m1, p2, m2);

        if (q.getX() > p0.getX() && q.getX() < p1.getX() && q.getX() > p2.getX() && q.getX() < p3.getX())
            return q;
        return null;
    }

    public static Point2D.Double lineIntersection(Point2D.Double p0, Point2D.Double p1,
                                                  Point2D.Double p2, Point2D.Double p3) {
        return lineIntersection(p0, (p1.getY() - p0.getY()) / (p1.getX() - p0.getX()),
                p2, (p3.getY() - p2.getY()) / (p3.getX() - p2.getX()));
    }

    public static Point2D.Double lineIntersection(Point2D.Double p1, double m1,
                                                  Point2D.Double p2, double m2) {
        double b1 = p1.getY() - p1.getX() * m1;
        double b2 = p2.getY() - p2.getX() * m2;
        double x = (b1 - b2) / (m2 - m1);
        double y = m1 * x + b1;
        return new Point2D.Double(x, y);
    }

    public static Point2D.Double lineIntersectiong(Point2D.Double p1, double m1,
                                                  Point2D.Double p2, double m2) {
        double a1, b1, c1,
                a2, b2, c2,
                det_inv;

        a1 = m1;
        a2 = m2;
        b1 = -1;
        b2 = -1;
        c1 = (p1.getY() - m1 * p1.getY());
        c2 = (p2.getY() - m2 * p1.getY());
        det_inv = 1 / (a1 * b2 - a2 * b1);
        return new Point2D.Double(((b1 * c2 - b2 * c1) * det_inv), ((a2 * c1 - a1 * c2) * det_inv));
    }

    static class Zone implements Comparable<Zone> {
        public Point2D.Double[] p = new Point2D.Double[4];

        public Zone(Point2D.Double a, Point2D.Double b, Point2D.Double c, Point2D.Double d) {
            p[0] = a;
            p[1] = b;
            p[2] = c;
            p[3] = d;
        }


        @Override
        public int compareTo(Zone zone) {
            return p[0].getX() < zone.p[0].getX() ? -1 : p[0].getX() > zone.p[0].getX() ? 1
                    : p[0].getY() < zone.p[0].getY() ? -1 : p[0].getY() > zone.p[0].getY() ? 1 : 0;
        }

        public double getIntersection(Zone z) {
            double x = 0;
            int[] from = new int[]{0, 0, 1, 3};
            int[] to = new int[]{1, 3, 2, 2};
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    Point2D.Double q = lineSegIntersection(p[from[i]], p[to[i]], z.p[from[j]], z.p[to[j]]);
                    if (q != null && (q.getX() < x || x == 0)) {
                        x = q.getX();
                    }

                }
            }

            return x;
        }
    }
}


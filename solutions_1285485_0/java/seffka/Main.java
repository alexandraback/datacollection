import org.apache.commons.math.fraction.Fraction;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class Main
{
    static class Point
    {
        Fraction x;
        Fraction y;

        Point()
        {
        }

        Point (int x, int y)
        {
            this (new Fraction(x), new Fraction(y));
        }

        Point(Fraction x, Fraction y)
        {
            this.x = x;
            this.y = y;
        }

        public boolean equals(Object obj)
        {
            Point otherPoint = (Point) obj;
            return x.equals(otherPoint.x) && y.equals(otherPoint.y);
        }

        public int hashCode()
        {
            return x.hashCode() + 17 * y.hashCode();
        }
    }

    static class Line
    {
        Line() {
        }

        Line(boolean vertical, int a, int c)
        {
            this(vertical, new Fraction(a), new Fraction(c));
        }

        Line(boolean vertical, Fraction a, Fraction c) {
            isVertical = vertical;
            this.a = a;
            this.c = c;
        }

        boolean isVertical;
        Fraction a;
        Fraction c;
        // x = c or y = ax + c

        public boolean posess(Point point)
        {
            if (isVertical)
            {
                return point.x.equals(c);
            }

            return point.y.equals(a.multiply(point.x).add(c));
        }

        public Point cross(Line line)
        {
            if (isVertical)
            {
                if (line.isVertical)
                {
                    // Don't consider equal lines.
                    return null;
                }
                else
                {
                    return new Point(c, line.a.multiply(c).add(line.c));
                }
            }
            else
            {
                if (line.isVertical)
                {
                    return new Point(line.c, a.multiply(line.c).add(c));
                }
                else
                {
                    if (a.equals(line.a))
                    {
                        // Don't consider equal lines.
                        return null;
                    }
                    Fraction cX = line.c.subtract(c).divide(a.subtract(line.a));
                    Fraction cY = a.multiply(cX).add(c);

                    return new Point(cX, cY);
                }
            }
        }
    }

    static class Section
    {
        Section() {
        }

        Section(Line line, Point start, Point end) {
            this.line = line;
            this.start = start;
            this.end = end;
        }

        Line line;
        Point start;
        Point end;
    }

    static class Ray
    {
        Ray() {
        }

        Ray(Line line, Point source, boolean toPositive) {
            this.line = line;
            this.source = source;
            this.toPositive = toPositive;
        }

        Line line;
        Point source;
        boolean toPositive;

        public boolean posess(Point point)
        {
            if (line.posess(point))
            {
                if (line.isVertical)
                {
                    if (toPositive)
                        return point.y.compareTo(source.y) >= 0;
                    else
                        return point.y.compareTo(source.y) <= 0;
                }
                else
                {
                    if (toPositive)
                        return point.x.compareTo(source.x) >= 0;
                    else
                        return point.x.compareTo(source.x) <= 0;
                }
            }

            return false;
        }
    }

    static List<Point> reflectingCorners = new ArrayList<Point>();
    static List<Section> mirrors = new ArrayList<Section>();
    static Point myPoint = new Point();
    static int H;
    static int W;
    static int D;

    public static void main(String[] args)
            throws Exception
    {
        BufferedReader in = new BufferedReader(new FileReader(args[0]));
        FileWriter out = new FileWriter(args[1]);
        int T = Integer.parseInt(in.readLine());


        Date start = new Date(System.currentTimeMillis());
        System.out.println(start);

        for (int t = 1; t <= T; t++)
        {
            String[] params = in.readLine().split("\\ ");
            H = Integer.parseInt(params[0]);
            W = Integer.parseInt(params[1]);
            D = Integer.parseInt(params[2]);

            int reflections = 0;

            readDataSimple(in);
            List<Line> guessedLines = guessLines();

            for (Iterator<Line> iterator = guessedLines.iterator(); iterator.hasNext(); )
            {
                Line line = iterator.next();
                Ray ray1 = new Ray(line, myPoint, true);
                Ray ray2 = new Ray(line, myPoint, false);

                if (checkReflection(0, ray1))
                    reflections++;

                if (checkReflection(0, ray2))
                    reflections++;

            }
            out.write("Case #" + t + ": " + reflections + "\n");
            System.out.println("Case #" + t + ": " + reflections + "\n");
        }

        Date end = new Date(System.currentTimeMillis());
        System.out.println(end);
        System.out.println(((double)end.getTime() - start.getTime()) / 1000.0);
        in.close();
        out.close();
    }

    static class ReflectionResult
    {
        Ray newRay;
        double distance;

        ReflectionResult(Ray newRay, double distance) {
            this.newRay = newRay;
            this.distance = distance;
        }
    }

    private static boolean checkReflection(double doneDistance, Ray ray)
    {
        // TODO: "dead" corners.
        if (!ray.source.equals(myPoint) && ray.posess(myPoint))
        {
            double d = distance(myPoint, ray.source);
            return (d + doneDistance) <= D;
        }

        Point corner = findCorner(ray);
        if (corner != null)
        {
            double d = distance(corner, ray.source);
            return (d + doneDistance) * 2 <= D;
        }

        ReflectionResult reflectionResult = findReflection(ray);

        double newDistance = doneDistance + reflectionResult.distance;

        if (newDistance > D)
            return false;
        return checkReflection(newDistance, reflectionResult.newRay);
    }

    private static ReflectionResult findReflection(Ray ray)
    {
        Section resultSection = null;
        double minDistance = Double.MAX_VALUE;
        Point resultCrossPoint = null;

        for (Iterator<Section> iterator = mirrors.iterator(); iterator.hasNext(); ) {
            Section section = iterator.next();

            Point crossPoint = section.line.cross(ray.line);
            if (crossPoint != null)
            {
                if (ray.posess(crossPoint) && !ray.source.equals(crossPoint))
                {
                    double d = distance(crossPoint, ray.source);
                    if (d < minDistance)
                    {
                        resultSection = section;
                        minDistance = d;
                        resultCrossPoint = crossPoint;
                    }
                }
            }
        }

        if (resultCrossPoint == null)
            throw new IllegalStateException();

        Ray newRay;
        if (ray.line.isVertical)
        {
            newRay = new Ray(ray.line, resultCrossPoint, !ray.toPositive);
        }
        else
        {
            Fraction newA = ray.line.a.negate();
            Fraction newC = resultCrossPoint.y.subtract(newA.multiply(resultCrossPoint.x));
            boolean toPositive =  (resultSection.line.isVertical) ? !ray.toPositive : ray.toPositive;

            newRay = new Ray(new Line(false, newA, newC), resultCrossPoint, toPositive);
        }

        return new ReflectionResult(newRay, minDistance);
    }

    private static Point findCorner(Ray ray)
    {
        for (Iterator<Point> iterator = reflectingCorners.iterator();
             iterator.hasNext();)
        {
            Point next = iterator.next();
            if (ray.posess(next))
                return next;
        }

        return null;
    }

    private static double distance(Point point1, Point point2)
    {
        double dx = point1.x.subtract(point2.x).doubleValue();
        double dy = point1.y.subtract(point2.y).doubleValue();

        return Math.sqrt(dx * dx + dy * dy);
    }

    private static List<Line> guessLines()
    {
        Date start = new Date(System.currentTimeMillis());
        List<Line> result = new ArrayList<Line>();

        result.add(new Line(true, new Fraction(0), myPoint.x));
        result.add(new Line(false, new Fraction(0), myPoint.y));

        Set<Fraction> coeffs = new LinkedHashSet<Fraction>();
        for (int m = 1; m <= D; m++)
            for (int n = 1; n <= D; n++)
            {
                Fraction a = new Fraction(m, n);
                coeffs.add(a);
                coeffs.add(a.negate());
            }

        for (Iterator<Fraction> iterator = coeffs.iterator(); iterator.hasNext(); )
        {
            Fraction a = iterator.next();
            Fraction c = myPoint.y.subtract(a.multiply(myPoint.x));
            result.add(new Line(false, a, c));
        }

        Date end = new Date(System.currentTimeMillis());
        System.out.println("Lines time:" + (((double)end.getTime() - start.getTime())/1000.0));
        System.out.println("Lines Guessed:" + result.size());

        return result;
    }

    private static void readDataSimple(BufferedReader in)
            throws Exception
    {
        for (int y = 0; y < H; y++)
        {
            String line = in.readLine();
            int pos = line.indexOf('X');
            if (pos >= 0)
            {
                myPoint.x = new Fraction(0.5).add(pos);
                myPoint.y = new Fraction(0.5).add(y);
            }
        }

        reflectingCorners.clear();
        mirrors.clear();

        reflectingCorners.add(new Point(1, 1));
        reflectingCorners.add(new Point(1, H - 1));
        reflectingCorners.add(new Point(W - 1, 1));
        reflectingCorners.add(new Point(W - 1, H - 1));

        mirrors.add(new Section(
                new Line(true, 0, 1),
                new Point(1, 1),
                new Point(1, H - 1)));
        mirrors.add(new Section(
                new Line(false, 0, H - 1),
                new Point(1, H - 1),
                new Point(W - 1, H - 1)));
        mirrors.add(new Section(
                new Line(true, 0, W - 1),
                new Point(W - 1, H - 1),
                new Point(W - 1, 1)));
        mirrors.add(new Section(
                new Line(false, 0, 1),
                new Point(W - 1, 1),
                new Point(1, 1)));
    }
}


public class CG {

	/** get the intersection between a segment (p1, p2), and a project line from the origin
	* with an angle. 
	* @return  Point(INF, INF) if there is no intersection
	 * */
	public static Point intersectSegmentOri(Point p1, Point p2, double angle)
	{
		Point ori = new Point(0.0, 0.0), out = new Point(Math.cos(angle),
				Math.sin(angle));
		Point intersect = new Point(0,0);
		int stat = crossPointLL(p1, p2, ori, out, intersect);

		// parallel
		if(stat == 0)
			return new Point(CGConst.INF, CGConst.INF);

		// check the case of intersect at the wrong side of the project line
		if(Math.cos(angle) * (intersect.x) < 0 || Math.sin(angle) * (intersect.y) < 0)
			return new  Point(CGConst.INF, CGConst.INF);
		
		// check if the intersection is on the segment
		if(intersectSP(p1, p2, intersect))
			return intersect;
		return new Point(CGConst.INF, CGConst.INF);


	}
	static boolean intersectSP(Point s0, Point s1, Point p) {
		return s0.minus(p).abs() + s1.minus(p).abs() - s1.minus(s0).abs()< CGConst.EPS; // triangle inequality
		
	}
	private static int crossPointLL(Point m0, Point m1, Point n0, Point n1,
			Point p) {
		if (Math.abs (cross (m1.minus(m0), n1.minus(n0))) > CGConst.EPS) { 
			// non-parallel => intersect
			double h = cross (m1 .minus( m0), n1.minus(n0));
			double k = cross (m1.minus( m0), m1.minus(n0));
			p.copy( n1.minus(n0).mul(k/h).add(n0));
			return 1; // intersect at one point
		}
		if (Math.abs (cross (m1.minus(m0), n0.minus(m0))) < CGConst.EPS) { // area==0 => same line => intersect
			p.copy( m0); // one of the intersection points, or m1, n0, n1, ...
			return -1; // intersect at infinitely many points (when 2 parallel lines overlap)
		}
		return 0; // no intersection points (when two lines are parallel but does not overlap)

	}
	private static double cross(Point a, Point b) {
		return a.x * b.y - a.y * b.x;
	}
	public static double distance(Point a, Point b)
	{
		return a.minus(b).abs();
	}
	public static double getAngle(Point a, Point b)
	{
		return Math.acos(point(a, b)/(a.abs()*b.abs()));
	}
	private static double point(Point a, Point b) {
		
		return a.x*b.x + a.y*b.y;
	}
	static int dblcmp (double a, double b) {
		if (Math.abs (a-b) < CGConst.EPS) return 0;
		return a < b ? -1 : 1;
		}
	public static int ccw (Point a, Point b, Point c) { // short version
		return dblcmp (cross (b.minus(a), c.minus(a)), 0);
		}
	// para: s0 and s1 form a segment s
	// para: t0 and t1 form a segment t
	// return: true if s and t appears like a 'X'
	public static boolean properIntersectSS (Point s0,  Point s1,  Point t0,  Point t1) {
	return ccw (s0, s1, t0) * ccw (s0, s1, t1) < 0 &&
	ccw (t0, t1, s0) * ccw (t0, t1, s1) < 0;
	}
	public static double triArea (Point a, Point b, Point c) {
		// centroid = (a + b + c) / 3.0; // centroid of triangle
		return Math.abs (cross (b.minus(a), c.minus(a))) * 0.5; // |cross product| / 2
		}
	/* check if two segments intersect and find the intersection point
	para:
	input s0 and s1 form a line s
	input t0 and t1 form a line t
	output p is the intersection point (if return value != 0)
	return:
	1: the segments intersect at exactly one point
	-1: the segments intersect improperly, p is ONE OF the intersection points
	0: no intersection points
	note: If you are sure the segment intersect and want to find the intersection point,
	you can include the statements in the first *if* block only.
	*/
	public static int crossPointSS( Point s0, Point s1,  Point t0, Point t1, Point p) {
		if (properIntersectSS (s0, s1, t0, t1)) {
		double r = triArea (s0, t0, t1) / triArea (s1, t0, t1);
		Point temp = s0.add(   (s1.minus(s0)).mul((r / (1+r))));
		p.x = temp.x;
		p.y = temp.y;
		return 1;
		}
		if (intersectSP (s0, s1, t0)) { p.copy(t0); return -1; }
		if (intersectSP (s0, s1, t1)) { p .copy( t1); return -1; }
		if (intersectSP (t0, t1, s0)) { p .copy(s0); return -1; }
		if (intersectSP (t0, t1, s1)) { p .copy(s1); return -1; }
		return 0;
		}
}

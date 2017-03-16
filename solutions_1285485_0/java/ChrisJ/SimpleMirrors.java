import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;


public class SimpleMirrors {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(args[1]);
		
		// number of testcases
		String sCount = in.readLine();
		int count = Integer.parseInt(sCount);

		for(int idx=1; idx<=count; idx++) {
			String[] parts = in.readLine().split(" ");
			int h = Integer.parseInt(parts[0]);
			int w = Integer.parseInt(parts[1]);
			int d = Integer.parseInt(parts[2]);
			
			int x = -1, y = -1;
			
			// small dataset => just find the "X"
			for(int i=0; i<h; i++) {
				String l = in.readLine();
				int p = l.indexOf('X');
				if(p > -1) {
					y = 10*i - 5;
					x = 10*p - 5;
				}
			}
			
			out.println("Case #" + idx + ": " + process(10*(h-2), 10*(w-2), 10*d, x, y));
			  
		}
		
		out.close();
	}

	private static int process(int h, int w, int d, int ox, int oy) {
		System.out.println("h=" + h + ", w=" + w + ", d=" + d + ", ox=" + ox + ", oy=" + oy);
		
		MirrorSet ms = new MirrorSet(
				Arrays.asList(new Mirror[] {
						new Mirror(Facing.POS, Orient.HORIZ, 0, 0, w),
						new Mirror(Facing.NEG, Orient.HORIZ, h, 0, w),
						new Mirror(Facing.POS, Orient.VERT, 0, 0, h),
						new Mirror(Facing.NEG, Orient.VERT, w, 0, h),
				}),
				ox,
				oy,
				d,
				w,
				h
				);
		
		Set<Point> pts = ms.transitiveImages();
		Set<Double> angles = ms.angles(pts);
		System.out.println("  " + pts.size() + ": " + pts);
		System.out.println("  " + angles.size() + ": " + angles);
		
		return angles.size();
	}
	
	
	private static class MirrorSet {
		private final Collection<Mirror> mirrors;
		private final int ox, oy, limit, w, h;
		
		public MirrorSet(Collection<Mirror> mirrors, int ox, int oy, int limit, int w, int h) {
			this.mirrors = mirrors;
			this.ox = ox;
			this.oy = oy;
			this.limit = limit;
			this.w = w;
			this.h = h;
		}
		
		public Set<Point> images(Set<Point> in) {
			HashSet<Point> out = new HashSet<Point>();
			
			for(Point i : in) {
				for(Mirror m : mirrors) {
					Point o = m.image(i);
					if(o != null && ! in.contains(o) && 
							Math.sqrt((ox-o.x)*(ox-o.x) + (oy-o.y)*(oy-o.y)) <= limit) out.add(o);
				}
			}
			
			return out;
		}
		
		public Set<Point> transitiveImages() {
			Set<Point> im = new HashSet<Point>();
			im.add(new Point(ox, oy));
			Set<Point> newer;
			do {
				newer = images(im);
				im.addAll(newer);
			} while(newer.size() > 0);
			
			return im;
		}
		
		public Set<Double> angles(Set<Point> in) {
			Set<Double> out = new HashSet<Double>();
			
			for(Point i : in) {
				if(i.x != ox || i.y != oy)
					out.add(Math.atan2(i.y-oy, i.x-ox));
			}
			
			return out;
		}
	}
	
	private static enum Facing {
		POS, NEG
	}
	
	private static enum Orient {
		VERT, HORIZ
	}
	
	private static class Mirror {
		private final Facing facing;
		private final Orient orient;
		private final int pos, start, stop;
		
		public Mirror(Facing facing, Orient orient, int pos, int start, int stop) {
			this.facing = facing;
			this.orient = orient;
			this.pos = pos;
			this.start = start;
			this.stop = stop;
		}
		
		public Point image(Point p) {
			switch(orient) {
			case VERT:
				if(facing == Facing.POS && p.x >= pos || facing == Facing.NEG && p.x <= pos) {
					return new Point(2 * pos - p.x, p.y);
				} else return null;
				
				
			case HORIZ:
				if(facing == Facing.POS && p.y >= pos || facing == Facing.NEG && p.y <= pos) {
					return new Point(p.x, 2 * pos - p.y);
				} else return null;

			}
			
			return null;
		}
	}
	
	private static class Point {
		public final int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		@Override
		public boolean equals(Object obj) {
			return obj instanceof Point && ((Point)obj).x == x && ((Point)obj).y == y;
		}
		
		@Override
		public int hashCode() {
			return (x << 16) ^ y;
		}
		
		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}
	
}
import java.util.Scanner;


public class D {

	int H,W,D;
	double x,y;
	
	D() {
		Scanner in=new Scanner(System.in);
		for (int T=in.nextInt(),TC=1; T-->0; ++TC) {
			H=in.nextInt();
			W=in.nextInt();
			D=in.nextInt();
			for (int i=0; i<H; ++i) {
				String line=in.next();
				for (int j=0; j<W; ++j)
					if (line.charAt(j)=='X') {
						x=j-0.5;
						y=(H-i-1)-0.5;
					}
			}
			H-=2; W-=2;
			System.out.printf("Case #%d: %d%n",TC,solve());
		}
	}
	
	int solve() {
		int res=0;
		for (int dx=-60; dx<=60; ++dx)
			for (int dy=-60; dy<=60; ++dy)
				if (dx!=0 || dy!=0)
					if (check(dx,dy))
						++res;
		return res;
	}
	
	boolean check(int dx, int dy) {
		double tx=getX(dx);
		double ty=getY(dy);
		double d=dist2(x,y,tx,ty); 
		if (d>D*D)
			return false;
		for (int ddx=Math.min(dx, 0); ddx<=Math.max(dx, 0); ++ddx)
			for (int ddy=Math.min(dy,0); ddy<=Math.max(dy, 0); ++ddy)
				if ((ddx!=0 || ddy!=0) && !(dx==ddx && dy==ddy)) {
					double ttx=getX(ddx);
					double tty=getY(ddy);
					if (collinear(x,y,tx,ty,ttx,tty) && d>dist2(x,y,ttx,tty))
						return false;
				}
		return true;
	}
	
	boolean collinear(double x1, double y1, double x2, double y2, double x3, double y3) {
		return x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)==0;
	}
	
	double dist2(double x1, double y1, double x2, double y2) {
		double dx=x1-x2;
		double dy=y1-y2;
		return dx*dx+dy*dy;
	}
	
	double getX(int dx) {
		if (dx==0)
			return x;
		double delta = (Math.abs(dx)-1)*W;
		if (dx>0) {
			if (dx%2==1) {
				delta+=W-x+W-x;
			} else {
				delta+=W-x+x;
			}
		} else {
			if (dx%2==0) {
				delta+=x+W-x;
			} else {
				delta+=x+x;
			}
		}
		return x+sgn(dx)*delta;
	}

	double getY(int dy) {
		if (dy==0)
			return y;
		double delta = (Math.abs(dy)-1)*H;
		if (dy>0) {
			if (dy%2==1) {
				delta+=H-y+H-y;
			} else {
				delta+=H-y+y;
			}
		} else {
			if (dy%2==0) {
				delta+=y+H-y;
			} else {
				delta+=y+y;
			}
		}
		return y+sgn(dy)*delta;
	}
	
	double sgn(double x) {
		return x>0?1:x<0?-1:0;
	}
	public static void main(String[] args) {
		new D();
	}

}

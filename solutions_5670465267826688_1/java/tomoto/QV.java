public class QV {
	public static QV E = new QV(1, Q.n);
	public static QV NE = new QV(-1, Q.n);
	public static QV I = new QV(1, Q.i);
	public static QV J = new QV(1, Q.j);
	public static QV K = new QV(1, Q.k);
	
	private Q q;
	private int r;

	@Override
	public String toString() {
		if (r == 1) {
			return q.toString();
		} else if (r == -1) {
			return "-" + q.toString();
		} else {
			return r + q.toString();
		}
	}

	public QV(int r, Q q) {
		this.r = r;
		this.q = q;
	}

	public QV mul(QV other) {
		switch (this.q) {
		case n:
			return new QV(this.r * other.r, other.q);
		case i:
			switch (other.q) {
			case n:
				return new QV(this.r * other.r, Q.i);
			case i:
				return new QV(-this.r * other.r, Q.n);
			case j:
				return new QV(this.r * other.r, Q.k);
			case k:
				return new QV(-this.r * other.r, Q.j);
			}
		case j:
			switch (other.q) {
			case n:
				return new QV(this.r * other.r, Q.j);
			case i:
				return new QV(-this.r * other.r, Q.k);
			case j:
				return new QV(-this.r * other.r, Q.n);
			case k:
				return new QV(this.r * other.r, Q.i);
			}
		case k:
			switch (other.q) {
			case n:
				return new QV(this.r * other.r, Q.k);
			case i:
				return new QV(this.r * other.r, Q.j);
			case j:
				return new QV(-this.r * other.r, Q.i);
			case k:
				return new QV(-this.r * other.r, Q.n);
			}
		}

		return other;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (obj instanceof QV) {
			QV other = (QV) obj;
			return this.r == other.r && this.q == other.q;
		} else {
			return false;
		}
	} 
}

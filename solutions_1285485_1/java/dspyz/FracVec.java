import java.awt.Point;

public class FracVec {
	public final Frac row, col;

	public FracVec(Frac row, Frac col) {
		this.row = row;
		this.col = col;
	}

	public FracVec(Point pos) {
		row = new Frac(pos.y);
		col = new Frac(pos.x);
	}

	public FracVec flipHoriz() {
		return new FracVec(row, col.neg());
	}

	public FracVec flipVert() {
		return new FracVec(row.neg(), col);
	}

	public boolean isCorner() {
		return row.denom == 1 && col.denom == 1;
	}

	public FracVec add(FracVec other) {
		return new FracVec(row.add(other.row), col.add(other.col));
	}

	public FracVec sub(FracVec other) {
		return new FracVec(row.sub(other.row), col.sub(other.col));
	}

	public FracVec neg() {
		return new FracVec(row.neg(), col.neg());
	}

	public boolean equals(FracVec other) {
		return row.equals(other.row) && col.equals(other.col);
	}

	public boolean equals(Point p) {
		return row.equals(p.y) && col.equals(p.x);
	}

	@Override
	public boolean equals(Object other) {
		return other instanceof FracVec && equals((FracVec) other);
	}

	@Override
	public int hashCode() {
		return (31 + row.hashCode()) * 31 + col.hashCode();
	}

	public String toString() {
		return "( " + row + ", " + col + " )";
	}

	public FracVec multiply(Frac scalar) {
		return new FracVec(row.mult(scalar), col.mult(scalar));
	}

	public int compareLengthTo(int d) {
		return row.mult(row).add(col.mult(col)).compareTo(new Frac(d * d));
	}

	public Point getNextCell(FracVec dm) {
		int resRow, resCol;
		if (dm.row.sgn() < 0) {
			resRow = row.roundDownAddSmallDown();
		} else {
			resRow = row.roundDownAddSmallUp();
		}
		if (dm.col.sgn() < 0)
			resCol = col.roundDownAddSmallDown();
		else
			resCol = col.roundDownAddSmallUp();
		return new Point(resCol, resRow);
	}
}


public class Marked implements Comparable<Marked> {
	public long str;
	public long ini;
	public long fin;
	public Marked(long i, long f, long s) {
		ini = i;
		fin = f;
		str = s;
	}
	@Override
	public int compareTo(Marked o) {
		if(ini == o.ini)
			return 0;
		if(ini < o.ini)
			return -1;
		return 1;
	}
}

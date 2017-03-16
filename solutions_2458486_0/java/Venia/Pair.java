
// pair inversely sorted by first element
public class Pair<T1 extends Comparable<T1>, T2> implements Comparable<Pair<T1, T2>>{
    T1 x; T2 y;
    public Pair(T1 a, T2 b) { x=a; y=b;}

    // inverse comparator on 'x'
    public int compareTo(Pair<T1, T2> other) {
        return other.x.compareTo(this.x);
    }
}

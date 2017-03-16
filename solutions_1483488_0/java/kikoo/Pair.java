/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package question3;

/**
 *
 * @author karim
 */
public class Pair {

    private Integer int1;
    private Integer int2;

    public Pair() {
    }

    public Pair(int int1) {
        this.int1 = int1;
    }

    public Pair(int int1, int int2) {
        this.int1 = int1;
        this.int2 = int2;
    }

    public int getint1() {
        return int1;
    }

    public void setint1(int int1) {
        this.int1 = int1;
    }

    public int getint2() {
        return int2;
    }

    public void setint2(int int2) {
        this.int2 = int2;
    }

    @Override
    public boolean equals(Object obj) {
        Pair o = (Pair) obj;
        if ((o.int1.equals(int1) && o.int2.equals(int2)) || (o.int2.equals(int1) && o.int1.equals(
                int2))) {
            return true;
        } else {
            return false;
        }

    }

    @Override
    public int hashCode() {

        return int1.hashCode() + int2.hashCode();
    }
}

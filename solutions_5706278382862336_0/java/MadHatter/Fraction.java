/**
 * Created by dkpiychenko on 5/11/14.
 */
public class Fraction {
    private int numerator;             // Fraction numerator
    private int denominator;           // Fraction denominator

    /*-----------------------------------------------------------------
     * constructor
     * Takes no parameters, initializes the object to 0/1
     */
    public Fraction() {
        numerator = 0;
        denominator = 1;
    }

    /*-----------------------------------------------------------------
     * constructor
     * Takes parameter, the numerator, initializes denominator to 1
     * so object is numerator/1
     */
    public Fraction(int num) {
        numerator = num;
        denominator = 1;
    }

    /*-----------------------------------------------------------------
     * constructor
     * If fraction is negative, put negative number in numerator
     */
    public Fraction(int num, int denom) {
        numerator = (denom < 0 ? -num : num);
        if (denom == 0) {
            denominator = 1;
        }
        denominator = (denom < 0 ? -denom : denom);
        reduce();
    }

    /*-----------------------------------------------------------------
     * setNumerator
     * numerator is set to be the given parameter
     */
    public void setNumerator(int num) {
        numerator = num;
        reduce();
    }

    /*-----------------------------------------------------------------
     * getNumerator
     * return numerator
     */
    public int getNumerator() {
        return numerator;
    }

    /*-----------------------------------------------------------------
     * setDenominator
     * denominator is set to be the given parameter (zero is ignored),
     * if denominator is negative, numerator is adjusted
     */
    public void setDenominator(int denom) {
        if (denom > 0) {
            denominator = denom;
            reduce();
        }
        else if (denom < 0) {
            numerator = -numerator;
            denominator = -denom;
            reduce();
        }
    }

    /*-----------------------------------------------------------------
     * getDenominator
     * return denominator
     */
    public int getDenominator() {
        return denominator;
    }

    /*-----------------------------------------------------------------
     * addTo
     * add the parameter Fraction to the current object Fraction
     */
    public Fraction addTo(Fraction rhs) {
        Fraction sum = new Fraction();
        sum.denominator = denominator * rhs.denominator;
        sum.numerator = numerator * rhs.denominator
                + denominator * rhs.numerator;
        sum.reduce();
        return sum;
    }

    /*-----------------------------------------------------------------
     * toString
     * convert the Fraction to a String object, e.g., 2/3
     */
    public String toString() {
        return numerator + "/" + denominator;
    }

    /*-----------------------------------------------------------------
     * equals
     * compare the parameter Fraction to the current object Fraction
     */
    public boolean equals(Fraction rhs) {
        return (numerator == rhs.numerator) && (denominator == rhs.denominator);
    }

    /*-----------------------------------------------------------------
     * reduce
     * reduce Fraction to lowest terms by finding largest common denominator
     * and dividing it out
     */
    public void reduce() {
        int n = numerator;
        int d = denominator;

        while (d != 0) {
            int t = d;
            d = n % d;
            n = t;
        }

        int gcd = n;

        numerator /= gcd;
        denominator /= gcd;
    }
}

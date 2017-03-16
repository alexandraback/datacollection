#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

class Ratio {
public:
    int numerator, denominator;
    
    Ratio(int numerator = 0, int denominator = 1) {
        setRatio(numerator, denominator);
    }
    
    void setRatio(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
        simplify();
    }
    
    void simplify() {
        int cd = gcd(numerator, denominator);
        if (cd) {
            numerator /= cd;
            denominator /= cd;
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    }
    
    void add_inverse(Ratio a) {
        numerator = -a.numerator;
        denominator = a.denominator;
    }
    
    void mul_inverse(Ratio a) {
        numerator = a.denominator;
        denominator = a.numerator;
    }
    
    void add(Ratio a, Ratio b) {
        int newNumerator = a.numerator * b.denominator + b.numerator * a.denominator,
            newDenominator = a.denominator * b.denominator;
        numerator = newNumerator;
        denominator = newDenominator;
        simplify();
    }
    
    void multiply(Ratio a, Ratio b) {
        int newNumerator = a.numerator * b.numerator,
            newDenominator = a.denominator * b.denominator;
        numerator = newNumerator;
        denominator = newDenominator;
        simplify();
    }
};

Ratio getMyX(char matrix[30][30], int h, int w)
{
    Ratio myX;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (matrix[i][j] == 'X') {
                myX.setRatio(2 * j + 1, 2);
                return myX;
            }
}

Ratio getMyY(char matrix[30][30], int h, int w)
{
    Ratio myY;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (matrix[i][j] == 'X') {
                myY.setRatio(2 * i + 1, 2);
                return myY;
            }
}

int getRight(Ratio x)
{
    return x.numerator / x.denominator + 1;
}

int getLeft(Ratio x)
{
    return (int)ceil((double)x.numerator / x.denominator) - 1;
}

int getTop(Ratio y)
{
    return (int)ceil((double)y.numerator / y.denominator) - 1;
}

int getBottom(Ratio y)
{
    return y.numerator / y.denominator + 1;
}

int checkAngle(Ratio x, Ratio y, int x_i, int y_i, int tm, int tn)
{
    Ratio y0(y_i);
    y0.add_inverse(y0);
    y.add(y, y0);
    Ratio x0(x_i);
    x.add_inverse(x);
    x.add(x0, x);
    x.mul_inverse(x);
    Ratio r;
    r.multiply(y, x);
    Ratio t(tn, tm);
    t.add_inverse(t);
    r.add(r, t);
    if (r.numerator > 0)
        return +1;
    else if (r.numerator == 0)
        return 0;
    else
        return -1;
}

bool passThrough(Ratio x, Ratio y, Ratio myX, Ratio myY, int tm, int tn)
{
    if (x.numerator == myX.numerator &&
        x.denominator == myX.denominator &&
        y.numerator == myY.numerator &&
        y.denominator == myY.denominator)
        return false;
    
    int j = getLeft(x);
    if (x.denominator == 1 && tm > 0)
        j++;
    int i = getTop(y);
    if (y.denominator == 1 && tn < 0)
        i++;
    if (!(j == getLeft(myX) && i == getTop(myY)))
        return false;
    
    Ratio a;
    a.add_inverse(myY);
    a.add(a, y);
    Ratio m(tm);
    a.multiply(a, m);
    
    Ratio b;
    b.add_inverse(x);
    b.add(myX, b);
    Ratio n(tn);
    b.multiply(b, n);
    
    if (a.numerator == b.numerator &&
        a.denominator == b.denominator)
        return true;
    else
        return false;
}

double calDistance(Ratio x_start, Ratio y_start, Ratio x, Ratio y)
{
    double dx = (double)x_start.numerator / x_start.denominator
        - (double)x.numerator / x.denominator;
    double dy = (double)y_start.numerator / y_start.denominator
        - (double)y.numerator / y.denominator;
    return sqrt(dx * dx + dy * dy);
}

void loop(int h, int w, int d, char matrix[30][30], int tn, int tm, int *counter)
{
    Ratio myX = getMyX(matrix, h, w),
        myY = getMyY(matrix, h, w);
    
    Ratio x(myX.numerator, myX.denominator);
    Ratio y(myY.numerator, myY.denominator);
    double dist = 0;
    
    cout << tn << "," << tm;
    
    while (1) {
    Ratio x_start(x.numerator, x.denominator);
    Ratio y_start(y.numerator, y.denominator);
    int tn_start = tn;
    int tm_start = tm;
    
    if (tn == 0 && tm > 0) {
        int right = getRight(x);
        Ratio newX(right);
        x = newX;
        
        int j = getLeft(x);
        int i = getTop(y);
        if (j + 1 < w && matrix[i][j + 1] == '#')
            tm = -tm;
        
    } else if (tn > 0 && tm > 0) {
        int right = getRight(x);
        int top = getTop(y);
        int sTopRight = checkAngle(x, y, right, top, tm, tn);
        if (sTopRight > 0) {
            Ratio newX(right);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y);
            if (j + 1 < w && matrix[i][j + 1] == '#')
                tm = -tm;
            
        } else if (sTopRight < 0) {
            Ratio newY(top);
            Ratio newX;
            newX.add_inverse(newY);
            newX.add(newX, y);
            Ratio t(tm, tn);
            newX.multiply(newX, t);
            newX.add(newX, x);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y) + 1;
            if (i - 1 >= 0 && matrix[i - 1][j] == '#')
                tn = -tn;
            
        } else {
            Ratio newY(top);
            Ratio newX;
            newX.add_inverse(newY);
            newX.add(newX, y);
            Ratio t(tm, tn);
            newX.multiply(newX, t);
            newX.add(newX, x);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y) + 1;
            if (i - 1 >= 0 && matrix[i - 1][j] == '#' &&
                j + 1 < w && matrix[i][j + 1] == '#' &&
                matrix[i - 1][j + 1] == '#') {
                tm = -tm;
                tn = -tn;
            } else if (i - 1 >= 0 && matrix[i - 1][j] != '#' &&
                j + 1 < w && matrix[i][j + 1] != '#' &&
                matrix[i - 1][j + 1] == '#') {
                return;
            } else if (i - 1 >= 0 && matrix[i - 1][j] == '#' &&
                j + 1 < w && matrix[i][j + 1] != '#' &&
                matrix[i - 1][j + 1] == '#') {
                tn = -tn;
            } else if (i - 1 >= 0 && matrix[i - 1][j] != '#' &&
                j + 1 < w && matrix[i][j + 1] == '#' &&
                matrix[i - 1][j + 1] == '#') {
                tm = -tm;
            }            
            
        }
    } else if (tn > 0 && tm == 0) {
        int top = getTop(y);
        Ratio newY(top);
        y = newY;
        
        int j = getLeft(x);
        int i = getTop(y) + 1;
        if (i - 1 >= 0 && matrix[i - 1][j] == '#')
            tn = -tn;
        
    } else if (tn > 0 && tm < 0) {
        int left = getLeft(x);
        int top = getTop(y);
        int sTopLeft = checkAngle(x, y, left, top, tm, tn);
        if (sTopLeft > 0) {
            Ratio newY(top);
            Ratio newX;
            newX.add_inverse(newY);
            newX.add(newX, y);
            Ratio t(tm, tn);
            newX.multiply(newX, t);
            newX.add(newX, x);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y) + 1;
            if (i - 1 >= 0 && matrix[i - 1][j] == '#')
                tn = -tn;
            
        } else if (sTopLeft < 0) {
            Ratio newX(left);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x) + 1;
            int i = getTop(y);
            if (j - 1 >= 0 && matrix[i][j - 1] == '#')
                tm = -tm;
            
        } else {
            Ratio newX(left);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x) + 1;
            int i = getTop(y) + 1;
            if (i - 1 >= 0 && matrix[i - 1][j] == '#' &&
                j - 1 >= 0 && matrix[i][j - 1] == '#' &&
                matrix[i - 1][j - 1] == '#') {
                tm = -tm;
                tn = -tn;
            } else if (i - 1 >= 0 && matrix[i - 1][j] != '#' &&
                j - 1 >= 0 && matrix[i][j - 1] != '#' &&
                matrix[i - 1][j - 1] == '#') {
                return;
            } else if (i - 1 >= 0 && matrix[i - 1][j] == '#' &&
                j - 1 >= 0 && matrix[i][j - 1] != '#' &&
                matrix[i - 1][j - 1] == '#') {
                tn = -tn;
            } else if (i - 1 >= 0 && matrix[i - 1][j] != '#' &&
                j - 1 >= 0 && matrix[i][j - 1] == '#' &&
                matrix[i - 1][j - 1] == '#') {
                tm = -tm;
            }
            
        }
    } else if (tn == 0 && tm < 0) {
        int left = getLeft(x);
        Ratio newX(left);
        x = newX;
        
        int j = getLeft(x) + 1;
        int i = getTop(y);
        if (j >= 0 && matrix[i][j - 1] == '#')
            tm = -tm;
        
    } else if (tn < 0 && tm < 0) {
        int left = getLeft(x);
        int bottom = getBottom(y);
        int sBottomLeft = checkAngle(x, y, left, bottom, tm, tn);
        if (sBottomLeft > 0) {
            Ratio newX(left);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x) + 1;
            int i = getTop(y);
            if (j - 1 >= 0 && matrix[i][j - 1] == '#')
                tm = -tm;
            
        } else if (sBottomLeft < 0) {
            Ratio newY(bottom);
            Ratio newX;
            newX.add_inverse(newY);
            newX.add(newX, y);
            Ratio t(tm, tn);
            newX.multiply(newX, t);
            newX.add(newX, x);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y);
            if (i + 1 < h && matrix[i + 1][j] == '#')
                tn = -tn;
            
        } else if (sBottomLeft == 0) {
            Ratio newX(left);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x) + 1;
            int i = getTop(y);
            if (j - 1 >= 0 && matrix[i][j - 1] == '#' &&
                i + 1 < h && matrix[i + 1][j] == '#' &&
                matrix[i + 1][j - 1] == '#') {
                tm = -tm;
                tn = -tn;
            } else if (j - 1 >= 0 && matrix[i][j - 1] != '#' &&
                i + 1 < h && matrix[i + 1][j] != '#' &&
                matrix[i + 1][j - 1] == '#') {
                return;
            } else if (j - 1 >= 0 && matrix[i][j - 1] == '#' &&
                i + 1 < h && matrix[i + 1][j] != '#' &&
                matrix[i + 1][j - 1] == '#') {
                tm = -tm;
            } else if (j - 1 >= 0 && matrix[i][j - 1] != '#' &&
                i + 1 < h && matrix[i + 1][j] == '#' &&
                matrix[i + 1][j - 1] == '#') {
                tn = -tn;
            }
            
        }
    } else if (tn < 0 && tm == 0) {
        int bottom = getBottom(y);
        Ratio newY(bottom);
        y = newY;
        
        int j = getLeft(x);
        int i = getTop(y);
        if (i + 1 < h && matrix[i + 1][j] == '#')
            tn = -tn;
        
    } else if (tn < 0 && tm > 0) {
        int right = getRight(x);
        int bottom = getBottom(y);
        int sBottomRight = checkAngle(x, y, right, bottom, tm, tn);
        if (sBottomRight > 0) {
            Ratio newY(bottom);
            Ratio newX;
            newX.add_inverse(newY);
            newX.add(newX, y);
            Ratio t(tm, tn);
            newX.multiply(newX, t);
            newX.add(newX, x);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y);
            if (i + 1 < h && matrix[i + 1][j] == '#')
                tn = -tn;
            
        } else if (sBottomRight < 0) {
            Ratio newX(right);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y);
            if (j + 1 < w && matrix[i][j + 1] == '#')
                tm = -tm;
            
        } else {
            Ratio newX(right);
            Ratio newY;
            newY.add_inverse(x);
            newY.add(newX, newY);
            Ratio t(tn, tm);
            newY.multiply(newY, t);
            newY.add_inverse(newY);
            newY.add(newY, y);
            x = newX;
            y = newY;
            
            int j = getLeft(x);
            int i = getTop(y);
            if (j + 1 < w && matrix[i][j + 1] == '#' &&
                i + 1 < h && matrix[i + 1][j] == '#' &&
                matrix[i + 1][j + 1] == '#') {
                tm = -tm;
                tn = -tn;
            } else if (j + 1 < w && matrix[i][j + 1] != '#' &&
                i + 1 < h && matrix[i + 1][j] != '#' &&
                matrix[i + 1][j + 1] == '#') {
                return;
            } else if (j + 1 < w && matrix[i][j + 1] == '#' &&
                i + 1 < h && matrix[i + 1][j] != '#' &&
                matrix[i + 1][j + 1] == '#') {
                tm = -tm;
            } else if (j + 1 < w && matrix[i][j + 1] != '#' &&
                i + 1 < h && matrix[i + 1][j] == '#' &&
                matrix[i + 1][j + 1] == '#') {
                tn = -tn;
            }
            
        }
    }
    
    /*
    cout << x.numerator << "/" << x.denominator << ", ";
    cout << y.numerator << "/" << y.denominator << ": ";
    cout << tn << "/" << tm << endl;
    
    cout << "* " << x_start.numerator << "/" << x_start.denominator << ", ";
    cout << y_start.numerator << "/" << y_start.denominator << ": ";
    cout << tn_start << "/" << tm_start << endl;
    */
    
    if (passThrough(x_start, y_start, myX, myY, tm_start, tn_start)) {
        dist += calDistance(x_start, y_start, myX, myY);
        if (dist <= d) {
            (*counter)++;
            cout << " FOUND_DIST: " << dist << endl;
        }
        break;
    }
    
    dist += calDistance(x_start, y_start, x, y);
    if (dist >= d) {
        cout << " EXCEEDED: " << dist << endl;
        break;
    }
    
    }
}

int main()
{
    ifstream in("d.in");
    ofstream out("d.out");
    int caseAmount;
    in >> caseAmount;
    for (int caseNum = 1; caseNum <= caseAmount; caseNum++) {
        int h, w, d;
        char matrix[30][30] = {};
        in >> h >> w >> d;
        in.getline(matrix[0], w + 1);
        for (int i = 0; i < h; i++)
            in.getline(matrix[i], w + 1);
        
        int counter = 0;
        
        {
            int tn = 0, tm = 1;
            loop(h, w, d, matrix, tn, tm, &counter);
        }
        
        for (int tn = 1; tn <= sqrt(d * d - 1); tn++) {
            for (int tm = 1; tm <= sqrt(d * d - tn * tn); tm++) {
                if (gcd(tn, tm) == 1)
                    loop(h, w, d, matrix, tn, tm, &counter);
            }
        }
        
        {
            int tn = 1, tm = 0;
            loop(h, w, d, matrix, tn, tm, &counter);
        }
        
        for (int tn = 1; tn <= sqrt(d * d - 1); tn++) {
            for (int tm = -1; tm >= -sqrt(d * d - tn * tn); tm--) {
                if (gcd(tn, -tm) == 1)
                    loop(h, w, d, matrix, tn, tm, &counter);
            }
        }
        
        {
            int tn = 0, tm = -1;
            loop(h, w, d, matrix, tn, tm, &counter);
        }
        
        for (int tn = -1; tn >= -sqrt(d * d - 1); tn--) {
            for (int tm = -1; tm >= -sqrt(d * d - tn * tn); tm--) {
                if (gcd(-tn, -tm) == 1)
                    loop(h, w, d, matrix, tn, tm, &counter);
            }
        }
        
        {
            int tn = -1, tm = 0;
            loop(h, w, d, matrix, tn, tm, &counter);
        }
        
        for (int tn = -1; tn >= -sqrt(d * d - 1); tn--) {
            for (int tm = 1; tm <= sqrt(d * d - tn * tn); tm++) {
                if (gcd(-tn, tm) == 1)
                    loop(h, w, d, matrix, tn, tm, &counter);
            }
        }
        
        out << "Case #" << caseNum << ": " << counter << endl;
    }
    return 0;
}

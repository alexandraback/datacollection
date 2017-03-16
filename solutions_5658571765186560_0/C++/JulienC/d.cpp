#include <iostream>

#define REP(i,n) for(int i=0,nn=static_cast<int>(n);i<nn;i++)

void fillable() { std::cout << "GABRIEL" << std::endl; }
void un_fillable() { std::cout << "RICHARD" << std::endl; }

void solve()
{
    int X,R,C; std::cin >> X >> R >> C;
    if (R > C) std::swap(R,C);
    if (X == 1)             return fillable();
    if ((R*C % X) != 0)     return un_fillable();
    if (X > R*C)            return un_fillable();
    if (X>R && X>C)         return un_fillable();

    if (R == 1)
    {
        if (C == 2)
        {
            if (X == 2) return fillable();
            if (X == 3) return un_fillable();
            if (X == 4) return un_fillable();
        }
        if (C == 3)
        {
            if (X == 2) return un_fillable();
            if (X == 3) return un_fillable();
            if (X == 4) return un_fillable();
        }
        if (C == 4)
        {
            if (X == 2) return fillable();
            if (X == 3) return un_fillable();
            if (X == 4) return un_fillable();
        }
    }
    if (R == 2)
    {
        if (C == 2)
        {
            if (X == 2) return fillable();
            if (X == 3) return un_fillable();
            if (X == 4) return un_fillable();
        }
        if (C == 3)
        {
            if (X == 2) return fillable();
            if (X == 3) return fillable();
            if (X == 4) return un_fillable();
        }
        if (C == 4)
        {
            if (X == 2) return fillable();
            if (X == 3) return un_fillable();
            if (X == 4) return un_fillable();
        }
    }
    if (R == 3)
    {
        if (C == 3)
        {
            if (X == 2) return un_fillable();
            if (X == 3) return fillable();
            if (X == 4) return un_fillable();
        }
        if (C == 4)
        {
            if (X == 2) return fillable();
            if (X == 3) return fillable();
            if (X == 4) return fillable();
        }
    }
    if (R == 4)
    {
        if (C == 4)
        {
            if (X == 2) return fillable();
            if (X == 3) return un_fillable();
            if (X == 4) return fillable();
        }
    }
    return un_fillable();
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}


#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void process(void) {
    string f;
    string g;
    int r, c, m, s, l;
    // start by filling row
    bool rmode = true;
    scanf("%d %d %d", &r, &c, &m);
    // assume shorter dimension is number of columns
    if (r >= c) { 
        s = c; 
        l = r;
    }
    else {
        s = r;
        l = c;
        // start by filling columns first
        rmode = false;
    }
    int fillr = 0, fillc = 0;
    
    // if number of mines > the length of the shorter one
    while (m >= s){
        if (rmode) fillr++;
        else fillc++;
        // fill the shorter row/column
        l--;
        m -= s;
        //switch mode
        if (l < s){
            rmode = !rmode;
            int temp = s;
            s = l;
            l = temp;
        }
        // printf("s is now %d, l is now %d, m is now %d, fillr %d, fillc %d \n",s, l, m, fillr, fillc);
    }

    // now we should have a nice rectangle that we need to fill with remaining mines with s <= l
    // interesting cases: m = l-1
    // check if it can be done
    // printf("l = %d, s = %d, m = %d, \n", l, s, m);
    // if ((m==0 && (l+s != 4 || l+s !=1)) || (m>0 && (l <= 2 || s <=2)) || (l-1 == m && s == 3) ) {
    if ((l-1 == m && s == 3) ) {
        cout << "Impossible" << endl;
        return;
    }
    if (m > 0){
        if (s == 1 && (r!=1 || c!=1)) {
        cout << "Impossible" << endl;
        return;
        }
        if (s == 2 && m ==1) {
        cout << "Impossible" << endl;
        return;
        }
    }
    if (m == 0){
        if ((s<=2) && !(s == 1 && l == 1) && !( s==1 && (r==1 || c==1)) && !(s == 2 && m%2 == 0)) {
        cout << "Impossible" << endl;
        return;
        }
    }

    // printf("r is %d, c is %d, s is now %d, l is now %d, m is now %d, fillr %d, fillc %d \n",r, c, s, l, m, fillr, fillc);
    f = string(c, '*');
    for(int i = fillr; i > 0; i--) cout << f <<endl;
    f = string(fillc, '*');
    //rmode means fill column first
    if (rmode){
        bool secondcol = (m == l-1);
        for (int i = r - fillr; i > 0; i--)
        {
            //last row
            if (i == 1){
                g = string(c-fillc -1 , '.');
                cout << f << g <<'c';
            }
            else if (m) {
                if (secondcol){
                    g = string(c-fillc - 2 , '.');
                    cout << f << '*' << '*' << g;
                    secondcol = !secondcol;
                    m--;
                }
                else {
                    g = string(c-fillc - 1 , '.');
                    cout << f << '*' << g;
                }
                m--;
            }
            else {
                string g (c-fillc, '.');
                cout << f << g;
            }
            cout << endl;
        }
    }
    //col mode means fill row first
    else {
        string h;
        if (m){
            bool secondcol = (m == l-1);
            // do first row
            if (m == l-1) {
                h = string(m-1, '*');
                g = string(l-1, '.');
                cout << f << h << '.' << '.' << endl;
                cout << f << '*' << g << endl;
                fillr +=2;
            }
            else {
                h = string (m, '*');
                g = string(l - m, '.');
                cout << f << h << g << endl;
                fillr++;
            }
        }
        for (int i = r - fillr; i > 0; i--)
        {
            //last row
            if (i == 1){
                g = string(c-fillc -1 , '.');
                cout << f << g <<'c';
            }
            else {
                g = string(c-fillc, '.');
                cout << f << g;
            }
            cout << endl;
        }
    }

}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d:\n", i);
        process();
    }
}
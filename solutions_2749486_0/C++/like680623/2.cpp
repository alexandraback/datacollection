

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <utility>
#include <list>
#include <sstream>
#include <iostream>
#include <functional>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;


int x, y;



int main()
{

      ifstream cin("B-small-attempt0.in");
    ofstream cout("b.txt");

    int t;

    cin >> t;

    int c = 1;


    while (t--)
    {

        cin >> x >> y;

        string s = "";

        for (int i = 0; i < abs(x); i++)
        {
            if (x < 0) {
                s += "E";
                s += "W";
            }
            else {
                s += "W";
                s += "E";
            }
        }

        for (int i = 0; i < abs(y); i++)
        {
            if (y < 0) {
                s += "N";
                s += "S";
            }
            else {
                s += "S";
                s += "N";
            }
        }


        cout << "Case #"<< c++ <<": " << s << endl;
    }

    return 0;
}

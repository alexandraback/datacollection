#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int T,N;
double ken[1000],naomi[1000];

int heavierPairs(double p1[], double p2[])
{
    //cout << "\tRunning heavierPairs():" << endl;
    int i=0, j=0;
    while(i<N)
    {
        //cout << "\t\tcomparing " << p1[i] << " and " << p2[j] << endl;
        if(p1[i] > p2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    return j;
}

int main()
{
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> N;
        for(int i=0; i<N; i++)
            cin >> naomi[i];
        for(int i=0; i<N; i++)
            cin >> ken[i];
        sort(ken, ken+N);
        sort(naomi, naomi+N);
        printf("Case #%d: %d %d\n", t,
                heavierPairs(naomi,ken), N - heavierPairs(ken,naomi));
    }
}

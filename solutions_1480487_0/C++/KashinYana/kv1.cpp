#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)


int main()
{
   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d\n", &n);
    for(int test = 1; test <= n; test++)
    {
        int num;
        cin >> num;
        vector<double> A(num);
        vector<double> C(num);
        vector<int> mark(num);
        double sum = 0;
        for(int i = 0; i < num; i++)
        {
            cin >> A[i];
            sum += A[i];
        }
        //cout << "sum = " << sum << endl;
        for(int i = 0; i < num; i++)
        {
            A[i] /= sum;
        }
        double temp2 = A[0]*(double)(num-1);
        for(int i = 1; i < num ;i++)
        {
            temp2 -= A[i];
        }
        //cout << "temp2 = " << temp2 << endl;
        C[0] = (1.0 - temp2)/num;
        for(int i = 1; i < num; i++)
        {
            C[i] = A[0] + C[0] - A[i];
        }
        //cout << "C[0] = " << C[0] << endl;
        int N = num;
        for(int i = 0; i < num; i++)
        {
            if(C[i] < 0)
            {
                N--;
                C[i]  = 0;
                mark[i] = 1;
            }
        }
        for(int i = 0; i < num; i++)
        {
            if(mark[i] == 0)
            {
                double temp = A[i]*(N -1);
                for(int j = 0; j < num; j++)
                {
                    if(mark[j] == 0 && j!=i)
                    {
                        temp -= A[j];
                    }
                }
                C[i] = (1.0 - temp)/N;
            }
        }
        cout << "Case #"<< test<<": ";
        for(int i = 0; i < num; i++)
            cout << C[i]*100 << " ";
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <string>
using namespace std;
#define fin in
#define fout out
#define Max 1001
typedef unsigned uint;
uint T,N;
double a[Max],b[Max];
int main()
{
    ifstream fin("D-small-attempt1.in");
    ofstream fout("D.txt");
    in >> T;
    for (uint I = 0; I++<T;)
    {
        in>>N;
        int cnt1 = 0, cnt2 = 0;
        bool hash[Max];
        memset(hash, true, sizeof(hash));
        for (int i = 0; i < N; i++) 
        {
            in>>a[i];
        }
        for (int i = 0; i < N; i++) 
        {
            in>>b[i];
        }
        sort(a, a+N);
        sort(b, b+N);
        for (int i = 0; i < N; i ++) 
        {
            for (int j = 0; j < N; j ++) 
            {
                if (a[j] > b[i] && hash[j]) 
                {
                    cnt1 ++;
                    hash[j] = false;
                    break;
                }
            }
        }
        memset(hash, true, sizeof(hash));
        for (int i = 0; i < N; i ++) 
        {
            for (int j = 0; j < N; j ++) 
            {
                if (b[j] > a[i] && hash[j]) 
                {
                    cnt2 ++;
                    hash[j] = false;
                    break;
                }
            }
        }
        out<<"Case #"<<I<<": ";
        out<<cnt1<<" "<< N-cnt2<<endl;
    }
    fin.close();
    fout.close();
}
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;


long long str(string s)
{
    stringstream S(s);
    long long r;
    S >> r;
    return r;
}
bool isPow(long long x)
{
    return !(x == 0) && !(x & (x - 1));
}

int solve(long long P, long long Q, long long n)
{
    if(P*2 >= Q) return n;
    return solve(2*P,Q,n+1);
}
int main()
{
    int T;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T; 
    for (int t = 1; t <= T; t++)
    {
        string a;
        in >> a;
        string A = "";
        string B = "";
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == '/') break;
            A += a[i];
        }
        int g = 0;
        for(int i = 0; i < a.size(); i++)
        {   
            if(g)
                B += a[i];
            if(a[i] == '/') g = 1;

        }
        long long P, Q;
        P = str(A);
        Q = str(B);
        long long div = __gcd(P,Q);
        P /= div;
        Q /= div;
        if( P % 2 == 0 || !isPow(Q))
            out << "Case #" << t << ": impossible"<< endl;
        else
        {
            out << "Case #" << t << ": "<< solve(P,Q,1) << endl;
        }   
    }    
    return 0;
    
}

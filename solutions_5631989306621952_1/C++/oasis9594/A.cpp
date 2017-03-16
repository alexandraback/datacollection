#include <bits/stdc++.h>

#define mod 1000000007
#define inf 1000000000000
#define root2 1.41421
#define root3 1.73205
#define pi 3.14159
#define MAX 100001
#define ll long long int
#define PII pair<int, int>
#define f first
#define s second
#define mk make_pair
#define PLL pair<ll, ll>
#define gc getchar
#define pb push_back

using namespace std;
string S;
int k, n;
deque<char> Q;
int main()
{
    ifstream in("A-large(1).in");
    ofstream out("output.txt");
    int t, j=1;
    in>>t;
    char ch;
    while(j<=t)
    {
        out<<"Case #"<<j<<": ";
        in>>S;
        n=S.size();
        k=1;
        Q.push_front(S[0]);
        while(k<n)
        {
            if(S[k]<Q.front())
                Q.push_back(S[k]);
            else
                Q.push_front(S[k]);
            k++;
        }
        while(!Q.empty())
        {
            ch=Q.front();
            out<<ch;
            Q.pop_front();
        }
        out<<endl;
        j++;
    }
    return 0;
}

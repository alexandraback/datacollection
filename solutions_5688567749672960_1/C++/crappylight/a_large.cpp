#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fin("a2.in");
ofstream fout("a_reference.txt");
long long pow10[16];
ll flip(ll x) {
    if (x<10) return x;
    ll j=0;
    while (pow10[j]<x) j++;
    return (flip(x/10)+(x%10)*pow10[j-1]);
    };
int solve(ll x) {
    if (x<10) return x;
    int j=0;
    while (pow10[j]<=x) j++;
    int di=j;
    if (pow10[j-1]==x) return (1+solve(x-1));
    cout << x << " " << di << endl;
    if (di%2==0) {
        ll t=(x-1)%pow10[di/2]+1;
        if (x-t==pow10[j-1]) return (t+1+solve(x-t-1));
        else return (t+solve(flip(x-t+1)));
    }
    else{
        ll t=(x-1)%pow10[(di+1)/2]+1;
        if (x-t==pow10[j-1]) return (t+1+solve(x-t-1));
        else return (t+solve(flip(x-t+1)));
    }
}
int main() {
    pow10[0]=1;
    for (int i=1;i<16;i++) pow10[i]=pow10[i-1]*10;
    int t;
    fin >> t;
    for (int i=0;i<t;i++)
        {
            ll s;
            fin >> s;
            fout << "Case #" << i+1 << ": " << solve(s) << endl;
        }
    fin.close();
    fout.close();
};

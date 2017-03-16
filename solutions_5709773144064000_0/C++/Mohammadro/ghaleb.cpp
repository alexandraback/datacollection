#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
double c,f,x;
int t;
int main(){
    ifstream cin("1.in");
    ofstream cout("1.out");
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>c>>f>>x;
        double ans=x/2;
        double speed=2;
        double now=0;
        while(true){
            double add=c/speed;
            double cur=add;
            speed+=f;
            cur+=now;
            now=cur;
            add=x/speed;
            cur+=add;
            if(cur<ans)ans=cur;
            else break;
        }
        cout<<"Case #"<<l<<": ";
        cout<<setprecision(7)<<fixed<<ans<<endl;
    }
}

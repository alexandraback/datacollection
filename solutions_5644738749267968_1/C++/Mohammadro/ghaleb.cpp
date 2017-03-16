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
double a[1000+10],b[1000+10];
int n,t;
bool mark[1000+10];
int main(){
    ifstream cin("1.in");
    ofstream cout("1.out");
    cin>>t;
    for(int l=1;l<=t;l++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(mark,0,sizeof(mark));
        cin>>n;
        int st=1,en=n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        cout<<"Case #"<<l<<": ";
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int point=0;
        for(int i=1;i<=n;i++){
            if(a[i]>b[st]){
                point++;
                st++;
            }
            else en--;
        }
        cout<<point<<" ";
        point=0;
        for(int i=1;i<=n;i++){
            bool check=0;
            for(int j=1;j<=n;j++){
                if(b[j]>a[i] && !mark[j]){
                    mark[j]=true;
                    check=true;
                    break;
                }
            }
            if(!check){
                point++;
                for(int j=1;j<=n;j++){
                    if(!mark[j]){
                        mark[j]=true;
                        break;
                    }
                }
            }
        }
        cout<<point<<endl;
    }
}

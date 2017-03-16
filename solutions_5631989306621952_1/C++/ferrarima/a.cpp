// template.cpp : Defines the entry point for the console application.
//
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>
#include <tuple>
#include <ctime>
#include <cassert>
using namespace std;


//type shortcuts
typedef long long ll;
typedef vector<ll> VI;
typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;


//constants
const DOUBLE EPS=1e-9;
const DOUBLE PI = atan(1) * 4;
const ll M = 1000000007;


int main()
{
    int TN;cin>>TN;
    for (int TI=1;TI<=TN;TI++){
        string s;cin>>s;
        int n=s.size();
        int head=0;
        int tail=-1;
        vector<pair<int,char>> tmp;
        map<int, char> p2c;
        for (int i=0;i<n;++i){
            int pos=head;
            bool front=false;
            while (pos<=tail){
                if (s[i]>p2c[pos]){
                    front=true;
                    break;
                }
                if (s[i]<p2c[pos]){
                    front=false;
                    break;
                }
                pos++;
            }
            pos = (front)?(--head):(++tail);
            tmp.emplace_back(pos, s[i]);
            p2c[pos]=s[i];
        }
        sort(tmp.begin(),tmp.end());
        cout<<"Case #"<<TI<<": ";
        for (auto pr:tmp){
            cout<<pr.second;
        }
        cout<<endl;
        
    }
    return 0;
}

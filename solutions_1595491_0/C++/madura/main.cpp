#define PROBLEM "B"
//#define PROBLEM_ID "small-attempt0"
#define PROBLEM_ID "small-attempt2"
#include<iostream>
#include<map>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<sstream>
#include<list>
#include<set>
#include<algorithm>
#include<sstream>

using namespace std;

typedef stringstream ss;
typedef unsigned char uchar;

int main()
{

    freopen(PROBLEM"-"PROBLEM_ID".in","r",stdin);
    freopen(PROBLEM"-"PROBLEM_ID".out","w",stdout);

    int cases=0,c=0;
    //char line[1000];
    cin>>cases;
    //cin.ignore(10,'\n');
    //cin.getline(line,1000);
   
    while (c++<cases){
        int n,s,p;
        cin>>n>>s>>p;
        int count=0;
        while (n-->0) {
            int t;
            cin>>t;
            int rem=t%3;
            int b=t/3;
            int best=b;
            //cout<<base<<endl;
            
            if (rem==0) {
                if (b>0 && best+1==p && s>0) {
                    best++;
                    s--;
                }
            } else if (rem==1) {
                best++;
            } else {
                if (best+1==p) {
                    best++;
                } else if (best+2==p && s>0) {
                    best+=2;
                    s--;
                }
            }
            
            if (best>=p){
                count++;
            }
            
        }
        cout<<"Case #"<<c<<": ";
        cout<<count;
        cout<<endl;
    }
    return 0;
}
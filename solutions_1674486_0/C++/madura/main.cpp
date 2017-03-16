#define PROBLEM "A"
//#define PROBLEM_ID "large-0"
#define PROBLEM_ID "small-attempt0"
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

void paths(int mat[1001][1001], int counters[1001], int start, int n){
    counters[start]++;
    int found=0;
    for (int i=1;i<=n;i++){
        if (mat[start][i]==1) {
            found=1;
            paths(mat, counters, i, n) ;
        }
    }
    if (found==0) {
        return;
    }

}
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
        int n;
        cin>>n;
        int i=1;
        vector< vector<int> > a;
        int mat[1001][1001]={0};
        while (i<=n){
            int from;
            cin>>from;
            int j=0;
            while (j<from) {
                int g;
                cin>>g;
                mat[i][g]=1;
                j++;
            }
            i++;
        }
        int yes=0;
        for (int i=1;i<=n;i++) {
            int counters[1001]={};
            paths(mat, counters, i, n);
            for (int j=1;j<=n;j++) {
                if (counters[j]>1){
                    yes=1;
                }
            }
        }
        cout<<"Case #"<<c<<": ";
        if (yes==1) {
            cout<<"Yes";
        } else {
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}
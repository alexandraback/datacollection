#include <iostream> 
#include <map> 
#include <vector> 
#include <string> 
#include <set> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <queue> 
#include <list> 
#include <limits> 
#include <stack> 
#include <sstream> 
#include <fstream> 
#include <ctime> 
#include <cstdlib> 
#include <complex> 
#include <cctype> 
#include <iomanip> 
#include <functional> 
#include <cstring> 
using namespace std; 
 
typedef long long int64 ; 
typedef unsigned long long uint64 ; 
 
#define two(X) (1<<(X))  
#define twoL(X) (((int64)(1))<<(X)) 
#define PB push_back 
#define SZ(X) ((int)(X.size())) 
#define LEN(X) ((int)(X.length()))

int sign [][4]={
    1,1,1,1,
    1,-1,1,-1, 
    1,-1,-1,1,
    1,1,-1,-1
};
int tran[][4]={
    0,1,2,3,
    1,0,3,2,
    2,3,0,1,
    3,2,1,0
}; 

inline int char2int(char c){ 
    return c-'i'+1;
}
int main (){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout); 
    int T; 
    cin >> T; 
    
    for(int Cas = 1 ; Cas <= T ; ++Cas){
        int64 X,L; 
        cin >> L >> X; 
        string s;
        cin >> s; 
        int left = -1;
        pair<int, int> leftcur = make_pair(1,0); 
        int64 leftpos = -1; 
        for(int i = 0 ; i < min(X,4LL); ++i){ 
            for(int j = 0 ; j < s.length(); ++j){ 
                leftcur.first = leftcur.first*sign[leftcur.second][char2int(s[j])];
                leftcur.second = tran[leftcur.second][char2int(s[j])];
                if(leftcur.first==1&&leftcur.second==1){
                    leftpos = i*s.length()+j+1;
                    break;
                }
            }
            if(leftpos!=-1) break;
        }
        int rsign[4][4], rtran[4][4];
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                rsign[i][j]=sign[j][i],rtran[i][j]=tran[j][i]; 
        pair<int,int> rightcur = make_pair(1,0);
        int64 rightpos =-1;
        for(int i=0; i < min(X,4LL); ++i){
            for(int j=s.length()-1; j>=0; --j){ 
                rightcur.first = rightcur.first*rsign[rightcur.second][char2int(s[j])];
                rightcur.second = rtran[rightcur.second][char2int(s[j])];
                if(rightcur.first==1&&rightcur.second==3){
                    rightpos = i*s.length()+s.length()-j;
                    break;
                }
            }
            if(rightpos!=-1) break;
        }
        pair<int,int> cur = make_pair(1,0); 

        for(int i=0; i < s.length(); ++i){
              cur.first = cur.first*sign[cur.second][char2int(s[i])];
              cur.second = tran[cur.second][char2int(s[i])];
        }
                
        bool can = false; 
        int res = (X%4==0)?4:X%4; 
        pair<int,int> tmp=cur;
        for(int i = 0 ; i < res-1; ++i){
            cur.first = cur.first*tmp.first*sign[cur.second][tmp.second];
            cur.second = tran[cur.second][tmp.second]; 
        }
        if(cur.first==-1&&cur.second==0)
            can = true;
        bool ans = true;
        if( !can || leftpos==-1 || rightpos==-1 ||leftpos+rightpos > X*L)
            ans = false; 
        cout <<"Case #"<<Cas<<": "<<(ans?"YES":"NO")<<endl; 
    }
    return 0;
}





        

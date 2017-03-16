#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>


using namespace std;

int spad[3][5]={0};
int cts[5];

int bfpad[5][5];
int cntpad[5][5];
int dppad[5][5];

int countAdj(int i,int j,int r,int c){
    int cnt = 0;
    for(int k=-1;k<=1;k++)
        for(int m=-1;m<=1;m++)
            if(abs(k) +abs(m) !=0){
                if(i+k>0 && i+k<r && j+m>0 && j+m<c){
                    if(bfpad[i+k][j+m] == 1){
                        cnt++;
                    }
                }
            }
    return cnt;
}
int  dfs(int i,int j,int r,int c){
    dppad[i][j] = 1;
    if(cntpad[i][j] !=0) return 0;
    for(int k=-1;k<=1;k++)
    for(int m=-1;m<=1;m++)
        if(abs(k) +abs(m) !=0){
            if(i+k>0 && i+k<r && j+m>0 && j+m<c){
                if(bfpad[i+k][j+m] == 0){
                    dfs(i+j,j+m,r,c);
                }
            }
        }
    
    return 0;
    
}

bool chkpad(int r, int c,int m){
    for(int i=0;i<r;i++) for (int j=0;j<c;j++) cntpad[i][j] = countAdj(i,j,r,c);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) dppad[i][j] = 0;
    int frow,fcol;
    bool found;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        if(bfpad[i][j]==0 && countAdj(i,j,r,c) ==0){
            if(found) break;
            found  = true;
            frow = i;
            fcol = j;
        }
    }
    if(!found) return false;
    dfs(frow,fcol,r,c);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        if(dppad[i][j] +bfpad[i][j] !=1) return false;
    }
    
    return true;
}
bool bf(int r,int c, int m, int i,int j){
    if(i==r){
        if(m==0)
            return chkpad(r,c,m);
        else return false;
    }
    if(m<0) return false;
    int nexti, nextj;
    if(j<c-1){
        nexti=i;nextj = j+1;
    }
    else {
        nexti = i+1;
        nextj = 0;
    }
    bfpad[i][j] = 0;
    bool b1 = bf(r,c,m-1,nexti,nextj);
    bfpad[i][j] = 1;
    bool b2 = bf(r,c,m,nexti,nextj);
    
    return b1||b2;
}


vector <string> buildsol(int R, int C, int topRowLength,int bottomRowLength, int height, int F){
    vector <string > ret;
    string s;
    for(int i=0;i<C;i++) s+='*';
    for(int i=0;i<R;i++) ret.push_back(s);
    int cnt =0 ;
    for(int i=0;i<height;i++) for(int j=0;j<bottomRowLength;j++) {
        if(i<2 || j<2) {
            ret[i][j] = '.';
            cnt++;
        }
    }
    for(int i=0;i<height;i++) for(int j=0;j<bottomRowLength;j++) {
        if(cnt<F && ret[i][j]=='*') {
            ret[i][j] = '.';
            cnt++;
        }
    }
    ret[0][0] = 'c';
    return ret;
    
}
vector<string> trp(vector <string> inp){
    vector <string> vs;
    string s;
    for(int i=0;i<inp.size();i++) s+='a';
    for(int j=0;j<inp[0].size();j++) vs.push_back(s);
    for(int i=0;i<inp.size();i++) for (int j=0;j<inp[0].size();j++) vs[j][i] = inp[i][j];
    return vs;
}

int main(){
    int T,R,C,M;
    cin >> T;
    for(int t=0;t<T;t++){
        
        bool rot = false;
        bool found = false;
        cin >> R >> C >> M;
        int F = R*C-M;
        //cout << "F = " << F << endl;
        if(C<R) rot = true;
        vector< string > sol;
        if(C<R) swap(C,R); //rows are always longer than columns;
        if(F==1){
            found = true;
            string s;
            for(int i=0;i<C;i++) s=s+"*";
            for(int i=0;i<R;i++) sol.push_back(s);
            sol[0][0] ='c';
        }
        else if(R==1){
            
            found = true;
            string s="c";
            for(int i=0;i<F-1;i++){
                s = s + ".";
                    
            }
            for(int i=F;i<C;i++) s= s+"*";
            sol.push_back(s);
            
           
        }
        else if (F==2){
            found  = false;
        }
        else if(R==2){
            
            if(F%2==0){
                found  = true;
                string s;
                for(int i=0;i<F/2;i++){
                    s = s + ".";
                    
                }
                for(int i=F/2;i<C;i++) s= s+"*";
                sol.push_back(s);
                sol.push_back(s);
                sol[0][0] = 'c';
                
            }
        }
        else{
            for(int bottomRowLength =2; bottomRowLength<=C;bottomRowLength++){
                for(int topRowLength = 2;topRowLength<=bottomRowLength;topRowLength++){
                    for(int height = 2; height <=R;height++){
                        int mx = bottomRowLength * height;
                        int mn = height * 2 + bottomRowLength*2-4;
                        if(F<=mx && F>=mn){
                            found = true;
                            sol = buildsol(R,C,topRowLength, bottomRowLength,height,F);
                            if(found) break;
                        }
                        if(found) break;
                    }
                    if(found) break;
                }
                if(found) break;
            }
            
        }
        if(C<=5){
        //bool bxx = bf(R,C,M,0,0);
        //if(bxx != found) cout << "AARGH " << R << " " << C << " " << " " << M << endl;
        }
        if(!found){
            cout << "Case #" << t+1 <<":\n" << "Impossible" << endl;
        }
        else{
            cout << "Case #" << t+1 <<":\n";
            if(rot) sol = trp(sol);
            for(int i=0;i<sol.size();i++) cout << sol[i] << endl;
            
            
        }
    }
    return 0;
    
}
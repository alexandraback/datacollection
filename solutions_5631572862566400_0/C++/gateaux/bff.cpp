
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

#define forn(i,n) for(int i=1;i<=n;i++)
using namespace std;

typedef vector<int> vi;

ifstream fin ("C-small-attempt0.in");
ofstream fout ("output.out");

int m=0;
int N;

void dfs(vi fr,vector<bool> visit,int current,int prec,int start,int length,vector<bool> happy){
    if(fr[current]==prec)happy[current]=true;
    if(visit[current]){
                       if(current==start)m=(m>length)?m:length;
                      }
    else{
        visit[current] = true;
        if(happy[current]){
            for(int i=1;i<=N;i++){
                dfs(fr,visit,i,current,start,length+1,happy);

                                }
                          }
        else{
            if(fr[fr[current]]==current)happy[fr[current]]=true;
            dfs(fr,visit,fr[current],current,start,length+1,happy);
        }
        }
}
int main(){
int T;
fin >> T;
forn(i,T){
    m=0;
    fin >> N;
   vi fr(N+1);
    forn(j,N){
        int x;
        fin >> x;
        fr[j]=x;
    }
    forn(j,N){
        vector<bool> visit(N+1,false);
        vector<bool> happy(N+1,false);
       dfs(fr,visit,j,j,j,0,happy);
    }
    fout << "Case #" << i << ": " <<m << endl;
    cout << "Finish test case " << i << endl;
}
return 0;
}

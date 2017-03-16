#include<iostream>
#include<vector>
using namespace std;
int field[100][100];
int result[100][100];
int t=1;
void d() {
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin>>field[i][j];
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) result[i][j]=100;
    for(int i=0;i<N;i++) {
        int mx=-1;
        for(int j=0;j<M;j++) if(field[i][j]>mx) mx=field[i][j];
        for(int j=0;j<M;j++) if(result[i][j]>mx) result[i][j]=mx;
    }
    for(int i=0;i<M;i++) {
        int mx=-1;
        for(int j=0;j<N;j++) if(field[j][i]>mx) mx=field[j][i];
        for(int j=0;j<N;j++) if(result[j][i]>mx) result[j][i]=mx;
    }
    bool aa=true;
    
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(result[i][j]!=field[i][j]) aa=false;
    cout<<"Case #"<<t<<": "<<(aa ? "YES" : "NO")<<endl;
    
}


int main() {
    int T;
    cin>>T;
for(t=1;t<=T;t++) d();
}

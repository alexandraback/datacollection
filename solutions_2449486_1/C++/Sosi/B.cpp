#include <iostream>
using namespace std;

int A[105][105];
int N,M;
bool judge()
{
    for(int i=0;i<N; i++)
    {
        for(int j=0; j<M;j++)
        {
            int P = 0; int Q = 0;
            for(int X = 0; X< N; X++){
                if(X != i && A[X][j] > A[i][j]) P++;
            }
            for(int Y=0; Y<M; Y++){
                if(Y != j && A[i][Y] > A[i][j]) Q++;
            }
            if(P>=1 && Q>=1) return false;
        }
    }
    return true;
}
int main()
{
    int T; cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>N>>M;
        for(int i=0; i<N; i++) for(int j=0; j<M;j++) cin>>A[i][j];
        if(judge()) cout<<"Case #"<<t<<": YES"<<endl;
        else cout<<"Case #"<<t<<": NO"<<endl;
    }

}

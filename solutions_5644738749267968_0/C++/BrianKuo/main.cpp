#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("D-small-attempt2.in");
    ofstream fout("D-small-attempt2.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        int N,ans1=0,ans2=0;
        fin>>N;
        double A[N],B[N];
        for(int i=0;i<N;i++){
            fin>>A[i];
        }
        for(int i=0;i<N;i++){
            fin>>B[i];
        }
        sort(A,A+N);
        sort(B,B+N);
        /*for(int i=0;i<N;i++){
            fout<<A[i]<<' ';
        }
        fout<<endl;
        for(int i=0;i<N;i++){
            fout<<B[i]<<' ';
        }
        fout<<endl;*/
        for(int i=0;i<N;i++){
            if(A[i]<B[ans1])
                continue;
            else
                ans1++;
        }
        for(int i=0;ans2+i<N;i++){
            while(A[i]>=B[ans2+i]){
                ans2++;
                if(ans2+i>=N)break;
            }
        }
        char ansstr[500];
        sprintf(ansstr,"Case #%d: %d %d",t,ans1,ans2);
        fout<<ansstr<<endl;
    }
    return 0;
}

/*
PROG: B
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define SUBMIT
#define _DSP(X)
#   define DV(Var) #Var<<"="<<Var<<' '
#ifdef SUBMIT
    ofstream fout ("B.out");ifstream fin ("B.in");
#   define cin fin
#   define cout fout
#endif

const int MAXN=100+5;
int score[MAXN];

int main()
{
    int T;
    cin>>T;cin.ignore();
    for(int t=1;t<=T;++t)
    {int i;
        int n,s,p;
        cin>>n>>s>>p;
        int lim1=(p>0?3*p-2:0),lim2=(p>1?3*p-4:1);
        for(i=0;i<n;++i)
            cin>>score[i];

        std::sort(score,score+n,std::greater<int>());
        _DSP(for(i=0;i<n;++i)cerr<<score[i]<<' ';cerr<<endl;)

        int cnt=0;
        for(i=0;i<n;++i)
        {
            if(score[i]>=lim1)++cnt;
            else if((s>0)&&(score[i]>=lim2))--s,++cnt;
            else break;
        }

        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }

    return 0;
}

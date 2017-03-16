#include <iostream>

using namespace std;

int score(int pts,int p)//0-pro dancer, 1-almost,-1-noob
{
    pts-=p;
    if(pts<0)
        return -1;
    pts/=2;
    if(pts==p-2)
        return 1;
    if(pts>p-2)
        return 0;
    if(pts<p-2)
        return -1;
}

int main()
{
    int T;
    cin>>T;
    int N,S,p;
    for(int i=0;i<T;i++)
    {
        int total=0;
        cin>>N>>S>>p;
        for(int j=0;j<N;j++)
        {
            int t;
            cin>>t;
            int s=score(t,p);
            if(s!=-1)
            {
                if(s==0)
                    total++;
                else
                    if(S>0)
                    {
                        S--;
                        total++;
                    }
            }
        }
        cout<<"Case #"<<i+1<<": "<<total<<endl;
    }
    return 0;
}

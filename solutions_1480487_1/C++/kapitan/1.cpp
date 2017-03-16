#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long T,N,s,X=0,n,x;
    vector<int> S;
    vector<bool>ok;
    cin >> T;
    for(int t =0;t<T;t++)
    {
        X=0;
        S.clear();
        ok.clear();
        cout << "Case #"<<t+1<<":";
        cin >> N;
        for(int i =0;i<N;i++)
        {
            cin >> s;
            S.push_back(s);
            X+=s;
            ok.push_back(false);
        }
        n=N;
        x=X;
        bool sprawdzaj=true;
        while(sprawdzaj)
        {
            sprawdzaj=false;
            for(int i =0;i<N;i++)
            {
                if(ok[i]==false&&double(2*x)/double(n)<S[i])
                {
                    x-=S[i];
                    n--;
                    ok[i]=true;
                    sprawdzaj=true;
                }
            }
        }


        for(int i =0;i<N;i++)
        {
            double w=100.*(((double)(X+x)/(double)(n)-S[i])/double(X));
            if(w<0)w=0;
            printf(" %.7f",w);
        }
        cout << endl;

    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
int main()
{
    cin>>t;
    for(int ij=1;ij<=t;ij++)
    {
        cin>>n;
        int poc1=0,poc2=0;
        map<string,int> M1,M2;
        vector<pair<int,int> > X(n);
        for(int i=0;i<n;i++)
        {
            string s,str;cin>>s>>str;
            if(M1.find(s)==M1.end()){M1[s]=poc1;poc1++;}
            if(M2.find(str)==M2.end()){M2[str]=poc2;poc2++;}
            X[i]={M1[s],M2[str]};
        }
        int odpoved;
        for(int i=0;i<=n;i++)
        {
            vector<bool> W(n,false);
            for(int j=n-1;j>=n-i;j--)W[j]=true;
            bool ok=true;
            do
            {
                //for(int j=0;j<W.size();j++)cout <<" "<<W[j];cout <<endl;
                ok=true;
                vector<bool> viem(poc1,false),vviem(poc2,false);
                for(int j=0;j<X.size();j++)
                {
                    if(W[j])viem[X[j].first]=vviem[X[j].second]=true;
                }
                for(int j=0;j<viem.size();j++)if(!viem[j]){ok=false;break;}
                for(int j=0;j<vviem.size();j++)if(!vviem[j]){ok=false;break;}
                if(ok){odpoved=n-i;break;}
            }while(next_permutation(W.begin(),W.end()));
            if(ok)break;
        }
        cout <<"Case #"<<ij<<": "<<odpoved<<endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int,int> PII;

int n;
vector<int> bf;


int max_circle(int i){
    vector<int> was(n,0);  
    int c=1;

    for(int x=bf[i]; !was[x]; x=bf[x]){
        ++c;
        if(bf[x]==i){ return c; }
        was[x]=true;
    }

    return 0;
}


int main(){
    int T;
    cin>>T;

    for(int tc=1; tc<=T; ++tc){ 
        cin>>n;
    
        bf.resize(n);
        for(int i=0;i<n;++i){ cin>>bf[i]; --bf[i]; }

        int mx=0;

        //big circle
        for(int i=0;i<n;++i){
            mx=max(mx, max_circle(i) );
            //cout<<"max circle of "<<i<<" is "<<max_circle(i);
        }

        //sucession of 2-circles and 1 inserts...
        vector<int> isswh(n);
        vector<int> isfree(n,1);
        int s=0;

        for(int i=0;i<n;++i)
            if(bf[bf[i]]==i){ isswh[i]=1; ++s; }
            else{ isswh[i]=0; }

        //calculate chain depths:
        vector<PII> chaindepths(n,PII(0,0)); 


        for(int i=0;i<n;++i){
            if(!isswh[i]){
                int prevj=i,cnt=1;
                vector<int> was(n,0);
                for(int j=bf[i]; j!=i && !was[j] && !isswh[j]; j=bf[j]){
                    prevj=j; ++cnt;
                    was[j]=true;
                }
                chaindepths[prevj]=PII(max(cnt-1,chaindepths[prevj].first),prevj);
            }
        }

        sort(chaindepths.begin(),chaindepths.end());
        for(int i=n-1; i>=0; --i){
            int x=chaindepths[i].second;
            if(!isswh[x]&&isswh[bf[x]]&&isfree[bf[x]]){ 
                isfree[bf[x]]=false;
                s+=chaindepths[i].first+1;
            }
        }

        mx=max(mx,s);

        cout<<"Case #"<<tc<<": "<<mx<<'\n';

    }
}

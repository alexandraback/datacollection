#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}e;
map<pair<int,int>,int> mab,mbc,mca;
vector<node> v,res;
int main()
{
    int a,b,c,k,i,j,l,n,t,r,bt;
    cin>>t;

    for(r = 1; r <= t; r++){
        v.clear();
        mab.clear();
        mbc.clear();
        mca.clear();
        res.clear();
        cin>>a>>b>>c>>k;
        for(i = 1; i <= a; i++){
            for(j = 1; j <= b; j++){
                for(l =1;l<=c;l++){
                    e.a= i;e.b=j;e.c=l;
                    if(mab[make_pair(i,j)] < k && mbc[make_pair(j,l)] < k && mca[make_pair(l,i)] < k){
                            v.push_back(e);
                            mab[make_pair(i,j)]++;
                            mbc[make_pair(j,l)]++;
                            mca[make_pair(l,i)]++;
                    }

                }
            }
        }
        printf("Case #%d: %d\n", r, v.size());
        for(i = 0; i < v.size(); i++){
            printf("%d %d %d\n", v[i].a, v[i].b,v[i].c);
        }
    }
    return 0;
}

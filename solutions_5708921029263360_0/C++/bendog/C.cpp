#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("Cout.txt","w",stdout);
    int cas,j,p,s,k;
    cin>>cas;
for(int q=1;q<=cas;q++){

    cin>>j>>p>>s>>k;
    map<int,int> ms[3];
    vector< pair<int, pair<int,int> > > vec;
    for(int a=1;a<=j;a++)
    for(int b=1;b<=p;b++)
    for(int c=1;c<=s;c++){
        if(ms[0][a<<4 | b] <k &&
           ms[1][a<<4 | c]<k &&
           ms[2][b<<4 | c] < k
           ){
            ms[0][a<<4 |b]++;
            ms[1][a<<4 |c]++;
            ms[2][b<<4 |c]++;
            vec.push_back(make_pair(a,make_pair(b,c)));
           }
    }
    cout<<"Case #"<<q<<": "<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].first<<' '<<vec[i].second.first<<' '<<vec[i].second.second<<endl;
    }
}
    return 0;
}

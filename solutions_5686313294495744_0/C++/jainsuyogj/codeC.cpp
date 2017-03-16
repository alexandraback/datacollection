#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define mat 1000006
set<string> st,st1;
int sz,sz1;
vector<pair<string,string> > vc,vc1;
int arr[20];
int n,mcnt;
void rec(int ind)
{
    if(ind==n)
    {
        st.clear(),st1.clear();
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                string a,b;
                a=vc[i].first;b=vc[i].second;
                st.insert(a);st1.insert(b);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                string a,b;
                a=vc[i].first;b=vc[i].second;
                if(st.find(a)==st.end()){
                    st.insert(a),st1.insert(b);
                }
                else if(st1.find(b)==st1.end()){
                    st1.insert(b);
                }
                else{
                    cnt++;
                }
            }

        }
        if(cnt>mcnt){
            mcnt=cnt;
        }
        return;
    }
    arr[ind]=0;
    rec(ind+1);
    arr[ind]=1;
    rec(ind+1);
}
void recc(int ind)
{
    if(ind==n)
    {
        st.clear(),st1.clear();
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                string a,b;
                a=vc1[i].first;b=vc1[i].second;
                st.insert(a);st1.insert(b);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                string a,b;
                a=vc1[i].first;b=vc1[i].second;
                if(st.find(a)==st.end()){
                    st.insert(a),st1.insert(b);
                }
                else if(st1.find(b)==st1.end()){
                    st1.insert(b);
                }
                else{
                    cnt++;
                }
            }

        }
        if(cnt>mcnt){
            mcnt=cnt;
        }
        return;
    }
    arr[ind]=0;
    rec(ind+1);
    arr[ind]=1;
    rec(ind+1);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {

        cin>>n;
        string a,b;
        vc.clear(),vc1.clear();
        for(int i=0;i<n;i++){
            cin>>a>>b;
            vc.push_back(make_pair(a,b)),vc1.push_back(make_pair(b,a));
        }
        sort(vc.begin(),vc.end());
        sort(vc1.begin(),vc1.end());
        for(int i=0;i<20;i++)
            arr[i]=0;
        mcnt=0;
        rec(0);
        recc(0);
        cerr<<ii<<endl;
        cout<<"Case #"<<ii<<": "<<mcnt<<endl;
    }
}

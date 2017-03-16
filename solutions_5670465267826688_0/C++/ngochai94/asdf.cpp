#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 0.0000001
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define maxn 32000

long long t,l,x,lis[10004],base,ansr,ansc,col[4],ansrr,anscc;
string s;
long long mat[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2},{2,7,4,1,6,3,0,5},{3,2,5,4,7,6,1,0},{4,5,6,7,0,1,2,3},{5,0,7,2,1,4,3,6},{6,3,0,5,2,7,4,1},{7,6,1,0,3,2,5,4}};
map<char,long long> dic;
bool flag;

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>t;
    dic['i']=1;dic['j']=2;dic['k']=3;
    For(cas,1,1+t)
    {
        cout<<"Case #"<<cas<<": ";
        cin>>l>>x;
        cin>>s;
        For(i,0,l) lis[i+1]=dic[s[i]];
        lis[0]=0;
        For(i,1,l+1) lis[i]=mat[lis[i-1]][lis[i]];
        base=lis[l];
        flag=false;
        if(base==4&&x&1) flag=true;
        if(base!=0&&base!=4&&x%4==2) flag=true;
        if(!flag)
        {
            cout<<"NO"<<endl;
            continue;
        }
        col[0]=0;
        ansr=ansc=5;
        For(i,1,4) col[i]=mat[col[i-1]][base];
        For(i,1,l+1) For(j,0,4) if(mat[col[j]][lis[i]]==1)
        {
            if(ansr>j)
            {
                ansr=j;
                ansc=i;
            }
        }
        if(ansr+1>x||ansr==5)
        {
            cout<<"NO"<<endl;
            continue;
        }
        ansrr=anscc=10;
        long long tmp;
        For(i,1,l+1) For(j,0,4) if(mat[col[j]][lis[i]]==3)
        {
            if(j<ansr||j==ansr&&i<ansc)
            {
                if(base!=4) tmp=j+4;
                else tmp=j+2;
            }
            else tmp=j;
            if(ansrr>tmp)
            {
                ansrr=tmp;
                anscc=i;
            }
        }
        if(ansrr+1>x||ansrr==10)
        {
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        //For(i,0,4) cout<<col[i]<<endl;
    }
}


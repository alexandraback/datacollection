#include<bits/stdc++.h>

#define xx first
#define yy second
#define LL long long
#define inf 2000000000000000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 1005

using namespace std;
string C,J;
int arc[22],arj[22];
LL dp[19][19][4][11][11];
int len;

LL solve(int indx,int last,int f,int a,int b,LL A,LL B){
    if(indx>len){
        LL d=A-B;
        if(d<0) d=-d;
        //cout<<"base case "<<indx<<" "<<A<<" "<<B<<" "<<d<<endl;
        //cout<<"base casssse "<<indx<<" "<<A<<" "<<B<<" "<<d<<endl;
        return d;
    }
    LL &ret=dp[indx][last][f][a][b];
    if(ret!=-1) return ret;
    ret=inf;
    if(f==0){
        if(C[indx-1]=='?' && J[indx-1]=='?'){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(i==j){
                        ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+i,B*10ll+j));
                    }
                    else if(i<j){
                        ret=min(ret,solve(indx+1,indx,1,i,j,A*10ll+i,B*10ll+j));
                    }
                    else{
                        ret=min(ret,solve(indx+1,indx,2,i,j,A*10ll+i,B*10ll+j));
                    }
                }
            }
        }
        else if(C[indx-1]=='?'){
            for(int i=0;i<10;i++){
                if(i==arj[indx]){
                    ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+i,B*10ll+arj[indx]));
                }
                else if(i<arj[indx]){
                    ret=min(ret,solve(indx+1,indx,1,i,arj[indx],A*10ll+i,B*10ll+arj[indx]));
                }
                else{
                    ret=min(ret,solve(indx+1,indx,2,i,arj[indx],A*10ll+i,B*10ll+arj[indx]));
                }
            }
        }
        else if(J[indx-1]=='?'){
            for(int i=0;i<10;i++){
                if(i==arc[indx]){
                    ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+i));
                }
                else if(i<arc[indx]){
                    ret=min(ret,solve(indx+1,indx,1,arc[indx],i,A*10ll+arc[indx],B*10ll+i));
                }
                else{
                    ret=min(ret,solve(indx+1,indx,2,arc[indx],i,A*10ll+arc[indx],B*10ll+i));
                }
            }
        }
        else{
            if(arc[indx]==arj[indx]){
                ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx]));
            }
            else if(arc[indx]<arj[indx]){
                ret=min(ret,solve(indx+1,indx,1,arc[indx],arj[indx],A*10ll+arc[indx],B*10ll+arj[indx]));
            }
            else{
                ret=min(ret,solve(indx+1,indx,2,arc[indx],arj[indx],A*10ll+arc[indx],B*10ll+arj[indx]));
            }
        }
    }
    else if(f==1){
        if(C[indx-1]=='?' && J[indx-1]=='?'){
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+9,B*10ll+0));
        }
        else if(C[indx-1]=='?'){
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+9,B*10ll+arj[indx]));
        }
        else if(J[indx-1]=='?'){
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+0));
        }
        else{
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx]));
        }
    }
    else{
        if(C[indx-1]=='?' && J[indx-1]=='?'){
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+0,B*10ll+9));
        }
        else if(C[indx-1]=='?'){
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+0,B*10ll+arj[indx]));
        }
        else if(J[indx-1]=='?'){
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+9));
        }
        else{
            ret=min(ret,solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx]));
        }
    }
   // cout<<"Here indx "<<indx<<" "<<ret<<endl;
    return ret;
}

string CC,JJ;

void getAns(int indx,int last,int f,int a,int b,LL A, LL B, LL ans){
    if(indx>len){
        return;
    }
    if(f==0){
        if(C[indx-1]=='?' && J[indx-1]=='?'){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(i==j && solve(indx+1,last,f,a,b,A*10ll+i,B*10ll+j)==ans){
                        CC+=(char)(i+'0');
                        JJ+=(char)(j+'0');
                        getAns(indx+1,last,f,a,b,A*10ll+i,B*10ll+j,ans);
                        return;
                    }
                    else if(i<j && solve(indx+1,indx,1,i,j,A*10ll+i,B*10ll+j)==ans){
                        CC+=(char)(i+'0');
                        JJ+=(char)(j+'0');
                        getAns(indx+1,indx,1,i,j,A*10ll+i,B*10ll+j,ans);
                        return;
                    }
                    else if(i>j && solve(indx+1,indx,2,i,j,A*10ll+i,B*10ll+j)==ans){
                        CC+=(char)(i+'0');
                        JJ+=(char)(j+'0');
                        getAns(indx+1,indx,2,i,j,A*10ll+i,B*10ll+j,ans);
                        return;
                    }
                }
            }
        }
        else if(C[indx-1]=='?'){
            for(int i=0;i<10;i++){
                if(i==arj[indx] && solve(indx+1,last,f,a,b,A*10ll+i,B*10ll+arj[indx])==ans){
                    CC+=(char)(i+'0');
                    JJ+=J[indx-1];
                    getAns(indx+1,last,f,a,b,A*10ll+i,B*10ll+arj[indx],ans);
                    return;
                }
                else if(i<arj[indx] && solve(indx+1,indx,1,i,arj[indx],A*10ll+i,B*10ll+arj[indx])==ans){
                    CC+=(char)(i+'0');
                    JJ+=J[indx-1];
                    getAns(indx+1,indx,1,i,arj[indx],A*10ll+i,B*10ll+arj[indx],ans);
                    return;
                }
                else if(i>arj[indx] && solve(indx+1,indx,2,i,arj[indx],A*10ll+i,B*10ll+arj[indx])==ans){
                    CC+=(char)(i+'0');
                    JJ+=J[indx-1];
                    getAns(indx+1,indx,2,i,arj[indx],A*10ll+i,B*10ll+arj[indx],ans);
                    return;
                }
            }
        }
        else if(J[indx-1]=='?'){
            for(int i=0;i<10;i++){
                if(i==arc[indx] && solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+i)==ans){
                    CC+=C[indx-1];
                    JJ+=(char)(i+'0');
                    getAns(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+i,ans);
                    return;
                }
                else if(i<arc[indx] && solve(indx+1,indx,1,arc[indx],i,A*10ll+arc[indx],B*10ll+i)==ans){
                    CC+=C[indx-1];
                    JJ+=(char)(i+'0');
                    getAns(indx+1,indx,1,arc[indx],i,A*10ll+arc[indx],B*10ll+i,ans);
                    return;
                }
                else if(i>arc[indx] && solve(indx+1,indx,2,arc[indx],i,A*10ll+arc[indx],B*10ll+i)==ans){
                    CC+=C[indx-1];
                    JJ+=(char)(i+'0');
                    getAns(indx+1,indx,2,arc[indx],i,A*10ll+arc[indx],B*10ll+i,ans);
                    return;
                }
            }
        }
        else{
            if(arc[indx]==arj[indx] && solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx])==ans){
                CC+=C[indx-1];
                JJ+=J[indx-1];
                getAns(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx],ans);
                return;
            }
            else if(arc[indx]<arj[indx] && solve(indx+1,indx,1,arc[indx],arj[indx],A*10ll+arc[indx],B*10ll+arj[indx])==ans){
                CC+=C[indx-1];
                JJ+=J[indx-1];
                getAns(indx+1,indx,1,arc[indx],arj[indx],A*10ll+arc[indx],B*10ll+arj[indx],ans);
                return;
            }
            else if(arc[indx]>arj[indx] && solve(indx+1,indx,2,arc[indx],arj[indx],A*10ll+arc[indx],B*10ll+arj[indx])==ans){
                CC+=C[indx-1];
                JJ+=J[indx-1];
                getAns(indx+1,indx,2,arc[indx],arj[indx],A*10ll+arc[indx],B*10ll+arj[indx],ans);
                return;
            }
        }
    }
    else if(f==1){
        if(C[indx-1]=='?' && J[indx-1]=='?' && solve(indx+1,last,f,a,b,A*10ll+9,B*10ll+0)==ans){
            CC+='9';
            JJ+='0';
            getAns(indx+1,last,f,a,b,A*10ll+9,B*10ll+0,ans);
            return;
        }
        else if(C[indx-1]=='?' && solve(indx+1,last,f,a,b,A*10ll+9,B*10ll+arj[indx])==ans){
            CC+='9';
            JJ+=J[indx-1];
            getAns(indx+1,last,f,a,b,A*10ll+9,B*10ll+arj[indx],ans);
            return;
        }
        else if(J[indx-1]=='?' && solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+0)==ans){
            CC+=C[indx-1];
            JJ+='0';
            getAns(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+0,ans);
            return;
        }
        else if(solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx])==ans){
            CC+=C[indx-1];
            JJ+=J[indx-1];
            getAns(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx],ans);
            return;
        }
    }
    else{
        if(C[indx-1]=='?' && J[indx-1]=='?' && solve(indx+1,last,f,a,b,A*10ll+0,B*10ll+9)==ans){
            CC+='0';
            JJ+='9';
            getAns(indx+1,last,f,a,b,A*10ll+0,B*10ll+9,ans);
            return;
        }
        else if(C[indx-1]=='?' && solve(indx+1,last,f,a,b,A*10ll+0,B*10ll+arj[indx])==ans){
            CC+='0';
            JJ+=J[indx-1];
            getAns(indx+1,last,f,a,b,A*10ll+0,B*10ll+arj[indx],ans);
            return;
        }
        else if(J[indx-1]=='?' && solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+9)==ans){
            CC+=C[indx-1];
            JJ+='9';
            getAns(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+9,ans);
            return;
        }
        else if(solve(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx])==ans){
            CC+=C[indx-1];
            JJ+=J[indx-1];
            getAns(indx+1,last,f,a,b,A*10ll+arc[indx],B*10ll+arj[indx],ans);
            return;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test; cin>>test;
    for(int kase=1;kase<=test;kase++){
        cin>>C>>J;
        len=C.length();
        for(int i=0;i<len;i++){
            arc[i+1]=C[i]-'0';
            arj[i+1]=J[i]-'0';
        }
        memset(dp,-1,sizeof dp);
        LL ret=solve(1,0,0,0,0,0,0);
        CC="";
        JJ="";
        getAns(1,0,0,0,0,0,0,ret);
        cout<<"Case #"<<kase<<": "<<CC<<" "<<JJ<<endl;
    }
    return 0;
}


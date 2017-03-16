#include<bits/stdc++.h>
using namespace std;
#define ll long long 
char A[110],B[110];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m;
    int T,Case=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",A,B);
        int len=strlen(A);
        int xx=1;
        for(int i=0;i<len;i++) xx*=10;
        int minn=1000000,mi,mj;
        for(int i=0;i<xx;i++)
        {
            int ff=1,tt=i;
            for(int k=len-1;k>=0;k--)
            {
                if(A[k]!='?'&&tt%10!=(A[k]-'0')) {
                    ff=0; break;
                }  
                tt/=10;
            }
            //if(i==1) cout<<ff<<"knasd,\n";//endl;
            if(ff)
            for(int j=0;j<xx;j++)
            {
                int f2=1,t2=j;
                for(int k=len-1;k>=0;k--)
                {
                    if(B[k]!='?'&&t2%10!=(B[k]-'0')) {
                        f2=0; break;
                    }
                    t2/=10;
                }  
                if(f2)
                {
                    if(abs(i-j)<minn){
                        minn=abs(i-j); mi=i;mj=j;
                    }
                    else if(abs(i-j)==minn)
                    {
                        if(i<mi) {
                            mi=i; mj=j;
                        }
                        else if(i==mi&&j<mj) {
                            mi=i; mj=j;
                        }
                    }
                }
            }
        }
        printf("Case #%d: ",Case++);
        int txa=xx/10,txb=xx/10;
        for(int i=0;i<len;i++)
        {
            if(A[i]=='?') {
                cout<<(mi/txa);
            }
            else printf("%c",A[i]);
            mi%=txa;
            //cout <<" laksjnd  "<<mi<<" kjnas  ";
            txa/=10;
            //cout<<mi<<" "<<txa<<endl;
        }
        cout<<" ";
        for(int i=0;i<len;i++)
        {
            if(B[i]=='?') {
                cout<<(mj/txb);
            }
            else printf("%c",B[i]);
            mj%=txb;
            txb/=10;
        }
        cout<<endl;
    }
    return 0;
}

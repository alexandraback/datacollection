//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL

int main()
{
    //freopen("input3.txt","r",stdin);freopen("output3.txt","w",stdout);
    int tt,test;
    int i,j,c,m,rem,swapped,mine,r,flag,mcp;
    char a[200][200];
    cin>>test;
    for(tt=1;tt<=test;tt++)
    {

        init(a,'.');mine=0;printf("Case #%d:\n",tt);
        cin>>r>>c>>m;
        mcp=m;
        if(r>c){swap(c,r);swapped=1;}else swapped=0;
        if(r==1)
        {
            //if(c-m==2){printf("Impossible\n");continue;}
            for(i=0;i<m;i++)a[0][i]='*';
            a[0][c-1]='c';
        }
        else if(r==2)
        {
            rem=(r*c)-m;
            if((rem>1 && m&1) || rem==2){printf("Impossible\n");continue;}
            for(i=0;i<(m/2);i++)a[0][i]=a[1][i]='*';
            a[0][c-1]='c';
        }
        else
        {
            a[r-1][c-1]='c';
            if(m<=(r-2)*(c-2))
            {
                for(i=0;i<r-2 && m;i++)for(j=0;j<c-2 &&m;j++){a[i][j]='*';m--;}
            }
            else
            {
                rem=(r*c)-m;flag=0;
                if(rem==2 || rem==3 || rem==5 || rem==7){printf("Impossible\n");continue;}
                for(i=0;i<r-2 && m;i++)for(j=0;j<c-2 &&m;j++){a[i][j]='*';m--;}
                if(m&1){m++;a[r-3][c-3]='.';flag=1;}
                for(i=0;i<r-2-flag && m>0;i++){a[i][c-1]=a[i][c-2]='*';m-=2;}
                for(j=0;j<c-2-flag && m>0;j++){a[r-1][j]=a[r-2][j]='*';m-=2;}
            }

        }
        if(r*c-mcp==1){init(a,'*');a[0][0]='c';}
        if(!swapped)for(i=0;i<r;i++,printf("\n"))for(j=0;j<c;j++)printf("%c",a[i][j]);
        else for(j=0;j<c;j++,printf("\n"))for(i=0;i<r;i++)printf("%c",a[i][j]);
        /*for(it=0;it<(r+c-1)&& mine<m;it++)
        {
            r1=(it<c)?0:it-c+1;
            c1=(it<c)?c:c-1;
            d=min(r-r1,c1+1);
            r2=r1+d-1;
            c2=c1-d+1;
            while(1)
            {
                if(r1>r2)break;
                    a[r2][c2]='*';
                    mine++;r2--;c2++;
                if(r1>r2)break;
                    a[r1][c1]='*';
                    mine++;r1++;c1--;
            }
        }*/

    }

return 0;
}

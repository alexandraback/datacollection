#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char dij[200][200];
bool rever[200][200];
int l,x;
string str;

int main(void)
{
    dij['i']['k']='j';
    dij['i']['j']='k';
    dij['j']['k']='i';
    dij['j']['i']='k';
    dij['k']['i']='j';
    dij['k']['j']='i';
    
    dij['i']['i']=1;
    dij['j']['j']=1;
    dij['k']['k']=1;
    
    dij['i'][1]='i';
    dij['j'][1]='j';
    dij['k'][1]='k';
    
    dij[1][1]=1;
    
    for (int i=0;i<200;i++)
        for (int j=0;j<200;j++)
            rever[i][j]=false;
    
    rever['i']['i']=true;
    rever['i']['k']=true;
    rever['j']['i']=true;
    rever['j']['j']=true;
    rever['k']['j']=true;
    rever['k']['k']=true;
    
    
    
    int tcase,tt;
    tt=0;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    cin>>tcase;
    while (tcase--)
    {
        int minus=0;
        tt++;
        scanf("%d%d",&l,&x);
        cin>>str;
        
        int wanted='i';
        int now='i';
        
        for (int i=1;i<=x;i++)
            for (int j=0;j<l;j++)
            {
                //cout<<(i-1)*l+j<<":"<<wanted<<endl;
                if (wanted==str[j])
                {
                    if (now=='k')
                        wanted=1;
                    else
                    {
                        now++;
                        wanted=now;
                    }
                    continue;
                }
                
                wanted=dij[str[j]][wanted];
                
                if (rever[str[j]][wanted])
                    minus=(minus+1)%2;
            }
        
        if (wanted==1 && minus==0)
            printf("Case #%d: YES\n",tt);
        else
            printf("Case #%d: NO\n",tt);
        
//        if (minus==1)
//            cout<<"minus";
    }
    return 0;
}
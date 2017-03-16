#include<stdio.h>
#include<cstring>

char name[1000002];

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    long long int an;
    int cases,ii,cons,near,n,len;
    int i;
    bool yes[333];
    
    for(i=0;i<=256;i++)yes[i]=false;
    for(i='a';i<='z';i++)yes[i]=true;
    yes['a']=yes['e']=yes['i']=yes['o']=yes['u']=false;
    
    
    scanf("%d",&cases);
    for(ii=1;ii<=cases;ii++){
        scanf("%s%d",name,&n);
        len=strlen(name);
        an=0;
        near=-1;
        for(i=0;i<len;i++){
            if(yes[name[i]])cons++;
            else cons=0;
            if(cons>=n)near=i-n+1;
            if(near>=0){
                an+=near+1;
            }
        }
        printf("Case #%d: %I64d\n",ii,an);
    }
    
    return 0;
}

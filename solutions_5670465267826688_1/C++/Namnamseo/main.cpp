#include <cstdio>
int l,x;
char buffer[10010];
int data[10010];
int left[10010];
int right[10010];
int map[5][5]={
    {0,0, 0, 0, 0},
    {0,1, 2, 3, 4},
    {0,2,-1, 4,-3},
    {0,3,-4,-1, 2},
    {0,4, 3,-2,-1}
};

int mul(int a,int b){
    bool sign=false;
    if(a<0) a=-a, sign=!sign;
    if(b<0) b=-b, sign=!sign;
    return sign?-map[a][b]:map[a][b];
}

int main()
{
    freopen("D:\\input","r",stdin);
    FILE *out=fopen("D:\\output","w");
    int t,i;
    scanf("%d",&t);
    for(int _=1;_<=t;++_){
        scanf("%d%d%s",&l,&x,buffer);
        for(i=0;i<l;++i) data[i]=buffer[i]-'g';
        int cur;
        for(cur=1,i=0;i<l;++i) left[i]=cur=mul(cur,data[i]);
        for(cur=1,i=0;i<l;++i) right[l-i-1]=cur=mul(data[l-i-1],cur);
        int all=1, alltemp=right[0];
        for(i=0;i<x;++i) all=mul(all,right[0]);
        if(all==-1){
            int li,ri;
            int lc=0,rc=(x-1);
            while(lc<x){
                for(li=0;li<l;++li) if(left[li]==2) break; else left[li]=mul(alltemp,left[li]);
                if(li!=l) break;
                ++lc;
                if(lc>=5) lc=x;
            }
            if(lc==x) goto dead;
            else li+=lc*l;
            while(rc>=0){
                for(ri=l-1;0<=ri;--ri) if(right[ri]==4) break; else right[ri]=mul(right[ri],alltemp);
                if(ri!=-1) break;
                --rc;
                if(x-1-rc>=5) rc=-1;
            }
            if(rc==-1) goto dead;
            else ri+=rc*l;
            int lv=left[li], rv=right[ri];
            if(li>ri) goto dead;
        } else goto dead;
        printf("Case #%d: YES\n",_);
        fprintf(out,"Case #%d: YES\n",_);
        continue;
    dead:
        printf("Case #%d: NO\n",_);
        fprintf(out,"Case #%d: NO\n",_);
    }
    return 0;
}

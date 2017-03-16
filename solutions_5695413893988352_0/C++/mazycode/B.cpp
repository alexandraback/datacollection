#include<stdio.h>
#include<string.h>
char s[100];
char x[100];
char as[100];
char ax[100];
char bs[100];
char bx[100];

/*void doit()
{
    int n=strlen(s);
    int last =0;
    int jy = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?'&&x[i]=='?')
        {
            jy = 0;
            break;
        }
        if(s[i] == x[i]) continue;

        if(x[i]!='?'&&s[i]!='?')
        {
            if(x[i]>s[i]) {
                    jy = -1;
                    last = i+1;
            }else
            {
                jy = 1;
                last = i+1;
            }
            break;
        }
        else break;
    }
    if(jy == 0)
    for(int i =0 ;i<n;i++)
    {
        if(x[i]=='?'||s[i]=='?'||x[i]==s[i]) continue;
        int f= 0;
        if(x[i] > s[i])
        {
            if(x[i]-s[i]<5)
            {
                jy = -1;
                f = i;
            }else
            {
                jy = -1;
                for(int j = i-1;j>=0;j--)
                if(x[j]!='9'&&s[j]=='?') {f=j;jy = 1;break;}
                for(int j = i-1;j>=0;j--)
                if(s[j]!='0'&&x[j]=='?') {if(f<j)f=j;jy = 1;break;}
                if(jy ==-1) f =i;
            }
        }
        else if(x[i] < s[i])
        {
            if(s[i]-x[i]<=5)
            {
                jy = 1;
                f = i;
            }else
            {
                jy = 1;
                 for(int j = i-1;j>=0;j--)
                if(s[j]!='9'&&x[j]=='?') {f=j;jy = -1;break;}
                for(int j = i-1;j>=0;j--)
                if(x[j]!='0'&&s[j]=='?') {if(f<j)f=j;jy = -1;break;}
                if(jy ==1) f =i;
            }
        }
        if(jy == 1)
        {
            if(s[f]=='?'&&x[f]!='?') s[f]=x[f]+1;
            if(s[f]!='?'&&x[f]=='?') x[f]=s[f]-1;
            if(s[f]=='?'&&x[f]=='?') {x[f] = '0'; s[f]='1';}
            for(int j=0;j<f;j++)
            {
                if(s[j]=='?'&&x[j]!='?') s[j]=x[j];
                if(s[j]!='?'&&x[j]=='?') x[j]=s[j];
                if(s[j]=='?') {x[j]='0';s[j]='0';}
            }
        }else
        {
            if(s[f]=='?'&&x[f]!='?') s[f]=x[f]-1;
            if(s[f]!='?'&&x[f]=='?') x[f]=s[f]+1;
            if(s[f]=='?'&&x[f]=='?') {x[f] = '1'; s[f]='0';}
            for(int j=0;j<f;j++)
            {
                if(s[j]=='?'&&x[j]!='?') s[j]=x[j];
                if(s[j]!='?'&&x[j]=='?') x[j]=s[j];
                if(s[j]=='?') {x[j]='0';s[j]='0';}
            }
        }
        last = f+1;
        break;
    }
    if(jy == 0)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?'&&x[i]!='?') s[i]=x[i];
            if(s[i]!='?'&&x[i]=='?') x[i]=s[i];
            if(s[i]=='?') {x[i]='0';s[i]='0';}
        }
    }
    else if(jy == 1)
    {
        for(int i=last;i<n;i++){if(x[i]=='?')x[i] ='9';if(s[i]=='?')s[i]='0';}
    }else
    {
        for(int i=last;i<n;i++){if(x[i]=='?')x[i] ='0';if(s[i]=='?')s[i]='9';}
    }
    printf("%s %s",s,x);
}*/
int ans= 0;
int stoi(char*x)
{
    int n =strlen(x);
    int re=0;
    for(int i=0;i<n;i++)
    re=re*10+x[i]-48;
    return re;
}
int abs(int x)
{
    if(x <0) return -x;return x;
}
void doit()
{
    int i[6];
    int n=strlen(s);
    ax[0]='0';ax[1]='0';ax[2]='0';
    as[0]='9';as[1]='9';as[2]='9';
    ax[n]=as[n]=0;
    for( i[0] = 0;i[0]<=9;i[0]++)
        for( i[1] = 0;i[1]<=9;i[1]++)
            for( i[2] = 0;i[2]<=9;i[2]++)
                for( i[3] = 0;i[3]<=9;i[3]++)
                    for( i[4] = 0;i[4]<=9;i[4]++)
                        for( i[5] = 0;i[5]<=9;i[5]++)
    {
        for(int j=0;j<n;j++)
         if(x[j]=='?')bx[j] = i[j]+48;else bx[j] = x[j];
         bx[n]=0;bs[n]=0;
        for(int j=0;j<n;j++)
         if(s[j]=='?')bs[j] = i[3+j]+48;else bs[j] = s[j];
         int bbx = stoi(bx);
         int bbs = stoi(bs);
         int bax = stoi(ax);
         int bas = stoi(as);
         if(abs(bbx-bbs)<abs(bax-bas)||(abs(bbx-bbs)==abs(bax-bas)&&bbx+bbs<bax+bas)||(abs(bbx-bbs)==abs(bax-bas)&&bbx+bbs==bax+bas&&bbx<bax))
         {
             strcpy(ax,bx);
             strcpy(as,bs);
         }
    }
    printf("%s %s",as,ax);
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%s%s",s,x);
        printf("Case #%d: ",i+1);
        doit();
        printf("\n");
    }
}

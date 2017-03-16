#include<stdio.h>
#include<string.h>
#define MOD 1000000007
#define ll long long
ll fact[1005]={0};
char a[102][102],b[102][102];
ll myMod(ll x)
{
    return x-MOD*(x/MOD);
}
ll build()
{
    ll i=1;
    fact[0]=1;
    for(i=1;i<=100;i++)
    fact[i]=myMod(fact[i-1]*i);
}
void merge(int first,int mid,int last)
{
     int x,i=first,j=mid+1,l=first;
     while(i<=mid && j<=last)
     {
         x=strcmp(a[i],a[j]);
        if(x<0)
        strcpy(b[l++],a[i++]);
        else strcpy(b[l++],a[j++]);
     }
     while(i<=mid)
     strcpy(b[l++],a[i++]);
     while(j<=last)
     strcpy(b[l++],a[j++]);
     for(i=first;i<=last;i++)
     strcpy(a[i],b[i]);
}
void mergesort(int first,int last)
{
     int mid;
     if(first<last)
     {
      mid=(first+last)/2;
      mergesort(first,mid);
      mergesort(mid+1,last);
      merge(first,mid,last);
      }
}
int main()
{
     freopen("i19.in","r",stdin);
    freopen("output.txt","w",stdout);

    int i,t,n,p1=1,j,k;
    ll amit,b,c;
    char ch;
    scanf("%d",&t);
    build();
    while(t--)
    {
        int l[1000]={0},x[256]={0},x1[26]={0},p[1000]={0},start[26]={0},end[26]={0};
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {scanf(" %s",a[i]);
        }
        //mergesort(0,n-1);
        for(i=0;i<n;i++)
        {l[i]=strlen(a[i]);
       // printf("%s\n",a[i]);
       }

        for(i=0;i<n;i++)
        {
            ch=a[i][0];
            for(j=1;a[i][j]!='\0';j++)
            if(a[i][j]!=ch)
            break;
            if(a[i][j]=='\0')
            x[ch-'a']++,p[i]=1;
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(p[i]!=1)
            {
                if(start[a[i][0]-'a']!=0 || end[a[i][l[i]-1]-'a']!=0)
                flag=1;
                start[a[i][0]-'a']=i+1,end[a[i][l[i]-1]-'a']=i+1;
            }
        }
        j=0,k=0;
        amit=0;
        for(i=0;i<26;i++)
        {
            if(start[i]!=0 && end[i]==0)
            {
                amit++;
            }
            else if(x[i]!=0 && start[i]==0 && end[i]==0)
            amit++;
        }
        for(i=0;i<n;i++)
        {
            if(p[i]==1)
            continue;
            j=0,k=l[i]-1;
            if(a[i][j]==a[i][k])
            flag=1;
            while(a[i][j]==a[i][0])
            j++;
            while(a[i][k]==a[i][l[i]-1])
            k--;
            while(j<=k)
            {
                if(start[a[i][j]-'a']!=0 ||end[a[i][j]-'a']!=0 || x1[a[i][j]-'a']!=0)
                flag=1;
                x1[a[i][j]-'a']++;
                j++;
            }
        }
        if(flag==1 || amit==0)
        {
            printf("Case #%d: 0\n",p1++);
            continue;
        }
        ll res=1;
        for(i=0;i<26;i++)
        res=myMod(res*fact[x[i]]);
        res=myMod(res*fact[amit]);
        printf("Case #%d: %lld\n",p1++,res);
    }
    return 0;
}

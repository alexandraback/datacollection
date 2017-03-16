#include<cstdio>
#include<algorithm>
#include<vector>
#define M 1000000007



int main()
{
int i,j,k,l,m,n,t,T;
long long fac[102];

char a[101][102];

fac[0]=fac[1]=1;
for(i=2;i<101;i++)
    {
    fac[i]=(fac[i-1]*i)%M;    
    }

scanf("%d",&T);

for(t=1;t<=T;t++)
    {
    int c[27]={0};
    m=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%s",a[i]);    
        for(j=0;a[i][j];j++)
            c[a[i][j]-'a']++;
        }        
        
    for(i=0;i<n;i++)
        {
        for(j=0;a[i][j];j++)
            {
            k=j;
            while(a[i][j]==a[i][k] && a[i][k]) k++;
            
            if(j==0)
                {// First Char repeating
                c[a[i][j]-'a'] -= k-j-1;
                if(!a[i][k]) c[a[i][j]-'a']++;    
                }    
            else
                {
                if(!a[i][k])
                    {// Last char
                    c[a[i][j]-'a'] -= k-j-1;    
                    }    
                else
                    {// Middle
                    if(c[a[i][j]-'a'] == k-j)
                        {// Present No where else
                        c[a[i][j]-'a']=0;
                        }
                    else
                        {
//                        printf("%d %d\n",c[a[i][j]-'a'],j-k);
  //                      printf("I %d j %d k %d\n",i,j,k);
                        m=1;
                        }
                    }
                }
            j=k-1;    
            }
        for(j=0;a[i][j];j++);
        a[i][1]=a[i][j-1];
        a[i][2]='\0';    
        }
    
//    printf("M1= %d\n",m);
    
    if(m==1)
        {
        printf("Case #%d: 0\n",t);
        continue;    
        }
    
    int next[27],ind[27]={0},trn[27],frst[27];
    for(i=0;i<27;i++)
        {
        next[i]=trn[i]=-1;
        frst[i]=1;
        } 
    
    for(i=0;i<n;i++) 
        {
        if(a[i][0]!=a[i][1])    
            {
            if(next[a[i][0]-'a']== -1 &&  trn[a[i][0]-'a']== -1)
                {
               trn[a[i][0]-'a']= i;
                next[a[i][0]-'a']== a[i][1]-'a';
                frst[a[i][1]-'a']=0;
                }
            else
                m=1;
            }
        else
            ind[a[i][0]-'a']++;
        }

//    printf("M1= %d\n",m);
    
    if(m==1)
        {
        printf("Case #%d: 0\n",t);
        continue;    
        }
    
    int listS[102]={0},listC[27]={0};
    long long mult=1;
    k=1;
    for(i=0;i<n;i++) 
        {
        //List Begin 
        if(listS[i]==0 && frst[a[i][0]-'a'] && (a[i][0]!=a[i][1]))
            {
            j=i;
            while(1)
                {
                listS[j]=k;
                if(ind[a[j][0]-'a']) 
                    {
                    listC[a[j][0]-'a']=k;
                    mult*= fac[ind[a[j][0]-'a']];
                    mult%= M;
                    }
                if(trn[a[j][1]-'a']==-1)
                    {
                    if(ind[a[j][1]-'a']) 
                        {
                        listC[a[j][1]-'a']=k;
                        mult*= fac[ind[a[j][1]-'a']];
                        mult%= M;
                        }
                    
                    break;    
                    }   
                else
                    j= trn[a[j][1]-'a'];
                    
                }    
            k++;
            }
            
        }
    for(i=0;i<27;i++)
        {
        if(ind[i] && listC[i]==0) 
            {
            mult*=fac[ind[i]];
            mult%=M;
            k++;    
            }    
        }
    
 //   printf("A %lld %lld\n",mult ,k);
    mult*= fac[k-1];
    mult%=M;
    
    printf("Case #%d: %lld\n",t,mult);    
    }
    
return 0;    
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int test,A,B;

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&test);
    for (int Q=1;Q<=test;Q++)
    {
        printf("Case #%d: ",Q); 
        scanf("%d%d",&A,&B);
        int cnt=0;
        for (int i=A;i<=B;i++)
        {
            int sx=i,len=1;
            while (sx) len*=10,sx/=10;
            len/=10;
            sx=i/10+(i%10)*len;
            while (sx!=i) 
            {
                 if (i<sx && sx>=A && sx<=B) ++cnt;
                 sx=sx/10+(sx%10)*len;
            }
        }
        printf("%d\n",cnt);
    }
}

            
    

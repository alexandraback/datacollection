#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n[20];
int d[12][20];
int p[12];

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int tc;
    cin >> tc;

    for(int nt=1; nt<=tc; nt++)
    {
        cout << "Case #1" << ":" << endl;
        int N, M, R, K;
        cin >> R >> N >> M >> K;
        for(int i=0; i<R; i++)
        {
            memset(d,0,sizeof(d));
            memset(p,0,sizeof(p));
            for(int k=0; k<K; k++)
            {
                    cin >> n[k];
                    for(int a=2; a<9; a++)
                    {
                        int b=n[k];
                        while(b%a==0)
                        {
                            b/=a;
                            d[a][k]++;
                        }
                    }
            }


                int cant=0;
                for(int j=0; j<K; j++)
                {
                        p[3]=max(p[3],d[3][j]);
                        p[5]=max(p[5],d[5][j]);
                }
                cant+=p[3]+p[5];

            p[4]=N-cant;
            int max2=0;
            for(int j=0; j<K; j++)
            {
                if(d[2][j]%2)
                    p[2]=1;
                max2=max(max2,d[2][j]);
            }
            if(p[2])
                p[4]--;
            for(int j=2; j<6; j++)
                while(p[j]){ cout << j; p[j]--;}
            cout << endl;
         }
    }
}

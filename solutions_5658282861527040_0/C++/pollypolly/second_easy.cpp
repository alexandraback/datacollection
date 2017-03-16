#include<iostream>
#include<cstdio>
using namespace std;

int T, a, b, k;

int main (){
    scanf ("%d",&T);

    for (int t=0; t<T; t++){

        scanf ("%d %d %d",&a,&b,&k);
        int br = 0;

        for (int i=0; i<a; i++)
            for (int j=0; j<b; j++)
                if ((i&j) < k) br++;

        printf ("Case #%d: %d\n",t+1,br);
    }
    return 0;
}

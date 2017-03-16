#include <iostream>
using namespace std;
#include <stdio.h>
#include <algorithm>

int num[1000005];
int T;
int N,A;
int MIN(int a,int b){ return a<b?a:b; }
bool cmp(int a,int b) { return a<b; }
int MIN_ENERGY(int energy, int left ,int right) {

    if (energy <= num[left]){
        int need = 0;
        while (energy<=num[left]) {
            need ++;
            energy += energy-1;
        }
        return MIN(need+MIN_ENERGY(energy, left, right), right-left+1);
    }
    while (left <= right && energy > num[left]) {
        energy += num[left];
        left++;
    }
    if (left > right) return 0;
    return MIN_ENERGY(energy, left, right);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);


    scanf("%d",&T);
    for(int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d%d",&A,&N);
        for(int j=0;j<N;j++) scanf("%d",num+j);
        if(A==1)   { printf("Case #%d: %d\n",cnt,N); continue ;}
        sort(num,num+N,cmp);
        printf("Case #%d: %d\n",cnt,MIN_ENERGY(A,0,N-1));
    }
    return 0;
}

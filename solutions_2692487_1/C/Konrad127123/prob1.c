#include<stdio.h>
#include<stdlib.h>
int A,N,T,t;
int n,mote[128];
int ans;
int count;
int main(){
scanf("%d",&T);

int comp(const void *a1, const void *a2){
int b1 = *((int*)a1);
int b2 = *((int*)a2);
if (b1<b2) return -1;
if (b1>b2) return 1;
return 0;
}

for(t=1;t<=T;t++){
scanf("%d",&A);
scanf("%d",&N);
for(n=0;n<N;n++) scanf("%d",&mote[n]);

qsort(mote, N, sizeof(*mote), comp);

count=0;
ans=10000;

for(n=0;n<N;n++){
if (mote[n]<A) {A+=mote[n];}
else {
if ((count + N-n) <ans) ans =  count + N-n;
count++;
A=2*A-1;
n--;
}
if (count>N) break;
}
if ((count + N-n) <ans) ans =  count + N-n;

printf("Case #%d: %d\n",t, ans);

}

return 0;
}


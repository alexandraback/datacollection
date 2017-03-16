#include <iostream>
/*#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>*/
#include <fstream>
int maxa(int* a, int n) {
int i, max = a[0];
for(i = 1; i < n; i++) {
if(a[i] > max)
max = a[i];
}
return max;
}
int mina(int* a, int n) {
int i, min = a[0];
for(i = 1; i < n; i++) {
if(a[i] < min)
min = a[i];
}
return min;
}
int max(int a, int b) {
if(a > b)
return a;
else
return b;
}
int min(int a, int b) {
if(a < b)
return a;
else
return b;
}
int search(int* a, int n, int b) {
int i;
for(i=0; i<n; i++)
if(a[i] == b)
return i;
return -1;
}
void sort(int* a, int n) {
int i, j, temp;
 for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
using namespace std;
int A;
int N;
int m[10];
int solve(int a, int i) {
if(a==1)
return N;
while(i < N) {
if(a <= m[i])
break;
a += m[i];
i++;
}
if(i == N)
return 0;
else {
return min(1 + solve((2*a)-1, i), N-i);
}
}
int main() {
ifstream fi;
ofstream fo;
fi.open("Ai.in");
fo.open("Ao.in");
int T;
fi >> T;
int i, j;
for(i = 1; i <= T; i++) {
fi >> A >> N;
for(j = 0;j<N;j++)
fi >> m[j];
sort(m, N);
if(i==1)
for(j = 0; j<N;j++)
cout << m[j] << " ";
fo << "Case #" << i << ": " << solve(A, 0) << endl;
}
fi.close();
fo.close();
}

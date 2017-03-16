#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 10000010;
long long counts[maxn], countb[maxn];
bool used[maxn];
int calcrecycle(int x, int minnum)
{
    int ans = 0;
    int temp = x/10, weight = 1;
    while (temp)
    {
          temp /= 10;
          weight *= 10;
    }
    temp = x;
    do
    {
      used[x] = true;
      if (x/weight>0 && x<temp && x>=minnum) ans++;
      x = x/10 + x%10*weight;
    } while (!used[x]);
    while (used[x])
    {
          used[x] = false;
          x = x/10 + x%10*weight;
    }
    countb[temp];
    return ans;
}/*
void preprocess()
{
     for (int i=1; i<=2000000; i++) counts[i] = calcrecycle(i);
     counts[0] = countb[0] = 0;
     for (int i=2; i<=2000000; i++) counts[i] += counts[i-1], countb[i] += countb[i-1];
}*/
long long countings(int a, int b)
{
     long long ans = 0;
     for (int i=a+1; i<=b; i++) ans += calcrecycle(i, a);
     return ans;
}
int main()
{
//    preprocess();
    freopen("1.in", "r", stdin);
    int t, a, b;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        scanf("%d%d", &a, &b);
        printf("Case #%d: %lld\n", i, countings(a, b));
    }
    return 0;
}

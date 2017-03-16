#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
 int c,d,v;
  vector<int> arr;
int solve()
{
    int n=arr.size();
   int res = 1;
   for (int i = 0; i < n && arr[i] <= res; i++)
       res = res + arr[i];
   return res;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        cerr<<"done "<<t<<endl;
        scanf("%d %d %d",&c,&d,&v);
        arr.clear();
        int x;
        for(int i=0;i<d;i++){
            scanf("%d",&x);
            arr.push_back(x);
        }
        int cnt=0;
        sort(arr.begin(),arr.end());
        while(1){
            int p=solve();
           // printf("%d\n",p);
            if(p>v)
                break;
            arr.push_back(p);
            sort(arr.begin(),arr.end());
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}





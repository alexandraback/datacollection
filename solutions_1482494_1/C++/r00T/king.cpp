#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int x = 1; x<= tc;x++)
    {
            int n,cnt = 0;
            scanf("%d", &n);
            int a[n],b[n];
            bool fa[n],fb[n];
            for(int i = 0 ;i<n ;i++)
            {
                    scanf("%d %d", &a[i], &b[i]);
                    fa[i] = 0;
                    fb[i] = 0;
            }
            bool flag = 0;
            int str = 0;
            
            while(str < n*2)
            {
                  bool check = 0;
                  for(int i = 0;i<n; i++)
                  {
                          if(b[i] <= str && fb[i] == 0)
                          {
                                  check = 1;
                                  if(fa[i] == 0)
                                      str = str +1;
                                  str = str +1;
                                  fa[i] = 1;
                                  fb[i] = 1;
                                  cnt++;
                                  //cout<<"b"<<i<<" "<<str<<endl;
                          }
                  }
                  if(check == 0)
                  {
                       int ind = -1,max =0;
                       for(int i = 0 ;i<n ;i++)
                       {
                             if(a[i] <= str && fa[i] == 0)
                             {
                                     if(ind == -1 || b[i] > max)
                                     {
                                            ind  = i;
                                            max = b[i];
                                     }
                             }
                       }
                       if(ind == -1)
                       {
                        printf("Case #%d: Too Bad\n", x);
                        goto out;
                        }
                        str = str + 1;
                        fa[ind] = 1;
                        cnt++;
                        //cout<<"a"<<ind<<" "<<str<<endl;
                 }
            }
            printf("Case #%d: %d\n", x, cnt);
            out : continue;
    }
    return 0;
}

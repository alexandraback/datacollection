#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#define SIZE 2000001
using namespace std;
bool used[SIZE];
int C(int n,int b);
int min_represent(int x);
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    FILE* fp = fopen("C1.out","w");
    int n,a,b,q,cnt;
  /*  while(cin>>n)
    {
        cout<<min_represent(n)<<endl;
    }*/
    cin>>n;
    for(q=1;q<= n ;q++)
    {
        cnt = 0;
        map<int,int> m;
        map<int,int>::iterator it;
        cin>>a>>b;
        for(int i = a ;i<= b ;i++)
        {
          /*  if(m.count(min_represent(i)) >0)
            {
                cout<<min_represent(i)<<' '<<i<<endl;
            }*/
            m[ min_represent(i)]++;
        }
        for(it = m.begin(); it!=m.end() ; it++)
        {
            //cout<<it->second<<endl;
         //   if(it->second > 2)
         //   cout<<"C("<<it->second<<','<<2<<")= "<<C(it->second,2)<<endl;
            cnt+=C(it->second,2);
//            cnt+= it->second -1;
        }
        fprintf(fp,"Case #%d: %d\n",q,cnt);
//        cout<<cnt<<endl;
    }
    return 0;
}
int min_represent(int x)
{
    char str[1024];
    sprintf(str,"%d",x);
    int i,j,l,pos,ti,tj,k;

        l = strlen(str);

        i = 0 ; j = 1; k =0;

        while(i < l && j < l)
        {
            if(str[ (i+k)%l ] == str[ (j+k)%l ])
                k++;
            else if(str[ (i+k)%l ] < str[ (j+k)%l ])
            {
                j+=k+1;
                if(j <=i)j = i+1;
                k = 0;
            }
            else if(str[(i+k)%l] > str[(j+k)%l])
            {
                i+=k+1;
                if(i <= j )i = j+1;
                k = 0;
            }
            if(k==l)break;
        }
    k = min(i,j);
    x =0;
    for(i=0;i<l  ;i++)
    {
        x*=10;
        x+=str[(k+i)%l]-'0';
    }
    return x;
}
int C(int n,int b)
{
    if(n< b)return 0;
    int u;
    u = 1;
    //cout<<"1"<<endl;
    for(int i = b ;i <= n ; i++)u*=i;
  //  cout<<u<<endl;
    for(int i = 1;i<= b ;i++) u/=i;
    for(int i = 1;i<=(n-b);i++)u/=i;
 //   cout<<u<<endl;
    return u;
}

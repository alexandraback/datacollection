/***********************

Shubham Singhal

CodeChef - torque
HackerEarth - torque
SPOJ - torque
HackerRank - torquecode
CodeForces - torquecode
***********************/

// If Tyrion dies, I am gonna riot :P


# include <bits/stdc++.h>
using namespace std;

# define MOD         1000000007
# define gc          getchar
# define LL          long long
# define L           long
# define pb          push_back
# define pINF        999999
# define nINF        -999999
# define printi(x)   printf("%d",&x);
# define printli(x)  printf("%ld",&x);
# define printlli(x) printf("%lld",&x);
# define mp          make_pair
# define vi          vector<int>
# define MAXN        150005

template<class T>
void scanint(T &x)
{
    register T c = gc();
    x = 0;
    T neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
FILE *in,*out;

int main()
{
  in=fopen("input.txt","rt");
  out=fopen("output.txt","wt");
  int t;
  fscanf(in,"%d",&t);
  for(int tt=1;tt<=t;tt++)
  {
    vector<LL> numbers;
    LL x[30000];
    int n;
    fscanf(in,"%d",&n);
    int maximum=-1,tmp;
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(in,"%d",&tmp);
            x[tmp]++;
            maximum=max(maximum,tmp);
        }
    }

    for(int i=0;i<=maximum;i++)
    {
        if(x[i]%2==1)
            numbers.pb(i);
        x[i]=0;
    }
    int sz=numbers.size();
    sort(numbers.begin(),numbers.end());
    fprintf(out,"Case #%d: ",tt);
    for(int i=0;i<sz;i++)
        fprintf(out,"%d ",numbers[i]);
    fprintf(out,"\n");


  }
  return 0;
}

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
        char s[1002];
        int a[2005];
        fscanf(in,"%s",s);
        int len=strlen(s);
        int k=1002;
        a[k]=s[0];
        int last=1002,start=1002;
        for(int i=1;i<len;i++)
        {
             if(s[i]<a[start])
            {
                a[last+1]=s[i];
                last++;
            }
            else
            {
                a[start-1]=s[i];
                start--;

            }
        }
        fprintf(out,"Case #%d: ",tt);
        for(int i=start;i<=last;i++)
            fprintf(out,"%c",a[i]);
        fprintf(out,"\n");

    }
    return 0;
}

// Can a man still be brave if he's afraid?  That is the only time a man can be brave !!

#include <bits/stdc++.h>
using namespace std;

#define cin(n) scanf("%d",&n)
#define pb push_back

void computeLPSArray(string pat, int M, int *lps);

int ans,lps[100008];
void KMPSearch(string pat)
{
    int M=pat.length();
    computeLPSArray(pat, M);


}

void computeLPSArray(string pat, int M)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i]==pat[len])
       {
         len++;
         lps[i]=len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

int k,l,ss;
double dp[108][108];
string s,ab;

int rec(int pos,int pre)
{
    if(dp[pos][pre]!=-1.0)
        return dp[pos][pre];

    if(pos==ss)
    {

    }

    double ret=0.0;

    for(i=0;i<k;i++)
    {
        int le=lps[pre];
        while((s[le]!=ab[i])&&le>0)
            le=lps[le-1];
        if(le==0&&s[0]!=ab[i])
            le=0;
        else
            le++;
        ret=ret+rec(pos+1,le);
    }
    return dp[pos][pre]=ret;

}
int main()
{

    int t,m,n,i,j;

    cin(t);
    j=1;
    //t=1;
    while(t--)
    {
        cin(k);cin(l);cin(ss);


        cin>>ab>>s;
        //cout<<"Case #"<<j++<<": ";
        KMPSearch(s);

        cout<<ans<<"\n";
    }

    return 0;
}

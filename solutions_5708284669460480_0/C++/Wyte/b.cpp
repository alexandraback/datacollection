#include<bits/stdc++.h>
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define INIT(x,y) memset((x),(y),sizeof(x))
#define PQ priority_queue
#define IT iterator
#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int k,l,s,pi[105],memo1[105][105][105];
char kb[105],target[105];
bool chk[105][105][105];
double memo2[105][105][105];
int ensure(int iteration,int matched_char,int matched_word)
{
    if(iteration==s)
    {
        return matched_word;
    }
    if(memo1[iteration][matched_char][matched_word]==-1)
    {
        memo1[iteration][matched_char][matched_word]=0;
        int i,ch,wrd;
        for(i=0;i<k;i++)
        {
            ch=matched_char;
            wrd=matched_word;
            while(ch!=0&&target[ch+1]!=kb[i])
            {
                ch=pi[ch];
            }
            if(target[ch+1]==kb[i])ch++;
            if(ch==l)
            {
                wrd++;
                ch=pi[ch];
            }
            memo1[iteration][matched_char][matched_word]=max(memo1[iteration][matched_char][matched_word],ensure(iteration+1,ch,wrd));
        }
    }
    return memo1[iteration][matched_char][matched_word];
}
double expected(int iteration,int matched_char,int matched_word)
{
    if(iteration==s)
    {
        return matched_word;
    }
    if(!chk[iteration][matched_char][matched_word])
    {
        chk[iteration][matched_char][matched_word]=1;
        memo2[iteration][matched_char][matched_word]=0;
        int i,ch,wrd;
        for(i=0;i<k;i++)
        {
            ch=matched_char;
            wrd=matched_word;
            while(ch!=0&&target[ch+1]!=kb[i])
            {
                ch=pi[ch];
            }
            if(target[ch+1]==kb[i])ch++;
            if(ch==l)
            {
                wrd++;
                ch=pi[ch];
            }
            memo2[iteration][matched_char][matched_word]+=expected(iteration+1,ch,wrd);
        }
        memo2[iteration][matched_char][matched_word]/=k;
    }
    return memo2[iteration][matched_char][matched_word];
}
int main()
{
    int t,ii,i,matched;
    scanf("%d",&t);
    for(ii=1;ii<=t;ii++)
    {
        scanf("%d %d %d %s %s",&k,&l,&s,kb,target+1);
        pi[1]=0;
        matched=0;
        for(i=2;i<=l;i++)
        {
            while(matched!=0&&target[matched+1]!=target[i])
            {
                matched=pi[matched];
            }
            if(target[matched+1]==target[i])matched++;
            pi[i]=matched;
        }
        INIT(memo1,-1);
        INIT(chk,0);
        printf("Case #%d: %lf\n",ii,ensure(0,0,0)-expected(0,0,0));
    }
}

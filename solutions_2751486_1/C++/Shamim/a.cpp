#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<sstream>
#include<queue>
#include<ctype.h>
#include<cstring>


using namespace std;

#define re return
#define co continue
#define pb push_back
#define br break
#define sz size


#define pf printf
#define sf scanf

char name[1000000+5];

bool IsConsonant(char ch)
{
    char tryVowel[] = {'a','e','i','o','u'};
    int i;
    for(i=0;i<5;i++)
        if ( tryVowel[i] == ch)
            return false;
    return true;
}

int main()
{
    //freopen("sample.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("a.ans","w",stdout);
    int t;
    int kase = 1;
    sf("%d",&t);
    while(t--)
    {
        long long sum = 0;
        int n;
        sf("%s",name);
        sf("%d",&n);
        int len = strlen(name);
        int lowerIndex = 0;
        int curIndex = 0;

        while( curIndex<len)
        {
            if ( IsConsonant (name[curIndex]) )
            {
                int run =  1;
                int starter = curIndex;
                curIndex++;
                while( curIndex<len && IsConsonant( name[curIndex]) )
                {
                    run++;
                    curIndex++;
                }
                while ( run>=n )
                {
                    // consecutive sequence found
                   // cout<<run<<endl;
                   // sum += (len - lowerIndex - n + 1); // sum these
                    // change lower index and curnindex

                     long long left,right;
                    left = starter-lowerIndex;
                    right = len - starter - n;
                    sum += (left+1)*(right+1);

                    lowerIndex = starter+1;
                    starter = lowerIndex;


                    run--;
                }
            }
            curIndex++;
        }
        printf("Case #%d: ",kase++);
        cout<<sum<<endl;
    }
    return 0;
}

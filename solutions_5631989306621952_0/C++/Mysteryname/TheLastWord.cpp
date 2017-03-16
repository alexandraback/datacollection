
/*
Google Code Jam 2016
Round 1A
AUTHOR: Phawin Prongpaophan
*/

#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

int n;
char word[1111];

void each(int tc)
{

    scanf("%s",word);
    n = strlen(word);
    stack <char> f;
    queue <char> b;
    f.push(word[0]);
    for(int i=1;i<n;i++)
    {
        if(word[i]>=f.top())    f.push(word[i]); else b.push(word[i]);
    }

    printf("Case #%d: ",tc);
    while(!f.empty()) {printf("%c",f.top()); f.pop();}
    while(!b.empty()) {printf("%c",b.front()); b.pop();}
    printf("\n");
    return;
}

int main()
{
    freopen("LastWordIn.in","r",stdin);
    freopen("LastWordOut.txt","w",stdout);
    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}


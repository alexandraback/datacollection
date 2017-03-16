#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

int GET_INT(){int ret; scanf("%d",&ret); return ret;}

#define INT GET_INT()

typedef long long LL;
typedef pair<int,int> pii;

string in1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string in2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string in3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

string out1 = "our language is impossible to understand";
string out2 = "there are twenty six factorial possibilities";
string out3 = "so it is okay if you want to just give up";

char MAP[300];

void proc(string in, string out){
    FOR(i,in.size()){
        MAP[in[i]] = out[i];
    }
}

int main()
{
    freopen("A_in.txt","r",stdin);
    freopen("A_out.txt","w",stdout);

    CLR(MAP,'#');

    MAP['a'] = 'y';
    MAP['o'] = 'e';
    MAP['z'] = 'q';

    proc(in1,out1);
    proc(in2,out2);
    proc(in3,out3);

    // q is not maped
    for(char ch='a';ch<='z';++ch){
        bool exists=0;
        for(char ch2='a';ch2<='z';++ch2){
            if(MAP[ch2]==ch) exists = 1;
        }
        if(!exists){
            MAP['q'] = ch;
            break;
        }
    }



    int T; scanf("%d",&T);

    getchar();

    REP(t,1,T){
        char input[200];
        gets(input);

        for(int i=0;input[i];++i)
            if(input[i]>='a'&&input[i]<='z')
                input[i] = MAP[input[i]];

        printf("Case #%d: %s\n",t,input);
    }

    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int tc;
char s[1000];
int m[]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};

int main() {
    scanf("%d",&tc);
    gets(s);
    for (int t=1; t<=tc; t++) {
        gets(s);
        printf("Case #%d: ",t);
        int len = strlen(s);
        for (int j=0; j<len; j++)
            if (s[j] == ' ') printf(" ");
            else printf("%c",m[s[j]-'a']+'a');
        printf("\n");
    }
}

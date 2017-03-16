#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
string p = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    string st;
    for (int i = 0 ; i < n ;i++)
    {
        getline(cin,st);
        printf("Case #%d: ",i+1);
        for (int j = 0 ; j < st.size();j++)
        {
            if (st[j] == ' ')
            {
                      printf(" ");
                      continue;
            }
            printf("%c",p[st[j]-'a']);
        }
        printf("\n");
    }
}

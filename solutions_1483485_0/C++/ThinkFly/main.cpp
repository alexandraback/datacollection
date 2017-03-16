#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <iostream>
using namespace std;
map<char,char> translate;
void init()
{
    string org_1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    string dst_1 = "our language is impossible to understand";
    string org_2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    string dst_2 = "there are twenty six factorial possibilities";
    string org_3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string dst_3 = "so it is okay if you want to just give up";
    int i;
    for(i=org_3.length()-1;i>=0;i--) {
        translate[org_3[i]] = dst_3[i];
    }
    for(i=org_2.length()-1;i>=0;i--) {
        translate[org_2[i]] = dst_2[i];
    }
    for(i=org_1.length()-1;i>=0;i--) {
        translate[org_1[i]] = dst_1[i];
    }
    translate['q'] = 'z';
    translate['z'] = 'q';
}

int main()
{
    init();
    int n_case;
    char org[1000];
    scanf("%d%c",&n_case,org);
    int n;
    for (n=1;n<=n_case;n++)
    {
        int len;
        do 
        {
            cin.getline(org,1000,'\n');
            len = strlen(org);
        } while (len<=0);
        
        printf("Case #%d: ",n);
        for (int i=0;i<len;i++) {
            if (translate.find(org[i])!=translate.end())
            {
                printf("%c",translate[org[i]]);
            }
            else printf("%c",' ');
        }
        printf("\n");
    }
    return 0;
}
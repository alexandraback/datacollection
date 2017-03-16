#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    freopen("test.txt","r",stdin);

    std::string str;
    unsigned case_count = 0;
    unsigned N =0;
//    content cont[100] = {0};
    unsigned Condi = 0;
    cin >>  case_count;
    //cout << case_count;
    char buffer[200];
    char buffer2[200];
    map<char,char> googlerese;
    //map<char,char> inver;
    cin.getline(buffer,200);

    if(case_count==0) return 0;
    for(int c =1; c <= case_count ; c++)
    {
        cin.getline(buffer,200);
        cin.getline(buffer2,200);
        for(int i =0;i<strlen(buffer);i++){
            googlerese[buffer[i]]= buffer2[i];

        }
    }
    googlerese['z'] = 'q';
    googlerese['q'] = 'z';
    int count =0;
    /*
    for(map<char,char>::iterator it = googlerese.begin(); it!= googlerese.end();it++)
    {
        printf("%d %c : %c\n",count++,it->first,it->second);

    }*/
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    cin >>  case_count;
    cin.getline(buffer,200);
    if(case_count==0) return 0;
    for(int c =1; c <= case_count ; c++)
    {
        cin.getline(buffer,200);
        for(int i =0;i<strlen(buffer);i++){
            buffer2[i] = googlerese[buffer[i]];
        }
        buffer2[strlen(buffer)] = '\0';
        printf("Case #%d: %s\n",c,buffer2);
    }

    return 0;
}

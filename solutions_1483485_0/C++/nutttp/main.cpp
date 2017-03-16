//
//  main.cpp
//  GCJ_Q1
//
//  Created by MBP13 on 4/14/55 BE.
//  Copyright (c) 2555 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main ()
{
    freopen("/Users/mbp13/Documents/Google Code Jam/GCJ_Q1/GCJ_Q1/input", "r", stdin);
    freopen("/Users/mbp13/Documents/Google Code Jam/GCJ_Q1/GCJ_Q1/output_q1", "w", stdout);
    //Decode         a b c d e f g h i j k l m n o p q r s t u v w x y z
    char decode[26]={'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};
    int num;
    int i,j,k;
    char input[105];
    char output[105];
    cin >> num;
    gets(input);
    for(i=0;i<num;i++)
    {
        gets(input);
        printf("Case #%d: ", i+1);
        for(j=0;input[j]!='\0';j++)
        {
            if(input[j] == ' ')
                output[j] = ' ';
            else
                for(k=0;k<26;k++)
                    if(input[j] == decode[k])
                        output[j] = k+'a';
            printf("%c",output[j]);
        }
        printf("\n");
    }
    return 0;
}


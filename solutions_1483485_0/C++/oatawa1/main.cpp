//
//  main.cpp
//  Speaking in Tongues
//
//  Created by Wasin Kalintha on 4/14/12.
//  Copyright 2012 Chulalongkorn University. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<string>
#include<sstream>

using namespace std;
#define pii pair<int , int>
#define vii vector<pii >

#define FOR(i , a , b) for(__typeof(b)i=a;i<b;i++)
#define FORE(i , a , b) for(__typeof(b)i=a;i<=b;i++)
#define FOR_INV(i , a , b) for(__typeof(b)i=a;i>b;i--)
#define FORE_INV(i , a , b) for(__typeof(b)i=a;i>=b;i--)
#define TR(it , c) for(__typeof((c).end())it = (c).begin();it != (c).end();it++)
int n;
char mapping[30] = "yhesocvxduiglbkrztnwjpfmaq";
char input[105];


int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d\n",&n);
    FOR(tt , 0 , n)
    {
        scanf("%[^\n]%*[\n]",&input);
        printf("Case #%d: ",tt+1);
        FOR(i , 0 , strlen(input))
        {
            if(input[i] >= 'a' && input[i] <= 'z')
                printf("%c",mapping[input[i]-'a']);
            else
                printf("%c",input[i]);
        }
        printf("\n");
        
    }
    
    return 0;
}
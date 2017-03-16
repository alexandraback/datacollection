//
//  main.cpp
//  Consonants
//
//  Created by Akhil Verghese on 5/12/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
using namespace std;

bool is_Consonant(char a)
{
    if((a!='a')&&(a!='e')&&(a!='i')&&(a!='o')&&(a!='u'))
        return 1;
    else
        return 0;
}
int main(int argc, const char * argv[])
{
    int t,x=0,n,count,sets;
    char name[1000000];
    cin>>t;
    while(t--)
    {
        x++;
        cin>>name>>n;
        count=sets=0;
        bool flag=0;
        for(int i=0;i<strlen(name);i++)
        {
            for(int j=i;j<strlen(name);j++)
            {
                if(is_Consonant(name[j]))
                {
                    count++;
                    if(count>=n)
                    {
                        flag=1;
                        sets++;
                    }
                }
                else
                {
                    if(flag)
                    {
                        count++;
                        sets++;
                    }
                    else
                        count=0;
                }
            }
            flag=0;
            count=0;
        }
        cout<<"Case #"<<x<<": "<<sets<<endl;
        getchar();
    }
    return 0;
}


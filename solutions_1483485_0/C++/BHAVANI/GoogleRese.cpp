//
//  GoogleRese.cpp
//  DESIGN
//
//  Created by Shankar, Penumaka Bhavani on 4/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    char mapping[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    int t;
    cin >> t;
   char str[10];
    gets(str);
    for ( int i = 0 ; i < t; i++ )
    {
        char str[110];
        gets(str);
        string src(str);
        cout << "Case #"<<(i+1)<<": ";
        for ( int i = 0 ; i < src.size(); i++ )
        {
            if ( src[i] != ' ') cout << mapping[src[i]-'a'];
            else    cout << " ";
        }
        cout << endl;
    }
    return 0;
}

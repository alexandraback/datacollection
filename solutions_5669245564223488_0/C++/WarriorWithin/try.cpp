#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <queue>


using namespace std;

string word[100];

int main()
{
    int t, i, n, ctr;
    char last;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n;
        for(int j=0; j<n; j++)
            cin>>word[j];

        int ar[n];
        for(int j=0; j<n; j++)
            ar[j] = j;

        long long int ans = 0;
        do
        {
            //for(int j=0; j<n; j++)
                //cout<<ar[j]<<" ";
            //cout<<endl;

            int ch[26], ctr = 0;
            for(int j=0; j<26; j++)
                ch[j] = 0;

            last = word[ar[0]][0];
            ch[last-'a'] = 1;
            for(int j=0; j<n; j++)
            {
                int k = ar[j];
                int pos = 0;
                while(pos<word[k].length())
                {
                    while(pos<word[k].length() && word[k][pos]==last)
                    {
                        pos++;
                    }

                    if(pos<word[k].length())
                    {
                        if(ch[word[k][pos]-'a']==0)
                        {
                            last = word[k][pos];
                            ch[word[k][pos]-'a'] = 1;
                        }
                        else
                        {
                            ctr = 1;
                            break;
                        }
                    }
                }
                if(ctr==1)
                    break;
            }

            if(ctr==0)
                ans++;

            //cout<<ans<<endl;
        }while(next_permutation(ar, ar+n));

        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}

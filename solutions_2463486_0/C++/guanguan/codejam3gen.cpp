#include<cstdio>
#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;
int palin[10]; //limited to 6
map<long long,long long> m;

bool ispalindrome(long long a)
{
     string s;
     while (a>0)
     {
           s=s+(char)(a%10+'a');
           a-=a%10;
           a/=10;
     }
     bool success=true;
     for (int i=0; i<=(s.length()/2); i++)
     {
         if (s[i]!=s[s.length()-1-i])
         {
            success=false;
            break;
         }
     }
     return success;
}

int main()
{
    //freopen("codejam3.in","r",stdin);
    //freopen("codejam3out.txt","w",stdout);
    ofstream out("fairandsquare.txt");
    for (long long i=0; i<10000000; i++)
    {
        if (ispalindrome(i) && ispalindrome(i*i))
        {
           cout << i << " " << (i*i) << endl;
           out << i << " ";
           out << (i*i) << endl;
        }
    }
}

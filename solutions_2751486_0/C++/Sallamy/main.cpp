#include <iostream>
#include <fstream>
int n;
using namespace std;
string s;
bool isVowel(char c)
{
    return (c=='a'|| c=='i'|| c=='o'|| c=='u'|| c=='e');
}
bool check(int i, int j)
{
    int count=0;
    for(i;i<=j;i++)
    {
        if(!isVowel(s[i]))count++;
            else count=0;
        if(count==n)return true;
    }
    return false;
}
int main()
{
    ifstream in;
    in.open("A-small-attempt0 (3).in");
    ofstream out;
    out.open("out.txt");
    int t,ans,size;
    in>>t;
    for(int o=1; o<=t; o++)
    {
        ans=0;
        in>>s>>n;
        size = s.size();
        for(int i=0; i<size;i++)
        {
            for(int j=i; j<size; j++)
            {
                if(j-i+1<n){}
                else
                {
                    if(check(i,j))
                    {
                        ans+=(size-j);
                        j=size;
                    }
                }
            }
        }
        out<<"Case #"<<o<<": "<<ans<<endl;
    }
    return 0;
}

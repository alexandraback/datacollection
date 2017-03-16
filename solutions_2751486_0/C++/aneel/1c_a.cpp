#include <iostream>
#include <cstring>
using namespace std;

char str[1000006];
int n,len;

int hasNCon(int i)
{
    int countn=0;
    for(;i<len;++i)
    {
        if( (str[i] > 'a' && str[i] < 'e') ||
            (str[i] > 'e' && str[i] < 'i') ||
            (str[i] > 'i' && str[i] < 'o') ||
            (str[i] > 'o' && str[i] < 'u') ||
            (str[i] > 'u')
            )
        {
            ++countn;
            if(countn==n) return i;
        }
        else countn=0;
    }
    return -1;
}

int main()
{
    
    int t;
    cin>>t;
    
    for(int ti = 1; ti <= t; ++ti)
    {
        cin>>str>>n;
        len = strlen(str);
        
        int total = 0;
        //cout<<str<<endl;
        for(int i = 0; i < len; ++i)
        {
            int j = hasNCon(i);
            //cout<<"("<<j<<") ";
            if(j != -1)
            {
                total += len - j;
            }
        }
        cout<<"Case #"<<ti<<": "<<total<<endl;
    }
    return 0;
}

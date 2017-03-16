#include <bits/stdc++.h>

using namespace std;

void resolver(int t)
{
    char s[2000], o[2000];
    int tam, i, j;
    scanf("%*c%s", s);
    tam = strlen(s);
    //cout<<tam<<endl;
    o[tam] = '\0';
    for(i=0;i<tam;i++)
    {
        if(s[i]>=o[0])
        {
            for(j=i-1;j>=0;j--)
            {
                o[j+1] = o[j];
            }
            o[0] = s[i];
        }
        else
        {
            o[i] = s[i];
        }
        //cout<<o<<endl;
    }
    cout<<"Case #"<<t<<": "<<o<<endl;
}

int main()
{
    int t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;


void func(string C,string J,string &c,string &j)
{
    int n=C.length();
    bool prevCmin=0;
    bool prevJmin=0;
    for(int i=0;i<n;i++)
    {
        if(prevCmin)
        {
            if(C[i]=='?'&& J[i]=='?')
            {
                c+='9';
                j+='0';
            }
            else if(C[i]=='?')
            {
                c+='9';
                j+=J[i];
            }
            else if(J[i]=='?')
            {
                c+=C[i];
                j+='0';
            }
            else
            {
                c+=C[i];
                j+=J[i];
            }
        }
        else if(prevJmin)
        {
            if(C[i]=='?'&& J[i]=='?')
            {
                c+='0';
                j+='9';
            }
            else if(C[i]=='?')
            {
                c+='0';
                j+=J[i];
            }
            else if(J[i]=='?')
            {
                c+=C[i];
                j+='9';
            }
            else
            {
                c+=C[i];
                j+=J[i];
            }
        }
        else
        {
            if(C[i]=='?'&& J[i]=='?')
            {
                if(i<n-1&&C[i+1]!='?'&&J[i+1]!='?')
                {
                    if(C[i+1]>J[i+1])
                    {
                        if(C[i+1]-J[i+1]>5)
                        {
                            c+='0';
                            j+='1';
                        }
                        else
                        {
                            c+='0';
                            j+='0';
                        }
                    }
                    else if(C[i+1]<J[i+1])
                    {
                        if(J[i+1]-C[i+1]>5)
                        {
                            c+='1';
                            j+='0';
                        }
                        else
                        {
                            c+='0';
                            j+='0';
                        }
                    }
                    else
                    {
                        c+='0';
                        j+='0';
                    }
                }
                else
                {
                    c+='0';
                    j+='0';
                }
            }
            else if(C[i]=='?')
            {
                if(i<n-1 && C[i+1]!='?'&& J [i+1]!='?') //12
                {
                    if(C[i+1]>J[i+1])
                    {
                        if(C[i+1]-J[i+1]>=5)
                        {
                            c+=J[i]-1;
                            j+=J[i];
                        }
                        else
                        {
                            c+=J[i];
                            j+=J[i];
                        }
                    }
                    else
                    {
                         c+=J[i];
                         j+=J[i];
                    }
                }                
                else
                {
                    c+=J[i];
                    j+=J[i];
                }
            }
            else if(J[i]=='?')
            {
                if(i<n-1 && C[i+1]!='?'&& J [i+1]!='?') //12
                {
                    if(J[i+1]>C[i+1])
                    {
                        if(J[i+1]-C[i+1]>=5)
                        {
                            c+=C[i];
                            j+=C[i]-1;
                        }
                        else
                        {
                            c+=C[i];
                            j+=C[i];
                        }
                    }
                    else
                    {
                         c+=C[i];
                         j+=C[i];
                    }
                } 
                else
                {
                    c+=C[i];
                    j+=C[i];
                }
            }
            else
            {
                c+=C[i];
                j+=J[i];
                if(C[i]<J[i])
                    prevCmin=1;
                else if(C[i]>J[i])
                    prevJmin=1;
            }
        }
    }
}

int diff(string a, string b)
{
    int x=0,y=0;
    x= stoi(a);
    y=stoi(b);
    return abs(x-y);
}
int main()
{
	int t;
	uint64_t n;
    cin>>t;
    int cnt=1;
    while(t--)
    {
    	string C,J;
        cin>>C>>J;
        string c,j;
        func(C,J,c,j);
        string c1,j1;
        int n=C.length();
        //reverse(C.begin(),C.end());
        //reverse(J.begin(),J.end());
        //func(C,J,c1,j1);
        //if(diff(c,j)<diff(c1,j1))
    	cout<<"Case #"<< cnt++<<": "<<c<<' '<<j<<endl;
        //else
        //cout<<"Case #"<< cnt++<<": "<<c1<<' '<<j1<<endl;
    }
}
#include<iostream>
#include<fstream>
using namespace std;
string A,B;
string C,D;
int small=-1,P,Q;
void Reccur(string a , string b)
{
    //cout<<a<<" "<<b<<endl;
    if(A.size()==a.size())
    {
        int X=0,Y=0;
        for(int i=0 ; i<a.size() ; i++)
        {
            X=X*10+a[i]-'0';
            Y=Y*10+b[i]-'0';
        }
        int H=X-Y;
        if(H<0)
        H=H*(-1);
        if(small==-1 || H<small)
        {
            small=H;
            C=a;
            D=b;
            P=X,Q=Y;
        }
        return;
    }
    for (int i=0 ; i<=9 ; i++)
    {
        char c=i+'0';
        string e,f;
        if(A[a.size()]=='?')
        {
            e=a+c;
            for(int j=0 ; j<=9 ; j++)
            {
                char d=j+'0';
                if(B[a.size()]=='?')
                {
                    f=b+d;
                }
                else
                {

                    f=b+B[a.size()];
                    Reccur(e,f);
                    break;
                }
                Reccur(e,f);
            }
        }
        else
        {
            e=a+A[a.size()];
            for(int j=0 ; j<=9 ; j++)
            {
                char d=j+'0';
                if(B[a.size()]=='?')
                {
                    f=b+d;
                }
                else
                {

                    f=b+B[a.size()];
                    Reccur(e,f);
                    break;
                }
                Reccur(e,f);
            }
            break;
        }
    }
}
int main()
{
    std:ios::sync_with_stdio(false);
    //input.tie();
    //output.tie();
    ifstream input;
    input.open("inp.txt");
    ofstream output;
    output.open("out.txt");
    int T;
    input>>T;
    for (int i=0 ; i<T ; i++)
    {
        small=-1;
        C="";
        D="";
        output<<"Case #"<<i+1<<": ";
        input>>A>>B;
        string G,H;
        int I,J;
        Reccur(G,H);
        output<<C<<" "<<D<<endl;
        int U=P-Q,V=I-J;
        /*if(U<0)
            U=U*(-1);
        if(V<0)
            V=V*(-1);
        if(U!=V)
        {
            cout<<U<<" "<<V<<endl;
            cout<<i<<endl;
            cout<<I<<" "<<C<<endl;
        }*/
        //cout<<small<<" "<<C<<" "<<D<<endl;
    }
}

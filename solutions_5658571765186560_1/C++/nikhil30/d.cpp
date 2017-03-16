#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;


#define cin fin
#define cout fout

int main()
{
    ifstream fin;
    fin.open("D-large.in");
    ofstream fout;
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        int x,r,c;
        cin>>x>>r>>c;
        if(r%x) swap(r,c);
        if(!(r%x) && c>=(x-1)) cout<<"GABRIEL\n";
        else cout<<"RICHARD\n";
    }
    return 0;
}

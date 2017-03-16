#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>

using namespace std;

#define uul unsigned long long
#define fOR(i) for(int j=0; j<i; j++)
#define fOR2(st,n) for(int i=st; i<n; i++)
#define ch(t,s1,s2) (t<s1 || t>s2)


int main()
{
	ifstream fin("p.in");
	ofstream fout("p.out");

	int tt;
    fin>>tt;
    int cc = 0;
    while(tt--) {
        cc++;
        long double a, b;
        char ch;
        fin>>a>>ch>>b;
        long double res = a/b;
        int count = 0;
        bool t = false;
        int first = 0;
        while(count <= 40) {
            
            if(res == 1) break;
            if(res > 1) {
                res = res - 1;
                if(!t){ first = count; t = true; }
            }
            res *= 2;
            count++;
        }
		fout<<"Case #"<<cc<<": ";
        if(!t) first = count;
        if(count <= 40) fout<<first<<endl;
        else fout<<"impossible"<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
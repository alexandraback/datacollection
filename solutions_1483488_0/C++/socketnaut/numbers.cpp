#include<fstream>
#include<string>
using namespace std;

ifstream fin("numbers.in");
ofstream fout("numbers.out");

int T, S;
int A, B;
int pow[10];

int ndig(int x){
    int c = 0;
    while(x!=0){
        x/=10;
        c++;
    }
    return c;
}

int next(int val){
    int n = ndig(val);
    for(int x = n-1; x>=1; x--)
        if(val%pow[x]==0)
            return pow[ndig(val)-x-1]*(val%pow[x+1]) + val/pow[x+1];
    return pow[ndig(val)-1]*(val%10) + val/10;
}

int main()
{
    pow[0] = 1;
    for(int c=1; c<10; c++)
        pow[c] = 10*pow[c-1];
    fin >> T;
    for(int t=0; t<T; t++){
        fin >> A >> B;
        S = 0;
        for(int c=A; c<=B; c++){
            int x = next(c);
            while(x!=c){
                if(x>c && x<=B) S++;
                x = next(x);
            }
        }
        fout << "Case #" << t+1 << ": " << S << endl;
    }
    return 0;
}

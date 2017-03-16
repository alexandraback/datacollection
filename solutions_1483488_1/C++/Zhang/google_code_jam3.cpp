#include <iostream>
#include <fstream>
#include <set>
#include <string.h>
using namespace std;

 int const MaxN = 2000001;
int table[MaxN];



void shift(char* buf)
{
     char t = buf[0];
     for(int i = 1; i < strlen(buf); i++)
     {
             buf[i - 1] = buf[i];             
     }
     buf[strlen(buf) - 1] = t;
}

int Judge(int i)
{
    char buffer[100];
    itoa(i, buffer, 10);
  //  cout << "*" << buffer << endl;
    
    int ans = 0;
    for(int j = 0; j < strlen(buffer) - 1; j++)
    {
            shift(buffer);
            if(buffer[0] == '0') continue;
            int b = atoi(buffer);
            if(b < i) ans++;
    }
//    cout << ans << endl;
    return ans;
    
}

int Judge1(int i, int r)
{
    char buffer[100];
    itoa(i, buffer, 10);
    set <int> s;    
    int ans = 0;
    for(int j = 0; j < strlen(buffer) ; j++)
    {
            shift(buffer);
            if(buffer[0] == '0') continue;
            int b = atoi(buffer);
            if(s.find(b) != s.end()) continue;
            s.insert(b);
            if(b > i && b <= r) ans++;
    }
    return ans;
    
}

void Construct()
{
     for(int i = 1; i <= MaxN; i++)
     {
             table[i] = table[i - 1] + Judge(i);
     }
}


int bruteforce(int l, int r)
{
    int ans = 0;
     for(int i = l; i <= r; i++)
     {
       ans += Judge1(i , r);
     }
     return ans;
}

int main()
{
    ifstream cin("jam3.in");
    ofstream cout("jam3.out");
//    Construct();
    int l,r;
    int N;
    cin >> N; 
    for(int i = 1; i <= N;i++)
    {
               cin >> l >> r;
               cout << "Case #" << i <<": " <<  bruteforce(l, r) << endl;
               //cout << table[l] << endl;
               //cout << table[r] << endl;
               //cout << table[r] - table[l - 1] << endl;
    }
    //getchar();
    //    getchar();
}

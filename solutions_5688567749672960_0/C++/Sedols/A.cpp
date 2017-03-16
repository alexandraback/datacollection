#include<iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int flip(int n)
{
    int temp = n;
    string s = "";
    while(temp > 0)
    {
        s += (temp%10) + '0';
        temp /= 10;
    }
    int ret = 0;
    int base = 1;
    for(int i = 1; i < s.size(); i++)
    {
        base *= 10;
    }
    for(int i = 0; i < s.size(); i++)
    {
        ret += base * (s[i]-'0');
        base/=10;
    }
    return ret;
}
int firstD(int n)
{

    if(n < 10) return n;
    int temp = n;
    string s = "";
    while(temp > 0)
    {
       
        s += (temp%10) + '0';
        temp /= 10;
    }

    return s[s.size()-1] - '0';
}

int MIN[1000001];

void set(int n)
{
    if(n < 10) 
    {
        MIN[n] = n;
        return;
    }
    if(n % 10 == 0)
    {
        MIN[n] = MIN[n-1] + 1; 
        return;
    }
    int t = flip(n);
    if(t < n)
    {
         MIN[n] = min(MIN[t] + 1, MIN[n-1] + 1);   
         return;
    }
    else
    {
        int min = n;
        for(int i = n - (n%10); i < n; i++)
        {
            min <?= MIN[i] + (n-i);
        }
        MIN[n] = min;
    }
}

int main()
{
  ifstream in;
  in.open("in.txt");
  ofstream out;
  out.open("out.txt");
  long long  T, N;
  in >> T;
  memset(MIN, 0, sizeof(MIN));
  for(int i = 0; i <= 1000000; i++)
  {
     set(i);      
  }
  
  for (int k = 1; k <= T; k++)
  {
        in >> N;
        out << "Case #" << k << ": " << MIN[N]<< endl;   
  }
  out.close();
  in.close();

}

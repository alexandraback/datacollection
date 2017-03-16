#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream in("abc.txt");
    ofstream out("b.txt");
       int t,tt=1;
       in >> t;
       while(t--)
       {
           int n;
           string s;
           in >> n >> s;
             int ans = 0 ;
             int val = (s[0]-'0');
           for(int i = 1 ; i <= n ; ++i ){
                if(s[i] != '0')
                    {
            if(val >= i )
               val+=(s[i]-'0');
               else{
                 ans+=(i-val);
                 val+=(i-val);
                 val+=(s[i]-'0');
                 }
           }
           }
                 out << "Case #"<<tt++<<": "<<ans << endl;
       }
       return 0;

}

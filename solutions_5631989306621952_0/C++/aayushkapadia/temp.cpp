#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d\n",&t);
  for(int gh=1;gh<=t;gh++)
  {
    string str;
    cin>>str;

        string newOne="";
        for(int i=0;i<str.length();i++)
        {
          if(i==0)
          {
            newOne+=str[i];
            continue;
          }
          //cout<<newOne<<endl;
          if(str[i]<newOne[0])
            newOne+=str[i];
          else if(str[i]>newOne[0])
            newOne=str[i]+newOne;
          else
          {
            string temp1 = newOne + str[i];
            string temp2 = str[i] + newOne;
            newOne = max(temp1,temp2);
            }

        }
        cout<<"Case #"<<gh<<": "<<newOne<<endl;

  }
  return 0;
}

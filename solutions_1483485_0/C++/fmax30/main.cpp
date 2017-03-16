#include <iostream>

#include <string>
#include <cstdio>
#include <cstdlib>


using namespace std;
char convert(char c)
{
    switch(c)
    {
        case'a':
        return 'y';
        break;
        case 'b':
        return 'h';
        break;
       case 'c':
        return 'e';
        break;
      case  'd':
        return 's';
        break;
       case 'e':
        return 'o';
        break;
        case'f':
        return 'c';
        break;
       case  'g':
        return 'v';
        break;
       case 'h':
        return 'x';
        break;
       case 'i':
        return 'd';
        break;
       case 'j':
        return 'u';
        break;
       case 'k':
        return 'i';
        break;
       case 'l':
        return 'g';
        break;
       case 'm':
        return 'l';
        break;
       case 'n':
        return 'b';
        break;
       case 'o':
        return 'k';
        break;
       case 'p':
        return 'r';
        break;
      case  'q':
        return 'z';
        //
        break;
       case 'r':
        return 't';
        break;
       case 's':
        return 'n';
        break;
       case 't':
        return 'w';
        break;
       case 'u':
        return 'j';
        break;
       case 'v':
        return 'p';
        break;
        case'w':
        return 'f';
        break;
       case 'x':
        return 'm';
        break;
        case'y':
        return 'a';
        break;
       case 'z':
        return 'q';
        ////
        break;



    }


}
void run (string &s,int t)
{
    for ( int i=0 ; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        s[i]=convert(s[i]);

    }
    cout<<"Case #"<<t+1<<": "<<s<<endl;


}
int main()
{
    int T=0;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>T;
    cin.get();

    for ( int i=0 ;i <T ; i++ )
    {
        string s ;
        getline(cin,s,'\n');
        run(s,i);


    }
    return 0;
}

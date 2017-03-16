#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    char c[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    char a[101],x;
    int t,q,l,i;
    cin>>t;
    cin.getline(a,100);
    for(q=1;q<=t;q++)
    {
        scanf("%[^\n]",a);
        scanf("%c",&x);
        l=strlen(a);
        cout<<"Case #"<<q<<": ";
        for(i=0;i<l;i++)
        {
            if(a[i]==' ')
               cout<<' ';
            else
                cout<<c[a[i]-97];
        }
        cout<<endl;
    }
}            
    

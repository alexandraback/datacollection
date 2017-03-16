#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    int cont;
    char vet[]={"yhesocvxduiglbkrztnwjpfmaqsd"};
    cin>>cont;
    char g[102];
    cin.getline(g,101);
    for(int i=0;i<cont;i++)
    {
        cin.getline(g,101);
        cout<<"Case #"<<i+1<<": ";
        for(int j=0;j<strlen(g);j++)
        {
            if(g[j]==' ')cout<<' ';
            else
                cout<<vet[g[j]-'a'];
        }
        cout<<endl;
    }
    return 0;
}

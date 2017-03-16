#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char change[27]={'y','h','e','s','o','c','v','x',
    'd','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q',' '};
    int n;
    char original[101];
    ifstream in("be1.in");
    ofstream out("output.txt");
    register int counter,j;
    in>>n;
    in.getline(original,101);
    for(counter=1;counter<=n;counter++){
              in.getline(original,101); original[100]='\0';
              out<<"Case #"<<counter<<": ";
              j=0;
              while(original[j]!='\n' && original[j]!='\0'){
                                      if (original[j]==' ') out<<' ';
                                      else out<<change[original[j]-'a'];
                                      j++;
              }
              out<<endl;                       
    }
    return 0;
}

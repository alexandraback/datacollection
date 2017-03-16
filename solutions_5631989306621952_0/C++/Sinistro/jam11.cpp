// jam11

#include <iostream>
#include <string>
using namespace std;

void insere(string& a, char b)
{
  a.push_back('q');
  for(int i =a.size()-1 ; i > 0; i--)
  {
    a[i] = a[i-1];
  }
  a[0] = b;
}

int main()
{
  int num;
  cin >> num;
  for(int i = 0; i < num; i++)
  {
    string linha, processado;
    cin >> linha;
    processado.push_back(linha[0]);
    for(int i = 1; i < linha.size(); i++)
    {
      if(processado[0] <= linha[i])
        insere(processado,linha[i]);
      else
        processado.push_back(linha[i]);
    }
    cout << "Case #" << i+1 << ": " << processado << "\n";
  }

}

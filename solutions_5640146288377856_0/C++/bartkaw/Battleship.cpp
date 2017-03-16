#include<iostream>
using namespace std;
void zadanie()
{
	int a, s, d;
	cin>>a>>s>>d;
	int wynik=a*(s/d)+d-1;
	if(s%d!=0)
		wynik++;
	cout<<wynik;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int z;
	cin>>z;
	for(int i=1; i<z+1; i++)
	{
		cout<<"Case #"<<i<<": ";
		zadanie();
		cout<<endl;
	}
	return 0;
}

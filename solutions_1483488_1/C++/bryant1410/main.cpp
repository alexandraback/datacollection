#include <iostream>
using namespace std;

void sigReciclado(char* &N)
{
	int largo = strlen(N);
	char temp = N[0];
	for(int j=0;j<largo-1;j++)
		N[j] = N[j+1];
	N[largo-1] = temp;
}

int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		int A, B, y;
		cin >> A >> B;
		y=0;
		for(int j=A;j<=B;j++)
		{
			char *J = new char[12];
			itoa(j, J, 10);
			char *rec = new char[12];
			itoa(j, rec, 10);
			sigReciclado(rec);
			while(strcmp(rec, J)!=0)
			{
				if(atoi(rec)>=A && atoi(rec)<=B)
					y++;
				sigReciclado(rec);
			}
			delete [] J;
			delete [] rec;
		}
		y /= 2; // Porque los cuenta 2 veces c/u.
		cout << "Case #" << i << ": " << y << endl;
	}
	return 0;
}

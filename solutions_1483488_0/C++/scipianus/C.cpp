#include<fstream>
#include<vector>
using namespace std;
int T,st,dr;
vector <int> verif;

inline int Rezolvare()
{
	int i,j,k,aux,size,lim,save;
	int v[20],sol=0;
	bool gasit;
	vector <int>::iterator it;
	for(i=st;i<=dr;i++)
	{
		aux=i;
		size=0;
		while(aux)
		{
			aux/=10;
			size++;
		}
		aux=i;
		save=size;
		while(aux)
		{
			v[size]=aux%10;
			size--;
			aux/=10;
		}
		size=save;
		for(j=1;j<=size;j++)
			v[j+size]=v[j];
		for(j=2;j<=size;j++)
		{
			aux=0;
			lim=j+size-1;
			for(k=j;k<=lim;k++)
				aux=aux*10+v[k];
			if(aux>i && aux>=st && aux<=dr)
			{
				gasit=false;
				for(it=verif.begin();it!=verif.end() && !gasit;it++)
				{
					if(*it==aux)
						gasit=true;
				}
				if(!gasit)
				{
					sol++;
					verif.push_back(aux);
				}
			}
		}
		verif.clear();
	}
	return sol;
}

int main()
{
	int t;
	ifstream fin("C.in");
	ofstream fout("C.out");
	fin>>T;
	for(t=1;t<=T;t++)
	{
		fin>>st>>dr;
		fout<<"Case #"<<t<<": "<<Rezolvare()<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}

#include <cstdio>
#include <iostream>

using namespace std;

int MAXGENTE = 20;
int LIMITE_DIAS = 1000000;
int pared[600];

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int cont = 0;
		for(int i=0;i<600;i++)
		{
			pared[i] = 0;
		}
		int N;
		cin>>N;
		int proximoAtacante = 0;
		int d[MAXGENTE], n[MAXGENTE], w[MAXGENTE], e[MAXGENTE], s[MAXGENTE], delta_d[MAXGENTE], delta_p[MAXGENTE], delta_s[MAXGENTE];
		for(int i=0;i<N;i++)
		{
			cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>delta_d[i]>>delta_p[i]>>delta_s[i];
			w[i] += 300;
			e[i] += 300;
			if(d[i] <= d[proximoAtacante]) proximoAtacante = i;
		}
		
		d[N] = LIMITE_DIAS;
		cont = 0;
		while(d[proximoAtacante] < LIMITE_DIAS)
		{
			bool exitoso = false;
			for(int i=w[proximoAtacante]; i<e[proximoAtacante]; i++)
			{
				if(pared[i] < s[proximoAtacante])
				{
					exitoso = true;
					pared[i] = s[proximoAtacante];
				}
			}
			if(exitoso) cont++;
			d[proximoAtacante] += delta_d[proximoAtacante];
			w[proximoAtacante] += delta_p[proximoAtacante];
			e[proximoAtacante] += delta_p[proximoAtacante];
			n[proximoAtacante]--;
			if(n[proximoAtacante] <= 0) d[proximoAtacante] = LIMITE_DIAS;
			s[proximoAtacante] += delta_s[proximoAtacante];
			for(int i=0;i<=N;i++)
			{
				if(d[i] <= d[proximoAtacante] && n[i] > 0) proximoAtacante = i;
			}
		}
		cout<<"Case #"<<t+1<<": "<<cont<<endl;
	}
}

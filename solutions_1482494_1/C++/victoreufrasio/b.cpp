#include<iostream>

using namespace std;

int a[2000];
int b[2000];
int marc1[2000];
int marc2[2000];

int N;
int stars;
int completes;

int possivel_dois()
{
	for(int i=0; i<N; i++)
	{
		if(marc2[i]==0 && b[i]<= stars)
		{
			marc2[i] = 1;
			completes++;
			if(marc1[i] == 0) stars++;
			stars++;
			return true;
		}
	}
	return false;
}

int possivel_um()
{
	int possivel = -1;
	
	for(int i=0; i<N; i++)
	{
		if(marc1[i]==0 && marc2[i]==0 && a[i]<=stars && (possivel==-1 || b[i]>b[possivel]))
		{
			possivel = i;
		}
	}
	
	if(possivel >=0)
	{
		marc1[possivel] = 1;
		completes++;
		stars++;
		return true;
	}
	return false;	
}

int main()
{
	int T;
	cin >> T;
	int teste = 1;
	
	int saved_stars;
	
	while(teste <= T)
	{
		stars = saved_stars = 0;
		completes = 0;
		
		cin >> N;
		for(int i=0; i<N; i++)
		{
			marc1[i] = 0;
			marc2[i] = 0;
			cin >> a[i];
			cin >> b[i];
		}
		
		//here we solve the problem
		while(possivel_dois());
		possivel_um();
		
		while(saved_stars != stars)
		{
			saved_stars = stars;
			while(possivel_dois());
			possivel_um();
		}
		cout << "Case #" << teste++ << ": ";
		if(stars == 2*N)
		{
			cout << completes << endl;
		}
		else
		{
			cout << "Too Bad" << endl;
		}
		
	}
	
	return 0;
}
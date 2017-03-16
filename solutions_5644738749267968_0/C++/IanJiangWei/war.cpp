#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>
using namespace std;

bool compare1(float a,float b)
{
	return a<b; 
}

bool compare2(float a,float b)
{
	return a>b;  //½µÐò
}

void output(float *f,int length)
{
	for (int i=0;i<length;i++)
	{
		cout<<f[i]<<' ';
	}
	cout<<endl;
	cout<<endl;
}

int deal(float *k_f,float *n_f,int length)
{
	sort(k_f,k_f+length,compare2);
	sort(n_f,n_f+length,compare1);
	output(k_f,length);
	output(n_f,length);
	int num_win=length;

	int n_start=0,n_end=length-1;
	int k_start=0,k_end=length-1;
	while(n_start<=n_end)
	{
		if (n_f[n_start]>k_f[k_start])
		{
			n_start++;
			k_start++;
			continue;
		}
		else
		{
			n_end--;
			n_start++;
			num_win--;
		}
	}
	
	return num_win;
}

int no_deal_cheat(float *k_f,float *n_f,int length)
{
	sort(n_f,n_f+length,compare2);
	sort(k_f,k_f+length,compare2);
	output(k_f,length);
	output(n_f,length);
	list<float> k_f_l(k_f,k_f+length);
	list<float> n_f_l(n_f,n_f+length);
	int nun_win=0;
	for (list<float>::iterator it_n=n_f_l.begin();it_n!=n_f_l.end();it_n++)
	{
		for (list<float>::iterator it_k=k_f_l.begin();it_k!=k_f_l.end();it_k++)
		{
			if ((*it_k)>(*it_n))
			{
				nun_win++;
				k_f_l.erase(it_k);
				break;
			}
		}
	}

	return nun_win;
}

int main()
{
	int num_data;
	ifstream infile("D-small-attempt4.in");
	ofstream outfile("Dr.txt");
	infile>>num_data;
	for (int i=0;i<num_data;i++)
	{
		int num_kn;
		infile>>num_kn;
		float *k_f=new float[num_kn];
		float *n_f=new float[num_kn];
		for (int i=0;i<num_kn;i++)
		{
			infile>>n_f[i];
		}
		for (int i=0;i<num_kn;i++)
		{
			infile>>k_f[i];
		}
		outfile<<"Case #"<<i+1<<": "<<no_deal_cheat(n_f,k_f,num_kn)<<" "<<num_kn-no_deal_cheat(k_f,n_f,num_kn)<<endl;
		delete []n_f;
		delete []k_f;
	}
	outfile.close();
	infile.close();
	return 0;
}
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

void main()
{
	ofstream out("A.out");
	ifstream in("A.in");
	int T,t;
	char G[101];
	char table[]={'y','h','e','s','o','c','v','x','d','u','i','g','l',
					'b','k','r','z','t','n','w','j','p','f','m','a','q'};

//	in>>T;
	in.getline(G,101);
	sscanf(G,"%d",&T);

	for(t=1;t<=T;t++)
	{
		int i;
		in.getline(G,101);
		for(i=0; G[i]; i++)
			if(G[i] >= 'a' && G[i] <='z')
				G[i] = table[G[i]-'a'];

		out<<"Case #"<<t<<": "<<G<<endl;
	}

	in.close();
	out.close();
}


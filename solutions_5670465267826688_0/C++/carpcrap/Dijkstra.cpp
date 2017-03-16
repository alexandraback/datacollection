#include <iostream>
#include <string>

using namespace std;

	char ret[10000][10000];
	bool n[10000][10000];
int main()
{
	char table[259][259];
	bool neg[259][259];

	table['1']['1'] = '1'; neg['1']['1'] = false;
	table['1']['i'] = 'i'; neg['1']['i'] = false;
	table['1']['j'] = 'j'; neg['1']['j'] = false;
	table['1']['k'] = 'k'; neg['1']['k'] = false;

	table['i']['1'] = 'i'; neg['i']['1'] = false;
	table['i']['i'] = '1'; neg['i']['i'] = true;
	table['i']['j'] = 'k'; neg['i']['j'] = false;
	table['i']['k'] = 'j'; neg['i']['k'] = true;

	table['j']['1'] = 'j'; neg['j']['1'] = false;
	table['j']['i'] = 'k'; neg['j']['i'] = true;
	table['j']['j'] = '1'; neg['j']['j'] = true;
	table['j']['k'] = 'i'; neg['j']['k'] = false;

	table['k']['1'] = 'k'; neg['k']['1'] = false;
	table['k']['i'] = 'j'; neg['k']['i'] = false;
	table['k']['j'] = 'i'; neg['k']['j'] = true;
	table['k']['k'] = '1'; neg['k']['k'] = true;
	int T = 0;
	cin >> T;
	for(int i=1; i<=T; i++)
	{
		int L,X;
		bool ok = false;
		cin >> L >> X;
		string s;
		cin >> s;

//printf("L: %d X: %d S: %s. s.len: %d\n", L, X, s.c_str(), s.length());
		// choose [1 to L]x[0-3]

		//preprocess
		for(int st = 0; st < L; st++)
		{
			ret[st][st] =s[st];
			n[st][st] = false;
			int prev = st;
			for(int en = (st +1) % L; en!=st; en++, en%=L)
			{
				ret[st][en] = table[ret[st][prev]][s[en]];
				n[st][en] = neg[ret[st][prev]][s[en]] ^ n[st][prev];
				prev = en;
			}
			//ret[st][st] = table[ret[st][prev]][s[st]];
			//n[st][st] = neg[n[st][prev]][s[en]] ^ n[st][prev];
		}

//printf("%d %d %c %d\n", n[0][1], false ^ true, ret[0][L-1], n[0][L-1]);
		// end of first string
		for(int b = 0; b<L; b++)
		{
			char firstPartial = ret[0][b];
			bool firstSign = n[0][b];
			int u = 0;
			for(; u<4 && u<X; u++)
			{
//printf("i check: %d %c %d\n", b, firstPartial, firstSign);
				if(firstPartial == 'i' && !firstSign) break;
				firstSign = n[0][L-1] ^ firstSign ^ neg[ret[0][L-1]][firstPartial];
				firstPartial = table[ret[0][L-1]][firstPartial];
			}
			if(u<4 && u<X)
			{
				X-=u;
				if(b==L-1) X--;
			}
			else continue;

//printf("i : %d u: %d\n", b,u);
			//start of third string
			for(int c = 0; c<L; c++)
			{
				char thirdPartial = ret[c][L-1];
				char thirdSign = n[c][L-1];
				int v = 0;
				for(; v<4 && v<X; v++)
				{
					if(thirdPartial == 'k' && !thirdSign) break;
					thirdSign = thirdSign ^ n[0][L-1] ^ neg[thirdPartial][ret[0][L-1]];
					thirdPartial = table[thirdPartial][ret[0][L-1]];
				}
				if(v<4 && v<X)
				{
					X-=v;
					if(c==0) X--;
				}
				else continue;

//printf("k: %d v: %d X: %d\n", c, v, X);
				// try second string
				if((b+1)%L >(c+L-1)%L) X--;
				X--;
				if( X>=0){
				int z=X %4;
				char secondPartial = ret[(b+1)%L][(c+L-1)%L];
				char secondSign = n[(b+1)%L][(c+L-1)%L];
				for(int k=1;k<=z;k++)
				{
					secondSign = secondSign ^ n[c][(c+L-1)%L] ^ neg[secondPartial][ret[c][(c+L-1)%L]];
					secondPartial = table[secondPartial][ret[c][(c+L-1)%L]];
				}
//printf("X: %d\n", X);	
//printf("j check: %c %d\n", secondPartial, secondSign);
				if(secondPartial == 'j' && !secondSign) ok = true;
				}

				X++;
				if((b+1)%L>(c+L-1)%L) X++;
				X+=v;
				if(c==0) X++;
			}

			X+=u;
			if(b==L-1) X++;
		}

		printf("Case #%d: %s\n", i, ok?"YES":"NO");
	}
}

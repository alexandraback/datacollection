#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string>
using std::vector;
using std::string;

bool is_state_win(const vector<string>& state,size_t size,char user)
{
	vector<bool> row(size,true),col(size,true),diagonal(2,true);
	for(size_t i = 0;i < size;++i)
	{
		for(size_t k = 0;k < size;++k)
		{
			char c = state[i][k];
			if(c == user || c == 'T') continue;
			row[i] = false;
			col[k] = false;
			if(i == k) diagonal[0] = false;
			if(i + k + 1 == size) diagonal[1] = false;
		}
	}
	bool ret = diagonal[0]|diagonal[1];
	for(size_t i = 0;i < size;++i) ret |= row[i];
	for(size_t i = 0;i < size;++i) ret |= col[i];
	return ret;
}

int main()
{
	static const size_t result_count = 4;
	char* results[result_count] = { "X won","O won","Draw","Game has not completed" };

	static const size_t maxlen = 4;
	char buff[maxlen+1] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		size_t xcount = 0,ocount = 0,ecount = 0;
		vector<string> state(maxlen);
		for(unsigned int i = 0;i < maxlen;++i)
		{
			scanf("%s",buff);
			state[i] = buff;
			for(unsigned int k = 0;k < maxlen;++k)
			{
				xcount += ('X' == buff[k]);
				ocount += ('O' == buff[k]);
				ecount += ('.' == buff[k]);
			}
		}

		unsigned int ans = 0;
		if(is_state_win(state,maxlen,'X')) ans = 0;
		else if(is_state_win(state,maxlen,'O')) ans = 1;
		else if(0 == ecount) ans = 2;
		else ans = 3;

		printf("Case #%u: %s\n",iCases,results[ans]);
	}
	return 0;
}
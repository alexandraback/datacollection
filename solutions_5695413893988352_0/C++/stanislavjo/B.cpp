#include <iostream>

long long p10(long long a)
{
	long long res = 1;
	for(long long i = 0;i < a;++ i)
		res *= 10;
	return res;
}

long long value(std::string& s)
{
	long long c = 0;
	for(int k = 0;k < s.size();++ k)
	{
		c *= 10;

		if(s[k] >= '0' and s[k] <= '9')
			c += s[k] - '0';
	}
	return c;
}

struct Res {
	long long nc, nj, diff;
};

Res findBest(int i, std::string& C, std::string& J)
{
	long long c = value(C), j = value(J);

	long long nc = 0, nj = 0, minDiff = c<j?j-c:c-j;
	long long rc = 0, rj = 0;
	long long power = p10(C.size() - i - 1);
	if(C[i] != '?' and J[i] != '?')
		return {C[i] - '0', J[i] - '0', 0};
	if(C[i] == '?' and J[i] == '?')
	{
		for(;nc < 10;++ nc)
		{
			for(nj = 0;nj < 10;++ nj)
			{
				long long _c = c + power * nc;
				long long _j = j + power * nj;
				long long diff = _c<_j?_j-_c:_c-_j;
				if(diff < minDiff)
				{
					minDiff = diff;
					rc = nc;
					rj = nj;
				}
			}
		}
		return {rc, rj, minDiff};
	}
	if(C[i] == '?' and J[i] != '?')
	{
		nj = J[i] - '0';
		rj = nj;
		for(;nc < 10;++ nc)
		{
			long long _c = c + power * nc;
			long long _j = j;
			long long diff = _c<_j?_j-_c:_c-_j;
			if(diff < minDiff)
			{
				minDiff = diff;
				rc = nc;
				rj = nj;
			}
		}
		return {rc, rj, minDiff};
	}
	if(C[i] != '?' and J[i] == '?')
	{
		nc = C[i] - '0';
		rc = nc;
		for(;nj < 10;++ nj)
		{
			long long _c = c;
			long long _j = j + power * nj;
			long long diff = _c<_j?_j-_c:_c-_j;
			if(diff < minDiff)
			{
				minDiff = diff;
				rc = nc;
				rj = nj;
			}
		}
		return {rc, rj, minDiff};
	}

}

int main()
{
	int t;
	std::cin >> t;

	std::string first, second;
	for(int _ = 0;_ < t;++ _)
	{
		int res = 0;
		std::string C, J, oC, oJ;
		std::cin >> C >> J;
		oC = C;
		oJ = J;

		for(int i = 0;i < C.size();++ i)
		{
 			if(C[i] == '?' or J[i] == '?')
			{
			auto best = findBest(i, C, J);
			char cib = 0, jib = 0;

			if(i > 0)
			{
				if(oC[i-1] == '?')
				{
					if(C[i-1] > '0')
					{
						C[i-1] --;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						C[i-1] ++;
					}
					if(C[i-1] < '9')
					{
						C[i-1] ++;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						C[i-1] --;
					}
				}
				if(oJ[i-1] == '?')
				{
					if(J[i-1] > '0')
					{
						J[i-1] --;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						J[i-1] ++;
					}
					if(J[i-1] < '9')
					{
						J[i-1] ++;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						J[i-1] --;
					}
				}
				if(oC[i-1] == '?' and oJ[i-1] == '?')
				{
					if(C[i-1] > '0' and J[i-1] > '0')
					{
						C[i-1] --;
						J[i-1] --;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						C[i-1] ++;
						J[i-1] ++;
					}
					if(C[i-1] > '0' and J[i-1] < '9')
					{
						C[i-1] --;
						J[i-1] ++;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						C[i-1] ++;
						J[i-1] --;
					}
					if(C[i-1] < '9' and J[i-1] > '0')
					{
						C[i-1] ++;
						J[i-1] --;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						C[i-1] --;
						J[i-1] ++;
					}
					if(C[i-1] < '9' and J[i-1] < '9')
					{
						C[i-1] ++;
						J[i-1] ++;
						auto b2 = findBest(i, C, J);
						if(b2.diff < best.diff)
						{
							best = b2;
							cib = C[i-1];
							jib = J[i-1];
						}
						C[i-1] --;
						J[i-1] --;
					}
				}
			}

			C[i] = best.nc + '0';
			J[i] = best.nj + '0';
			if(i > 0 and cib != 0)
				C[i-1] = cib;
			if(i > 0 and jib != 0)
				J[i-1] = jib;
			}

			//std::cout << C << ' ' << J << std::endl;
		}
		std::cout << "Case #" << _+1 << ": " << C << ' ' << J << std::endl;
	}
	return 0;
}

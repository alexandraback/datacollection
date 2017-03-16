#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char *argv[])
{		
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen((argv[1] + std::string(".out")).c_str(), "w");

	int T;
	fscanf(in, "%d", &T);
	for (int x = 1; x <= T; ++x)
	{
		fprintf(out, "Case #%d: ", x);
		int y = 0;
		int t = 0;
		int s;
		fscanf(in, "%d", &s);
		std::vector<int> shy(s + 1);
		for (auto it = shy.begin(); it != shy.end(); ++it)
		{
			fscanf(in, "%1d", &*it);
		}
		for (int k = 0; k <= s; ++k)
		{
			if (t < k)
			{
				y += k - t;
				t = k;
			}
			t += shy[k];
		}
		fprintf(out, "%d\n", y);
	}

	fclose(in);
	fclose(out);
}
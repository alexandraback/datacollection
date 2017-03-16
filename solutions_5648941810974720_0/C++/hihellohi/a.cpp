#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	int t;
	scanf("%d\n",&t);
	for(int n = 1; n <= t; n++){
		printf("Case #%d: ", n);
		int *buffer = (int*)calloc(300, sizeof(int));
		for(int i = getchar(); i != '\n'; i = getchar()){
			buffer[i]++;
		}
		char *output = (char*)calloc(2005, sizeof(char));
		int i = 0;
		memset(output + i, '6', buffer['X']);
		i += buffer['X'];
		buffer['S'] -= buffer['X'];
		buffer['I'] -= buffer['X'];

		memset(output + i, '7', buffer['S']);
		i += buffer['S'];
		buffer['V'] -= buffer['S'];
		buffer['N'] -= buffer['S'];

		memset(output + i, '0', buffer['Z']);
		i += buffer['Z'];
		buffer['R'] -= buffer['Z'];

		memset(output + i, '8', buffer['G']);
		i += buffer['G'];
		buffer['I'] -= buffer['G'];


		memset(output + i, '2', buffer['W']);
		i += buffer['W'];

		memset(output + i, '5', buffer['V']);
		i += buffer['V'];
		buffer['I'] -= buffer['V'];
		buffer['F'] -= buffer['V'];

		memset(output + i, '9', buffer['I']);
		i += buffer['I'];
		buffer['N'] -= buffer['I']*2;

		memset(output + i, '1', buffer['N']);
		i += buffer['N'];

		memset(output + i, '4', buffer['F']);
		i += buffer['F'];
		buffer['R'] -= buffer['F'];
		memset(output + i, '3', buffer['R']);
		i += buffer['R'];
		sort(output, output+i);
		printf("%s\n", output);
		free(buffer);
		free(output);
	}
	return 0;
}

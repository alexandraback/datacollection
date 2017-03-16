#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> letters;

/*typedef struct pair {
	int subbegin;
	int subend;

} Pair;*/

//typedef struct pair Pair;

__int64 solve(string str, int num) {
	//vector<Pair> substrs;
	int count = 0;
	int firsttime = 0;
	int flag = 0;
	int i = 0, j;
	int begin = 0;
	int end;
	int len = str.length();
	while (i < len) {
		if (letters.find(str[i])->second != 0 ) {
			flag++;
			
			if (flag == num) {
				if (firsttime == 0) {
					firsttime++;
					end = i;
					count += (end - begin - num + 2) * (len - end);
					begin = end - num + 2;
					flag--;
				}
				else
				{
					end = i;
					count += (end - begin - num + 2) * (len - end);
					begin = end - num + 2;
					flag--;
				}
			}
		}
		else {
			flag = 0;
		}
		i++;
			
			
	}
	return count;
}

int main()
{
    int T,Case;
	FILE *in,*out;
	char str[1000002];
	//string str;
	int num;
	__int64 nvalue;
	char count = 'a';
	while (count <= 'z') {
		if (count != 'a' && count != 'e' && count != 'i' && count != 'o' && count != 'u')
			letters.insert(std::pair<char, int>(count, 1));
		else
			letters.insert(std::pair<char, int>(count, 0));
		count++;
	}
	in = fopen("A-large.in","r");
	out = fopen("out.txt","w");

    fscanf(in,"%d",&T);
    Case = 1;
    while(Case<=T)
    {
		if (Case > 1)
			fprintf(out, "\n");
		//total = 0;
		//target = 0;
		fscanf(in,"%s%d",&str,&num);
		string str_s(str);
		nvalue = solve(str_s, num);
		fprintf(out,"Case #%d: %d",Case, nvalue);
		Case++;
    }

    return 0;
}
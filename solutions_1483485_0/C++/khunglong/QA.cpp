#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define file_in "A-small-attempt0.in"
#define file_out "QA.out"

//abcdefghijklmnopqrstuvwxyz
//ynficwlbkuomxsevzpdrjgthaq

int main()
{
    int T;
    FILE *f;
    f = fopen(file_in, "r");
    fscanf(f, "%d", &T);
    fclose(f);

    f = fopen(file_out, "w");
    
	ifstream ifs(file_in);
  	string st;
  	string s = "yhesocvxduiglbkrztnwjpfmaq";
  	
  	getline(ifs, st);   //skip this line

  	for (int i=0; i<T; i++)
  	{
		getline(ifs, st);
		for (int j=0; j<st.length(); j++)
		{
			if (st[j]!=32)
			{
                st[j]=s[st[j]-97];
			}
		}
		fprintf(f, "Case #%d: %s\n", i+1, st.c_str());
  	}
  	fclose(f);
}

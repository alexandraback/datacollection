#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

#define file_in "D-small-attempt1.in"
//#define file_in "Q4.in"
#define file_out "Q4.out"
#define MAXT 20

int test;          /* # of test case */
FILE *fi;
FILE *fo;

int k, n;
int key[MAXT+1];  //the key you have. key[i]= x means you have x keys of type i
int chest[MAXT+1][MAXT+1]; //what inside chest[j]
int openchest[MAXT+1];
bool o[MAXT+1];
int order[MAXT+1];
bool all_opened, time_elapsed;

clock_t end;

bool precheck()
{
	//check how many chest need to open by key 1, 2, 3...
	int i, j;
	int need[MAXT+1];
	int avai[MAXT+1];
	bool ok;
	
	for (i=0; i<=MAXT; i++)
	{
		need[i] = 0;
		avai[i] = key[i];
	}
		
    //if need key i to open chest j, but only check j has key i --> false
	for (i=0; i<n; i++)
	    if (!o[i])
	    {
			//the key to open this chest is openchest[i]
			//any other chest contains this key?
			if (avai[openchest[i]]>0) continue;
			
			ok = false;
			for (j=0; j<n; j++)
			    if ((j!=i)&&(!o[j]))
				{
                	if (chest[j][openchest[i]]>0)
                	{
						ok = true;  //so you may find a key to open chest[i]
						break;
                	}
				}
			if (!ok)
			{
				//cout<<i<<" "<<avai[1]<<" "<<avai[2]<<" "<<avai[3]<<endl;
				//cout<<n<<" "<<key[1]<<" "<<key[2]<<" "<<key[3]<<endl;
				//getch();
				return false;
			}
	    }


	//dem xem can bao nhieu khoa moi loai de mo cac ruong chua dc mo
	for (i=0; i<=MAXT; i++)
	    if (not o[i])
		{
			need[openchest[i]] += 1;
		}

	//tim xem trong dong ruong con lai co du so luong khoa de mo ko?
	for (i=0; i<=MAXT; i++)
	    if (not o[i])
		{
			for (j=1; j<=MAXT; j++)
			{
                avai[j] += chest[i][j];
			}
		}
/*
	for (i=1; i<=10; i++)
	    cout<<avai[i]<<" ";
	cout<<endl;

	for (i=1; i<=10; i++)
	    cout<<need[i]<<" ";
	cout<<endl;

	getch();
*/

	for (i=1; i<=MAXT; i++)
	{
		if (need[i] > avai[i]) return false;
	}
	
	return true;
}


int try2open(int n_opened)
{
	int i, j, h;
	if (n_opened==n)
	{
		//done, exit
		all_opened = true;
		return 0;
	}
	
	if (!precheck()) return 0;
/*
	if (clock() > end)
	{
        //time out, exit
		all_opened = true;
		time_elapsed = true;
		return 0;
	}
*/
	for (i=0; i<n; i++)
	{
		if (not o[i])   //chest i close
		{
			//do you have the key o open chest[i]
			for (j=0; j<=MAXT; j++)
			    if ((key[j]>0) && (openchest[i]==j)) //you can open chest[i]
			    {
					key[j]--;   //used this key
					o[i]=true;  //to open this chest
					for (h=0; h<=MAXT; h++)
					    key[h] += chest[i][h];  //you colect some more key
					order[n_opened] = i+1;
					
					try2open(n_opened+1);
					
					if (all_opened) break;
					
					key[j]++;
					o[i] = false;
					for (h=0; h<=MAXT; h++)
					    key[h] -= chest[i][h];
			    }
		}
		if (all_opened) break;
	}
	return 0;
}


int main() {
    int i, j, h, x, y;

    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);

    for (i=1; i<=test; i++)
    {
		cout<<i<<"/"<<test<<endl;
		
		for (j=0; j<=MAXT; j++)
		{
			key[j] = 0;
			o[j] = false;
			openchest[j] = 0;
			for (h=0; h<=MAXT; h++) chest[j][h]=0;
		}
		
		fscanf(fi, "%d %d", &k, &n);
		for (j=0; j<k; j++)
		{
			fscanf(fi, "%d", &x);
			key[x]++;
		}

		for (j=0; j<n; j++)
		{
			fscanf(fi, "%d %d", &openchest[j], &x); //x = number of key in the chest
			for (h=0; h<x; h++)
			{
			    fscanf(fi, "%d", &y);
				chest[j][y]++;
			}
		}

		fprintf(fo, "Case #%d: ", i);
		if (!precheck())
		{
            fprintf(fo, "IMPOSSIBLE\n");
		}
		else
		{
            all_opened = false;
            time_elapsed = false;
            
            end = clock() + 10 * CLOCKS_PER_SEC;
			try2open(0);


			if (all_opened && !time_elapsed)
			{
	            for (j=0; j<n-1; j++) fprintf(fo, "%d ", order[j]);
	            fprintf(fo, "%d\n", order[n-1]);
			}
			else
			    fprintf(fo, "IMPOSSIBLE\n");
		}
		
	}

    fclose(fi);
    fclose(fo);
}


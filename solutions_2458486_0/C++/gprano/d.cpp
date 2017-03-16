#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

#define DEBUG if(false) 

typedef unsigned long long ull;

int n;
ull keyring;
ull keys_of_chest[20];
ull content[20];
//data structure for the DFS
vector<int> order;
bool seen[1<<20];
//temporal data structure to get it from the input
int temp_type_of_key[40];
int temp_type_of_chest[20];
int nb_keys;

void print_bit(int bs)
{
    for(int i = 0; i < n; i++)
	printf("%d", (bool) (bs & (1<<i)));
    printf("\n");
}

void print_bit40(ull bs)
{
    for(int i = 0; i < 40; i++)
	printf("%d", (bool) (bs & ((ull)1<<i)));
    printf("\n");
}

bool explore(int open_mask)
{
    if(seen[open_mask])
	return false;
    seen[open_mask] = true;
    DEBUG printf("open and ring : \n");
    DEBUG print_bit(open_mask);
    DEBUG print_bit40(keyring);
    if(open_mask == (1<<n)-1)
    {
	//solution found
	for(vector<int>::iterator it = order.begin(); it != order.end(); it++)
	{
	    if(it != order.begin()) printf(" ");
	    printf("%d", *it + 1);
	}
	printf("\n");
	return true;
    }
    for(int i = 0; i < n; i++)
    {
	ull usable_keys = keyring & keys_of_chest[i];
	DEBUG printf("keys to open %d : ",i);
	DEBUG print_bit40(usable_keys);
	if(((open_mask & (1<<i)) == 0) && usable_keys)
	{
	    DEBUG printf("in\n");
	    ull key_used = (usable_keys & -usable_keys);
	    keyring = keyring - key_used + content[i];
	    order.push_back(i);
	    if(explore(open_mask + (1<<i)))
		return true;
	    order.pop_back();
	    keyring = keyring + key_used - content[i];
	}
    }
    return false;
}

ull insert(int new_key)
{
    temp_type_of_key[nb_keys] = new_key;
    nb_keys++;
    return (ull) 1<<(nb_keys-1);
}

int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	nb_keys = 0;
	keyring = 0;
	printf("Case #%d: ",cas);
	int k;
	scanf("%d%d",&k,&n);
	for(int i = 0; i < k; i++)
	{
	    int new_key;
	    scanf("%d",&new_key);
	    keyring += insert(new_key);
	}
	for(int i = 0; i < n; i++)
	{
	    content[i] = 0;
	    int ti,ki;
	    scanf("%d%d",&ti,&ki);
	    temp_type_of_chest[i] = ti;
	    for(int j = 0; j < ki; j++)
	    {
		int kj;
		scanf("%d",&kj);
		content[i] += insert(kj);
	    }
	}
	for(int i = 0; i < n; i++)
	{
	    keys_of_chest[i] = 0;
	    for(int j = 0; j < nb_keys; j++)
	    {
		if(temp_type_of_key[j] == temp_type_of_chest[i])
		    keys_of_chest[i] += (ull)(1<<j);
	    }
	}
	//data structures up to date
	order.clear();
	for(int i = 0; i < (1<<n); i++)
	    seen[i] = false;
	bool result = explore(0);
	if(!result)
	    printf("IMPOSSIBLE\n");	
    }
    return 0;
}

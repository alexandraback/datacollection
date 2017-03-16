#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

struct list_entry
{
	struct list_entry *prev, *next;
};

typedef struct list_entry link_list_t;

struct pair_node
{
	int val;
	link_list_t list;
};

link_list_t recycle[2000001];

void list_init(link_list_t *list)
{
	list->prev = list->next = list;
}

void list_add(link_list_t *list, int val)
{
	struct pair_node *node = (struct pair_node *)malloc(sizeof(struct pair_node));
	node->val = val;

	link_list_t *p = list->prev;
	(&(node->list))->next = list;
	list->prev = &(node->list);
	(&(node->list))->prev = p;
	p->next = &(node->list);
}

bool list_find(link_list_t *list, int val)
{
	link_list_t *le = list->next;
	for (; le != list; le = le->next)
	{
		struct pair_node * node = (struct pair_node *)(((uintptr_t)le) - offsetof(struct pair_node, list));
		if (node->val == val)	return true;
	}
	return false;
}

void list_free(link_list_t *list)
{
	link_list_t *le = list->next;
	link_list_t *free_le;
	while (le != list)
	{
		free_le = le;
		le = le->next;
		struct pair_node * node = (struct pair_node *)(((uintptr_t)free_le) - offsetof(struct pair_node, list));
		free(node);
	}
}

int
main(void)
{
	freopen("input", "r", stdin);
	freopen("out","w", stdout);

	int n, a, b;
	scanf("%d", &n);

	int i, j;

	for (i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		int count = 0;
		
		for (j = 0; j < 2000001; ++j)
		{
			list_init(&recycle[j]);
		}

		for (j = a; j <= b; ++j)
		{
			int pos = 10;
			int back = 0, front = 0;
			while ((front = j / pos) > 0)
			{
				int move = 1, t = front;
				while (t > 0)
				{
					move *= 10;
					t /= 10;
				}
				back = j % pos;
				int pair = back * move + front;
				if (pair <= b && pair >= a && pair != j && !list_find(&recycle[j], pair))
				{
					//printf("Pair (%d, %d)\n", j, pair);
					++count;
					list_add(&recycle[j],pair);
					list_add(&recycle[pair],j);
				}
				pos *= 10;
			}

		}

		for (j = 0; j < 2000001; ++j)
		{
			list_free(&recycle[j]);
		}

		printf("Case #%d: %d\n", i+1, count);
	}
	return 0;
}
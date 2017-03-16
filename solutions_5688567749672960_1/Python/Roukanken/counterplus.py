from functools import lru_cache

def reverse (x):
	return int("".join(reversed(str(x))))


@lru_cache(maxsize=None)
def solve (x):
	x = str(x)
	if len(x) == 1: return int(x)
	
	head, trail = x[:len(x)//2], int(x[len(x)//2:])
	head = int("".join(reversed(head)))

	if trail == 0: return solve(int(x) - 1) + 1
	return solve("9"*(len(x)-1)) + int(head) + int(trail) + 1 - (1 if head == 1 else 0)


for case in range(int(input())):
	print ("Case #{}: {}".format(case +1, solve(int(input()))))
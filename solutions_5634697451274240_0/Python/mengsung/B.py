
def solve():
	pancakes = input()
	
	happy = [0]
	blank = [0]
	
	for i, pancake in enumerate(pancakes):
		if pancake =='+':
			happy.append(happy[i])
			blank.append(happy[i] + 1)
		else:
			happy.append(blank[i] + 1)
			blank.append(blank[i])
	return happy[len(pancakes)]
		

if __name__ == '__main__':
	ncase = int(input())
	for i in range(ncase):
		print('Case #{}: {}'.format(i+1, solve()))

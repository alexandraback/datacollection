from math import ceil
import sys

def main():
	name, pathin, pathout = sys.argv

	filein = open(pathin)
	fileout = open(pathout,'w')

	total = int(filein.readline())
	results = []
	for case in range(total):
		K, C, S = [int(_) for _ in filein.readline().split()]
		results.append(solve(K,C,S))

	for case, result in enumerate(results):
		fileout.write('Case #%s: %s\n'%(case+1, result))



def getposition(li,k,c):
	def position(el, k, c):
		return pow(k, c-1)*(el-1)

	result = 1
	for el in li:
		el = int(el)
		result += position(el, k, c)
		c = c-1

	return str(result)

# def generate(pool, selected):
# 	if selected >= pool:
# 		selected = pool
# 	base = ''.join([str(i+1) for i in range(pool)])
# 	li = list(combinations(base, selected))

# 	return li

# def totalnumbers(pool, selected):
# 	if selected >= pool:
# 		return 1

# 	result = 1
# 	for i in range(selected):
# 		result *= pool
# 		result //= (i + 1)
# 		pool -= 1
# 	return result

def generate(pool, selected):
	if selected >= pool:
		return [[str(i+1) for i in range(pool)]]
	else:
		pool = [str(i+1) for i in range(pool)]
		size = len(pool)
		results = []
		if size % selected == 0:
			pass
		else:
			pool += '1'*(selected - size % selected)

		for i in range(len(pool)//selected):
			results.append(pool[i*selected: (i+1)*selected])
		return results

def totalnumbers(pool, selected):
	return ceil(pool/selected)


def solve(K, C, S):

	required = totalnumbers(K, C)
	if S < required:
		return 'IMPOSSIBLE'
	else:
		results = []
		lis = generate(K, C)
		for li in lis:
			results.append(getposition(li, K, C))

		return ' '.join(results)

if __name__ == '__main__':
	main()







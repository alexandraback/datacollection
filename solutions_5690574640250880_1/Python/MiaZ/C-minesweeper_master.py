from __future__ import print_function

def trans(mat):
	if mat == False:
		return False
	else:
		newmat = []
		row = len(mat)
		col = len(mat[0])
		for i in range(col):
			newmat.append([])
			for j in range(row):
				newmat[-1].append(mat[j][i])
		return newmat
		
def recurseFill(row,col,remain):	
	if row < col:
		return trans(recurseFill(col,row,remain))
	
	if row == 1:
		return [['.']]
	if row == 2:
		if col ==1:
			if remain == 1:
				return [['*'],['.']]
			else :
				return [['.'],['.']]
		else:
			if remain == 1 or remain == 2:
				return False
			elif remain == 3:
				return [['*','*'],['*','.']]
			else:
				return [['.','.'],['.','.']]
	if row == 3:
		if col == 1:
			if remain ==1:
				return [['*'],['.'],['.']]
			elif remain ==2:
				return [['*'],['*'],['.']]
			else:
				return [['.'],['.'],['.']]
		if col == 2:
			if remain == 1 or remain ==3 or remain ==4:
				return False
			elif remain ==2:
				return [['*','*']]+[['.','.']]+[['.','.']]
			elif remain ==5:
				return [['*','*']]+[['*','*']]+[['*','.']]
			else:
				return [['.','.'],['.','.'],['.','.']]
		if col == 3:
			if remain == 2 or remain ==4 or remain == 6 or remain == 7:
				return False
			elif remain == 1:
				return [['*','.','.']]+[['.','.','.']]+[['.','.','.']]
			elif remain == 3:
				return [['*','*','*'],['.','.','.'],['.','.','.']]
			elif remain == 5:
				return [['*','*','*']]+[['*','.','.']]+[['*','.','.']]
			elif remain ==8:
				return [['*','*','*']]+[['*','*','*']]+[['*','*','.']]
			else:
				return [['.','.','.'],['.','.','.'],['.','.','.']]
			
	if row > 3:
		if remain >= col:
			fill = col
		elif remain == col -1:
			fill = max(col -2,0)
		else:
			fill = remain
		remain -= fill
		add = ['*']*fill+['.']*(col-fill)
	
		res = recurseFill(row-1,col,remain)
		if res == False:
			return False
		else:
			return [add] + res

n = int(raw_input())
for i in range(n):
	print("Case #%d:"%(i+1))
	num = raw_input().split()
	row = int(num[0])
	col = int(num[1])
	mine = int(num[2])
	result = recurseFill(row,col,mine)
	if result == False:
		print('Impossible')
	else:
		result[-1][-1] = 'c'
		for j in range(row):
			for k in range(col):
				print(result[j][k],end ='')	
			print('')
	
def case():
	rows, columns = map(int, input().split())
	
	row_major = [ list(map(int,input().split())) for i in range(rows) ]
	
	column_major = [ [row_major[j][i] for j in range(rows)] for i in range(columns) ]
	
	row_max = [max(row) for row in row_major]
	column_max = [max(column) for column in column_major]
	
	#print(row_major)
	#print(column_major)
	#print(row_max)
	#print(column_max)
	
	for i in range(rows):
		for j in range(columns):
			if row_max[i] > row_major[i][j] and column_max[j] > row_major[i][j]:
				return "NO"
	
	return "YES"

	
for t in range(1,int(input())+1):
	print ( "Case #%d: %s" % (t,case()) )

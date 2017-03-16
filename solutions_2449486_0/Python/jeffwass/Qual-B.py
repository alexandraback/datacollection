from numpy import matrix

base = "B-small-attempt1"
f = open(base+'.in','r')
fout = open(base+'.out','w')

num = int(f.readline())
for case in range(1,num+1):
	prefix = "Case #" + str(case) + ": "
	l = f.readline()
	n,m = l.split()
	n = int(n)
	m = int(m)

	premat = []
	row_max = []
	col_max = []
	for i in range(0,n):
		row = map( lambda x: int(x), f.readline().split() )
		row_max.append( max(row) )
		if( len( col_max ) == 0 ):
			col_max = list( row )
		else:
			for j in range(0,m):
				el = row[j]
				if( el > col_max[j] ):
					col_max[j] = int( el )
		premat.append( row )

	Mowable = True
	for i in range(0,n):
		if( not Mowable ):
			break
		for j in range(0,m):
			if( premat[i][j] < row_max[i] and premat[i][j] < col_max[j] ):
				Mowable = False;
				break
	if( Mowable ):
		suffix = "YES"
	else:
		suffix = "NO"
	fout.write( prefix + suffix + "\n" )
	print(prefix + suffix)
	print(matrix(premat))
	print()

f.close
fout.close
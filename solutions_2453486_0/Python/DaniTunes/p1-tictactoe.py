import sys

def won(a):
    for k in range(4):
	if a[4*k:4*k+4] == 'TTTT':
	    return True
	if a[k::4] == 'TTTT':
	    return True
    if a[0::5] == 'TTTT':
	return True
    if a[3:-1:3] == 'TTTT':
	return True
    return False

data = sys.stdin.readlines()
n = int(data[0])
#print n
for i in range(n):
    k = 5*i+1
    a = "".join(data[k:k+4]).replace('\n','');
    print "Case #%d:" % (i+1),
    if won(a[:].replace('X','T')):
	print 'X won'
    elif won(a[:].replace('O','T')):
	print 'O won'
    elif a.count('.') == 0:
	print 'Draw'
    else:
	print 'Game has not completed'


def canblock(size,row,col):
	#row<=col
	if size==1:
		return False
	if not row*col%size==0:
		return True
	if size==2:
		return col<2 or row<1
	if size==3:
		return col<3 or row<2
	if size==4:
		return col<4 or row<3
	if size==5:
		if col<5 or row<3:
			return True
		if row==3:
			return col<10
		return False
	if size==6:
		if col<6 or row<4:
			return True
		return False
	# if size>=7:
	return True

T=int(raw_input())

for test in range(1,T+1):
	size,row,col=map(int, raw_input().split())
	if(row>col):
		temp=row
		row=col
		col=temp
	if canblock(size,row,col):
		print "Case #{0}: RICHARD".format(test)
	else:
		print "Case #{0}: GABRIEL".format(test)
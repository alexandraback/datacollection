T=input()
for t in xrange(1,T+1):
	x,r,c=map(int,raw_input().split())
	r,c=min(r,c),max(r,c)
	k=(r*c)/float(x)
	print "Case #%d:"%t,
	if(k!=int(k)):
		print "RICHARD"
	else:
		if(r==1 and c==1):
			if(x==1):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==1 and c==2):
			if(x==1 or x==2):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==1 and c==3):
			if(x==1):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==1 and c==4):
			if(x==1 or x==2):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==2 and c==2):
			if(x==1 or x==2):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==2 and c==3):
			if(x==1 or x==2 or x==3):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==2 and c==4):
			if(x==1 or x==2):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==3 and c==3):
			if(x==1 or x==3):
				print "GABRIEL"
			else:
				print "RICHARD"
		elif(r==3 and c==4):
			print "GABRIEL"
		elif(r==4 and c==4):
			if(x==1 or x==2 or x==4):
				print "GABRIEL"
			else:
				print "RICHARD"

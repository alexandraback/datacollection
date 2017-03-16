for t,T in enumerate(range(input())):
	s=raw_input()
	l=dict()
	
	l[0]=s.count("Z")
	l[2]=s.count("W")
	l[4]=s.count("U")
	l[6]=s.count("X")

	l[3]=s.count("R")-l[4]-l[0]
	l[7]=s.count("S")-l[6]
	
	l[1]=s.count("O")-l[0]-l[2]-l[4]	
	l[5]=s.count("V")-l[7]
	l[8]=s.count("H")-l[3]

	l[9]=s.count("I")-l[6]-l[8]-l[5]

	f=""
	for i in sorted(l.keys()):
		f+=str(i)*l[i]
	print "Case #%d: %s" % (t+1,f)

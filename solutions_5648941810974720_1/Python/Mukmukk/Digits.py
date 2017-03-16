

def takeamap(s):
	t={}
	for k in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
		t[k]=0
	for c in s:
			if c in t.keys():
				t[c]+=1
			else:
				t[c]=1			
			
	return t
	
f=open("A-large.in")



t=int(next(f))
for i in xrange(t):
	s=next(f)
	ma=takeamap(s[:-1])
	#----------------------
	N0=ma["Z"]
	ma["Z"]-=N0
	ma["E"]-=N0
	ma["R"]-=N0
	ma["O"]-=N0
	
	#----------------------
	N2=ma["W"]
	ma["T"]-=N2
	ma["W"]-=N2
	ma["O"]-=N2
	
	#----------------------
	N6=ma["X"]
	ma["S"]-=N6
	ma["I"]-=N6
	ma["X"]-=N6
	
	N7=ma["S"]
	ma["S"]-=N7
	ma["E"]-=2*N7
	ma["V"]-=N7
	ma["N"]-=N7
	
	
	N5=ma["V"]
	ma["F"]-=N5
	ma["I"]-=N5
	ma["V"]-=N5
	ma["E"]-=N5

	N8=ma["G"]
	ma["E"]-=N8
	ma["I"]-=N8
	ma["G"]-=N8
	ma["H"]-=N8
	ma["T"]-=N8
	
	N9=ma["I"]
	ma["N"]-=N9
	ma["I"]-=N9
	ma["N"]-=N9
	ma["E"]-=N9
	
	N1=ma["N"]
	ma["O"]-=N1
	ma["N"]-=N1
	ma["E"]-=N1
	
	N3=ma["T"]
	ma["T"]-=N3
	ma["H"]-=N3
	ma["R"]-=N3
	ma["E"]-=2*N3
	
	N4=ma["F"]
	ma["F"]-=N4
	ma["O"]-=N4
	ma["U"]-=N4
	ma["R"]-=N4
	
	
	print "Case #"+str(i+1)+":",N0*"0"+N1*"1"+N2*"2"+N3*"3"+N4*"4"+N5*"5"+N6*"6"+N7*"7"+N8*"8"+N9*"9"	
f.close()

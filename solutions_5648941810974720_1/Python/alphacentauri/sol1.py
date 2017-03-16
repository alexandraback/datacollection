from collections import Counter
def getValue(string):
	mapper=Counter(string)
	numcount=[0]*10
	if 'Z' in mapper:
		count=mapper['Z']
		numcount[0]=count
		mapper['Z']=mapper['Z']-count
		mapper['E']=mapper['E']-count
		mapper['O']=mapper['O']-count
	if 'X' in mapper:
		count=mapper['X']
		numcount[6]=count
		mapper['X']=mapper['X']-0
		mapper['S']=mapper['S']-count
		mapper['I']=mapper['I']-count
	if 'U' in mapper:
		count=mapper['U']
		numcount[4]=count
		mapper['U']=mapper['U']-count
		mapper['F']=mapper['F']-count
		mapper['O']=mapper['O']-count
		mapper['R']=mapper['R']-count
	if 'W' in mapper:
		count=mapper['W']
		numcount[2]=count
		mapper['W']=mapper['W']-count
		mapper['T']=mapper['T']-count
		mapper['O']=mapper['O']-count
	if 'G' in mapper:
		count=mapper['G']
		numcount[8]=count
		mapper['G']=mapper['G']-0
		mapper['T']=mapper['T']-count	
		mapper['H']=mapper['H']-count
		mapper['E']=mapper['E']-count
		mapper['I']=mapper['I']-count
	if 'O' in mapper:
		count=mapper['O']
		numcount[1]=count
		mapper['O']=mapper['O']-count
		mapper['E']=mapper['E']-count
		mapper['N']=mapper['N']-count
	if 'H' in mapper:
		count=mapper['H']
		numcount[3]=count
		mapper['H']=mapper['H']-count		
		mapper['E']=mapper['E']-2*count
		mapper['T']=mapper['T']-count
		mapper['R']=mapper['R']-count
	if 'F' in mapper:
		count=mapper['F']
		numcount[5]=count
		mapper['F']=mapper['F']-count
		mapper['E']=mapper['E']-count
		mapper['I']=mapper['I']-count
		mapper['V']=mapper['V']-count
	if 'V' in mapper:
		count=mapper['V']
		numcount[7]=count
		mapper['V']=mapper['V']-count
		mapper['E']=mapper['E']-2*count
		mapper['S']=mapper['S']-count
		mapper['N']=mapper['N']-count
	if 'I' in mapper:
		count=mapper['I']
		numcount[9]=count
		mapper['I']=mapper['I']-count
		mapper['E']=mapper['E']-count		
		mapper['N']=mapper['N']-2*count
	finalnum=[]						
	for i in range(0,10):
		finalnum.extend([str(i)]*numcount[i])
	return ''.join(finalnum)


T=int(raw_input())
for i in range(1,T+1):
	text=raw_input()
	print "Case #"+str(i)+": "+str(getValue(text))
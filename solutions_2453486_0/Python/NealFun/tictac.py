#!/usr/bin/env python

def check_win(a,b,c,d):
	x=0
	o=0
	t=0
	if a=='X':
		x+=1
	elif a=='O':
		o+=1
	elif a=='T':
		t+=1
	if b=='X':
		x+=1
	elif b=='O':
		o+=1
	elif b=='T':
		t+=1
	if c=='X':
		x+=1
	elif c=='O':
		o+=1
	elif c=='T':
		t+=1
	if d=='X':
		x+=1
	elif d=='O':
		o+=1
	elif d=='T':
		t+=1
	if (x==3 and t==1) or (x==4):
		return 'X'
	if (o==3 and t==1) or(o==4):
		return 'O' 
	return 'N'
	
		
		
filein=open('input_s','r')
fileout=open('result','w')
t=filein.readline()
t=int(t)
for i in range(1,t+1):
	game=[]
	for j in range(0,4):
		temp=filein.readline()
		row=[]
		for k in range(0,4):
			row.append(temp[k])
		game.append(row)
	#####input ends
	##### X O D N
	status='S'
	for j in range(0,4):
		temp=check_win(game[j][0],game[j][1],game[j][2],game[j][3])
		if temp=='X' or temp=='O':
			status=temp
			break	
		temp=check_win(game[0][j],game[1][j],game[2][j],game[3][j])
		if temp=='X' or temp=='O':
			status=temp
			break	
	if status=='X':
		fileout.write("Case #"+str(i)+": "+"X won\n")
		filein.readline()
		continue
	elif status=='O':
		fileout.write("Case #"+str(i)+": "+"O won\n")
		filein.readline()
		continue
	status=check_win(game[0][0],game[1][1],game[2][2],game[3][3])
	if status=='X':
		fileout.write("Case #"+str(i)+": "+"X won\n")
		filein.readline()	
		continue
	elif status=='O':
		fileout.write("Case #"+str(i)+": "+"O won\n")
		filein.readline()	
		continue
	status=check_win(game[0][3],game[1][2],game[2][1],game[3][0])
	if status=='X':
		fileout.write("Case #"+str(i)+": "+"X won\n")
		filein.readline()	
		continue
	elif status=='O':
		fileout.write("Case #"+str(i)+": "+"O won\n")
		filein.readline()
		continue
	##check whether there is .
	N=False
	for j in range(0,4):
		for k in range(0,4):
			if game[j][k]=='.':
				N=True
				break
		if N==True:
			break
	if N==True:
		fileout.write("Case #"+str(i)+": "+"Game has not completed\n")
	else:
		fileout.write("Case #"+str(i)+": "+"Draw\n")

	filein.readline()
filein.close()
fileout.close()
	

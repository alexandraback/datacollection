import sys

import psyco

psyco.full()

def GCD(x, y):
 if x < 0 : x = -x
 if y < 0 : y = -y
 if x + y > 0 :
  g = y
  while x > 0:
   g = x
   x = y % x
   y = g
  return g
 else:
  return 0
# kepzeld azt, hogy hozzaadsz felet.
def myrange(d) :
    if d>0 :
	return range(d)
    elif d<0 :
	return range(-1,d-1,-1)
    else :
	return []

def targetCell_Buggy(realX,realY,deltaX,deltaY) :
    targetX = realX+deltaX
    targetY = realY+deltaY
    sgnX = cmp(deltaX,0.) # epszilon-erzekeny
    sgnY = cmp(deltaY,0.)
    # melyikbe lep bele? athalad-e racsponton?
    cellX = int(targetX+float(sgnX+1)/2)
    cellY = int(targetY+float(sgnY+1)/2)
    return cellX,cellY

def half(q) :
    return abs(round(q+0.5)-q-0.5)<1e-7

def targetCell(realX,realY,deltaX,deltaY) :
    targetX = realX+deltaX
    targetY = realY+deltaY
    sgnX = cmp(deltaX,0.) # epszilon-erzekeny
    sgnY = cmp(deltaY,0.)
    cellX = int(targetX+0.5)
    cellY = int(targetY+0.5)
    if half(targetX) :
	cellX = int(targetX)+(sgnX+1)/2
    if half(targetY) :
	cellY = int(targetY)+(sgnY+1)/2
    lastCellX = int(realX+0.5)
    lastCellY = int(realY+0.5)
    if half(realX) :
	lastCellX = int(realX)+(sgnX+1)/2
    if half(realY) :
	lastCellY = int(realY)+(sgnY+1)/2
    # melyikbe lep bele? athalad-e racsponton?
    return cellX,cellY,lastCellX,lastCellY

def normSq(a,b) :
    return a*a+b*b

def didI(lastX,lastY,x,y) :
    global logging
    if logging :
	print (lastX,lastY,x,y)
    if normSq(x,y)<1e-10 :
	return True
    if normSq(lastX,lastY)<1e-10 :
	return True
    if lastX*x<=0 and lastY*y<=0 :
	if abs(lastX*y-lastY*x)<1e-8 :
	    return True
    return False

logging = False

def sim(a,posH,posW,dH,dW,h,w,d) :
    global logging
    logging = False #(dH==-5 and dW==2)
    assert dH*dH+dW*dW<=d*d
    v = []
    for hi in myrange(dH) :
	hf = float(hi)+0.5
	wf = hf*dW/dH
	v.append((hf,wf))
    for wi in myrange(dW) :
	wf = float(wi)+0.5
	hf = wf*dH/dW
	v.append((hf,wf))
    v.append((0.,0.))
    v.append((float(dH),float(dW)))
    v.sort( key = lambda (x,y) : x*x+y*y )
    vv = []
    for i,(x,y) in enumerate(v) :
	if i==0 :
	    lastX = x
	    lastY = y
	    continue
	if (lastX-x)**2+(lastY-y)**2>1e-8 :
	    vv.append([x,y,1])
	else :
	    vv[-1][2] = 2
	lastX = x
	lastY = y
    vv[-1][2] = -1
    if logging :
	print ">",vv

    realX = float(posH)
    realY = float(posW)
    hMirr = 1 # a vizszintes tengelyre tukroz ha -1!!!
    wMirr = 1
    lastX = 0.
    lastY = 0.
    for i,(x,y,mode) in enumerate(vv) :
	if logging :
	    print ">>",i,(x,y,mode),(realX,realY)
	deltaX = (x-lastX)*hMirr
	deltaY = (y-lastY)*wMirr
	cellX,cellY,lastCellX,lastCellY = targetCell(realX,realY,deltaX,deltaY)
#	if logging :
#	    print ">>",cellX,cellY
	move = abs(cellX-lastCellX)+abs(cellY-lastCellY)
#	print mode,move
#	print "moving from",(realX,realY),"to",(realX+deltaX,realY+deltaY)
#	print "cellwise",(lastCellX,lastCellY),"to",(cellX,cellY)
	assert 0<=move<=2
	if move==0 :
	    assert mode==-1
	assert mode==move or mode==-1
	sys.stdout.flush()
	
	bounced = False

	if move==1 :
	    if a[cellX][cellY]=="#" :
		bounced = True
		if cellX!=lastCellX :
		    hMirr *= -1
		if cellY!=lastCellY :
		    wMirr *= -1
	else :
	    # athaladtam egy rohadt racsponton.
	    c00 = a[lastCellX][lastCellY]=="#"
	    c10 = a[    cellX][lastCellY]=="#"
	    c01 = a[lastCellX][    cellY]=="#"
	    c11 = a[    cellX][    cellY]=="#"
	    assert not c00
	    if c11 :
		bounced = True
		if (not c01) and (not c10) :
		    return False # destroy
		else :
		    # vagy forditva?:
		    if c10 :
			hMirr *= -1
		    if c01 :
			wMirr *= -1
	if i!=0 and didI(realX-posH,realY-posW,realX+deltaX-posH,realY+deltaY-posW) :
	    if logging :
		print "returned:",(realX,realY,realX+deltaX,realY+deltaY,posH,posW)
	    return True
	realX = realX+deltaX
	realY = realY+deltaY
	lastX = x
	lastY = y
	if not bounced :
	    lastCellX = cellX
	    lastCellY = cellY
    return False


def solve(a,posH,posW,h,w,d) :
    num = 0
    d2 = d*d
    for dH in range(-d,d+1) :
	for dW in range(-d,d+1) :
	    if dH*dH+dW*dW>d2 :
		continue
	    if dH==0 and dW==0 :
		continue
	    g = GCD(abs(dH),abs(dW))
	    if g!=1 :
		continue
	    assert dH*dH+dW*dW<=d2
	    dHR = dH
	    dWR = dW
	    while (dHR+dH)**2+(dWR+dW)**2 <= d2 :
		dHR += dH
		dWR += dW
#	    print dHR,dWR
	    if sim(a,posH,posW,dHR,dWR,h,w,d) :
		# print dHR,dWR
		num += 1
    return num

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    h,w,d = map(int,sys.stdin.readline().split())
    a = []
    for i in range(h) :
	a.append(sys.stdin.readline().strip())
	assert len(a[-1])==w
    for i in range(h) :
	for j in range(w) :
	    if a[i][j]=="X" :
		posH = i
		posW = j
    output = solve(a,posH,posW,h,w,d)
    print "Case #"+str(testNr)+": "+str(output)
    sys.stdout.flush()

def go():
    f=open('in.txt')
    c=int(f.readline())
    for case in range(1,c+1):
        f.readline()
        l1=[float(x) for x in f.readline().split()]
        l2=[float(x) for x in f.readline().split()]
        print 'Case #%d:'%case,cheat(l1,l2),fair(l1,l2)
    
    

def cheat(l1,l2):
	c1=list(l1)
	c2=list(l2)
	c1.sort()
	c2.sort()
	c2.reverse()
	win=0
	while c1:
		for x in range(len(c2)):
			if c1[0]>c2[x]:
				#print c1[0],c2[x], 'win'
				del c1[0]
				del c2[x]
				win+=1
				break
			if x==len(c2)-1:
				#print c1[0],c2[0],'lose'
				del c1[0]
				del c2[0]
	return win

    
def fair(l1,l2):
    c1=list(l1)
    c2=list(l2)
    c1.sort()
    c2.sort()

    #c1.reverse()
    #c2.reverse()
    win=0
    while c1:
        for x in range(len(c2)):
                if c1[0]>c2[-1]:
                        #print c1[0],c2[x], 'win'
                        del c1[0]
                        del c2[-1]
                        win+=1
                        break
                m=0
                while c2[m]<c1[0]:
                    m+=1
                #print c1[0],c2[m],'lose'
                del c1[0],c2[m]
                        
    return win

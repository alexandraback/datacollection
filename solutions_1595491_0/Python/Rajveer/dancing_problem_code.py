f=open('/home/cscape/Desktop/B-small-attempt0.in','r')
r_lines=f.readlines()
number_of_inputs=int(r_lines[0])
word_lines=[]
for inp in range(number_of_inputs):
    line=r_lines[inp+1].split(' ')
    dancers_no=int(line[0])
    surprise_val=int(line[1])
    num=int(line[2])
    li=[]
    for dancer in range(1,dancers_no+1):
    	li.append(int(line[2+dancer]))
    count=0
    a=[]
    for i in li:
	    if num*3<=i:
    		count+=1
	    	a.append(i)
	    elif abs(num*3-4)>i :
	    	pass
	    else:
	    	if 3*num-1==i or 3*num-2==i:
	    	    count+=1
	    	    a.append(i)
	    	elif 3*num-3==i or 3*num-4==i:
	    	    if surprise_val!=0:
        	        surprise_val-=1
	    	        count+=1
	    	        a.append(i)
	    	else:
	    	    pass
    word_lines.append('Case #%s'%(inp+1)+': '+str(count)+'\n')
f=open('/home/cscape/Desktop/dancing_problem.out','w')
f.writelines(word_lines)
f.close()

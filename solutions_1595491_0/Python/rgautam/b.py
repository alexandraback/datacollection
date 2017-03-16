f=open('/home/cscape/Downloads/B-small-attempt0.in','r')
r_lines=f.readlines()
number_of_inputs=int(r_lines[0])
w_lines=[]
num_of_judge = 3
for inp in range(number_of_inputs):
    line=r_lines[inp+1].split(' ')
    num_dancers=int(line[0])
    surprise=int(line[1])
    num=int(line[2])
    li=[]
    for dancer in range(1,num_dancers+1):
    	li.append(int(line[2+dancer]))
    count=0
    for i in li:
	    if num*num_of_judge<=i:
    		count+=1
	    elif abs(num*num_of_judge-4)>i :
	    	pass
	    else:
	    	if num_of_judge*num-1==i or num_of_judge*num-2==i:
	    	    count+=1
	    	elif num_of_judge*num-3==i or num_of_judge*num-4==i:
	    	    if surprise!=0:
        	        surprise-=1
	    	        count+=1
	    	else:
	    	    pass
    w_lines.append('Case #%s'%(inp+1)+': '+str(count)+'\n')
f=open('/home/cscape/Desktop/codejam_b.txt','w')
f.writelines(w_lines)
f.close()

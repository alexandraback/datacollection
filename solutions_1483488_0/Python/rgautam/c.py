f=open('/home/cscape/Downloads/C-small-attempt0.in','r')
r_lines=f.readlines()
number_of_inputs=int(r_lines[0])
w_lines=[]
for ln in range(number_of_inputs):
    line=r_lines[ln+1].split(' ')
    l_limit=int(line[0])
    h_limit=int(line[1])
    li = []
    if h_limit < 10:
        pass
    else:
        if l_limit < 10:
            l_limit = 10
        for i in xrange(l_limit,h_limit+1):
            s = str(i)
            for j in xrange(1,len(s)):
                s1 = int(s[j:]+s[:j])
                if s1 > i:
                    if s1 <= h_limit and s1 >= l_limit:
                        if len(set(str(s1)).difference(s)) == 0:
                            li.append((s,s1))
    
    w_lines.append('Case #%s: %s\n'%((ln+1),str(len(set(li)))))
    
#print w_lines
 
f=open('/home/cscape/Desktop/codejam-c.txt','w')
f.writelines(w_lines)
f.close()

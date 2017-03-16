f=open('/home/cscape/Desktop/C-large.in','r')
r_lines=f.readlines()
f.close()
number_of_inputs=int(r_lines[0])
word_lines=[]
for i in range(number_of_inputs):
   line=r_lines[i+1].split(' ')
   l_limit=int(line[0])
   h_limit=int(line[1])
   a=[]
   for num_int in range(l_limit,h_limit):
     num=str(num_int)
     for j in range(1,len(num)):
        rev=num[-j:]+num[:-j]
        if  int(rev)>=l_limit and int(rev)<=h_limit  and int(rev)>num_int:
            a.append(num+'-'+rev)
   word_lines.append('Case #%s'%(i+1)+': %s \n'%len(set(a)))        
   i+=1
f=open('/home/cscape/Desktop/C-large-.out','w')
f.writelines(word_lines)
f.close()

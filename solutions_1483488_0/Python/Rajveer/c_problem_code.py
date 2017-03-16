f=open('/home/cscape/Desktop/C-small-attempt0.in','r')
r_lines=f.readlines()
f.close()
number_of_inputs=int(r_lines[0])
word_lines=[]
for j in range(number_of_inputs):
   line=r_lines[j+1].split(' ')
   low_value=int(line[0])
   high_value=int(line[1])
   count=0
   for num  in range(low_value,high_value):
        for i in range(1,len(str(num))):
            mod_no=num%pow(10,i)
            devide_no=num/pow(10,i)
            new_no=(mod_no*pow(10,len(str(num))-i))+devide_no
            if new_no >= low_value and new_no <= high_value and new_no>num:
                count+=1
   word_lines.append('Case #%s'%(j+1)+': '+str(count)+'\n')        
   j+=1
f=open('/home/cscape/Desktop/A-small-attempt0.out','w')
f.writelines(word_lines)
f.close()

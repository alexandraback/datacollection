filename = open("ain.txt")
out = open("aout.txt",'w')

       
t = int(filename.readline())

i=0
while i<t:
        i += 1
        k = int(filename.readline())
        
        if(k == 0):
                out.write('Case #'+str(i)+': INSOMNIA')
                out.write('\n')
        else:
                j=1
                xset = set([])
                while j>0:
                        digits = str(j*k)
                        l = 0
                        while l<10:
                                if str(l) in digits:
                                        xset.add(str(l))
                                l +=1
                                
                                              
                        if len(xset) == 10:
                                break
                        j += 1


        
                out.write('Case #'+str(i)+': '+str(j*k))
                out.write('\n')

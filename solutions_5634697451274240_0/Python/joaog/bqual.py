filename = open("bin.txt")
out = open("bout.txt",'w')

    
t = int(filename.readline())

i=0
while i<t:
        i += 1
        stack = filename.readline()

        
        res = 0
        j = 0

        while j < len(stack)-2:
                if stack[j] != stack[j+1]:
                        res += 1
                j += 1

        if stack[j] == '-':
                res += 1
                

        
        out.write('Case #'+str(i)+': '+str(res))
        out.write('\n')

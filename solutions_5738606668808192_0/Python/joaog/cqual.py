filename = open("cin.txt")
out = open("cout.txt",'w')

    
t = int(filename.readline())

i=0
while i<t:
        i += 1
        line = filename.readline()
        data = line.split()
        n = int(data[0])
        j = int(data[1])
        out.write('Case #'+str(i)+':')
        out.write('\n')
        
        l = 0
        while l<j:
                
                res = ''

                d = 0
                while d< n/2:
                        res = str(((2*l+1)/(2**d))%2)+res
                        d += 1

                res = res[::-1]+res

                out.write(res)
                out.write(' 3 4 5 6 7 8 9 10 11\n')

                l += 1

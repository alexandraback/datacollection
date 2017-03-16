filename = open("din.txt")
out = open("dout.txt",'w')

    
t = int(filename.readline())

i=0
while i<t:
        i += 1
        line = filename.readline()
        data = line.split()

        k = int(data[0])
        c = int(data[1])
        s = int(data[2])

        if c*s < k:
                out.write('Case #'+str(i)+': IMPOSSIBLE\n')
        else:
                out.write('Case #'+str(i)+': ')
                l = 0
                j = 0
                while l<s:
                        res = 1
                        r = 0
                        while r<c:
                                res = res + (j%k)*(k**r)
                                r += 1
                                j += 1
                        out.write(str(res)+' ')
                        l += 1
                        if j >= k:
                                break
                out.write('\n')

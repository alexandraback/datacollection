t = int(raw_input())
for i in range(t):
    line = raw_input()
    s,size = line.split()
    need =0
    val= int(size[0])
    for c in range(1,len(size)):
        if(int(size[c]) != 0):
            if(val>=c):
                val+=int(size[c])
            else:
                need += c-val
                val+=c-val+int(size[c])
    print "Case #%d: %d"%(i+1,need)  
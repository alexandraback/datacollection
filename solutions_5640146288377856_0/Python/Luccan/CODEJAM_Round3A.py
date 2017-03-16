def sol():
    def firstqn(R,C,W):
        miss = R*(C/W)
        killboat = W-1
        if (C%W!=0):
            miss+=1
        return miss+killboat
    global line_counter
    data = inp[line_counter].split()
    line_counter+=1
    R = int(data[0])
    C = int(data[1])
    W = int(data[2])
    return str(firstqn(R,C,W))
    
##with open('lol.txt', 'r') as f:
with open('A-small-attempt0 (3).in', 'r') as f:
##with open('A-large (1).in', 'r') as f:
    inp = f.readlines()
    f.close()
line_counter = 0
T = int(inp[line_counter])
line_counter+=1
data = ''
for i in range(T):
    print i
    data += 'Case #%d:' %(i+1) + ' ' + sol()+'\n'
with open('output.txt', 'w') as f:
    f.write(data)
    f.close()
print data
print 'done!'

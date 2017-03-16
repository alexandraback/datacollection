lines = open("D-small-attempt0.in").readlines()

T = int(lines[0])

caseno = 1
    
# 0 -> L
# 1 -> G

for line in lines[1:T+1]:
    line = line.lstrip().rstrip()
    K = int(line.split(" ")[0])
    C = int(line.split(" ")[1])
    S = int(line.split(" ")[2])
    
    ans = ''
    if C * S < K:
        ans = 'IMPOSSIBLE'
    else:
        output = 0
        count = 1
        while count < K:
            output = (K * output) + count
            if count%C == 0:
                ans = ans + str(output) + " "
                output = 0
            else:
                output = output - 1
            count = count + 1
        count = 0
        output = output * K
        while (count + K)%C != 0:
            output = output * K
            count = count + 1
        ans = ans + str(output + K)
    
    print 'Case #%s: %s' % (caseno, ans)            
    
    caseno = caseno + 1

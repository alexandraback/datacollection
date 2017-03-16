#python3

def getseq(a, n):
    if a >= 0:
        return getseq_(a, n)
    
    seq, n = getseq_(-a, n)
    return [-s for s in seq], n


def getseq_(a, n):
    seq = []
    sum = 0
    while sum <= (a-n):
        seq.append(n)
        sum += n
        n += 1
        
    if sum == a:
        return seq, n
    
    for i in range(a-sum):
        seq.append(-n)
        seq.append(n+1)
        n += 2
    
    return seq, n
        

def get_string(seq, s):
    string = ""
    for x in seq:
        if x > 0:
            string += s[0]
        else:
            string += s[1]
    return string
    

def goto(s):
    x, y = 0, 0
    
    i = 1
    for c in s:
        if (c == 'N'):
            y += i
        elif (c == 'S'):
            y -= i
        elif (c == 'E'):
            x += i
        elif (c == 'W'):
            x -= i
        
        i += 1
    
    return x, y


T = int(input())

for t in range(T):
    
    X, Y = list(map(int, input().split()))
    
    seq_x, n1 = getseq(X, 1)
    seq_y, n2 = getseq(Y, n1)
    
    string = get_string(seq_x, "EW") + get_string(seq_y, "NS")
    #if goto(string) != (X, Y):
    #    raise RuntimeError("wrong way!!")
    #if len(string) > 500:
    #    raise RuntimeError("too long!!")
    
    print("Case #%d: %s" % (t+1, string))


